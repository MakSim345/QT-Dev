#include <QApplication>
#include <QLabel>

#include "belows_enh.h"
#include "mainWidget.h"
#include "mythread.h"
#include "qprog.h"
#include "customwidget.h"

//#define QT_RND_SERVER
#ifndef QT_RND_SERVER
 #include <time.h>
#endif 

mainWidget::mainWidget(QWidget *parent)
     : QWidget(parent)
 {
   // setFixedSize(450, 300);
   initStyleSheetVars();
   
   initWidgets();
   setConnectionsWidgets();
   setAllLayouts();
   setStyleSheets();
 }
     // setFixedSize(450, 300);
	 
	 //quit->setFont(QFont("Times", 25, QFont::Bold));
	 //aerobutton_test->setFont(QFont("Times", 12, QFont::Bold));
	 //aerobutton_quit->setGeometry(10, 20, 230, 40);
	 //aerobutton_test->setGeometry(10, 70, 230, 40);
 
void mainWidget::setAllLayouts()
{
    // This is a main layout:
    mlayout = new QHBoxLayout;
   
    hlayout->addWidget(vumeter);     
    hlayout->addWidget(qProgBar);
    // hlayout->addWidget(cwTouchBar);
    vlayout->addWidget(lcd);
    vlayout->addWidget(slider); 
    vlayout->addWidget(test); 
    vlayout->addWidget(quit);
	
    // layout->addWidget(aerobutton_test);
    // layout->addLayout(grid);
    // layout->addWidget(button_power);
     
    //layout->addWidget(slider);
    mlayout->addLayout(hlayout);
    mlayout->addLayout(vlayout);
    setLayout(mlayout);
}

void mainWidget::initWidgets()
{
  test = new QPushButton(tr("T&est"));
  quit = new QPushButton(tr("&Exit"));
  qProgBar = new QProg();
  cwTouchBar = new CustomWidget();
  vumeter = new BelowsEnh();
  vlayout = new QVBoxLayout;	 
  hlayout = new QHBoxLayout;
  
  //qProgBar->setMaximumSize(280, 60);  
  qProgBar->setMaxValue(1000.0);
    
	 
  lcd = new QLCDNumber(3);
  lcd->setSegmentStyle(QLCDNumber::Filled);
    
  slider = new QSlider(Qt::Horizontal);
  slider->setRange(0, 999);
  slider->setValue(0);
}

void mainWidget::setConnectionsWidgets()
{   
    //QObject::connect(aerobutton_quit, SIGNAL(clicked()), &app, SLOT(quit()));
    // connect(aerobutton_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    // connect(aerobutton_quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
    //connect(aerobutton_test, SIGNAL(clicked()), this, SLOT(showMessageBox() ));
    connect(quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
    connect(test, SIGNAL(clicked()), this, SLOT(setValue() ));

    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    connect(slider, SIGNAL(valueChanged(int)), vumeter, SLOT(setProgrBarValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), qProgBar, SLOT(setProgrBarValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), qProgBar, SLOT(qProgBar->setValue(double)));
    connect (&m_thread, SIGNAL(currentValue(int)), lcd, SLOT(display(int)) );
    //connect(quit, SIGNAL(clicked()), this, SLOT(close() ));
    // connect(button_power, SIGNAL(mousePressEvent()), this, SLOT(close() ));
}

void mainWidget::setStyleSheets()
{
  //quit->setStyleSheet("QPushButton {color: black; border: 1px solid black; border-radius: 6px;font: bold 18px;} QPushButton:pressed {background-color: red;}");
  //quit->setStyleSheet("QPushButton#exitButton { color: black; };");
  // QString("QPushButton {background-color: red;} QPushButton:checked{background-color: red;} QPushButton:pressed {background-color: red;}"));
  quit->setStyleSheet(strButtonsStSheet);
  test->setStyleSheet(strButtonsStSheet);

}

void mainWidget::showMessageBox()
{
 QMessageBox::about(this, "Application", "Vista aero style");
}

void mainWidget::closeApp()
{
 close();
}

void mainWidget::StartMyThread()
{
    m_thread.setMValue( lcd->intValue() );
    m_thread.start();
}

void mainWidget::setValue()
{ 
  static int nFirsTime = 1;
  if (nFirsTime)
  {
    //lnMSTime->setText(QString::number(GetRNDValue()));
    //lcd->display(lnMSTime->text());
    lcd->display(QString::number(GetRNDValue()));
    // lnMSTime->setText(QString::number(Get1msTimeMS() ));
   StartMyThread();
   mainWidget::test->setDisabled(1);
   nFirsTime = 0;    
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

void mainWidget::initStyleSheetVars()
{
  strButtonsStSheet = "QPushButton \
                         {color: lightgray; \
                          background-color:  \
                               qlineargradient(x1:0, y1:0, x2:0, y2:1,  \
                                stop: 0 black,  \
                                stop: 0.1 lightgray  \
                                stop: 0.3 black,  \
                                stop: 0.8 black,  \
                                stop: 10.0 lightblue);  \
                          border: 1px solid black; \
                          border-radius: 6px;font: 25px;} \
                        QPushButton:hover \
                          {background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,  \
                                stop: 0 black,  \
                                stop: 0.1 lightgray  \
                                stop: 0.3 black,  \
                                stop: 0.8 black,  \
                                stop: 1.0 RGB(105, 230,230));  \
                           border: 1px solid red;}";
}
