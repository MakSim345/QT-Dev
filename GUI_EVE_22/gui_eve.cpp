

//============================================================
//
// Copyright © 2008 GENERAL ELECTRIC COMPANY
//
//============================================================
/// 
///
///============================================================
#include <QtGui>
#include <arb.h>
#include <icssw.h>
#include <trace.h>

#include "gui_eve.h"
#include "gen.h"
#include "utils.h"
#include <process.h>
#include <tchar.h>


//RegIf Reg;
CTRACE t(1,0);
//CRITICAL_SECTION critsect;
QString strRecMsgDlg;  

extern int PortNumber;
char ReceiveBuffer[500];
extern int NbrOfReadBytes;
extern long GenRecBytes;
extern  long GenSentBytes;  
extern int gReceivedMessageID[];
  
void thReadSerialPort(void *dummy );	
  

MainClass::MainClass(QWidget *parent,
                     Qt::WFlags flags,
                     ARB::SessionPrx s) :
    QDialog(parent, flags),
    _session(s),
    _proxy(0),
    _vent(0)
{
    // Check that session proxy is valid
    ASSERT(_session);
	
    m_GenComInput = "1";	
	m_ComInEdit = ("");
	m_DACValue = 0;
	m_Connected = 0;
	m_RunVentilation = 0;
	m_ExhalationFlag = 0;
	// EVECore = new EVEMainClass();
	
	m_thread = new NotifyThread(500);
	//m_thread2 = new NotifyThread(500);
	
	/*
	qDebug("NotifyTimer - start");
	QTimer timer;
	connect (&timer, SIGNAL(timeout()), this, SLOT(ObserverMsgLoop()));
	timer.start(100);
    */
 		
	ui.setupUi(this);
	
	OnInitDialog();
	
	connect(ui.IDE_Exit, SIGNAL(clicked()), this, SLOT(OnDestroy()));
	
	connect(ui.IDC_RunVentilation, SIGNAL(clicked()), this, SLOT(OnRunVentilation()));
	connect(ui.IDC_Connect, SIGNAL(clicked()), this, SLOT(OnConnect()));
	
	connect(ui.IDC_TimeONPlus, SIGNAL(clicked()), this, SLOT(OnTimeONPlus()));
	connect(ui.IDC_TimeONMinus, SIGNAL(clicked()), this, SLOT(OnTimeONMinus()));
	
	connect(ui.IDC_TimeOFFPlus, SIGNAL(clicked()), this, SLOT(OnTimeOFFPlus()));
	connect(ui.IDC_TimeOFFMinus, SIGNAL(clicked()), this, SLOT(OnTimeOFFMinus()));
	
	connect(ui.IDC_TotalFlowPlus, SIGNAL(clicked()), this, SLOT(OnTotalFlowPlus()));
	connect(ui.IDC_TotalFlowMinus, SIGNAL(clicked()), this, SLOT(OnTotalFlowMinus()));
	
	connect(ui.IDC_ExhFlowPlus, SIGNAL(clicked()), this, SLOT(OnExhFlowPlus()));
	connect(ui.IDC_ExhFlowMinus, SIGNAL(clicked()), this, SLOT(OnExhFlowMinus()));
	
	connect(ui.IDC_ExhFlowPlus2, SIGNAL(clicked()), this, SLOT(OnExhFlowPlus2()));
	connect(ui.IDC_ExhFlowMinus2, SIGNAL(clicked()), this, SLOT(OnExhFlowMinus2()));
	
	connect(ui.IDC_O2PercentPlus, SIGNAL(clicked()), this, SLOT(OnO2PercentPlus()));
	connect(ui.IDC_O2PercentMinus, SIGNAL(clicked()), this, SLOT(OnO2PercentMinus()));

    connect(ui.IDC_AIRVLV_CNTRL, SIGNAL(toggled(bool)), this, SLOT(OnAirvlvCntrl()));	
    
    // here ObserverMsgLoop() function linked to timer's related function timerClick():
    connect(m_thread, SIGNAL(timerClick()), this, SLOT(ObserverMsgLoop()) );
    //connect(m_thread2, SIGNAL(timerClick()), this, SLOT(CloseUI()) );
	
}

MainClass::~MainClass()
{
}


void MainClass::CloseUI()
{
    static int i=80;
    i++;
    ui.IDC_ComByteCounterSent->setText(QString::number(i));
}

