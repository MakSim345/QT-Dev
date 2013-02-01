#include "eve_main.h"

#include "gen.h"
#include "utils.h"
#include "comminc.h"
#include "commport.h"
#include <process.h>

#include <tchar.h>

#include "NetworkServices.h"
#include "iris_if.h"
#include "MessageSimul.h"
#include "Message.h"
#include "RegIf.h"
#include "GetRequestMessage.h"
#include "VcbTestMessageHeaders.h"
#include "DoIrisSerialPort.h"

typedef struct
{
  //IRIS_UBYTE ID;
  IRIS_UINT16 DAC_Value;
  //IRIS_UINT16 crc;
  //IRIS_UINT16 nIRIS_PACKET_END_FLAG;

} Test_STRUCT;

  RegIf Reg;
  CTRACE t(1,0);
  IRIS_Node *INode;
  DOIrisSerialPort *PortObject;
  CommPort *CPort[NBR_OF_PORTS];  
  CRITICAL_SECTION critsect;  
  
  uVcbSensorInfo VcbSensorInfoStruct;
  uVcbOtherVcbData VcbOtherVcbDataStruct;
  
  int PortNumber = 1;
  int DispSync=0;
  int MainNewChar=0;
  //char ReceiveBuffer[500];
  int NbrOfReadBytes=0;
  long GenRecBytes = 0;
  long GenSentBytes = 0;  
  int gReceivedMessageID[255];

  unsigned int DOIrisReadThread(IRIS_Node *pINode, char *buffer, unsigned long length);
  // void thReadSerialPort(void *dummy );	
  void thRunTimer(void *pParam);
  

EVEMainClass::EVEMainClass()
{
	
    // m_GenComInput = "1";	
	//m_ComInEdit = ("");
	//m_DACValue = 0;
	m_Connected = 0;
	//m_RunVentilation = 0;
	//m_ExhalationFlag = 0;
	//m_repeat = TRUE;	
	
	OnInitDialog();	
}

EVEMainClass::~EVEMainClass()
{

}


bool EVEMainClass::OnInitDialog()
{

    //QString str;
	int nRegComPort=10;
	int nRegComSpeed=4;
	TCHAR szSubkey[256];
	
	INode = new IRIS_Node(); // this object using only for pINode->receivePacket()	
    PortObject = new DOIrisSerialPort();
	
	// GET size of a message here:		(For TEST only)
	/*
	Test_STRUCT tmpqq;
	t.TRACEY("sizeof (VcbTest_SendAirvlvDac) = %d\n", (int)sizeof(tmpqq));
	*/
		
	// InitSerialPorts(g_sComPort);	
	
	// Read Registry and set Comm-port settingse from there:
	lstrcpy (szSubkey, _T("Software\\LSS\\IRIS_GUI01\\COM Settings"));	
	
	Reg.ReadIniDword(&nRegComPort, szSubkey, _T("ComPort") );
	Reg.ReadIniDword(&nRegComSpeed, szSubkey, _T("ComSpeed") );	
			
	
	//m_pComBoxPortNum->SetCurSel(6);
	//m_pComBoxPortSpeed->SetCurSel(4);

	// ui.IDC_COM_NUMBER->setText(QString::number(nRegComPort));
	// ui.IDC_COM_SPEED->setText(QString::number(nRegComSpeed));
	
	//g_sComPort      = getComPortNumber();
	//g_nComPortSpeed = getComPortSpeed();   
  
	// set timer and so on:	
	//SetTimer(0, 1, 100, NULL );
	//SetTimer( this, 2, 1000, NULL );
	
	_beginthread(thRunTimer, 0, this);
	
	InitializeCriticalSection(&critsect);		
 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

/********************************************************************

  Declaration: Function incapsulates 3 valves open/close features 
	           and their check-boxes settings
  Call:  
  Input: 
  Returns: none
  30.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::GasVLvControls(int nOnValue)
{ 	
	int nMsgShift = 0;
	unsigned long nMsgSize = 28;
	const int nArrSz = 50;
	unsigned char IRISbuffer [nArrSz];
	unsigned char serializedMsgBuf[nArrSz];  		
	unsigned char tmpchr;
/*
	VcbTest_SetAirValveEn *Vcb_SetAirValveEn= new	VcbTest_SetAirValveEn();
	VcbTest_SetO2ValveEn *Vcb_SetO2ValveEn= new 	VcbTest_SetO2ValveEn(); 
	VcbTest_SetExhValveEn *Vcb_SetExhValveEn= new 	VcbTest_SetExhValveEn();

	m_pCheckBoxAirVlv->SetCheck(nOnValue);
	m_pCheckBoxO2Vlv->SetCheck(nOnValue);
	//m_pCheckBoxExhVlv->SetCheck(nOnValue); 
	m_pCheckBoxExhVlv->SetCheck(1); 

//	Send_ONOFF_Message(80, nOnValue, g_sComPort);	
//	Send_ONOFF_Message(81, nOnValue, g_sComPort);		
//	Send_ONOFF_Message(82, nOnValue, g_sComPort);
	  
	 Vcb_SetExhValveEn->Setting = 1; // nOnValue;
	 
	 INode->StuffMessageInternal (Vcb_SetExhValveEn, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 nMsgShift = nMsgShift+nMsgSize;

	 Vcb_SetAirValveEn->Setting = nOnValue;
	 INode->StuffMessageInternal (Vcb_SetAirValveEn, IRISbuffer+nMsgShift, &nMsgSize, serializedMsgBuf);
	 nMsgShift = nMsgShift+nMsgSize;
   
	 Vcb_SetO2ValveEn->Setting = nOnValue;
	 INode->StuffMessageInternal (Vcb_SetO2ValveEn, IRISbuffer+nMsgShift, &nMsgSize, serializedMsgBuf);
	 nMsgShift = nMsgShift+nMsgSize;
	 
	 t.TRACEY ("Send_80-82_Message - set to %d\n", nOnValue);

   
	 for (int j=0; j < nMsgShift; j++)
 	 {
 	  tmpchr=(unsigned char) IRISbuffer[j];
 	  t.TRACEY("\\0x%X", tmpchr); 
 	 }		  
	 t.TRACEY ("\n");
	
	 TxData(g_sComPort, (char*)IRISbuffer, nMsgShift);

	 delete Vcb_SetAirValveEn;
	 delete Vcb_SetO2ValveEn;
	 delete Vcb_SetExhValveEn;	
*/
}

