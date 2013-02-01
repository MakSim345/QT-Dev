#include <QtGui>
#include <ifthread.h>
#include <QApplication>
// #include "uiform.h"
//using namespace std;

NotifyThread::NotifyThread()
{
 // stopped= false;
 // m_CalcForm = calcForm;
 m_nValue = 100;
}

NotifyThread::NotifyThread(int nVal)
{
 setMValue(nVal);
}
 
void NotifyThread::setMValue(int i)
{
 if (i < 0) 
   m_nValue = 100;
 else
   m_nValue = i;
}

int NotifyThread::getMValue(void)
{
 return m_nValue;
}

/********************************************************************

  Declaration: Function "connected" to timer and called on every timer 
               tick. 
  Call: slotNextValue
  Input: 
  Returns: none
  30.05.2008 Initial coding / YS  
  
*********************************************************************/
void NotifyThread::slotNextValue()
{
  emit timerClick();
}

/********************************************************************

  Declaration: The RUN function for thread. Start after method start called.
  Call:  
  Input: 
  Returns: none
  30.05.2008 Initial coding / YS  
  
*********************************************************************/
void NotifyThread::run()
{
 qDebug("NotifyThread::run() - start");
 QTimer timer;
 connect (&timer, SIGNAL(timeout()), SLOT(slotNextValue()));
 timer.start(100);
 
 exec();  
}

void NotifyThread::setMessage(const QString &message)
{
 // stopped= true;
 // run();
}

#ifdef YS_TEST_234234334009

void MyThread::run()
{
 int res = 0;
 int DataSize = 2000;
 /*
 for(int i=0;i<10;i++)
  {
    qDebug() << "Time: " << 10-i;    
 
    int t=1;
 
    // some OS specific stuff
    // mingw (3.4.2) sleep on windows is called _sleep and uses microseconds
    #ifdef Q_OS_WIN32
    t = t * 1000;
    _sleep(t);
    #else
    sleep(t);
    #endif
 }
 
 qDebug() << "Execution done";
 */

qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));


for (int i = 0; i < DataSize; ++i) 
{ 
 res = (int)qrand();
 sleep(1000);
 // m_CalcForm->setResult(res);
}

}

#endif
