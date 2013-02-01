/*********************************************************************

  iris_if.cpp
  
**********************************************************************/


#include "gen.h"
//#include "error.h"
#include "utils.h"
#include "commport.h"
#include "iris_if.h"
#include "comminc.h"
#include "NetworkServices.h"
#include "Message.h"
#include "GetRequestMessage.h"

#include  "VcbTestMessageHeaders.h"
#include "gui_eve.h" 

extern int PortNumber;
extern CTRACE t;
//extern CString strRecMsgDlg;
extern int gReceivedMessageID[];


IRIS_Node::IRIS_Node()
       :irisIsInitialized(0),
        unstuffedMsgBufSize(0),       
		unstuffedMsgBuf(0)

{
  //printf ("IRIS_Node - constructor income\n"); 
	IrisNodeInit();
	//printf ("IRIS_Node - constructor over\n"); 

}
/*
IRIS_Node::IRIS_Node(long compatCode, int maxMsg, unsigned char subsysId)
       :irisIsInitialized(0),
        unstuffedMsgBufSize(0),       
				unstuffedMsgBuf(0)
{

}
*/

IRIS_Node::~IRIS_Node()
{
		// Make sure the node is destroyed
	IrisNodeDestroy();
}
/********************************************************************

  Declaration: Performs initialization (including opening the DOSerial
	             PortInterface) required to make the node ready to begin
							 communications.
							 
							 Actual instance of a class implementing DOSerialPort
							 Interface is passed to the init function to isolate IRIS
							 from any knowlege of the hardware or aplication.

  Call: 
  Input: char *, unsigned long
  Returns: 
	Initial coding: 13-OCT-2006, YS
  	  
*********************************************************************/
int IRIS_Node::IrisNodeInit ()
{
	int ndx;
	int status = IRIS_NodeInterface::OK; // Init to 'OK'
	//int status = 1; // Init to 'OK'
    linkTestResult=0;
		// Do not proceed if IRIS is already initialized
	if(irisIsInitialized)
		return IRIS_NodeInterface::OK; 
	
	// Set the multithreading mode
	//multiThreaded = threadSafe;
	
		// If not thread safe, initialize the piggy back buffer
		/*
		** NOTE Piggy back buffer is automatically set up to be 
		** the maximum allowable IRIS message size.  There is no dynamic 
		** buffer size increase provision as there is with received messages.
		*/
	if(!multiThreaded)
	{
		printf ("IrisNodeInit:(multiThreaded == FALSE)\n"); 
		// Create the array
		piggyBackBuffer = new unsigned char[IRIS_MAX_MESSAGE_LENGTH];
	  // Initialize the pointers
		piggyBackHead = piggyBackTail = piggyBackBuffer;
		piggyBackEnd = piggyBackBuffer + IRIS_MAX_MESSAGE_LENGTH - 1;
	}

		// Initialize the receive packet buffer
	if(unstuffedMsgBuf != 0)
		{
		 delete unstuffedMsgBuf;
		}

	unstuffedMsgBufSize = 300;
	unstuffedMsgBuf = new unsigned char [unstuffedMsgBufSize];

	
	// Create and initialize the message pool
	messagePool = (Message **)(new Message *[256]);
	
	if(messagePool != 0)
	{
		// Pre-fill the message pool with zeros to indicate empty slots
		for(ndx = 0 ; ndx < 256; ndx++)
			messagePool[ndx] = (Message *)0;
		
		// Create pool items for the special IRIS messages
		messagePool[GET_REQUEST_MSG_ID] = new GetRequestMessage();
		messagePool[LINK_TEST_MESSAGE] = new LinkTestMessage();
		/*
		messagePool[UPGRADE_COMMAND_MESSAGE] = new UpgradeCommandMessage();
		messagePool[UPGRADE_DATA_MESSAGE] = new UpgradeDataMessage();
		messagePool[STATUS_MESSAGE] = new StatusMessage();
		messagePool[ROUTED_SUBSYSTEM_MESSAGE] = new SubsystemRoutedMessage();
		*/
    // Now fill in the pool by calling the node's createMessage function with successive ID's
		// until zero is returned
		for(ndx = 32; ndx < 256; ndx++)		
		{
			messagePool[ndx] = CreateMessage(ndx);			
			if(messagePool[ndx] == (Message *)0)
			{
			  // t.TRACE("IrisNodeInit::CreateMessage for %d FAIL! ", ndx);
				// break; // All done (create returned a zero)
			}
			else
			{
			 //t.TRACEY("IrisNodeInit::CreateMessage for %d - OK\n", ndx);
			}
		}
 
	}
	else // Initialization fails on failure to allocate message pool
	{
		status = 0;//IRIS_NodeInterface::IRIS_INIT_FAILURE;
		// Do a cleanup
		//IrisNodeDestroy();

		return status;
	}
	

	//if(upgradePktForSend == 0)
	//	upgradePktForSend = new UpgradeDataMessage();

	// Save the serial port reference
  // comport = IRISserialPort;

   // Add this node to the subsystem manager	
   //IRIS_SubsystemServicesManager::AddBoundaryObject(this);

	// Indicate initialization is complete
   irisIsInitialized = true;

	return status;

}
/********************************************************************

  Declaration: Dispatches the received message.  Length is the number 
	             of characters from the start of buffer, up to and
							 including the end flag.
							 This function unstuffs, CRC checks, de-serializes, and
							 dispatches the incomming packet.
							 If the CRC check fails, the message is discarded.

  Call: 
  Input: char *, unsigned long
  Returns: 
  	  
*********************************************************************/ 
void IRIS_Node::receivePacket (char *buffer, unsigned long length)
{
	unsigned int unstuffNdx, stuffNdx;
	Message *incomming; // The received message
	int id;  // The received message ID
	int status;	

	// Make sure the buffer is big enough
	if(length > (unsigned long)unstuffedMsgBufSize)
	{
		// Delete the old buffer if it exists
		if(unstuffedMsgBuf != 0)
			delete[] unstuffedMsgBuf;

	  // Now allocate the new buffer
		if(length > IRIS_MAX_MESSAGE_LENGTH) // Message length limited to IRIS_MAX_MESSAGE_LENGTH
		{
			unstuffedMsgBufSize = IRIS_MAX_MESSAGE_LENGTH;
			unstuffedMsgBuf = new unsigned char [unstuffedMsgBufSize];
		}
		
		else
		{
				// Allocate plenty of space to avoid thrashing the heap
			unstuffedMsgBufSize = length * 2;
			unstuffedMsgBuf = new unsigned char [unstuffedMsgBufSize];
		}
	}		

	// Unstuff the message
	// NOTE: stuffNdx is the length of the unstuffed packet
	for(stuffNdx = unstuffNdx = 0; stuffNdx < length - 1;) // Last character is the end flag (thus length - 1)
	{
			// Copy the character into the unstuffed message buffer
		unstuffedMsgBuf[unstuffNdx] = ((unsigned char *)buffer)[stuffNdx];
			// Detect the first character (IRIS_PACKET_CONTROL_CHAR) of a stuffed series
		if(unstuffedMsgBuf[unstuffNdx] == IRIS_PACKET_CONTROL_CHAR)
		{
			/*
			Stuff sequence detected, if its a IRIS_PACKET_END_FLAG replace it 
			(overwriting the original control character).  
			Otherwise its a 0x7D and that character is already in the dest buffer from the if operation
			NOTE: any unstuffing errors are detected by the CRC check since the CRC calculation
			and check wrap the stuff/unstuff operations on the packet.
			*/
			if((((unsigned char *)buffer)[++stuffNdx]) == IRIS_PACKET_CONTROL_SEQUENCE_0x7E_REPLACEMENT)
				unstuffedMsgBuf[unstuffNdx]	= IRIS_PACKET_END_FLAG;
		}
		stuffNdx++;  // Not a stuffed character, on to the the next
		unstuffNdx++;
	 }

	// Get the message ID
	id = (int)unstuffedMsgBuf[0];
	if (31 != id)
	{
		  t.TRACEY ("Receive message id=%d", id);
		  t.TRACEY (" [0x%X]\n", id);  
	 }

	//strRecMsgDlg.Format("Receive msg %d\n", id);
	
		// Now get a message object for this ID
	incomming = messagePool[id];
	
	// Report an error and abort if message ID is no good
	if(incomming == 0)
	{
		//commError(IRIS_NodeInterface::BAD_MESSAGE_ID);
		t.TRACEY ("IRIS_NodeInterface::BAD_MESSAGE_ID - %d. Check MessagePool.\n", id);
		return;
	}

	// Deserialize the packet into the message object
	status = incomming->deserialize(unstuffedMsgBuf, length);
	if (CRC_FAIL == status)
		{
		 t.TRACEY ("IRIS_NodeInterface::CRC_FAIL - %d\n", status);
		}
	else
		{
		 //t.TRACEY ("IRIS_NodeInterface::CRC_OK - %d\n", status);
		}
	
 /*************TRACE******************
	unsigned short calcCRC;
  unsigned short recvCRC;

	calcCRC = NetworkServices::calcCRC(unstuffedMsgBuf, length-3);
	t.TRACE ("calculated CRC: 0x%X\n", calcCRC);
 ************************************/	
  
  // If the de-serialization went ok, deliver the message
	if(status == IRIS_NodeInterface::OK)
		dispatch(incomming);  // After return, message has been delivered
	else
		{	
		 printf ("Something went bad\n");
		//commError((IRIS_NodeInterface::IRIS_STATUS_CODE)status);  // Something went bad, log an error
		}
  
}