/********************************************************************

  Declaration: function handles the timer's interrupts.
  Call:  
  Input: 
  Returns: none
  10.11.2006 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::OnTimer(UINT nIDEvent) 
{
    static int i=0;
    
    // QString str;
	static long lTimerCounter = 1000;
	static long LastTimeInCtr = 0;	
	long ValuesInBars = 0;
	static int ConnectEstablishedCtr = 0;
	// static int nExhalationFlag = 0;
	static int nFirstTime = 1;

	if ((1 == m_Connected) && (1 == nIDEvent))
	{ 
	 t.TRACEY ("nIDEvent-1, time: %ld. \n",lTimerCounter);
	}
#ifdef THE_TIMER_OFF_01_APR_2008_YS
	
	 lTimerCounter = lTimerCounter+100;	    
	 //insert Receive bytes value to a box:
	 str.Format("%d", GenRecBytes);
	 ui.IDC_ComByteCounter, str);
	 //insert Sent bytes value to a box:   
	 str.Format("%d", GenSentBytes);
	 ui.IDC_ComByteCounterSent, str);

	 //t.TRACEY ("nIDEvent-1, time: %ld. \n",lTimerCounter);
	 if (1 == m_RunVentilation)
	 {		
	  //t.TRACEY ("nIDEvent-1, Get1msTimeMS(): %ld. \n", Get1msTimeMS());	
	  ValuesInBars = ui.IDC_TimeON, NULL, 1);
	  if ((( lTimerCounter - LastTimeInCtr)>(ValuesInBars*1000)-1) || (LastTimeInCtr > lTimerCounter ))
 	   {
 	    if (1 == m_ExhalationFlag)
 	    {
 		  // sending "open valve" messages to Air and O2:
		  GasVLvControls(1);
		  m_ExhalationFlag = 0;
		  t.TRACEY ("time: %ld. Open valve messages to Air and O2.\n", lTimerCounter);
		  LastTimeInCtr = lTimerCounter;
		 }			
 	   }
      
      ValuesInBars = ui.IDC_TimeOff, NULL, 1);
	  	  
	  if ((( lTimerCounter - LastTimeInCtr)>(ValuesInBars*1000)-1) || (LastTimeInCtr > lTimerCounter ))
 	   {
 	    if (0 == m_ExhalationFlag)
 	    {
 		 // sending "open valve" messages Exh:
		 GasVLvControls(0);
		 m_ExhalationFlag = 1;
		 t.TRACEY ("time: %ld. Open valve messages to Exh.\n", lTimerCounter);	 
		 LastTimeInCtr = lTimerCounter;
		 }			
 		}
	 }
	 	 
	 UpdateVCBInformation(1);
	 
	}
	else if (2 == nIDEvent)
	{
	 // once per second: read values from boxes and send appropriotary. 
	 UpdateData(TRUE);
	 if (1 == m_Connected)
	 {
	  if(0 == INode->GetLinkCheckResult() )
	  {
	    SendMessageRequestInternal (30, g_sComPort);
	    ConnectEstablishedCtr++;
	  }
	  else
	  {
	   if (1 == nFirstTime)
	    {
	     // Here: sending once on/off messages and set checkboxes:
		 //GasVLvControls(1);
		 m_pCheckBoxSafeCls->SetCheck(1);			
		 Send_ONOFF_Message(67, 1, g_sComPort);
		 m_pCheckBoxMNVROpen->SetCheck(0);
		 Send_ONOFF_Message(68, 0, g_sComPort);
		 m_pCheckBoxOKToZero->SetCheck(0);
		 Send_ONOFF_Message(69, 0, g_sComPort);
		 Send_ONOFF_Message(70, 204, g_sComPort); // why 204? - copy from mini platinum sw.
		 Send_ONOFF_Message(72, 0, g_sComPort); // copy from mini platinum sw.
		 Send_ONOFF_Message(73	, 0, g_sComPort); // copy from mini platinum sw.
		 Send_ONOFF_Message(76, 204, g_sComPort); // why 204? - copy from mini platinum sw.
		 m_pCheckBoxFSPWREn->SetCheck(1);
		 Send_ONOFF_Message(71, 1, g_sComPort);
 
   		 m_pCheckBoxIlimModEn->SetCheck(0);
		 Send_ONOFF_Message(74, 0, g_sComPort);
		 m_pCheckBoxIlimPsmEn->SetCheck(0);
		 Send_ONOFF_Message(75, 0, g_sComPort);
		 m_pCheckBoxZeroAuxpEn->SetCheck(1);
		 Send_ONOFF_Message(77, 1, g_sComPort);
		 m_pCheckBoxZeroInspEn->SetCheck(1);
		 Send_ONOFF_Message(78, 1, g_sComPort);
		 m_pCheckBoxVcBuzzerOn->SetCheck(1);
		 Send_ONOFF_Message(79, 1, g_sComPort);

         // Enable RUN button for emulation an ventialtion:
         m_pRunVentButton->EnableWindow(TRUE);
		 nFirstTime = 0;
	   }
			 
	  SendMessageRequestInternal (32, g_sComPort); // temp, airflow
      SendMessageRequestInternal (37, g_sComPort); // CPU load and so on
	  
	  if (1 == m_RunVentilation)
	  {
	   CalculateO2Volume();
	   CalculateAirVolume();
	   Send_43_Message (g_sComPort);
	   Send_44_Message (g_sComPort);
	   Send_45_Message (g_sComPort);			  
	   Send_46_Message (g_sComPort);
	   }
	 }
   }
  }	 
#endif // THE_TIMER_OFF_01_APR_2008_YS
}


/********************************************************************

  Declaration: The termination. finalize the thread, kill the timer(s)
               and send "close" message to EVE valves. 
  Call:  
  Input: 
  Returns: none
  30.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::OnDestroy() 
{	
	t.TRACEY("OnDestroy() function call.\n"); 
	// TODO: Add your message handler code here	
	GasVLvControls(0);
	m_repeat = FALSE;
	delete INode;
	PortObject->ClosePort();
	delete PortObject;	
	Sleep (100);
	/*
	KillTimer(1);	
	*/
}

