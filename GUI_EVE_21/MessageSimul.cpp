
#include "gen.h"
#include "MessageSimul.h"
#include "Message.h"
//#include "utils.h"
#include "NetworkServices.h"
#include "comminc.h"
#include "iris_if.h"
#include "GetRequestMessage.h"
#include "VcbTestMessageHeaders.h"

extern CTRACE t;
extern int PortNumber;
extern IRIS_Node *INode;

#if 0
/********************************************************************

  Declaration: 
	Call:  Send_0x_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  10.11.2006 Initial coding / YS  

*********************************************************************/
void Send_0x_Message (int nSize, int nCOM)
{
  unsigned char  *IRISbuffer;
  int nMsgSize = 146;
	unsigned char tmpchr;
	unsigned short calcCRC;
  unsigned char tmpBuf[2];
	//unsigned char IRISbuffer[160];
	
  nMsgSize = sizeof(Test_STRUCT);
  IRISbuffer = new unsigned char[nMsgSize]; 
  t.TRACEY ("0x22::nMsgSize=%d\n", (int)nMsgSize);  	
	
	Test_STRUCT Test_Str;
	Test_Str.ID = 0x22;
	Test_Str.AuxPressureCounts = 10;
	Test_Str.AirValveCurrentCounts =2;

	memcpy( (void*)(IRISbuffer), (const void*)&Test_Str, nMsgSize);	

	calcCRC = NetworkServices::calcCRC(IRISbuffer, nMsgSize-3);	
	t.TRACEY ("calculated CRC: 0x%X\n", calcCRC);
	memcpy ((void*)(tmpBuf),  (const void*)&calcCRC, sizeof(calcCRC) );
  
	Test_Str.crc = calcCRC;
	Test_Str.nIRIS_PACKET_END_FLAG=IRIS_PACKET_END_FLAG;

  
	
	//IRISbuffer[143] =tmpBuf[1]; //0x35
	//IRISbuffer[144] =tmpBuf[0]; //0xAC

	//IRISbuffer[145] =0x7E;
 
 memcpy( (void*)(IRISbuffer), (const void*)&Test_Str, nMsgSize);	
 
 t.TRACEY ("Send_0x_Message- "); 
 for (int j=0; j < nMsgSize; j++)
  {
   tmpchr=(unsigned char) IRISbuffer[j];
   t.TRACEY ("\\0x%X", tmpchr); 
	}
	t.TRACEY ("\n"); 

  TxData(nCOM, (char*)IRISbuffer, nMsgSize);
	
	delete [] IRISbuffer;
}
#endif

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

int SendMessageRequestInternal (int msgID, int nCOM)
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
	INode->StuffMessageInternal(&getReq, stuffedMsgBuf, &length, serializedMsgBuf);

	// And send it as the send thread	
	//t.TRACEY ("SendMessageRequestInternal(for id=%d)\n", msgID);
	return TxData(nCOM, (char*)stuffedMsgBuf, length); // add by YS
	// return sendThreadWritePort((char *)stuffedMsgBuf, length); - original return		

}