bool MainClass::OnInitDialog()
{
    QString str;
	// TCHAR szSubkey[256];
	
	ui.IDC_Connect->setEnabled(true);	
	ui.IDC_RunVentilation->setEnabled(true);
	
	/*
      m_pComBoxPortNum->AddString("COM1");
      m_pComBoxPortNum->AddString("COM2");
      m_pComBoxPortNum->AddString("COM3");
      m_pComBoxPortNum->AddString("COM4");
      m_pComBoxPortNum->AddString("COM5");
      m_pComBoxPortNum->AddString("COM6");
      m_pComBoxPortNum->AddString("COM7");

      m_pComBoxPortSpeed->AddString("9600");
      m_pComBoxPortSpeed->AddString("19200");
      m_pComBoxPortSpeed->AddString("38400");
      m_pComBoxPortSpeed->AddString("57600");
      m_pComBoxPortSpeed->AddString("115200");
    */    
	
	// Read Registry and set Comm-port settingse from there:
	//lstrcpy (szSubkey, _T("Software\\LSS\\IRIS_GUI01\\COM Settings"));	
	
	//Reg.ReadIniDword(&nRegComPort, szSubkey, _T("ComPort") );
	//Reg.ReadIniDword(&nRegComSpeed, szSubkey, _T("ComSpeed") );	
		
	str.sprintf("Ver: %s. CT: %s %s", VERSION, __DATE__, __TIME__);
	
	SetVersionInfoTxt(str);
	
	// Disable some editBoxes:
    ui.IDC_ComByteCounterSent->setReadOnly(true);
	ui.IDC_ComByteCounter->setReadOnly(true);
	
	ui.IDC_TotalFlow->setReadOnly(true);
	ui.IDC_OxigFlow->setReadOnly(true);
	ui.IDC_AirFlow->setReadOnly(true);
	ui.IDC_TCTemp->setReadOnly(true);
	ui.IDC_OCTemp->setReadOnly(true);
	ui.IDC_ACTemp->setReadOnly(true);
	
	setBoxAirDAC(0);
	ui.IDC_AirDAC->setReadOnly(true);
		
	setBoxO2DAC(0);
	ui.IDC_O2DAC->setReadOnly(true);
	
	setBoxExhDAC(0);
	ui.IDC_ExhDAC->setReadOnly(true);
	
    setBoxDitherDAC(0);
	ui.IDC_DitherDAC->setReadOnly(true);
	
    setBoxTimeONVal(1);
	ui.IDC_TimeON->setReadOnly(true);
	
	setBoxTimeOFFVal(1);
	ui.IDC_TimeOff->setReadOnly(true);
	
	setBoxO2Percents(21);
	ui.IDC_O2Percents->setReadOnly(true);
	
	setBoxTotalFlowResult(15000);
	ui.IDC_TotalFlowResult->setReadOnly(true);
	
	setBoxExhFlow(15000);
	ui.IDC_ExhalFlow->setReadOnly(true);
	
	setBoxExhFlow2(1000);
	ui.IDC_ExhalFlow2->setReadOnly(true);
	
	setBoxCPULoad("--%");
	ui.IDC_CPULoad->setReadOnly(true);
	
	setBoxO2Comp("--%");
	ui.IDC_O2Comp->setReadOnly(true);
	
	// Those sets are private, so not necessary yet to incapsulate:		
	ui.IDC_O2PercentsSteps->setText(QString::number(1) );
	ui.IDC_TotalFlowSteps->setText(QString::number(1000) );
	ui.IDC_ExhFlowSteps->setText(QString::number(1000) );
	ui.IDC_ExhFlowSteps2->setText(QString::number(1000) );
	
	ui.IDC_RunVentilation->setText("&Start Vent.");
	
	m_thread->start();
	//m_thread2->start();
	// set timer and so on:	
	//SetTimer( 1, 100, NULL );
	//SetTimer( 2, 1000, NULL );
	
    // MainClass::threadA.setMessage("Message");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void MainClass::SetVersionInfoTxt(QString str)
{
    ui.IDC_InformBox->setText(str);
}

/********************************************************************

  Declaration: The termination.
  Call:  
  Input: 
  Returns: none
  30.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnDestroy() 
{	
	t.TRACEY("OnDestroy() function call.\n"); 
	
	// send event of death to EVECore:
	_vent->OnDestroy();
	Sleep (100);

    // Close connection to ventilator
    if(_vent)
    {
        _session->closeHandle(_vent);
    }
    // End session to Arbitrator
    _session->close();

	// terminate the GUI form:
	close();
}


/********************************************************************

  Declaration: The "Connect" button click handler. Sending an appr.
               event to EVE core.
  Call: OnConnect()
  Input: none 
  Returns: none
  18.01.2007 Initial coding YS

*********************************************************************/
void MainClass::OnConnect() 
{
    TRACE("Connecting to ventilator...");
    
    ARB::HandleErr herr;
    const string hostname = "DemoVent";

    // Ask Arbitrator to create handle to Ventilator
    _proxy = _session->createHandle(hostname, ARB::WRITE, herr);
    
    if (!_proxy)
    {
        switch(herr)
        {
        case ARB::ALREADYCONNECTED:
            //TBD if multiple connections are prohibited
        case ARB::HOSTOFFLINE:
            TRACE("Host "+hostname+" offline");
            break;
        case ARB::HOSTNAME:
            TRACE("Invalid host name: "+hostname);
            break;
        case ARB::ACCESS:
            TRACE("Access prohibited");
            break;
        default:
            ASSERT(0); // invalid error msg
            break;
        }
    }            
    else
    {
        // Try casting to ventilator type
        _vent = VENTC::VentComponentRWPrx::checkedCast(_proxy);
        if (!_vent)
        {
            TRACE("Returned proxy doesn't support DemoComponentPrx interface!");
        }
        else
        {
            // Ventilator is now accessible, clean temporary proxy
            TRACE("Connection estabilished!");
            _proxy = 0;
            _vent->OnConnect(); // force EVECore to make a connection to EVE HW.
        }
    }
}


/********************************************************************

  Declaration: Function ... 
  Call:  ObserverMsgLoop(*)
  Input: 
  Returns: none
  30.04.2008 Initial coding / YS  
  
*********************************************************************/
void MainClass::ObserverMsgLoop()
{
 // int nParam = 0;
 int nMsgId = 0;

/********TEST ONLY START*********/ 
 static int i=109230;
 i++;
 ui.IDC_ComByteCounter->setText(QString::number(i));
/********TEST ONLY END***********/ 

 while (!_vent->isEmpty())
 {  
   nMsgId = _vent->getMsgFromStore();
   
   if (nMsgId > 0)
   {
    switch(nMsgId)
    {
     case MSGID_SET_COM_PORT_SPEED:
       setBoxComPortSpeed(_vent->getComPortSpeed());
     break;
     
     case MSGID_SET_COM_PORT_NUMBER:
       setBoxComPortNumber(_vent->getComPortNumber());
     break;
     
     case MSGID_SET_REC_BYTES:
       setBoxRecBytes(_vent->getRecBytes());
     break;
     
     case MSGID_SET_SENT_BYTES:
       setBoxSentBytes(_vent->getSentBytes());
     break;
     
     case MSGID_SET_TIME_OFF_VAL:
     break;
     
     case MSGID_SET_TIME_ON_VAL:
     break;
     
     case MSGID_SET_EXHVLV_CNTRL:
     break;
     
     case MSGID_SET_AIRVLV_CNTRL:
     break;
     
     case MSGID_SET_MNVR_OPEN:
     break;
     
     case MSGID_SET_OK_TO_ZERO:
     break;
     
     case MSGID_SET_ILIM_MOD_EN:
     break;
     
     case MSGID_SET_ZERO_AUXP_EN:
     break;
     
     case MSGID_SET_ZEROINSP_EN:
     break;
     
     case MSGID_SET_VC_BUZZER_ON:
     break;
     
     case MSGID_SET_FS_PWR_EN:
     break;
     
     case MSGID_SET_O2DAC:
     break;
     
     case MSGID_SET_O2PERCENTS:
     break;
     
     case MSGID_SET_TOTAL_FLOW_RES:
     break;
     
     case MSGID_SET_TOTAL_FLOW:
     break;
     
     case MSGID_SET_AIRDAC:
     break;
     
     case MSGID_SET_EXHAL_FLOW:
     break;
     
     case MSGID_SET_EXHAL_FLOW2:
     break;
     
     case MSGID_SET_EXHDAC:
     break;
     
     case MSGID_SET_DITHER_DAC:
     break;
     
     case MSGID_SET_AIR_FLOW:
     break;
     
     case MSGID_SET_OXIG_FLOW:
     break;
        
     case MSGID_ENB_BTN_RUNVENT:
     break;
     
     case MSGID_ENB_BTN_CONNECT:
     break;
     
     default:
	 break;
   }  
  }
 }
 
}

/********************************************************************

  Declaration:
  Call: 
  Input: 
  Returns: 
  18.01.2008 Initial coding YS

*********************************************************************/
int MainClass::getBoxComPortNumber() 
{	
    return ui.IDC_COM_NUMBER->text().toInt();
}

/********************************************************************

  Declaration:
  Call: 
  Input: 
  Returns: 
  18.01.2008 Initial coding YS

*********************************************************************/
void MainClass::setBoxComPortSpeed(int nVal)
{
    ui.IDC_COM_SPEED->setText(QString::number(nVal));
}

/********************************************************************

  Declaration:
  Call: 
  Input: 
  Returns: 
  18.01.2008 Initial coding YS

*********************************************************************/
int MainClass::getBoxComPortSpeed()
{
   int CurSel = ui.IDC_COM_SPEED->text().toInt() ; 
 
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

/********************************************************************

  Declaration: the "run ventilation" button click handler. Sending an
               event to EVE core.
  Call:  OnRunVentilation() 
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnRunVentilation() 
{	
  // call this function from EVECore:
  
  TRACE("Run ventilation clicked");
  if(_vent)
  {
      _vent->OnRunVentilation();
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
void MainClass::OnAirvlvCntrl() 
{
	//_vent->Send_ONOFF_Message(80, ui.IDC_AIRVLV_CNTRL->isChecked(), 0);	
}

/********************************************************************

  Declaration: Function reacts to a click on the checkbox and sends an ON/OFF
               message according to the checkbox value. 
  Call:  OnO2vlvCntrl ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnO2vlvCntrl() 
{
    // _vent->Send_ONOFF_Message(81, ui.IDC_O2VLV_CNTRL->isChecked(), 0);
}

/********************************************************************

  Declaration: Function reacts to a click on the checkbox and sends an ON/OFF
               message according to the checkbox value. 
  Call:  OnExhvlvCntrl ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnExhvlvCntrl() 
{
	// _vent->Send_ONOFF_Message(82, ui.IDC_EXHVLV_CNTRL->isChecked(), 0);
}

/********************************************************************

  Declaration: Function reacts to a click on the checkbox and sends an ON/OFF
               message according to the checkbox value. 
  Call:  OnSafeCls ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnSafeCls() 
{
    // _vent->Send_ONOFF_Message(67, ui.IDC_SAFE_CLS->isChecked(), 0);	
}


/********************************************************************

  Declaration: Function for calculation safe borders in gui settings.
  Call:  CheckVal (double)
  Input: double - tested value
  Returns: integer - 0 error, 1 - ok.
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
int MainClass::CheckVal(double nVal)
{
 if ((nVal) > 25.00)
	 return 0;
 if ((nVal) < 1.00)
	 return 0;
 return 1;
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnTimeONPlus() 
{	
	double nVal = 0;	
	QString str;
	  
	str = ui.IDC_TimeON->text();
	nVal = str.toDouble();
	nVal = nVal + 0.5;
	
	if (1 == CheckVal(nVal))
	{
	 str.sprintf("%0.2f", nVal);
	 ui.IDC_TimeON->setText(str);
	}
	
	// Send message to EVE:
	_vent->setTimeONVal(1,0);
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnTimeONMinus() 
{
    double nVal = 0;	
	QString str;
  
	str = ui.IDC_TimeON->text();
    nVal = str.toDouble();
	nVal = nVal - 0.5;

	if (1 == CheckVal(nVal))
	{
	 str.sprintf("%0.2f", nVal);
	 ui.IDC_TimeON->setText(str);
	}
	
	// Send message to EVE:
	_vent->setTimeONVal(1, 0);
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnTimeOFFPlus() 
{
	double nVal = 0;	
	QString str;
  
	str = ui.IDC_TimeOff->text();
    nVal = str.toDouble();		
	nVal = nVal + 0.5;
	
	if (1 == CheckVal(nVal))
	{
	 str.sprintf("%0.2f", nVal);
	 ui.IDC_TimeOff->setText(str);
	}	
	
	// Send message to EVE:
	_vent->setTimeOFFVal(1, 0);
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnTimeOFFMinus() 
{
	double nVal = 0;	
	QString str;
  
	str = ui.IDC_TimeOff->text();
    nVal = str.toDouble();
	nVal = nVal-0.5;
	
	if (1 == CheckVal(nVal))
	{
	 str.sprintf("%0.2f", nVal);
	 ui.IDC_TimeOff->setText(str);
	}
	
	// Send message to EVE:
	_vent->setTimeOFFVal(1, 0);
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnTotalFlowPlus() 
{
	int nVal = 0;	
	//QString str;
  
	nVal = ui.IDC_TotalFlowResult->text().toInt();	
	nVal = nVal + ui.IDC_TotalFlowSteps->text().toInt();
		
	if (nVal < 50000)
	{
	 ui.IDC_TotalFlowResult->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	_vent->setTotalFlow(1, 0);
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnTotalFlowMinus() 
{
 	int nVal = 0;	
  
	nVal = ui.IDC_TotalFlowResult->text().toInt();	
	nVal = nVal - ui.IDC_TotalFlowSteps->text().toInt();
		
	if (nVal >= 0)
	{
		ui.IDC_TotalFlowResult->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	_vent->setTotalFlow(1, 0);
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnExhFlowPlus() 
{
	int nVal = 0;	
  
	nVal = ui.IDC_ExhalFlow->text().toInt();
	nVal = nVal + ui.IDC_ExhFlowSteps->text().toInt();
		
	if (nVal < 50000)
	{
		ui.IDC_ExhalFlow->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	// _vent->setTotalFlow(1);
	
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnExhFlowMinus() 
{
	int nVal = 0;	
  
	nVal = ui.IDC_ExhalFlow->text().toInt();
	nVal = nVal - ui.IDC_ExhFlowSteps->text().toInt();
		
	if (nVal >= 0)
	{
		ui.IDC_ExhalFlow->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	_vent->setExhalFlow(nVal, 0);
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnO2PercentPlus() 
{
	int nVal = 0;	
  
	nVal = ui.IDC_O2Percents->text().toInt();
	nVal = nVal + ui.IDC_O2PercentsSteps->text().toInt();
		
	if (nVal <= 100)
	{
		ui.IDC_O2Percents->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	_vent->setO2Percents(nVal, 0);
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnO2PercentMinus() 
{
	int nVal = 0;	
    const int nMinValue = 20; 
	nVal = ui.IDC_O2Percents->text().toInt();
	nVal = nVal - ui.IDC_O2PercentsSteps->text().toInt();
		
	if (nVal >= nMinValue)
	{
		ui.IDC_O2Percents->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	// _vent->set(nVal, 0);	
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnExhFlowPlus2() 
{
    int nVal = 0;	
  
	nVal = ui.IDC_ExhalFlow2->text().toInt();
	nVal = nVal + ui.IDC_ExhFlowSteps2->text().toInt();
		
	if (nVal < 50000)
	{
	 ui.IDC_ExhalFlow2->setText(QString::number(nVal) );
	}
	
}

/********************************************************************

  Declaration: Function reacts to button click and set value to an
               appropriate textbox in gui.
  Call:  OnTimeONPlus ()
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void MainClass::OnExhFlowMinus2() 
{
	int nVal = 0;	
  
	nVal = ui.IDC_ExhalFlow2->text().toInt();
	nVal = nVal - ui.IDC_ExhFlowSteps2->text().toInt();
		
	if (nVal >= 0)
	{
		ui.IDC_ExhalFlow2->setText(QString::number(nVal) );
	}
	
}

void MainClass::setBoxComPortNumber(int nVal)
{
    ui.IDC_COM_NUMBER->setText(QString::number(nVal));
}

int MainClass::getBoxRecBytes()
{
    return ui.IDC_ComByteCounter->text().toInt();
}

void MainClass::setBoxRecBytes(int nVal)
{
    ui.IDC_ComByteCounter->setText(QString::number(nVal));
}

int MainClass::getBoxSentBytes()
{
    return ui.IDC_ComByteCounterSent->text().toInt();
}

void MainClass::setBoxSentBytes(int nVal)
{
    ui.IDC_ComByteCounterSent->setText(QString::number(nVal));
}

int MainClass::getBoxTimeONVal()
{
    return ui.IDC_TimeON->text().toInt();
}

void MainClass::setBoxTimeONVal(int nVal)
{
    ui.IDC_TimeON->setText(QString::number(nVal) );
}

int MainClass::getBoxTimeOFFVal()
{
    return ui.IDC_TimeOff->text().toInt();
}

void MainClass::setBoxTimeOFFVal(int nVal)
{
    ui.IDC_TimeOff->setText(QString::number(nVal) );
}


//*******************CHECK BOXES****************

int MainClass::getChkBxSAFE_CLS()
{
    return ui.IDC_SAFE_CLS->isChecked();
}

void MainClass::setChkBxSAFE_CLS(int nVal)
{
    ui.IDC_SAFE_CLS->setCheckState( Qt::CheckState(nVal) );
}

int MainClass::getChkBxEXHVLV_CNTRL()
{
    return ui.IDC_EXHVLV_CNTRL->isChecked();
}
void MainClass::setChkBxEXHVLV_CNTRL(int nVal)
{
    ui.IDC_EXHVLV_CNTRL->setCheckState( Qt::CheckState(nVal) );
}

int MainClass::getChkBxO2VLV_CNTRL()
{
    return ui.IDC_O2VLV_CNTRL->isChecked();
}
void MainClass::setChkBxO2VLV_CNTRL(int nVal)
{
    ui.IDC_O2VLV_CNTRL->setCheckState( Qt::CheckState(nVal) );
}

int MainClass::getChkBxAIRVLV_CNTRL()
{
    return ui.IDC_AIRVLV_CNTRL->isChecked();
}

void MainClass::setChkBxAIRVLV_CNTRL(int nVal)
{
    ui.IDC_AIRVLV_CNTRL->setCheckState( Qt::CheckState(nVal) );
}
 
int MainClass::getChkBxMNVR_OPEN()
{
    return ui.IDC_MNVR_OPEN->isChecked();
}

void MainClass::setChkBxMNVR_OPEN(int nVal)
{
    ui.IDC_MNVR_OPEN->setCheckState( Qt::CheckState(nVal) );
}

int MainClass::getChkBxOK_TO_ZERO()
{
    return ui.IDC_OK_TO_ZERO->isChecked();
}

void MainClass::setChkBxOK_TO_ZERO(int nVal)
{
    ui.IDC_OK_TO_ZERO->setCheckState( Qt::CheckState(nVal) );
}

int MainClass::getChkBxILIM_MOD_EN()
{
    return ui.IDC_ILIM_MOD_EN->isChecked();
}

void MainClass::setChkBxILIM_MOD_EN(int nVal)
{
    ui.IDC_ILIM_MOD_EN->setCheckState( Qt::CheckState(nVal) );
}

int MainClass::getChkBxZERO_AUXP_EN()
{
    return ui.IDC_ZEROAUXP_EN->isChecked();
}

void MainClass::setChkBxZERO_AUXP_EN(int nVal)
{
    ui.IDC_ZEROAUXP_EN->setCheckState( Qt::CheckState(nVal) );
}	

int MainClass::getChkBxZEROINSP_EN()
{
    return ui.IDC_ZEROINSP_EN->isChecked();
}

void MainClass::setChkBxZEROINSP_EN(int nVal)
{
    ui.IDC_ZEROINSP_EN->setCheckState( Qt::CheckState(nVal) );
}	

int MainClass::getChkBxVC_BUZZER_ON()
{
    return ui.IDC_VC_BUZZER_ON->isChecked(); 
}

void MainClass::setChkBxVC_BUZZER_ON(int nVal)
{
    ui.IDC_VC_BUZZER_ON->setCheckState( Qt::CheckState(nVal) );
}

int MainClass::getChkBxILIM_PSM_EN()
{
    return ui.IDC_ILIM_PSM_EN->isChecked();
}

void MainClass::setChkBxILIM_PSM_EN(int nVal)
{
    ui.IDC_ILIM_PSM_EN->setCheckState( Qt::CheckState(nVal) );
}


int MainClass::getChkBxFS_PWR_EN()
{
    return ui.IDC_FS_PWR_EN->isChecked();
}

void MainClass::setChkBxFS_PWR_EN(int nVal)
{
    ui.IDC_FS_PWR_EN->setCheckState( Qt::CheckState(nVal) );
}


// *************************
int MainClass::getBoxO2DAC()
{
 return ui.IDC_O2DAC->text().toInt();
}

void MainClass::setBoxO2DAC(int nVal)
{
  ui.IDC_O2DAC->setText(QString::number(nVal) );
}

void MainClass::setBoxO2Percents(int nVal)
{
    ui.IDC_O2Percents->setText(QString::number(nVal) );
}

int MainClass::getBoxO2Percents()
{
    return ui.IDC_O2Percents->text().toInt();
}

void MainClass::setBoxTotalFlowResult(int nVal)
{
    ui.IDC_TotalFlowResult->setText(QString::number(nVal) );
}

int MainClass::getBoxTotalFlowResult()
{
    return ui.IDC_TotalFlowResult->text().toInt();
}

void MainClass::setBoxTotalFlow(int nVal)
{
    ui.IDC_TotalFlow->setText(QString::number(nVal) );
}

int MainClass::getBoxTotalFlow()
{
    return ui.IDC_TotalFlow->text().toInt();
}


void MainClass::setBoxAirDAC(int nVal)
{
    ui.IDC_AirDAC->setText(QString::number(nVal));
}

int MainClass::getBoxAirDAC()
{
    return ui.IDC_AirDAC->text().toInt();
}

void MainClass::setBoxExhFlow(int nVal)
{
    ui.IDC_ExhalFlow->setText(QString::number(nVal) );
}

int MainClass::getBoxExhFlow()
{
    return ui.IDC_ExhalFlow->text().toInt();
}

void MainClass::setBoxExhFlow2(int nVal)
{
    ui.IDC_ExhalFlow2->setText(QString::number(nVal) );
}

int MainClass::getBoxExhFlow2()
{
    return ui.IDC_ExhalFlow2->text().toInt();
}

void MainClass::setBoxExhDAC(int nVal)
{
    ui.IDC_ExhDAC->setText(QString::number(nVal));
}

int MainClass::getBoxExhDAC()
{
    return ui.IDC_ExhDAC->text().toInt();
}	

void MainClass::setBoxDitherDAC(int nVal)
{
    ui.IDC_DitherDAC->setText(QString::number(nVal) );
}

int MainClass::getBoxDitherDAC()
{
    return ui.IDC_DitherDAC->text().toInt();
}


void MainClass::setBoxAirFlow(int nVal)
{
    ui.IDC_AirFlow->setText(QString::number(nVal) );
}

int MainClass::getBoxAirFlow()
{
    return ui.IDC_AirFlow->text().toInt();
}

void MainClass::setBoxOxigFlow(int nVal)
{
    ui.IDC_OxigFlow->setText(QString::number(nVal) );
}

int MainClass::getBoxOxigFlow()
{
    return ui.IDC_OxigFlow->text().toInt();
}


// ***********char values:***********
void MainClass::setBoxOCTemp(string sVal)
{
    ui.IDC_OCTemp->setText(QString::fromStdString(sVal));
}

int  MainClass::getBoxOCTemp(string * sVal)
{   
    return 1;
}

void MainClass::setBoxTCTemp(string sVal)
{
    ui.IDC_TCTemp->setText(QString::fromStdString(sVal));
}

int MainClass::getBoxTCTemp(string * sVal)
{
    return 1;
}
		
void MainClass::setBoxACTemp(string sVal)
{
    ui.IDC_ACTemp->setText(QString::fromStdString(sVal));
}

int MainClass::getBoxACTemp(string * sVal)
{
    return 1;
}

void MainClass::setBoxO2Comp(string sVal)
{
     ui.IDC_O2Comp->setText(QString::fromStdString(sVal));
}

int MainClass::getBoxO2Comp(string * sVal)
{
    return 1;
}

void MainClass::setBoxCPULoad(string sVal)
{
    ui.IDC_CPULoad->setText(QString::fromStdString(sVal));
}

int MainClass::getBoxCPULoad(string * sVal)
{
 return 1;
}		

//***************************

void MainClass::enableBtnRunVent(int nVal)
{
 nVal = 1;
}

void MainClass::enableBtnConnect(int nVal)
{
 nVal = 1;
}

void MainClass::showMessageBox(std::string sVal)
{
 
}