/********************************************************************

  Declaration: 
  Call:  Send_43_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::Send_43_Message(int nCOM)
{
    unsigned long nMsgSize = 28;
	const int nArrSz = 50;
	unsigned char IRISbuffer [nArrSz];
	unsigned char serializedMsgBuf[nArrSz]; 
	/*
    VcbTest_SendAirvlvDac *Vcb_SendAirvlvDac = new VcbTest_SendAirvlvDac();
	// ((VcbTest_SendAirvlvDac *)IRISmessagePool[43])->DAC_Value = ui.IDC_AirDAC, NULL, 1);
	Vcb_SendAirvlvDac->DAC_Value = ui.IDC_AirDAC, NULL, 1);
	// t.TRACEY ("Send_43_Message. AirvlvDac=%d\n", Vcb_SendAirvlvDac->DAC_Value);
	
	INode->StuffMessageInternal (Vcb_SendAirvlvDac, IRISbuffer, &nMsgSize, serializedMsgBuf);
    // t.TRACEY _HEX((char*)IRISbuffer, nMsgSize);
	
	TxData(nCOM, (char*)IRISbuffer, nMsgSize);
	delete Vcb_SendAirvlvDac;
	*/
}

/********************************************************************

  Declaration: 
  Call:  Send_44_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::Send_44_Message(int nCOM)
{
    unsigned long nMsgSize = 28;
	const int nArrSz = 50;
	unsigned char IRISbuffer [nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
  /*
	VcbTest_SendO2vlvDac *Vcb_SendO2vlvDac = new VcbTest_SendO2vlvDac();
  
	Vcb_SendO2vlvDac->DAC_Value = ui.IDC_O2DAC, NULL, 1);	

	INode->StuffMessageInternal (Vcb_SendO2vlvDac, IRISbuffer, &nMsgSize, serializedMsgBuf);
  
	// t.TRACEY ("Send_44_Message - %d bytes\n", (int)nMsgSize);	
	TxData(nCOM, (char*)IRISbuffer, nMsgSize);

	delete Vcb_SendO2vlvDac;
  */
}

