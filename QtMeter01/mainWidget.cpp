#include <QApplication>
#include <QLabel>

#include "qvumeter.h"
#include "mainWidget.h"
#include "mythread.h"

//#define QT_RND_SERVER
#ifndef QT_RND_SERVER
 #include <time.h>
#endif 

void mainWidget::showMessageBox()
{
    // QMessageBox::about(this, "Application", "Countdown timer over!");
}

void mainWidget::closeApp()
{
 // showMessageBox();
 QApplication::beep();
 close();
}

void mainWidget::StartMyThread()
{
    m_thread.setMValue( lcd->intValue() );
    m_thread.start();
}

void mainWidget::setValue()
{ 
  //lnMSTime->setText(QString::number(GetRNDValue()));
  //lcd->display(lnMSTime->text());
  m_nRandomValue = GetRNDValue();
  lcd->display(QString::number(m_nRandomValue));
  slider->setValue(m_nRandomValue);
  // lnMSTime->setText(QString::number(Get1msTimeMS() ));
  mainWidget::bStartThread->setDisabled(0);
  QApplication::beep();
}

void mainWidget::onTestClick()
{ 
  static int nValue = 0;
  //vumeter->setLeftValue(nValue++);
  // QApplication::beep();
  m_timer.start(100);
  mainWidget::bRnd->setDisabled(1);
  mainWidget::bStartThread->setDisabled(1);
  mainWidget::bTest->setDisabled(1);
  mainWidget::slider->setDisabled(1);
}

void mainWidget::onTimerEvent()
{ 
  
  if (m_nRandomValue > 999)
  {
   m_nGoDown = 1;
  }
    
  if (m_nRandomValue < 0)
  {
   m_nGoDown = 0;
  }
  
  if (!m_nGoDown)
  {
   m_nRandomValue=m_nRandomValue+20;
  }
  else
  {
   m_nRandomValue=m_nRandomValue-20;
  }
  slider->setValue(m_nRandomValue);
} 

void mainWidget::onStartThreadClick()
{ 
  static int nFirstTime = 1;
  if (nFirstTime)
  {   
    StartMyThread();
    // Disable appr. buttons:
    mainWidget::bRnd->setDisabled(1);
    mainWidget::bStartThread->setDisabled(1);
    nFirstTime = 0;    
   }
 QApplication::beep();
}



