/* mywidget.cpp */
#include <QtGui>
    
#include "mywidget.h"
#include "qled.h"

//#define QT_RND_SERVER
#ifndef QT_RND_SERVER
 #include <time.h>
#endif 
 
 
MyWidget::MyWidget (QWidget *parent)
      : QWidget(parent)
{
    //setFixedSize(350, 220);    
    //setFixedHeight(sizeHint().height());
    
    line3 = new QLineEdit (this); 
    lnMSTime = new QLineEdit (this); 
    bExit = new QPushButton ("&Exit", this);
    bRnd  = new QPushButton ("&RND", this);    
    bLed1 = new QLed();
    bLed2 = new QLed();
    
    bLed1->setMaximumSize(50,50);
    bLed2->setMaximumSize(50,50);
    
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *hLayout2 = new QHBoxLayout;
    
    line3->setReadOnly (true);    
    hLayout->addWidget(line3); 
    hLayout->addWidget(lnMSTime); 
    hLayout->addWidget(bRnd);
    
    //mainLayout->addWidget(line3); 
    hLayout2->addWidget(bLed1);
    hLayout2->addWidget(bLed2);
    //mainLayout->addWidget(bRnd);
    
    mainLayout->addLayout(hLayout2);
    mainLayout->addLayout(hLayout);
    mainLayout->addWidget(bExit);            
    setLayout(mainLayout);    
       
    bLed2->toggleValue();
    
    connect (bRnd, SIGNAL(clicked ()), this, SLOT (setValue()));
    connect (bExit, SIGNAL(clicked ()), this, SLOT (onExit ()));
    
    setWindowTitle(tr("Test LED indicator project"));
}
 
MyWidget::~MyWidget ()
{
 
}

void MyWidget::setValue()
{ 
 line3->setText(QString::number(GetRNDValue()));
 // bLed->setColor(Qt::red);
 lnMSTime->setText(QString::number(Get1msTimeMS() ));
 bLed1->toggleValue();
 bLed2->toggleValue();
 // QApplication::beep();
}

int MyWidget::GetRNDValue()
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

 int RND_MAX = 65;
 
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
 
void MyWidget::onExit()
{
 close(); 
}

// Timer class

CTimer::CTimer() 
{ 
 ::QueryPerformanceFrequency(&m_liFreq);
 Start();
}

void CTimer::Start()
{ 
 ::QueryPerformanceCounter(&m_liStart);  
}

unsigned int CTimer::GetElapsedTimeMs() const
{
  LARGE_INTEGER liEnd;
  ::QueryPerformanceCounter(&liEnd);  
  return static_cast<unsigned int>((liEnd.QuadPart - m_liStart.QuadPart) * 1000 / m_liFreq.QuadPart);
}

unsigned __int64 CTimer::GetElapsedTimeMks() const 
{
  LARGE_INTEGER liEnd;
  ::QueryPerformanceCounter(&liEnd);
  return static_cast<unsigned __int64>((liEnd.QuadPart - m_liStart.QuadPart) * 1000000 / m_liFreq.QuadPart);
}

// End of the class.

/********************************************************************

  Declaration: implementation of Get1msTime() for Microsoft env. 
  Call: Get1msTimeMS(void)
  Input: none
  Returns: milliseconds.
  	  
*********************************************************************/ 
long  Get1msTimeMS(void)
{
  /*
  // 1. Use function  _ftime
   struct _timeb timebuffer;

  _ftime( &timebuffer );
  // g_lTimeTick = (timebuffer.time*1000)+timebuffer.millitm;
  return (timebuffer.time*1000)+timebuffer.millitm;
  */
  
  /*
  // 2. Use function GetTickCount():
  // after 49 days it will reset. Check it!
  return GetTickCount();
  */
  
  /*
   // 3. Use  QueryPerformanceCounter () function:
  __int64 nTick, f; 

  // This function must be called once!
  QueryPerformanceFrequency((PLARGE_INTEGER)&f); 
  
  QueryPerformanceCounter((PLARGE_INTEGER)&nTick);
  return (long)(nTick/3000000); // divide to processor speed!!!
  */
   
   // 3. Use class based on QueryPerformanceCounter () functions:
   //static int nFirsTime = 1;
   static CTimer *t = new CTimer(); // take memory from heap, not from stack!    
   return t->GetElapsedTimeMs();
   //return t.GetElapsedTimeMs();
   //return t.GetElapsedTimeMks();
}