/********************************************************************

  Declaration: Message delivery function called upon successful
	             deserialization of a received message.
							 
							 This function handles internal messaging or calls the
							 application receive functions if it is an application
							 message.
  Call: 
  Input: Message *msg
  Returns: 
	Initial coding: 18-OCT-2006, YS
  	  
*********************************************************************/
int IRIS_Node::dispatch (Message *msg)
{
  // int status;
  // t.TRACEY("Dispatcher for message %d\n", msg->ID); 
	switch(msg->ID)
	{
			// Pass off any upgrade messages to the handlers
		case ROUTED_SUBSYSTEM_MESSAGE:
			// Notify subsystem manager of originator in received message
			//IRIS_SubsystemServicesManager::ReceivedOriginator(((SubsystemRoutedMessage *)msg)->originator);
			//IRIS_SubsystemServicesManager::IncommingSubsystemMessage((SubsystemRoutedMessage *)msg);
			break;
		case IRIS_NodeInterface::UPGRADE_COMMAND_MESSAGE:
		{
			// Notify subsystem manager of originator in received message
			//IRIS_SubsystemServicesManager::ReceivedOriginator(((UpgradeCommandMessage *)msg)->originator);
			//IRIS_SubsystemClient *localSubsys = IRIS_SubsystemServicesManager::GetLocalSubsystem();
			//IRIS_SubsystemServer *subsysServer = IRIS_SubsystemServicesManager::GetServer(); 
			
			/*
			switch(((UpgradeCommandMessage *)msg)->command)
			{ 				
				// Client commands.  Call the local subsystem client
				case IRIS_Subsystem::START:
					if(localSubsys != 0)
						localSubsys->UpgradeStart();
					break;
				case IRIS_Subsystem::FINISHED:
					if(localSubsys != 0)
						localSubsys->UpgradeFinished();
					break;
				case IRIS_Subsystem::STATUS_REQUEST:
					if(localSubsys != 0)
						localSubsys->StatusRequest();
					break;
       */

				/*
				** Server commands.  These are passed to the server through the manager.
				** NOTE:
				** The messages are only received from single node (C) implementations.  Since these
				** nodes only understand point-to-point communications the clientId member of the 
				** message is established as the subsystem ID of the remote node.  This is done
				** on behalf of the single node subsystem by putting the ID in the server call.
				*/

				/*
		    case IRIS_Subsystem::ACCEPT_START:
					((UpgradeCommandMessage *)msg)->clientId = GetSubsystemId();
					if(subsysServer != 0)
						subsysServer->UpgradeAcceptStart(GetSubsystemId(), ((UpgradeCommandMessage *)msg)->data);
					break;
				case IRIS_Subsystem::ACK_PKT:
					((UpgradeCommandMessage *)msg)->clientId = GetSubsystemId();
					if(subsysServer != 0)
						subsysServer->UpgradePacketAcknowledge(GetSubsystemId(), (unsigned char)((UpgradeCommandMessage *)msg)->data);
					break;
        
				default:
					break;
			}
			*/
			break;
		}

		case IRIS_NodeInterface::STATUS_MESSAGE:
		{
			/*
			IRIS_SubsystemServer *subsysServer = IRIS_SubsystemServicesManager::GetServer(); 
			// Notify subsystem manager of originator in received message
			IRIS_SubsystemServicesManager::ReceivedOriginator(((StatusMessage *)msg)->originator);
			// Call the server, filling in the ID on behalf of the remote single node subsystem
			((StatusMessage *)msg)->clientId = GetSubsystemId();
			if(subsysServer != 0)
				subsysServer->StatusResponse(GetSubsystemId(), (StatusMessage *)msg);
			*/
			printf ("STATUS_MESSAGE\n");
			break;
		}
		
		case IRIS_NodeInterface::UPGRADE_DATA_MESSAGE:
		{
			/*
			IRIS_SubsystemClient *localSubsys = IRIS_SubsystemServicesManager::GetLocalSubsystem();
				// Notify subsystem manager of originator in received message
			IRIS_SubsystemServicesManager::ReceivedOriginator(((UpgradeDataMessage *)msg)->originator);
			if(localSubsys != 0)
				localSubsys->
				ReceiveUpgradePacket (	((UpgradeDataMessage *)msg)->deviceAddress, 
										((UpgradeDataMessage *)msg)->packetSize, 
										((UpgradeDataMessage *)msg)->GetBuffer(), 
										((UpgradeDataMessage *)msg)->sequenceNumber);
      */
			break;			
		}
		
		// If this is a get request, get an empty message and ask that it be filled in
		case IRIS_NodeInterface::GET_REQUEST_MSG_ID:

				// Handle link test request right here
      //t.TRACEY ("msg->reqMessageID =%d\n", ((GetRequestMessage *)msg)->requestedMessageID);
      
			gReceivedMessageID[((GetRequestMessage *)msg)->requestedMessageID] = 1;

			if(((GetRequestMessage *)msg)->requestedMessageID == IRIS_NodeInterface::LINK_TEST_MESSAGE)
			{
				linkTestRequestReceived();
				return IRIS_NodeInterface::OK;
			}
				// Get a pointer to the actual Message
			msg = messagePool[((GetRequestMessage *)msg)->requestedMessageID];
				// Report an error and abort if message ID is no good
			if(msg == 0)
			{
				commError(IRIS_NodeInterface::BAD_MESSAGE_ID);
				return IRIS_NodeInterface::BAD_MESSAGE_ID;
			}
      /*
			status = ReceiveMessageRequest(msg);
				// If the get was handled by the receiver, send back the result
			switch(status)
			{
				case IRIS_NodeInterface::OK:
					SendMessageReceiveThread(msg);
					break;
				case IRIS_NodeInterface::APP_MSG_REQUEST_NO_RESPONSE:
					break; // No action taken, app will handle response
				default:
					commError(IRIS_NodeInterface::APP_MSG_NOT_SUPPORTED);
					break;
			}
			*/
			break; // Done with Get Request

		default:
			//t.TRACEY ("dispatcher: default for message %d\n", msg->ID);
			// Handle Link test messages here
			if(msg->ID == IRIS_NodeInterface::LINK_TEST_MESSAGE)
			{
				//linkTestMessageReceived((LinkTestMessage *)msg);
				linkTestResult = 1;
				return IRIS_NodeInterface::OK;
			}
			// Deliver the message
			// status = ReceiveMessage(msg); -- requires NodeAdapter!! 
			gReceivedMessageID[ReceiveMessage(msg)] = 1;
			
			//if(status != IRIS_NodeInterface::OK)
			//	commError(IRIS_NodeInterface::APP_MSG_NOT_SUPPORTED);			
			break;

	}

	return IRIS_NodeInterface::OK;		 
}