/********************************************************************

  Declaration: 
  Call:  Send_45_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::Send_45_Message(int nCOM)
{
    unsigned long nMsgSize = 28;
	const int nArrSz = 50;
	unsigned char IRISbuffer [nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
	int nTmpVal = 0;
/*
	VcbTest_SendExhvlvDac *Vcb_SendExhvlvDac = new VcbTest_SendExhvlvDac();  

    if (1 == m_ExhalationFlag)
	{
	 nTmpVal = ui.IDC_ExhalFlow, NULL, 1);
	}
	else
	{
	 nTmpVal = ui.IDC_ExhalFlow2, NULL, 1);
	}
	
    str.Format("%d", nTmpVal);
	ui.IDC_ExhDAC, str);	

	Vcb_SendExhvlvDac->DAC_Value = nTmpVal;

	INode->StuffMessageInternal (Vcb_SendExhvlvDac, IRISbuffer, &nMsgSize, serializedMsgBuf);
    //t.TRACEY ("Send_45_Message - %d bytes\n", (int)nMsgSize);  	
	TxData(nCOM, (char*)IRISbuffer, nMsgSize);
	delete Vcb_SendExhvlvDac;
	*/
}

/********************************************************************

  Declaration:
  Call:  Send_46_Message (nSize, nCOM)
  Input: size of message (int) and number of com-mport
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::Send_46_Message(int nCOM)
{
    unsigned long nMsgSize = 28;
	const int nArrSz = 50;
	unsigned char IRISbuffer [nArrSz];
	unsigned char serializedMsgBuf[nArrSz];
  /*
	VcbTest_SendExhvlvDitherDac *Vcb_SendExhvlvDitherDac = new VcbTest_SendExhvlvDitherDac();
    
	Vcb_SendExhvlvDitherDac->DAC_Value = ui.IDC_DitherDAC, NULL, 1);	
	
	INode->StuffMessageInternal (Vcb_SendExhvlvDitherDac, IRISbuffer, &nMsgSize, serializedMsgBuf);
    //t.TRACEY ("Send_46_Message - %d bytes\n", (int)nMsgSize);  	
	TxData(nCOM, (char*)IRISbuffer, nMsgSize);
	delete Vcb_SendExhvlvDitherDac;
  */
}

