 #include <QtGui>

 #include "gui_form.h"

 GUIForm::GUIForm(QWidget *parent)
     : QDialog(parent)
 {
    ui.setupUi(this);
    m_vent = 0;
    m_nShowVwntPrgs = 0;
    
    BelowsProgress = new BelowsPrg(ui.groupBox_4);
    BelowsProgress->move (10, 360); 
    BelowsProgress->resize (150, 60);
    // BelowsProgress->show();
    // addWidget(BelowsProgress);
    // QVBoxLayout *verticalLayout = new QVBoxLayout;
    //ui.groupBox_4->addWidget(BelowsProgress);
    // setLayout(layout);
     
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
    
    connect(ui.IDC_TestBtn, SIGNAL(clicked()), BelowsProgress, SLOT(slotSetProgress(int)));
    
    connect(ui.IDC_TestBtn, SIGNAL(clicked()), this, SLOT(slotSetProgress()));
    
 }


void GUIForm::slotSetProgress()
{
  m_nShowVwntPrgs = m_nShowVwntPrgs + 20;
  BelowsProgress->slotSetProgress(m_nShowVwntPrgs);
}

bool GUIForm::OnInitDialog()
{
    QString str;
	// TCHAR szSubkey[256];
	
	ui.IDC_Connect->setEnabled(true);	
	ui.IDC_RunVentilation->setEnabled(true);
	
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
	
	setBoxO2PercentsSteps(1);
	setBoxTotalFlowSteps (1000);	
	setBoxExhFlowSteps   (1000);
	setBoxExhFlowSteps2  (1000);
	
	//ui.IDC_TotalFlowSteps->setText(QString::number(1000) );
	//ui.IDC_ExhFlowSteps->setText(QString::number(1000) );
	//ui.IDC_ExhFlowSteps2->setText(QString::number(1000) );
	
	ui.IDC_RunVentilation->setText("&Start Vent.");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void GUIForm::SetVersionInfoTxt(QString str)
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
void GUIForm::OnDestroy() 
{	
	// t.TRACEY("OnDestroy() function call.\n"); 
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
void GUIForm::OnConnect() 
{
    // TRACE("Connecting to ventilator...");
}
   
/********************************************************************

  Declaration: the "run ventilation" button click handler. Sending an
               event to EVE core.
  Call:  OnRunVentilation() 
  Input: none
  Returns: none
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
void GUIForm::OnRunVentilation() 
{	
  // TRACE("Run ventilation clicked");
  if(m_vent)
  {
      // m_vent->OnRunVentilation();
  }
}

/********************************************************************

  Declaration: Function for calculation safe borders in gui settings.
  Call:  CheckVal (double)
  Input: double - tested value
  Returns: integer - 0 error, 1 - ok.
  24.03.2007 Initial coding / YS  
  
*********************************************************************/
int GUIForm::CheckVal(double nVal)
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
void GUIForm::OnTimeONPlus() 
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
  if(m_vent)
  {
    //m_vent->setTimeONVal(1,0);
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
void GUIForm::OnTimeONMinus() 
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
  if(m_vent)
  {    
   // m_vent->setTimeONVal(1, 0);
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
void GUIForm::OnTimeOFFPlus() 
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
    if(m_vent)
    {
      // m_vent->setTimeOFFVal(1, 0);
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
void GUIForm::OnTimeOFFMinus() 
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
    if(m_vent)
    {    
      // m_vent->setTimeOFFVal(1, 0);
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
void GUIForm::OnTotalFlowPlus() 
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
    if(m_vent)
    {    
      // m_vent->setTotalFlow(1, 0);
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
void GUIForm::OnTotalFlowMinus() 
{
 	int nVal = 0;	
  
	nVal = ui.IDC_TotalFlowResult->text().toInt();	
	nVal = nVal - ui.IDC_TotalFlowSteps->text().toInt();
		
	if (nVal >= 0)
	{
		ui.IDC_TotalFlowResult->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	if(m_vent)
    {    
      // m_vent->setTotalFlow(1, 0);
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
void GUIForm::OnExhFlowPlus() 
{
	int nVal = 0;	
  
	nVal = ui.IDC_ExhalFlow->text().toInt();
	nVal = nVal + ui.IDC_ExhFlowSteps->text().toInt();
		
	if (nVal < 50000)
	{
		ui.IDC_ExhalFlow->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	if(m_vent)
    {    
      // m_vent->setExhalFlow(nVal, 0);
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
void GUIForm::OnExhFlowMinus() 
{
	int nVal = 0;	
  
	nVal = ui.IDC_ExhalFlow->text().toInt();
	nVal = nVal - ui.IDC_ExhFlowSteps->text().toInt();
		
	if (nVal >= 0)
	{
		ui.IDC_ExhalFlow->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	if(m_vent)
    {    
      // m_vent->setExhalFlow(nVal, 0);
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
void GUIForm::OnO2PercentPlus() 
{
	int nVal = 0;	
  
	nVal = ui.IDC_O2Percents->text().toInt();
	nVal = nVal + ui.IDC_O2PercentsSteps->text().toInt();
		
	if (nVal <= 100)
	{
		ui.IDC_O2Percents->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	if(m_vent)
    {    
      // m_vent->setO2Percents(nVal, 0);
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
void GUIForm::OnO2PercentMinus() 
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
	if(m_vent)
    {    
      // m_vent->setO2Percents(nVal, 0);
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
void GUIForm::OnExhFlowPlus2() 
{
    int nVal = 0;	
  
	nVal = ui.IDC_ExhalFlow2->text().toInt();
	nVal = nVal + ui.IDC_ExhFlowSteps2->text().toInt();
		
	if (nVal < 50000)
	{
	 ui.IDC_ExhalFlow2->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	if(m_vent)
    {    
      //// m_vent->setO2Percents(nVal, 0);
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
void GUIForm::OnExhFlowMinus2() 
{
	int nVal = 0;	
  
	nVal = ui.IDC_ExhalFlow2->text().toInt();
	nVal = nVal - ui.IDC_ExhFlowSteps2->text().toInt();
		
	if (nVal >= 0)
	{
		ui.IDC_ExhalFlow2->setText(QString::number(nVal) );
	}
	
	// Send message to EVE:
	if(m_vent)
    {    
     // // m_vent->setO2Percents(nVal, 0);
    }
	
}

/********************************************************************

  Declaration:
  Call: 
  Input: 
  Returns: 
  18.01.2008 Initial coding YS

*********************************************************************/
int GUIForm::getBoxComPortNumber() 
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
void GUIForm::setBoxComPortSpeed(int nVal)
{
    ui.IDC_COM_SPEED->setText(QString::number(nVal));
}


void GUIForm::setBoxComPortNumber(int nVal)
{
    ui.IDC_COM_NUMBER->setText(QString::number(nVal));
}

int GUIForm::getBoxRecBytes()
{
    return ui.IDC_ComByteCounter->text().toInt();
}

void GUIForm::setBoxRecBytes(int nVal)
{
    ui.IDC_ComByteCounter->setText(QString::number(nVal));
}

int GUIForm::getBoxSentBytes()
{
    return ui.IDC_ComByteCounterSent->text().toInt();
}

void GUIForm::setBoxSentBytes(int nVal)
{
    ui.IDC_ComByteCounterSent->setText(QString::number(nVal));
}

int GUIForm::getBoxTimeONVal()
{
    return ui.IDC_TimeON->text().toInt();
}

void GUIForm::setBoxTimeONVal(int nVal)
{
    ui.IDC_TimeON->setText(QString::number(nVal) );
}

int GUIForm::getBoxTimeOFFVal()
{
    return ui.IDC_TimeOff->text().toInt();
}

void GUIForm::setBoxTimeOFFVal(int nVal)
{
    ui.IDC_TimeOff->setText(QString::number(nVal) );
}

int GUIForm::getBoxO2PercentsSteps()
{
    return ui.IDC_O2PercentsSteps->text().toInt();
}

void GUIForm::setBoxO2PercentsSteps(int nVal)
{
    ui.IDC_O2PercentsSteps->setText(QString::number(nVal) );
}

int GUIForm::getBoxTotalFlowSteps()
{
    return ui.IDC_TotalFlowSteps->text().toInt();
}

void GUIForm::setBoxTotalFlowSteps(int nVal)
{
    ui.IDC_TotalFlowSteps->setText(QString::number(nVal) );
}
	
int GUIForm::getBoxExhFlowSteps()
{
    return ui.IDC_ExhFlowSteps->text().toInt();
}

void GUIForm::setBoxExhFlowSteps(int nVal)
{
    ui.IDC_ExhFlowSteps->setText(QString::number(nVal) );
}
	
int GUIForm::getBoxExhFlowSteps2()
{
    return ui.IDC_ExhFlowSteps2->text().toInt();
}

void GUIForm::setBoxExhFlowSteps2(int nVal)
{
    ui.IDC_ExhFlowSteps2->setText(QString::number(nVal) );
}

int GUIForm::getBoxO2DAC()
{
 return ui.IDC_O2DAC->text().toInt();
}

void GUIForm::setBoxO2DAC(int nVal)
{
  ui.IDC_O2DAC->setText(QString::number(nVal) );
}

void GUIForm::setBoxO2Percents(int nVal)
{
    ui.IDC_O2Percents->setText(QString::number(nVal) );
}

int GUIForm::getBoxO2Percents()
{
    return ui.IDC_O2Percents->text().toInt();
}

void GUIForm::setBoxTotalFlowResult(int nVal)
{
    ui.IDC_TotalFlowResult->setText(QString::number(nVal) );
}

int GUIForm::getBoxTotalFlowResult()
{
    return ui.IDC_TotalFlowResult->text().toInt();
}

void GUIForm::setBoxTotalFlow(int nVal)
{
    ui.IDC_TotalFlow->setText(QString::number(nVal) );
}

int GUIForm::getBoxTotalFlow()
{
    return ui.IDC_TotalFlow->text().toInt();
}


void GUIForm::setBoxAirDAC(int nVal)
{
    ui.IDC_AirDAC->setText(QString::number(nVal));
}

int GUIForm::getBoxAirDAC()
{
    return ui.IDC_AirDAC->text().toInt();
}

void GUIForm::setBoxExhFlow(int nVal)
{
    ui.IDC_ExhalFlow->setText(QString::number(nVal) );
}

int GUIForm::getBoxExhFlow()
{
    return ui.IDC_ExhalFlow->text().toInt();
}

void GUIForm::setBoxExhFlow2(int nVal)
{
    ui.IDC_ExhalFlow2->setText(QString::number(nVal) );
}

int GUIForm::getBoxExhFlow2()
{
    return ui.IDC_ExhalFlow2->text().toInt();
}

void GUIForm::setBoxExhDAC(int nVal)
{
    ui.IDC_ExhDAC->setText(QString::number(nVal));
}

int GUIForm::getBoxExhDAC()
{
    return ui.IDC_ExhDAC->text().toInt();
}	

void GUIForm::setBoxDitherDAC(int nVal)
{
    ui.IDC_DitherDAC->setText(QString::number(nVal) );
}

int GUIForm::getBoxDitherDAC()
{
    return ui.IDC_DitherDAC->text().toInt();
}


void GUIForm::setBoxAirFlow(int nVal)
{
    ui.IDC_AirFlow->setText(QString::number(nVal) );
}

int GUIForm::getBoxAirFlow()
{
    return ui.IDC_AirFlow->text().toInt();
}

void GUIForm::setBoxOxigFlow(int nVal)
{
    ui.IDC_OxigFlow->setText(QString::number(nVal) );
}

int GUIForm::getBoxOxigFlow()
{
    return ui.IDC_OxigFlow->text().toInt();
}


// ***********char values:***********
void GUIForm::setBoxOCTemp(string sVal)
{
    ui.IDC_OCTemp->setText(QString::fromStdString(sVal));
}

int  GUIForm::getBoxOCTemp(string * sVal)
{   
    return 1;
}

void GUIForm::setBoxTCTemp(string sVal)
{
    ui.IDC_TCTemp->setText(QString::fromStdString(sVal));
}

int GUIForm::getBoxTCTemp(string * sVal)
{
    return 1;
}
		
void GUIForm::setBoxACTemp(string sVal)
{
    ui.IDC_ACTemp->setText(QString::fromStdString(sVal));
}

int GUIForm::getBoxACTemp(string * sVal)
{
    return 1;
}

void GUIForm::setBoxO2Comp(string sVal)
{
     ui.IDC_O2Comp->setText(QString::fromStdString(sVal));
}

int GUIForm::getBoxO2Comp(string * sVal)
{
    return 1;
}

void GUIForm::setBoxCPULoad(string sVal)
{
    ui.IDC_CPULoad->setText(QString::fromStdString(sVal));
}

int GUIForm::getBoxCPULoad(string * sVal)
{
 return 1;
}		

//***************************

void GUIForm::enableBtnRunVent(int nVal)
{
 nVal = 1;
}

void GUIForm::enableBtnConnect(int nVal)
{
 nVal = 1;
}

void GUIForm::showMessageBox(std::string sVal)
{
 
}


BelowsPrg::BelowsPrg(QWidget *parent)
     : QFrame(parent),
        m_nProgress(0),
        m_nMaxProgressValue(100)
 {
    setLineWidth(3);
    // setFrameStyle(Box | Sunken);
    setFrameStyle(Box | StyledPanel);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
 }
 
void BelowsPrg::paintEvent(QPaintEvent*)
{
   QPainter painter (this);
   QLinearGradient gradient(0,0, width(), height());
   float f = m_nProgress / (m_nMaxProgressValue * 1.0f);

   //gradient.setColorAt(f, Qt::black);
   gradient.setColorAt(0, Qt::blue);

   painter.fillRect(rect(), Qt::black);
   painter.setBrush(gradient);
   // painter.drawRect(0,0, (int)width() * f, height());
   // painter.drawRect(0,0, (int)height() * f, width());
   // painter.drawRect(width(), height(), -130, -(int)height() * f);   
   painter.drawRect(0, -height(), width(), -(int)height() * f);   
   painter.setPen(QPen(Qt::green));

   QString str = QString().setNum(m_nProgress) + "%";
   painter.drawText(rect(), Qt::AlignCenter, str);
   drawFrame(&painter);

}

QSize BelowsPrg::sizeHint() const
{
 return QSize(90,300);
}

void BelowsPrg::slotSetProgress(int n)
{
    m_nProgress = n > m_nMaxProgressValue ? m_nMaxProgressValue : n < 0 ? 0 : n;
    repaint();
    emit progressChanged(m_nProgress);
}