/********************************************************************

  Declaration: Sets the most recently received error to the given value.
  Call: 
  Input: IRIS_STATUS_CODE errCode
  Returns: 
	Initial coding: 18-OCT-2006, YS
  	  
*********************************************************************/

void IRIS_Node::commError (IRIS_STATUS_CODE errCode)
{
	// Notify any listeners
	//if(errorEventListener != 0)
	//	errorEventListener->Notify(errCode);
		// Update the counter 
	totalErrorCount++;
		// Set the error code
	lastErrorCode = errCode;
}


/********************************************************************

  Declaration: Sets the most recently received error to the given value.
  Call: 
  Input: IRIS_STATUS_CODE errCode
  Returns: 
	Initial coding: 18-JAN-2007, YS
  	  
*********************************************************************/

int IRIS_Node::ReceiveMessage(Message *msg)
{
 return msg->ID;
}

/***************************************************************
*
*  Function name: CreateMessage
*  Parameter(s):  int - Message ID
*  Return type:   Message * - Newley created message
*  Author(s):     J Klaus
*  Purpose:       Allocates a new message on the heap 
*                   whose type is determined by the 
*                   given ID
*
*  Notes (i.e., error codes, special resource needs, etc.):
*
****************************************************************/

Message *IRIS_Node::CreateMessage (int msgID)
{
  
	// Select the class
  switch(msgID)
  {
    case VCB_TEST_SENSOR_INFO_ID:
      return new VcbTest_SensorInfo(); // 32 -Done
      break;
    case VCB_TEST_SENSOR_DETAILS_ID:
      return new VcbTest_SensorDetails(); // 33
      break;
    case VCB_TEST_CHANNEL_CONFIGURATIONS_ID:
      return new VcbTest_ChannelConfigurations(); // 34
      break;
    case VCB_TEST_INPUT_SIGNAL_LATCH_ID:
      return new VcbTest_InputSignalLatch(); // 35
			break;
    case VCB_TEST_PING_CALIBRATION_STATUS_ID: // 36
			return new VcbTest_PingCalibrationStatus();
			break;
    case VCB_TEST_OTHER_VCB_DATA_ID:
      return new VcbTest_OtherVcbData(); // 37
			break;
		case VCB_TEST_SYSTEM_STATE_ID:
      return new VcbTest_SystemState(); // 38
			break;
    case VCB_TEST_INTERRUPT_NUMBER_ID: //39
			return new VcbTest_InterruptNumber();
			break;
    case VCB_TEST_VCB_VMB_COMMON_ALARMS_ID: //41
			return new VcbTest_VcbVmbCommonAlarms();
			break;
    case VCB_TEST_SEND_AIRVLV_DAC_ID: //43
			return new VcbTest_SendAirvlvDac();
			break;
    case VCB_TEST_SEND_O2VLV_DAC_ID: //44
			return new VcbTest_SendO2vlvDac();
			break;
    case VCB_TEST_SEND_EXHVLV_DAC_ID: //45
			return new VcbTest_SendExhvlvDac();
			break;
    case VCB_TEST_SEND_EXHVLV_DITHER_DAC_ID: //46
			return new VcbTest_SendExhvlvDitherDac();
			break;
    case VCB_TEST_PWR_VMB_INTERNAL_ID: // 47
			return new VcbTest_PwrVmbInternal();
			break;
    case VCB_TEST_PWR_EXT_SENSOR_ID: //48
			return new VcbTest_PwrExtSensor();
			break;
    case VCB_TEST_PRESS_XDCR_OUT_ID: //49
			return new VcbTest_PressXdcrOut();
			break;
    case VCB_TEST_PORT_INPUT_ID: // 50
			return new VcbTest_PortInput();
			break;
    case VCB_TEST_VMB_TASK_INFO_ID: //52
			return new VcbTest_VmbTaskInfo();
			break;
    case VCB_TEST_PARACUBE_DATA_ID : //53
			return new VcbTest_ParacubeData();
			break; 
		case VCB_TEST_ACUTRONICS_INFO_ID: // 54
			return new VcbTest_AcutronicsInfo();
			break;
		case VCB_TEST_VMB_SYSTEM_STATE_ID:
      return new VcbTest_VmbSystemState(); // 55
			break;
		case VCB_TEST_SYSTEM_CHECKS_DATA_ID:
      return new VcbTest_SystemChecksData(); // 56
			break;
		case VCB_TEST_CHECKOUT_CIRCUIT_CHECK_ID:
      return new VcbTest_CheckoutCircuitCheck(); // 57
			break;
    case VCB_TEST_REGULATOR_TEST_RESULTS_ID:
      return new VcbTest_RegulatorTestResults(); // 60
			break;
    case VCB_TEST_SET_SAFE_CLOSE_ID: // 67
      return new VcbTest_SetSafeClose(); 
			break;
	  case VCB_TEST_SET_MNVR_OPEN_ID : //68
			return new VcbTest_SetMnvrOpen();
			break;
	  case VCB_TEST_SET_OK_TO_ZERO_ID : //69
			return new VcbTest_SetOkToZero();
			break;
    case VCB_TEST_SET_SW_LED_ID : //70
			return new VcbTest_SetSwLed();
			break;
    case VCB_TEST_SET_FS_PWR_EN_ID : //71
			return new VcbTest_SetFsPwrEn();
			break;
    case VCB_TEST_SET_NEB_ON_ID: //72
			return new VcbTest_SetNebOn();
			break;
	  case VCB_TEST_SET_MBUS_RESET_ID: //73
			return new 	VcbTest_SetMbusReset();
			break;
	  case VCB_TEST_SET_ILIM_MOD_EN_ID: //74
			return new 	VcbTest_SetIlimModEn();
			break;
	  case VCB_TEST_SET_ILIM_PSM_EN_ID: //75
			return new 	VcbTest_SetIlimPsmEn();
			break;
    case VCB_TEST_SET_WD_STRB_ID: //76
			return new 	VcbTest_SetWdStrb();
			break;
    case VCB_TEST_SET_EXP_ZERO_ID: //77
			return new 	VcbTest_SetExpZero();
			break;
    case VCB_TEST_SET_AUX_ZERO_ID: //78
			return new 	VcbTest_SetAuxZero();
			break;
		case VCB_TEST_SET_BUZZER_ID: //79	
			return new 	VcbTest_SetBuzzer();
			break;
    case VCB_TEST_SET_AIR_VALVE_EN_ID: //80
			return new 	VcbTest_SetAirValveEn();
			break;
    case VCB_TEST_SET_O2_VALVE_EN_ID: //81
			return new 	VcbTest_SetO2ValveEn();
			break;
    case VCB_TEST_SET_EXH_VALVE_EN_ID: //82
			return new 	VcbTest_SetExhValveEn();
			break;
    case VCB_TEST_E_E_PROM_TEST_PROGRESS_ID: // 84
      return new VcbTest_EEPromTestProgress();
			break;
/*
    case : //
			return new ();
			break;
*/
    default:
      return 0; // Message ID not supported!
  }
	
}