/********************************************************************

  Declaration: This function is sending ON/OFF messages for 67-82 messages.
  Call:  Send_ONOFF_Message (int, int, int)
  Input: message id, ON/OFF setting and number of com-mport
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::Send_ONOFF_Message(int MsgID, int nSetting, int nCOM)
{
    unsigned long nMsgSize = 28;
	const int nArrSz = 50;
	unsigned char IRISbuffer [nArrSz];
	unsigned char serializedMsgBuf[nArrSz];  		
	int SendFlag = 1;
/*
	if (VCB_TEST_SET_SAFE_CLOSE_ID == MsgID)// 67      
	{
	 VcbTest_SetSafeClose *Vcb_SetSafeClose = new  VcbTest_SetSafeClose(); 	
	 Vcb_SetSafeClose->Setting = nSetting; 
	 INode->StuffMessageInternal (Vcb_SetSafeClose, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetSafeClose;
	}
	else if (VCB_TEST_SET_MNVR_OPEN_ID == MsgID)//68
	{
    VcbTest_SetMnvrOpen *Vcb_SetMnvrOpen = new VcbTest_SetMnvrOpen();	
	 Vcb_SetMnvrOpen->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetMnvrOpen, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetMnvrOpen;
	}
	else if (VCB_TEST_SET_OK_TO_ZERO_ID == MsgID) //69
	{
	 VcbTest_SetOkToZero *Vcb_SetOkToZero= new VcbTest_SetOkToZero();
	 Vcb_SetOkToZero->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetOkToZero, IRISbuffer, &nMsgSize, serializedMsgBuf);	
	 delete Vcb_SetOkToZero;
	}
	else if (VCB_TEST_SET_SW_LED_ID == MsgID) // 70
	{
    VcbTest_SetSwLed *Vcb_SetSwLed= new VcbTest_SetSwLed();
	 Vcb_SetSwLed->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetSwLed, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetSwLed;
	}
	else if (VCB_TEST_SET_FS_PWR_EN_ID == MsgID) // 71
	{
    VcbTest_SetFsPwrEn *Vcb_SetFsPwrEn = new VcbTest_SetFsPwrEn();
	 Vcb_SetFsPwrEn->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetFsPwrEn, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetFsPwrEn;
	}
	else if (VCB_TEST_SET_NEB_ON_ID == MsgID)// 72
	{
    VcbTest_SetNebOn *Vcb_SetNebOn = new VcbTest_SetNebOn();
	 Vcb_SetNebOn->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetNebOn, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetNebOn;
	}
	else if (VCB_TEST_SET_MBUS_RESET_ID == MsgID) // 73
	{
    VcbTest_SetMbusReset *Vcb_SetMbusReset= new VcbTest_SetMbusReset();
    Vcb_SetMbusReset->Setting = nSetting;
	INode->StuffMessageInternal (Vcb_SetMbusReset, IRISbuffer, &nMsgSize, serializedMsgBuf);
	delete Vcb_SetMbusReset;
	}
	else if (VCB_TEST_SET_ILIM_MOD_EN_ID == MsgID) // 74
	{
	 VcbTest_SetIlimModEn *Vcb_SetIlimModEn= new 	VcbTest_SetIlimModEn();
	 Vcb_SetIlimModEn->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetIlimModEn, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetIlimModEn;
	}
	else if (VCB_TEST_SET_ILIM_PSM_EN_ID == MsgID) // 75
	{
     VcbTest_SetIlimPsmEn *Vcb_SetIlimPsmEn= new 	VcbTest_SetIlimPsmEn();
	 Vcb_SetIlimPsmEn->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetIlimPsmEn, IRISbuffer, &nMsgSize, serializedMsgBuf);
   delete Vcb_SetIlimPsmEn;
	}
	else if (VCB_TEST_SET_WD_STRB_ID == MsgID) // 76
	{
     VcbTest_SetWdStrb *Vcb_SetWdStrb= new 	VcbTest_SetWdStrb();
	 Vcb_SetWdStrb->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetWdStrb, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetWdStrb;
	}
	else if (VCB_TEST_SET_EXP_ZERO_ID == MsgID) // 77
	{
	 VcbTest_SetExpZero *Vcb_SetExpZero= new 	VcbTest_SetExpZero();
	 Vcb_SetExpZero->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetExpZero, IRISbuffer, &nMsgSize, serializedMsgBuf);
   delete Vcb_SetExpZero;
	}
	else if (VCB_TEST_SET_AUX_ZERO_ID == MsgID) // 78
	{
	 VcbTest_SetAuxZero *Vcb_SetAuxZero= new 	VcbTest_SetAuxZero();
	 Vcb_SetAuxZero->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetAuxZero, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetAuxZero;
	}
	else if (VCB_TEST_SET_BUZZER_ID == MsgID) // 79
	{
	 VcbTest_SetBuzzer *Vcb_SetBuzzer= new 	VcbTest_SetBuzzer();
	 Vcb_SetBuzzer->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetBuzzer, IRISbuffer, &nMsgSize, serializedMsgBuf);
   delete Vcb_SetBuzzer;
	}
	else if (VCB_TEST_SET_AIR_VALVE_EN_ID == MsgID) // 80
	{
   VcbTest_SetAirValveEn *Vcb_SetAirValveEn= new 	VcbTest_SetAirValveEn();
	 Vcb_SetAirValveEn->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetAirValveEn, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetAirValveEn;
	}
	else if (VCB_TEST_SET_O2_VALVE_EN_ID == MsgID) // 81
	{
   VcbTest_SetO2ValveEn *Vcb_SetO2ValveEn= new 	VcbTest_SetO2ValveEn(); 
	 Vcb_SetO2ValveEn->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetO2ValveEn, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetO2ValveEn;
	}
	else if (VCB_TEST_SET_EXH_VALVE_EN_ID == MsgID) // 82
	{
	 VcbTest_SetExhValveEn *Vcb_SetExhValveEn= new 	VcbTest_SetExhValveEn();
	 Vcb_SetExhValveEn->Setting = nSetting;
	 INode->StuffMessageInternal (Vcb_SetExhValveEn, IRISbuffer, &nMsgSize, serializedMsgBuf);
	 delete Vcb_SetExhValveEn;
	}
	else
  {     	
    t.TRACEY ("%d Message - not supported in ON/OFF impl.\n", MsgID, (int)nMsgSize);
	SendFlag = 0;
  }
  */
    if (1 == SendFlag)
	{
	 t.TRACEY ("Send_%d_Message - set to %d\n", MsgID, nSetting);
	 TxData(nCOM, (char*)IRISbuffer, nMsgSize);	
	}
	
}

