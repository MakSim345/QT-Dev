#include "debug_cmp.h"

#include <time.h>

DebugCMP::DebugCMP(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	m_GrnIcon = new QIcon("ledGreen.png");
	m_RedIcon = new QIcon("ledRed.png");
	
	InitDialog();	

	connect(ui.exitButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.newCMPButton, SIGNAL(clicked()), this, SLOT(startThreadGUI()));
	connect(ui.runTestButton, SIGNAL(clicked()), this, SLOT(startThreadEVE()));
	
	connect(&m_threadEVE, SIGNAL(currentValue(QString)), this, SLOT(readEVEMessage(QString)));
	connect(&m_threadGUI, SIGNAL(currentValue(QString)), this, SLOT(readGUIMessage(QString)));
	
	// connect(&m_threadEVE, SIGNAL(currentNumValue(int)), this, SLOT(readEVEMessageNum(int)));
		
	// connect(ui.pbStartVent, SIGNAL(pressed ()), this, SLOT(setBiggerSize()));
	// connect(ui.pbStartVent, SIGNAL(released ()), this, SLOT(setSmallerSize()));
	// connect(ui.pbStartVent, SIGNAL(clicked()), this, SLOT(CloseUI()));
	
	/*
	color: black;
	background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.4 gray, stop: 0.5 lightgray, stop: 1.0 black);
	border: 1px solid black;
	border-radius: 6px;
	font: bold 18px; 
	*/
}

DebugCMP::~DebugCMP()
{

}

void DebugCMP::InitDialog()
{
  QString str;
  QSize ver_size_min;
  
  // set minimum sizes for widgets:
  setMinimumSizeIDC_VER();
  setMinimumSizeEXIT_BTN();
  setMinimumSizeTAB();
  
  str.sprintf("Ver: %s. Compiled: %s %s", VERSION, __DATE__, __TIME__);
  setVersionInfoTxt(str);
  
  initTabs();
}

void DebugCMP::initTabs()
{
  // ui.tabWidget->
  // ui.tabWidget->setTabText(ui.tabWidget->indexOf(tab), QApplication::translate("DebugCMP", "Tab 1", 0, QApplication::UnicodeUTF8));
  /*
  QWidget *newTab = new QWidget(ui.tabWidget);
  ui.tabWidget->addTab(newTab, tr("name")); 
  */
  // ui.tabWidget->addTab(ui.tabWidget, "QT");
  ui.tabWidget->setTabText(ui.tabWidget->indexOf(ui.tabEVE), "VentCore");
  ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabEVE), *m_RedIcon); 
  
  ui.tabWidget->setTabText(ui.tabWidget->indexOf(ui.tabGUI), "GUI");
  ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabGUI), *m_RedIcon); 
  
  ui.tabWidget->setTabText(ui.tabWidget->indexOf(ui.tabARB), "Arbitrator");
  ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabARB), *m_RedIcon); 
  
  ui.tabWidget->setTabText(ui.tabWidget->indexOf(ui.tabGDU), "GDU");
  ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabGDU), *m_RedIcon);
  
  ui.tabWidget->setTabText(ui.tabWidget->indexOf(ui.tabALL), "General");
  ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabALL), *m_RedIcon);
  
  ui.tabWidget->setCurrentIndex(0); 
}

void DebugCMP::readEVEMessage(QString str)
{
 QString sOutputLine;
 
 sOutputLine = QDateTime::currentDateTime().toString("dd.MM.yy hh:mm:ss.zzz - ") + str;
 
 ui.textEdit_1->append(sOutputLine);
}

/*
void DebugCMP::readEVEMessageT()
{
 QString str = "Test";
 ui.textEdit_1->append(str);
}
*/

void DebugCMP::readGUIMessage(QString str)
{
 QString sOutputLine;
 
 sOutputLine = QDateTime::currentDateTime().toString("dd.MM.yy hh:mm:ss.zzz") + str;
 
 ui.textEdit_2->append(sOutputLine);
}