/********************************************************************

  Declaration: This function does the serialization and byte stuffing.
	             After this call the stuffed message buffer contains the
							 meassage ready to send and length contains the length of
							 the stuffed message.
							 It can handle internal messages (ID < 32) so it is not
							 available to the external interface.
	Call:  StuffMessageInternal(nSize, nCOM)
  Input: Message *, unsigned char *, unsigned long *, unsigned char *
  Returns: int - IRIS_NodeInterface::OK
  16.11.2006 Initial coding   

*********************************************************************/
int IRIS_Node::StuffMessageInternal (Message *msg, unsigned char *stuffedMsgBuf, unsigned long *length, unsigned char *serializedMsgBuf)
{
	int pktLength;
	int ndx, stuffNdx; 

	// Serialize the message 
	//t.TRACE("Before serialize.pktLength=%d\n", pktLength);
	pktLength = msg->serialize(serializedMsgBuf);
  //t.TRACE("StuffMessageInternal: pktLength=%d\n",pktLength); 
	
	// Byte stuff the message in a character by character loop
	for(stuffNdx = ndx = 0; ndx < pktLength; ndx++) 
	{
		switch(serializedMsgBuf[ndx])
		{
				// Control character
			case IRIS_PACKET_CONTROL_CHAR:
				stuffedMsgBuf[stuffNdx++] = IRIS_PACKET_CONTROL_CHAR;
				stuffedMsgBuf[stuffNdx++] = IRIS_PACKET_CONTROL_SEQUENCE_0x7D_REPLACEMENT;
				break;

				// End flag
			case IRIS_PACKET_END_FLAG:
				stuffedMsgBuf[stuffNdx++] = IRIS_PACKET_CONTROL_CHAR;
				stuffedMsgBuf[stuffNdx++] = IRIS_PACKET_CONTROL_SEQUENCE_0x7E_REPLACEMENT;
				break;

				// Normal Characters
			default:
				stuffedMsgBuf[stuffNdx++] = serializedMsgBuf[ndx];
				break;
		}	
	}

	// Add the end flag
	stuffedMsgBuf[stuffNdx++] = IRIS_PACKET_END_FLAG;
  
		// Set the length value
	*length = (unsigned long)stuffNdx;

	return IRIS_NodeInterface::OK;	
}