/********************************************************************

  Declaration: draw received information in appr. boxes.
  Call: UpdateVCBInformation(int)
  Input: int 
  Returns: int
  18.01.2007 Initial coding YS

*********************************************************************/
int EVEMainClass::UpdateVCBInformation(int nSet)
{
    
    int nMsgId = 0;
	
    const int nMsgsInPool = 255;
/*
	for (nMsgId=0; nMsgId<nMsgsInPool; nMsgId++)
	{
	 if (1 == gReceivedMessageID[nMsgId])
	 {
	  gReceivedMessageID[nMsgId]=0; // reset update;
	  switch(nMsgId)
	  {
       case VCB_TEST_SENSOR_INFO_ID:
       // 32
       str.Format("%d", VcbSensorInfoStruct.nTotalFlow);
	   ui.IDC_TotalFlow, str);	
					
	   str.Format("%d", VcbSensorInfoStruct.nAirFlow);
	   ui.IDC_AirFlow, str);	
					
	   str.Format("%d", VcbSensorInfoStruct.nOxygenFlow);
	   ui.IDC_OxigFlow, str);
					
	   str.Format("%.2f C", (float)VcbSensorInfoStruct.nOxygenCurrentTemp/100);
	   ui.IDC_OCTemp, str);							
					
	   str.Format("%.2f C", (float)VcbSensorInfoStruct.nTotalCurrentTemp/100);
	   ui.IDC_TCTemp, str);	
	 		
	   str.Format("%.2f C", (float)VcbSensorInfoStruct.nAirCurrentTemp/100);
	   ui.IDC_ACTemp, str);	
					
	   break;
	   case VCB_TEST_SENSOR_DETAILS_ID:
	   // 33
	   break;
	   case VCB_TEST_CHANNEL_CONFIGURATIONS_ID:
	   // 34
	   break;
	   case VCB_TEST_INPUT_SIGNAL_LATCH_ID:
	   // 35
	   break;
	   case VCB_TEST_PING_CALIBRATION_STATUS_ID:
	   // 36        
	   break;
	   case VCB_TEST_OTHER_VCB_DATA_ID:
	   // 37
	
	   str.Format("%.2f%%", (float)VcbOtherVcbDataStruct.CpuLoadAvg/10);
	   ui.IDC_CPULoad, str);	
         
	   str.Format("%.2f%%", (float)VcbOtherVcbDataStruct.O2Comp/10);
	   ui.IDC_O2Comp, str);	
					
	   break;
	   case VCB_TEST_SYSTEM_STATE_ID:
	   // 38
	   break;
       
       case VCB_TEST_SEND_AIRVLV_DAC_ID:
	   //43
	   //VcbTest_SendAirvlvDac.
	   break;
	   case VCB_TEST_VMB_SYSTEM_STATE_ID:
	   // 55
	   break;
	   case VCB_TEST_SYSTEM_CHECKS_DATA_ID:
	   // 56
	   break;
	   case VCB_TEST_E_E_PROM_TEST_PROGRESS_ID:
	   // 84
	   break;   

	   default:
	   // Message ID not supported!
	   break;
	  }
	 }
	}
*/
	return 0;
}

void EVEMainClass::OnConnect()
{
	char TxtBuf[50];
	TCHAR szSubkey[256];
	int nRegComPort=1;
	int nRegComSpeed=4;  
	
	if (0 == m_Connected)
	{
	 // if (1 == InitSerialPorts(g_sComPort, g_nComPortSpeed))
	 if( PortObject->OpenPort(g_sComPort, 2048, INode, g_nComPortSpeed, TRUE	) )
	  {	   
	   m_Connected = 1;
	   // m_pButton->SetWindowText("Disconnect");
	   //ui.IDC_Connect->setEnabled(false);
       //ui.IDC_COM_SPEED->setEnabled(false);
       //ui.IDC_COM_NUMBER->setEnabled(false);
	   m_repeat = TRUE;
//**************************Registry*******
	   // Write Comm-port settings to the Registry:
	   lstrcpy (szSubkey, _T("Software\\LSS\\IRIS_GUI01\\COM Settings"));	

	   nRegComPort = getComPortNumber();
	   nRegComSpeed= getComPortSpeed();
			
	   Reg.WriteIniDword(&nRegComPort, szSubkey, _T("ComPort") );
	   Reg.WriteIniDword(&nRegComSpeed, szSubkey, _T("ComSpeed") );			
//*****************************************
	   }
	  else
	   {
		// COM-PORT probably does not exist, try again!
		sprintf(TxtBuf, "COM-PORT %d probably does not exist, try again!", g_sComPort);
		// QMessageBox::warning(this, "Serial Port", TxtBuf);
		m_Connected = 0;
	   }
	}
	else
	{
	 m_repeat = FALSE;
	 //m_pButton->SetWindowText("Connect");
	 //t.TRACEY ("m_repeat = 0. Thread stop.\n"); 	
	 m_Connected = 0;
	 // release serial ports objects:
	 // RemoveSerialPortFromPoll();
	}

}