int mainWidget::GetRNDValue()
{
  int nRetVal=0;
  static int nFirstTime = 1;

#ifdef QT_RND_SERVER

 if (1 == nFirstTime)
 {
  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
  nFirstTime = 0;
 }
 nRetVal = (int)qrand(); 

#else

 int RND_MAX = 900;
 
 if (1 == nFirstTime)
 {
  srand (time (NULL));
  nFirstTime = 0;
 }
 nRetVal = 1 + (rand() % RND_MAX); 
 
 //qDebug() << "Time: " << nRetVal;    
 //qDebug() << "Execution done";
#endif  

return nRetVal;
} 
mainWidget::mainWidget(QWidget *parent)
     : QWidget(parent),
       m_nRandomValue(0),
       m_nGoDown(0)
 {
     // setFixedSize(450, 300);

     // button_power = new QPower(this);
	 // aerobutton_test = new AeroButton("Test", this);
	 bRnd = new QPushButton(tr(" Ra&ndom "));
	 bQuit = new QPushButton(tr(" &Exit "));
	 bStartThread = new QPushButton(tr(" &Countdown "));
	 bTest = new QPushButton(tr(" &Run Vent. "));
	 vumeter = new QVUMeter();
	 //BelowsProgress = new BelowsPrg(); 
	 BelowsEnhanced = new BelowsEnh();
	 
	 vlayout = new QVBoxLayout;	 
	 vlayout2 = new QVBoxLayout;	 
	 vlayout3 = new QVBoxLayout;
	 vlayout4 = new QVBoxLayout;	 
	 
	 hlayout = new QHBoxLayout;
	 hlayout2 = new QHBoxLayout;
	 hlayout3 = new QHBoxLayout;
	 
	 // This is a main layout:
	 mlayout = new QHBoxLayout;
	 
	 //quit->setFont(QFont("Times", 25, QFont::Bold));
	 //aerobutton_test->setFont(QFont("Times", 12, QFont::Bold));
	 //aerobutton_quit->setGeometry(10, 20, 230, 40);
	 //aerobutton_test->setGeometry(10, 70, 230, 40);
	 
	 //quit->setStyleSheet("QPushButton {color: black; border: 1px solid black; border-radius: 6px;font: bold 18px;} QPushButton:pressed {background-color: red;}");
	 //quit->setStyleSheet("QPushButton#exitButton { color: black; };");
	 // QString("QPushButton {background-color: red;} QPushButton:checked{background-color: red;} QPushButton:pressed {background-color: red;}"));

bQuit->setStyleSheet("QPushButton {color: lightgray;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 10.0 lightblue); border: 1px solid black;border-radius: 6px;font: 25px;} QPushButton:hover{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230)); border: 1px solid red;} QPushButton:pressed { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230)); }");
bRnd->setStyleSheet("QPushButton {color: lightgray;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 10.0 lightblue); border: 1px solid black;border-radius: 6px;font: 25px;} QPushButton:hover{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230)); border: 1px solid red;} QPushButton:pressed { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230)); }");
bTest->setStyleSheet("QPushButton {color: lightgray;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 10.0 lightblue); border: 1px solid black;border-radius: 6px;font: 25px;} QPushButton:hover{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230)); border: 1px solid red;} QPushButton:pressed { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230)); }");
bStartThread->setStyleSheet("QPushButton {color: lightgray;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 10.0 lightblue); border: 1px solid black;border-radius: 6px;font: 25px;} QPushButton:hover{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230)); border: 1px solid red;} QPushButton:pressed { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230)); }");

//QPixmap pix("HP_Monitor.jpg");
//bTest->setIcon(pix);
// bTest->setIconSize(pix.size());

/*
QPushButton:pressed 
{
   background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230));
}
*/
	 
	 /*
	 QGridLayout *grid = new QGridLayout;
     for (int row = 0; row < 3; ++row)
     {
      for (int column = 0; column < 2; ++column) 
      {
       LCDRange *lcdRange = new LCDRange;
       grid->addWidget(lcdRange, row, column);
      }
     }
	*/	
	  
	 
    lcd = new QLCDNumber(3);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    
    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 999);
    slider->setValue(0);
    
    vlayout4->addWidget(BelowsEnhanced);  
    hlayout3->addWidget(BelowsEnhanced); 
    //hlayout->addWidget(BelowsProgress);  
    
    vlayout->addWidget(lcd);
    vlayout->addWidget(slider); 
    
    vlayout2->addWidget(bRnd); 
    vlayout2->addWidget(bQuit);
    
    vlayout3->addWidget(bTest);
    vlayout3->addWidget(bStartThread); 
        
    hlayout2->addLayout(vlayout3);
    hlayout2->addLayout(vlayout2);
    
	vlayout->addLayout(hlayout2);
	//vlayout->addLayout(vlayout3);
      
     //layout->addWidget(slider);
    mlayout->addLayout(hlayout);
    mlayout->addLayout(hlayout3);
    mlayout->addLayout(vlayout);
    setLayout(mlayout);

     
	//QObject::connect(aerobutton_quit, SIGNAL(clicked()), &app, SLOT(quit()));
    // connect(aerobutton_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    // connect(aerobutton_quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
    //connect(aerobutton_test, SIGNAL(clicked()), this, SLOT(showMessageBox() ));
    connect (&m_timer, SIGNAL(timeout()), this, SLOT(onTimerEvent()));
    
    connect(bQuit, SIGNAL(clicked()), this, SLOT(close() ));
    
    connect(bRnd, SIGNAL(clicked()), this, SLOT(setValue() ));
    
    connect(bStartThread, SIGNAL(clicked()), this, SLOT(onStartThreadClick()));
    
    connect(bTest, SIGNAL(clicked()), this, SLOT(onTestClick() ));
    
    //connect(slider, SIGNAL(valueChanged(int)), BelowsProgress, SLOT(slotSetProgress(int)));
    
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    
    connect(slider, SIGNAL(valueChanged(int)), BelowsEnhanced, SLOT(setProgrBarValue(int)) );
    
    connect (&m_thread, SIGNAL(currentValue(int)), lcd, SLOT(display(int)) );
    connect (&m_thread, SIGNAL(finished()), this, SLOT(closeApp()) );
     // connect(quit, SIGNAL(clicked()), this, SLOT(close() ));
     // connect(button_power, SIGNAL(mousePressEvent()), this, SLOT(close() ));
    
    mainWidget::bStartThread->setDisabled(1);
 }