/********************************************************************

  Declaration: 
	Call:  Send_32_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  10.11.2006 Initial coding / YS  
  
*********************************************************************/
void Send_32_Message (int nSize, int nCOM)
{
  unsigned long nMsgSize = 28;
	const int nArrSz = 50;
	unsigned char IRISbuffer [nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
  VcbTest_SensorInfo *Vcb_SensorInfo = new VcbTest_SensorInfo();
  
	Vcb_SensorInfo->TotalFlow = 14+nSize;
  Vcb_SensorInfo->OxygenFlow= 12;
  Vcb_SensorInfo->AirFlow = 13;
	Vcb_SensorInfo->TotalCurrentTemp= 167;
  Vcb_SensorInfo->OxygenCurrentTemp= 235;
  Vcb_SensorInfo->AirCurrentTemp= 145;

  INode->StuffMessageInternal (Vcb_SensorInfo, IRISbuffer, &nMsgSize, serializedMsgBuf);

	//Vcb_SensorInfo->serialize(IRISbuffer);
  
	//IRISbuffer[27] =0x7E; // this is wrong, because we should use something like "stuff message"

  t.TRACEY ("Send_32_Message - %d bytes\n", (int)nMsgSize);
  // t.TRACEY _HEX((char*)IRISbuffer, nMsgSize);
	
	TxData(nCOM, (char*)IRISbuffer, nMsgSize);

	//delete [] IRISbuffer;
}

/********************************************************************

  Declaration: 
	Call:  Send_34_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  10.11.2006 Initial coding / YS  
  
*********************************************************************/
void Send_34_Message (int nSize, int nCOM)
{
  const int nArrSz = 250;
	unsigned long nMsgSize = 0;	
	unsigned char IRISbuffer[nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
	unsigned char tmpchr;
  
	VcbTest_ChannelConfigurations *Vcb_ChannelConfigurations = new VcbTest_ChannelConfigurations();
  
  // Expiratory Pressure 
  Vcb_ChannelConfigurations->InspPressureCounts=nSize;
  
	// Expiratory Pressure   
  Vcb_ChannelConfigurations->InspPressureValue=nSize;

  // Aux Pressure 
  Vcb_ChannelConfigurations->AuxPressureCounts=1;
  
	// Aux Pressure 
  Vcb_ChannelConfigurations->AuxPressureValue=100;
  
	// Exhalation Valve Drive Voltage   
  Vcb_ChannelConfigurations->ExhValveVoltageCounts=1;
  // Exhalation Valve Drive Voltage 
  Vcb_ChannelConfigurations->ExhValveVoltageValue=1;
  
	//Exhalation Valve Drive Current 
  Vcb_ChannelConfigurations->ExhValveCurrentCounts=1;
  
	//Exhalation Valve Drive Current 
  Vcb_ChannelConfigurations->ExhValveCurrentValue=1;
 
	//Secondary Voltage Reference 
  Vcb_ChannelConfigurations->V4096refCounts=1;
  
	//Secondary Voltage Reference 
  Vcb_ChannelConfigurations->V4096refValue=1;
  
	//Analog Ground 
  Vcb_ChannelConfigurations->MUXA_AGND_Counts=1;

  //Analog Ground 
  Vcb_ChannelConfigurations->MUXA_AGND_Value=1;

  //Analog Ground 
  Vcb_ChannelConfigurations->MUXB_AGND_Counts=1;

  //Analog Ground 
  Vcb_ChannelConfigurations->MUXB_AGND_Value=1;

  //Analog Ground 
  Vcb_ChannelConfigurations->ADC_AGND_Counts=1;
  
	//Analog Ground 
  Vcb_ChannelConfigurations->ADC_AGND_Value=1;

  // Oxygen Valve Drive Current 
  Vcb_ChannelConfigurations->O2ValveCurrentCounts=1;

  //Oxygen Valve Drive Current 
  Vcb_ChannelConfigurations->O2ValveCurrentValue=1;

  // Air Valve Current Counts 
  Vcb_ChannelConfigurations->AirValveCurrentCounts=1;

  //Air Valve Current Counts 
  Vcb_ChannelConfigurations->AirValveCurrentValue=1;

  //Nebulizer Supply Voltage 
  Vcb_ChannelConfigurations->V9Test_C_Counts=1;

  //Nebulizer Supply Voltage 
  Vcb_ChannelConfigurations->V9Test_C_Value=1;

  //Ambient Temperature Near Valves 
  Vcb_ChannelConfigurations->AmbientTempCounts=1;

  //Ambient Temperature Near Valves 
  Vcb_ChannelConfigurations->AmbientTempValue=1;

  //Mod Power Fail 
  Vcb_ChannelConfigurations->ModPwrFailCounts=1;

  //Mod Power Fail 
  Vcb_ChannelConfigurations->ModPwrFailValue=1;

  //12P5 
  Vcb_ChannelConfigurations->V12P5_Test_Counts=1;

  //12P5 
  Vcb_ChannelConfigurations->V12P5_Test_Value=1;

  //5VA 
  Vcb_ChannelConfigurations->V5VA_Test_Counts=1;

  //5VA 
  Vcb_ChannelConfigurations->V5VA_Test_Value=1;

  //6VA 
  Vcb_ChannelConfigurations->V6VA_Test_Counts=1;

  //6VA 
  Vcb_ChannelConfigurations->V6VA_Test_Value=1;

  //N6VA 
  Vcb_ChannelConfigurations->N6VA_Test_Counts=1;

  //N6VA 
  Vcb_ChannelConfigurations->N6VA_Test_Value=1;

  //5P5VA 
  Vcb_ChannelConfigurations->V5P5VA_Test_Counts=9;

  //5P5VA 
  Vcb_ChannelConfigurations->V5P5VA_Test_Value=900;

  //9VA 
  Vcb_ChannelConfigurations->V9_TestA_Counts=1;

  //9VA 
  Vcb_ChannelConfigurations->V9_TestA_Value=1;
  
	//9VB 
  Vcb_ChannelConfigurations->V9_TestB_Counts=1;

  //9VB
  Vcb_ChannelConfigurations->V9_TestB_Value=10;
	
  INode->StuffMessageInternal (Vcb_ChannelConfigurations, IRISbuffer, &nMsgSize, serializedMsgBuf);

  t.TRACEY ("Send_34_Message - %d bytes\n", (int)nMsgSize);
  /*
	for (int j=0; j < nMsgSize; j++)
  {
   tmpchr=(unsigned char) IRISbuffer[j];
   t.TRACEY (" [%d]=", j); 
	 t.TRACEY ("\\0x%X", tmpchr); 
	}
	t.TRACEY ("\n");
  */
	TxData(nCOM, (char*)IRISbuffer, nMsgSize);
}

/********************************************************************

  Declaration: 
	Call:  Send_35_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  10.11.2006 Initial coding / YS  
  
*********************************************************************/
void Send_35_Message (int nSize, int nCOM)
{  
  unsigned long nMsgSize = 0;
	const int nArrSz = 50;
	//unsigned char tmpchr;
  unsigned char  IRISbuffer[nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
	
  VcbTest_InputSignalLatch *Vcb_InputSignalLatch = new VcbTest_InputSignalLatch();
  
	Vcb_InputSignalLatch->ModPwrFail = 1+nSize;
  Vcb_InputSignalLatch->PsmPwrFail = 2+nSize;
	Vcb_InputSignalLatch->OverPress  = 3;
	Vcb_InputSignalLatch->ZeroExppOn = 4+nSize;
	Vcb_InputSignalLatch->ZeroAuxPOn = 5;
	Vcb_InputSignalLatch->VmExhalOpen= 6;
	Vcb_InputSignalLatch->VmBuzzerOn = 7;
	Vcb_InputSignalLatch->NebSnse1   = 8+nSize;
	Vcb_InputSignalLatch->ExpPwrFail = 9;
	Vcb_InputSignalLatch->BuzzerSnse = 10;
	Vcb_InputSignalLatch->NebSnse2   = 11;

  //Vcb_InputSignalLatch->serialize(IRISbuffer):
  INode->StuffMessageInternal (Vcb_InputSignalLatch, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 
	t.TRACEY ("Send_35_Message - %d bytes\n", (int)nMsgSize);
  /*
	for (int j=0; j < nMsgSize; j++)
  {
   tmpchr=(unsigned char) IRISbuffer[j];
   t.TRACEY ("\n[%d] = ", j); 
	 t.TRACEY ("\\0x%X", tmpchr); 
	}
	t.TRACEY ("\n");
  */
	TxData(nCOM, (char*)IRISbuffer, nMsgSize);

	// delete [] IRISbuffer;
}

/********************************************************************

  Declaration: 
	Call:  Send_36_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  10.11.2006 Initial coding / YS  
  
*********************************************************************/
void Send_36_Message (int nSize, int nCOM)
{
  unsigned long nMsgSize = 0;
	const int nArrSz = 100;
	unsigned char  IRISbuffer[nArrSz]; 	
	unsigned char serializedMsgBuf[nArrSz];
  VcbTest_PingCalibrationStatus *Vcb_PingCalibrationStatus = new VcbTest_PingCalibrationStatus();
  
	// Current running calibration 
  // IRIS_BYTE CalStatus[40];
  
	strcpy( Vcb_PingCalibrationStatus->CalStatus, "Calibration in progress...");
	  
  //Pass Fail running calibration 
  //IRIS_UBYTE PassFailStatus;
  Vcb_PingCalibrationStatus->PassFailStatus = 10;

  //Percentage complete of current running calibration 
  //IRIS_UINT16 CalPercent;
  Vcb_PingCalibrationStatus->CalPercent = nSize;

  INode->StuffMessageInternal (Vcb_PingCalibrationStatus, IRISbuffer, &nMsgSize, serializedMsgBuf);

  t.TRACEY ("Send_36_Message - %d bytes\n", (int)nMsgSize);

  TxData(nCOM, (char*)IRISbuffer, nMsgSize);

 	//delete [] IRISbuffer;
}

/********************************************************************

  Declaration: 
	Call:  Send_37_Message (nSize, nCOM) - 56
  Input: size of message (int) and number of com-mport
  Returns: none
  23.11.2006 Initial coding / YS  
  
*********************************************************************/
void Send_37_Message (int nSize, int nCOM)
{
  unsigned long nMsgSize = 0;
	const int nArrSz = 50;
	unsigned char IRISbuffer[nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
  VcbTest_OtherVcbData *Vcb_OtherVcbData = new VcbTest_OtherVcbData();
  
	//********************INIT SIMUL MESSAGE**********
	Vcb_OtherVcbData->CpuLoadAvg = 3+nSize;
  Vcb_OtherVcbData->O2Comp     = 1+nSize;
	Vcb_OtherVcbData->WaveformJitter = 3+nSize;
	Vcb_OtherVcbData->MaxVentParamJitter = 3+nSize;
	Vcb_OtherVcbData->AvgVentParamJitter = 7+nSize;
	Vcb_OtherVcbData->AvgSysStateJitter = 3+nSize;
	Vcb_OtherVcbData->MaxSysStateJitter = 4+nSize;
	Vcb_OtherVcbData->VCBParameterAlarmStatus = 3;
	Vcb_OtherVcbData->VCBTechnicalAlarmStatus1 = 10+nSize;
	Vcb_OtherVcbData->VCBTechnicalAlarmStatus2 = 5+nSize;
	Vcb_OtherVcbData->VmbVcbCommErrors = 0;
	
	//************************************************
  
  INode->StuffMessageInternal (Vcb_OtherVcbData, IRISbuffer, &nMsgSize, serializedMsgBuf);

  t.TRACEY ("Send_37_Message - %d bytes\n", (int)nMsgSize);
  // t.TRACEY _HEX((char*)IRISbuffer, nMsgSize);
  TxData(nCOM, (char*)IRISbuffer, nMsgSize);
}

/********************************************************************

  Declaration: 
	Call:  Send_38_Message (nSize, nCOM) - 56
  Input: size of message (int) and number of com-mport
  Returns: none
  23.11.2006 Initial coding / YS  
  
*********************************************************************/
void Send_38_Message (int nSize, int nCOM)
{
  unsigned long nMsgSize = 0;
	const int nArrSz = 50;
	unsigned char IRISbuffer[nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
  VcbTest_SystemState *Vcb_SystemState = new VcbTest_SystemState();
  
	//********************INIT SIMUL MESSAGE**********
	Vcb_SystemState->SystemState = nSize;
	//************************************************
  
  INode->StuffMessageInternal (Vcb_SystemState, IRISbuffer, &nMsgSize, serializedMsgBuf);

  t.TRACEY ("Send_38_Message - %d bytes\n", (int)nMsgSize);
  //t.TRACEY _HEX((char*)IRISbuffer, nMsgSize);
  TxData(nCOM, (char*)IRISbuffer, nMsgSize);
}



/********************************************************************

  Declaration: 
	Call:  Send_56_Message (nSize, nCOM) - 56
  Input: size of message (int) and number of com-mport
  Returns: none
  23.11.2006 Initial coding / YS  
  
*********************************************************************/
void Send_55_Message (int nSize, int nCOM)
{
  unsigned long nMsgSize = 0;
	const int nArrSz = 50;
	unsigned char IRISbuffer[nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
  VcbTest_VmbSystemState *Vcb_VmbSystemState = new VcbTest_VmbSystemState();
  
	//********************INIT SIMUL MESSAGE**********
	Vcb_VmbSystemState->VmbSystemState = nSize;
	//************************************************
  
  INode->StuffMessageInternal (Vcb_VmbSystemState, IRISbuffer, &nMsgSize, serializedMsgBuf);

  t.TRACEY ("Send_55_Message - %d bytes\n", (int)nMsgSize);
  //t.TRACEY _HEX((char*)IRISbuffer, nMsgSize);
  TxData(nCOM, (char*)IRISbuffer, nMsgSize);
}


/********************************************************************

  Declaration: 
	Call:  Send_56_Message (nSize, nCOM) - 56
  Input: size of message (int) and number of com-mport
  Returns: none
  23.11.2006 Initial coding / YS  
  
*********************************************************************/
void Send_56_Message (int nSize, int nCOM)
{
  unsigned long nMsgSize = 0;
	const int nArrSz = 50;
	unsigned char IRISbuffer[nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
  VcbTest_SystemChecksData *Vcb_SystemChecksData = new VcbTest_SystemChecksData();
  
	//********************INIT SIMUL MESSAGE**********
	//IRIS_UINT16 FlashPasses;
	Vcb_SystemChecksData->FlashPasses=nSize; 
  //IRIS_UINT16 FlashFailures;
	Vcb_SystemChecksData->FlashFailures=13;  
  //IRIS_UINT16 SramPasses;
	Vcb_SystemChecksData->SramPasses =12; 
  //IRIS_UINT16 SramFailures;
	Vcb_SystemChecksData->SramFailures =13; 
  //IRIS_UINT16 EEPromPasses;
	Vcb_SystemChecksData->EEPromPasses =12; 
  //IRIS_UINT16 EEPromFailures;
	Vcb_SystemChecksData->EEPromFailures =13; 
  //IRIS_INT16 TimerRatio;
	Vcb_SystemChecksData->TimerRatio =50; 
	//************************************************
  
  INode->StuffMessageInternal (Vcb_SystemChecksData, IRISbuffer, &nMsgSize, serializedMsgBuf);

  t.TRACEY ("Send_56_Message - %d bytes\n", (int)nMsgSize);
  //t.TRACEY _HEX((char*)IRISbuffer, nMsgSize);
  TxData(nCOM, (char*)IRISbuffer, nMsgSize);
}

/********************************************************************

  Declaration: 
	Call:  Send_84_Message (nSize, nCOM) - 56
  Input: size of message (int) and number of com-mport
  Returns: none
  23.11.2006 Initial coding / YS  
  
*********************************************************************/
void Send_84_Message (int nSize, int nCOM)
{
  unsigned long nMsgSize = 0;
	const int nArrSz = 50;
	unsigned char IRISbuffer[nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
  VcbTest_EEPromTestProgress *Vcb_EEPromTestProgress = new VcbTest_EEPromTestProgress();
  
	//********************INIT SIMUL MESSAGE**********
	Vcb_EEPromTestProgress->Progress = 3+nSize;
	//************************************************
  
  INode->StuffMessageInternal (Vcb_EEPromTestProgress, IRISbuffer, &nMsgSize, serializedMsgBuf);

  t.TRACEY ("Send_84_Message - %d bytes\n", (int)nMsgSize);
  //t.TRACEY _HEX((char*)IRISbuffer, nMsgSize);
  TxData(nCOM, (char*)IRISbuffer, nMsgSize);
}

#if 0
/********************************************************************

  Declaration: 
	Call:  Send_0x_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  27.10.2006 Initial coding / YS  
  
	binary part:
	\0x20\0x0\0x0\0xD\0x8E\0x0\0x0\0x0\0x17\0x0\0x0\0xD\0xC1\0x0
  \0x0\0xB\0xF\0x0\0x0\0xB\0x4D\0x0\0x0\0xA\0xDD\0x35\0xAC\0x7E

*********************************************************************/
void Send_0x_Message (int nSize, int nCOM)
{
  unsigned char  *IRISbuffer;   
  const int nMsgSize = 28;
	unsigned char tmpchr;
	unsigned short calcCRC;
  unsigned char tmpBuf[2];

	t.TRACEY ("nSize: 0x%X", nSize);
  t.TRACEY (", %d\n", nSize);
  IRISbuffer = new unsigned char[nMsgSize];
  // Message ID:
	IRISbuffer[0] =0x20;

	// Flow ml/min - Total:
	IRISbuffer[1] =0x0;
	IRISbuffer[2] =0x0;	
	IRISbuffer[3] =0x0;
	IRISbuffer[4] =0x8E;
	// Flow ml/min - Oxygen:
	IRISbuffer[5] =0x0;
	IRISbuffer[6] =0x0;	
	IRISbuffer[7] =0x0;
	//*(IRISbuffer+8) = 6;
	IRISbuffer[8] = nSize;// 0x05;

// Flow ml/min - Air:	
	IRISbuffer[9] = 0x0;
	IRISbuffer[10] =0x0;
	IRISbuffer[11] =0x0;
	IRISbuffer[12] =0xC1;

//Temperature - Total:	
	IRISbuffer[13] =0x0;
	IRISbuffer[14] =0x0;	
	IRISbuffer[15] =nSize;
	IRISbuffer[16] =nSize; //0x0;

//Temperature - Oxygen:	
	IRISbuffer[17] =0x0;	
	IRISbuffer[18] =0x0;
	IRISbuffer[19] =0x0; // 0xB
	IRISbuffer[20] =0x4D;

//Temperature - air:		
	IRISbuffer[21] =0x0; 
	IRISbuffer[22] =0x0;
	IRISbuffer[23] =0x0;
	IRISbuffer[24] =0x4D;
	
	calcCRC = NetworkServices::calcCRC(IRISbuffer, nMsgSize-3);	
	t.TRACEY ("calculated CRC: 0x%X\n", calcCRC);
	memcpy ((void*)(tmpBuf),  (const void*)&calcCRC, sizeof(calcCRC) );

  IRISbuffer[25] =tmpBuf[1]; //0x35
	IRISbuffer[26] =tmpBuf[0]; //0xAC

	IRISbuffer[27] =0x7E;
 
 t.TRACEY ("Send_0x_Message- "); 
 for (int j=0; j < nMsgSize; j++)
  {
   tmpchr=(unsigned char) IRISbuffer[j];
   t.TRACEY ("\\0x%X", tmpchr); 
	}
	t.TRACEY ("\n"); 

  TxData(nCOM, (char*)IRISbuffer, nMsgSize);

	delete [] IRISbuffer;
}
#endif
/********************************************************************

  Declaration: 
	Call:  Send_SET_AIR_VALVE_EN_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  01.09.2004 Initial coding / YS  
 
*********************************************************************/
void Send_TEST_Message (int nSize, int nCOM)
{
  unsigned char  *IRISbuffer;   
  int nMsgSize = 12;
	unsigned char tmpchr;

  IRISbuffer = new unsigned char[15];

	IRISbuffer[0] =0x1E;
	IRISbuffer[1] =0x8F;
	IRISbuffer[2] =0x12;
	IRISbuffer[3] =0x36;
	IRISbuffer[4] =0x93;
	IRISbuffer[5] =0x10;
	IRISbuffer[6] =0x4;
	IRISbuffer[7] =0x41;
	IRISbuffer[8] =0xCC;
	IRISbuffer[9] =0xE;
	IRISbuffer[10]=0xF;
	IRISbuffer[11]=0x7E;
	//IRISbuffer[0]=0x
	//IRISbuffer[0]=0x
  
 t.TRACEY ("Send- "); 
 for (int j=0; j < nMsgSize; j++)
  {
   tmpchr=(unsigned char) IRISbuffer[j];
   t.TRACEY ("\\0x%X", tmpchr); 
	}
	t.TRACEY ("\n"); 

  TxData(nCOM, (char*)IRISbuffer, nMsgSize);

	delete [] IRISbuffer;
}

/********************************************************************

  Declaration: Send request message, based on GetRequestMessage class.
	Call:  SendRequestMessage (nSize, nCOM)
  Input: num of message (int) and number of com-mport
  Returns: none
  01.09.2004 Initial coding / YS  
 
*********************************************************************/
void SendRequestMessage (int nNum, int nCOM)
{
  
	unsigned long nMsgSize = 0;
	const int nArrSz = 50;
	unsigned char IRISbuffer[nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
  GetRequestMessage *pGetRequestMessage = new GetRequestMessage();
  
	//********************INIT SIMUL MESSAGE**********
	pGetRequestMessage->requestedMessageID = nNum;
	//************************************************
  
  INode->StuffMessageInternal (pGetRequestMessage, IRISbuffer, &nMsgSize, serializedMsgBuf);

  t.TRACEY ("Send_Request_Message(%d)\n",nNum);
  t.TRACE_HEX((char*)IRISbuffer, nMsgSize);
  TxData(nCOM, (char*)IRISbuffer, nMsgSize);
}