/********************************************************************

  Declaration: Responds to the request by sending the node's
	             compatability code along with a runtime object's address
							 as a unique identifier for loopback detection.

	Call:  linkTestRequestReceived()
  Input: 
  Returns: 
  24.11.2006 Initial coding JK

*********************************************************************/
void IRIS_Node::linkTestRequestReceived ()
{
	// Buffers for sending the Link Test message
	unsigned char stuffedMsgBuf[LINK_TEST_STUFFED_MSG_SIZE];
	unsigned char serializedMsgBuf[LINK_TEST_SERIALIZED_MSG_SIZE_IRIS_NODE];
	unsigned long length;

		// Link test not supported until initialization is complete
	if(irisIsInitialized)
	{
		LinkTestMessage temp;

		temp.compatabilityCode = this->compatabilityCode;
			// Send address of node object as unique identifier
		temp.controlNumber = (IRIS_UINT32)this;

			// Stuff the message
		StuffMessageInternal(&temp, stuffedMsgBuf, &length, serializedMsgBuf);

		// And send it as the receive thread
		// receiveThreadWritePort((char *)stuffedMsgBuf, length); - original		
		t.TRACEY ("Send linkTestRequestReceived(id=%d)\n", temp.ID);
		TxData(1, (char*)stuffedMsgBuf, length); // add by YS
	}
}
/********************************************************************

  Declaration: This function does the actual send of a request.
               Since internal messages will fail a msgID_IsValid 
							 check, this method does not check the validity of 
							 the ID and for this reason is not available to the 
							 external interface.

	Call:  SendMessageRequestInternal(int)
  Input: 
  Returns: 
  24.03.2007 Initial coding JK

*********************************************************************/

