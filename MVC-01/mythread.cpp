#include "mythread.h"
 
MyThread::MyThread()
   :m_nValue(10)
{   
    // QThread.(parent)    
    qDebug ("MyThread initiated!");
    
}

MyThread::MyThread(int nCounter)
{   
    m_nValue = nCounter;
    // QThread.(parent)    
    qDebug ("MyThread initiated!");    
}


void MyThread::setMValue(int i)
{
    m_nValue = i;
}

int MyThread::getMValue(void)
{
    return m_nValue;
}

void MyThread::setMessage(const QString &message)
{

}

void MyThread::slotNextValue()
{
    emit currentValue(--m_nValue);
  
    if (!m_nValue)
    { 
      emit finished(); 
    }
}

void MyThread::run()
{
    //QTimer timer;
    //connect (&timer, SIGNAL(timeout()), SLOT(slotNextValue()));
    //pModel->start(1000); 
    //exec();  

    for (int i = 0; i < m_nValue; i++)
    {
        qDebug( "Thread is running! %d time", i);
        //time.sleep(0.1)
    }
    // qDebug( f.get1MSTime(),  " - Start signal emitting...");
    //emit(SIGNAL(/threadEvent()))
    // qDebug( f.get1MSTime(),  " - Stop  signal emitting...");
}