int EVEMainClass::getComPortNumber() 
{	
    return 1;// ui.IDC_COM_NUMBER->text().toInt();
}


void EVEMainClass::OnSelchangeComSpeed() 
{
	// TODO: Add your control notification handler code here
	getComPortSpeed();
}


int EVEMainClass::getComPortSpeed()
{
    int CurSel  = 4; //= ui.IDC_COM_SPEED->text().toInt() ; 
 
    switch(CurSel)
    {
     case 0:
	   return 9600;			 
	   break;
	 case 1:
	   return 19200;
	   break;
	 case 2:
       return 38400;
	   break;
	 case 3:
	   return 57600;
	   break;
	 case 4:
      return 115200;
      break;
     default:
      return 115200;
      break;
	 }  
}

void EVEMainClass::OnSendMsg() 
{
	// TODO: Add your control notification handler code here
	Send_43_Message(g_sComPort);
}

void EVEMainClass::OnSendMsgO2VLV() 
{
	// TODO: Add your control notification handler code here
	Send_44_Message(g_sComPort);
}

void EVEMainClass::OnSendMsgExhVLV() 
{
	// TODO: Add your control notification handler code here
	Send_45_Message(g_sComPort);
	
}

/********************************************************************

  Declaration: the "run ventilation" button click handler.
  Call:  OnRunVentilation() 
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::OnRunVentilation() 
{
	if (0 == m_RunVentilation)
	{
		//ui.IDC_RunVentilation->setText("Stop Vent.");
		m_RunVentilation = 1;	
	}
	else
  {
		GasVLvControls(0);
		//ui.IDC_RunVentilation->setText("Start Vent.");
		m_RunVentilation = 0;	
	}

}


/********************************************************************

  Declaration: Function reacts to a click on the checkbox and sends an ON/OFF
               message according to the checkbox value. 
  Call:  OnAirvlvCntrl ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::OnAirvlvCntrl() 
{
	// Send_ONOFF_Message(80, ui.IDC_AIRVLV_CNTRL->isChecked() , g_sComPort);	
	
	//t.TRACEY ("Send_80_Message - IDC_AIRVLV_CNTRL %d\n",m_pCheckBoxAirVlv->GetCheck());
 	/*
 	
	if (1 == m_pCheckBoxAirVlv->GetCheck())
	{
	 Send_ONOFF_Message(80, 1, g_sComPort);
	 t.TRACEY ("Send_80_Message - IDC_AIRVLV_CNTRL ON\n");
	}
	else
	{
 	 Send_ONOFF_Message(80, 0, g_sComPort);
	 t.TRACEY ("Send_80_Message - IDC_AIRVLV_CNTRL OFF\n");
	}
    */
}