int IRIS_Node::SendMessageRequestInternal (int msgID)
{
  // Create a get request on the stack
  GetRequestMessage getReq;
	unsigned long length;

	// Stuffed and serialized message buffers for the special get request message are 
	// created on the stack right here (since the size is known)
	unsigned char stuffedMsgBuf[GET_REQUEST_STUFFED_MSG_SIZE];
	unsigned char serializedMsgBuf[GET_REQUEST_SERIALIZED_MSG_SIZE_IRIS_NODE];

	// Set the ID
	getReq.requestedMessageID = msgID;

	// Send the request message by normal means
	// Stuff the message
	StuffMessageInternal(&getReq, stuffedMsgBuf, &length, serializedMsgBuf);

	// And send it as the send thread	
	//t.TRACEY ("SendMessageRequestInternal(for id=%d)\n", msgID);
	return TxData(PortNumber, (char*)stuffedMsgBuf, length); // add by YS
	// return sendThreadWritePort((char *)stuffedMsgBuf, length); - original return		

}

/********************************************************************

  Declaration: This function 
	Call:  GetLinkCheckResult
  Input: 
  Returns: int
  27.03.2007 Initial coding YS

*********************************************************************/
int IRIS_Node::GetLinkCheckResult()
{
  //t.TRACEY ("IRIS_Node::GetLinkCheckResult returns %d\n", linkTestResult);
	return	linkTestResult;
}