void DebugCMP::setMinimumSizeTAB()
{
 QSize ver_size_min;
 ver_size_min.setHeight(150);
 ver_size_min.setWidth(150);
  
 ui.tabWidget->setMinimumSize(ver_size_min);
}

void DebugCMP::setMinimumSizeEXIT_BTN()
{
 QSize ver_size_min;
 const int minHeight = 35;
 const int minWidth = 150;
 
 ui.exitButton->setStyleSheet("QPushButton {color: lightgray;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 10.0 lightblue); border: 1px solid black;border-radius: 6px;font: 25px;} QPushButton:hover{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230)); border: 1px solid red;} QPushButton:pressed { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230)); }");
 ui.runTestButton->setStyleSheet("QPushButton {color: lightgray;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 10.0 lightblue); border: 1px solid black;border-radius: 6px;font: 25px;} QPushButton:hover{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230)); border: 1px solid red;} QPushButton:pressed { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230)); }");
 ui.newCMPButton->setStyleSheet("QPushButton {color: lightgray;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 10.0 lightblue); border: 1px solid black;border-radius: 6px;font: 25px;} QPushButton:hover{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230)); border: 1px solid red;} QPushButton:pressed { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230)); }");
 
 ver_size_min.setHeight(minHeight);
 ver_size_min.setWidth(minWidth);
  
 ui.exitButton->setMinimumSize(ver_size_min);
 ui.runTestButton->setMinimumSize(ver_size_min);
 ui.newCMPButton->setMinimumSize(ver_size_min);
}

void DebugCMP::setMinimumSizeIDC_VER()
{
 QSize ver_size_min;
 ver_size_min.setHeight(25);
 ver_size_min.setWidth(255);
  
 ui.IDC_VERSION_INFO->setMinimumSize(ver_size_min);
}

void DebugCMP::setVersionInfoTxt(QString str)
{
 ui.IDC_VERSION_INFO->setText(str);
}

void DebugCMP::startThreadEVE()
{
 static int i = 20;
 m_threadEVE.start();
 setLedOnTab(EVE, GRNLED);
}

void DebugCMP::startThreadGUI()
{
 static int i = 20;
 m_threadGUI.start();
 setLedOnTab(GUI, GRNLED);
}

void DebugCMP::setLedOnTab(int nDest, int nColor)
{
 switch (nDest)    
    {
	 case 1001:
	    if (nColor == REDLED)
	      ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabEVE), *m_RedIcon); 
	    else  
	      ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabEVE), *m_GrnIcon); 
	    break;		
	 
	 case 1002:
	    if (nColor == REDLED)
	      ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabGUI), *m_RedIcon); 
	    else  
	      ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabGUI), *m_GrnIcon); 
		break;
	 
	 case 1003:
	    if (nColor == REDLED)	    
	      ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabGDU), *m_RedIcon); 
	    else  
	      ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabGDU), *m_GrnIcon);   
		break;
	 
	 case 1004:
	    if (nColor == REDLED)
	      ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabARB), *m_RedIcon); 
	    else  
	      ui.tabWidget->setTabIcon(ui.tabWidget->indexOf(ui.tabARB), *m_GrnIcon);
		break;
						
	 default:
	    // sprintf_s(m_MonthValue, nNumCharMonth, "%d", nMonthVal);
	    break;
    }
}


void DebugCMP::CloseUI()
{
 static int i = 20;
 // ui.editTotalFlow->setText(QString::number(i++)); 
}

void DebugCMP::setBiggerSize()
{
 // ui.pbStartVent->resize();
 // ui.pbStartVent->setGeometry(62, 40, 75, 30);
 //  ui.pbStartVent->setFixedSize(130, 90);
}

void DebugCMP::setSmallerSize()
{
 // ui.pbStartVent->resize();
 // ui.pbStartVent->setGeometry(62, 40, 75, 30);
  // ui.pbStartVent->setFixedSize(120, 80);
}