/********************************************************************

  Declaration: Function reacts to a click on the checkbox and sends an ON/OFF
               message according to the checkbox value. 
  Call:  OnO2vlvCntrl ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::OnO2vlvCntrl() 
{

	//Send_ONOFF_Message(81, ui.IDC_O2VLV_CNTRL->isChecked(), g_sComPort);
	//t.TRACEY ("Send_81_Message - IDC_O2VLV_CNTRL %d\n",m_pCheckBoxO2Vlv->GetCheck());
}

/********************************************************************

  Declaration: Function reacts to a click on the checkbox and sends an ON/OFF
               message according to the checkbox value. 
  Call:  OnExhvlvCntrl ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::OnExhvlvCntrl() 
{
	//Send_ONOFF_Message(82, ui.IDC_EXHVLV_CNTRL->isChecked(), g_sComPort);
	//t.TRACEY ("Send_82_Message - IDC_EXHVLV_CNTRL %d\n",m_pCheckBoxExhVlv->GetCheck());	
}

/********************************************************************

  Declaration: Function reacts to a click on the checkbox and sends an ON/OFF
               message according to the checkbox value. 
  Call:  OnSafeCls ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void EVEMainClass::OnSafeCls() 
{
	//Send_ONOFF_Message(67, m_pCheckBoxSafeCls->GetCheck(), g_sComPort);
	//t.TRACEY ("Send_67_Message - IDC_EXHVLV_CNTRL %d\n",m_pCheckBoxSafeCls->GetCheck());		
}

int EVEMainClass::CheckVal(double nVal)
{
 if ((nVal) > 25.00)
	 return 0;
 if ((nVal) < 1.00)
	 return 0;
 return 1;
}


/********************************************************************
  Declaration: This would be a thread for timer simulation
  Call: 
  Input: 
  Returns:
  04.04.2008 Initial coding - YS.
*********************************************************************/
void thRunTimer(void *pParam)
 {  
 	
 	long LastTimeInMS = 0;
 	unsigned char tmpchr;
 	BOOL m_repeat = 1;
 	
 	// Here- take a pointer to a MainCLass object
 	EVEMainClass *nMainClass = (EVEMainClass*) pParam; 

 	t.TRACEY("ComSerialPort thread started.\n");  	
 	
	while (m_repeat)
	{ 
 	 if ((( Get1msTimeMS() - LastTimeInMS)>100-1) || (LastTimeInMS > Get1msTimeMS() ))
 	  {			 
 	   t.TRACEY ("Thread time: %ld. \n",Get1msTimeMS()); 	   
 	   nMainClass->OnTimer(1); // Emulation of a timer event for MainCLass object.
 	   LastTimeInMS = Get1msTimeMS();	
      }
    
	Sleep (100);
    EnterCriticalSection(&critsect);
 	//t.TRACEY ("3 ReadRxData after  time: %ld. \n",Get1msTimeMS());	
 	LeaveCriticalSection(&critsect);	
    }
 	t.TRACEY ("ComSerialPort thread stop.\n"); 
 	_endthread();
 	
 }

// #define THREAD_IN_USE
/********************************************************************
  Declaration: This would be a thread for serial port receiving info.
  Call: 
  Input: 
  Returns:
  23.10.2006 Initial codin - YS.
*********************************************************************/
void thReadSerialPort(void *pParam)
 {   

#ifdef THREAD_IN_USE
    int PortNumber = 1;
 	long LastTimeInMS = 0;
 	//long GenRecBytes = 0;
 	unsigned char tmpchr;
	ULONG lpEvtMask=0;		
	
    EVEMainClass *CTest = (CIRIS_GUI_01Dlg*)pParam;
  
	// Get a com-port number:
	PortNumber = CTest->g_sComPort; 	

 	t.TRACEY("ComSerialPort thread started.\n");  	
 	
	//SetCommMask(CPort[PortNumber]->GetComPortHandle(), EV_CTS|EV_DSR);

 	while (m_repeat)
  { 
 	 /*
		if ((( Get1msTimeMS() - LastTimeInMS)>100-1) || (LastTimeInMS > Get1msTimeMS() ))
 		 {			 
 			 //t.TRACEY ("Thread time: %ld. \n",Get1msTimeMS());
 			 LastTimeInMS = Get1msTimeMS();
			 //INode->SendMessageRequestInternal(32);
 		 }
     */
	Sleep (100);
    EnterCriticalSection(&critsect);
 	//**********************************
	//t.TRACEY ("1 WaitCommEvent before time: %ld. \n",Get1msTimeMS());		 
	//WaitCommEvent(CPort[PortNumber]->GetComPortHandle(), &lpEvtMask, NULL);
    //t.TRACEY ("2 ReadRxData before time: %ld. \n",Get1msTimeMS());		 
 	NbrOfReadBytes = ReadRxData(PortNumber, ReceiveBuffer);
	//t.TRACEY ("3 ReadRxData after  time: %ld. \n",Get1msTimeMS()); 		 
	if (NbrOfReadBytes)
 	{
 	 GenRecBytes = GenRecBytes+NbrOfReadBytes;			
	 //CPort[PortNumber]->SetRecBytes(NbrOfReadBytes);
	 // CTest->ui.); 
	 /*
 	 t.TRACEY ("NbrOfReadBytes: %d\n", NbrOfReadBytes);
	 for (int j=0; j < NbrOfReadBytes; j++)
	 {
 	  tmpchr=(unsigned char) ReceiveBuffer[j];
 	  t.TRACEY("\\0x%X", tmpchr); 
 	 }		  
	 t.TRACEY ("\n");
	 */
	 DOIrisReadThread(INode, ReceiveBuffer, NbrOfReadBytes);
	 // CTest->UpdateVCBInformation(1);
 	 }
 	//**********************************
 	LeaveCriticalSection(&critsect);
	//dlg.UpdateData (FALSE);
    }
 	
 	RemoveSerialPortFromPoll();	
	//INode->IrisNodeDestroy ();
#endif THREAD_IN_USE

 	t.TRACEY ("ComSerialPort thread stop.\n"); 
 	_endthread();
 	
 }