/********************************************************************

  Declaration: This function
  Call:  UpdateDialogItems(int, void*)
  Input: message number, pointer to the dialog box
  Returns: int
  27.03.2007 Initial coding YS

*********************************************************************/
int IRIS_Node::UpdateDialogItems(int nMsgId, void* Dialog)
{
 //int PortNumber = 1;
 //long LastTimeInMS = 0;
 //long GenRecBytes = 0;
 //unsigned char tmpchr;
 //CString str;
 //MainClass *CTest = (CIRIS_GUI_01Dlg*)Dialog;

 if (1 == gReceivedMessageID[nMsgId])
	{
	 gReceivedMessageID[nMsgId]=0; // reset update;
	}
 return 1;
}

//	This returns the IRIS node to an uninitialized state.
//	The serial port is closed.  Memory resources used by
//	IRIS are released and the node is marked as not
//	initialized.
//
//	This does not result in the destruction of the object.
void IRIS_Node::IrisNodeDestroy ()
{
		// Indicate IRIS is no longer initialized
	irisIsInitialized = false;
		
	// Close the serial port so we can't get any more messages
	/*
	if(comport != 0)
	{
		comport->ClosePort();
		comport = 0; // Drop the reference (its up to the app to delete the object).
	}
  */
	
	// Remove this node from the subsystem manager	
  // IRIS_SubsystemServicesManager::RemoveBoundaryObject(this);

  // Delete the single threaded piggyback buffer if it exists
	/*
	if(piggyBackBuffer != 0)
	{
		delete[] piggyBackBuffer;
		piggyBackBuffer = 0;
	}
 */
		// Delete the unstuffed message buffer
	if(unstuffedMsgBuf != 0)
	{
		delete[] unstuffedMsgBuf;
		unstuffedMsgBufSize = 0;
		unstuffedMsgBuf = 0;
	}
		// Only clean up the message pool if it exists!
	if(messagePool != 0)
	{
			// Delete the instanciated messages of the message pool
		for(int ndx = 0; ndx < 256; ndx++)
		{
			if(messagePool[ndx] != 0)
			{
				delete messagePool[ndx];
				messagePool[ndx] = 0; 
			}
		}

			// Now delete the message pool itself
		delete[] messagePool;
		messagePool = 0;
	}
 /*
	if(upgradePktForSend != 0)
	{
		delete upgradePktForSend;
		upgradePktForSend = 0;
		
	}
*/
}
