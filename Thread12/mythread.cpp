#include "mythread.h"
#include <QtCore> 
#include <QDebug>


MyThread::MyThread()
{


}

void MyThread::run()
{

    qDebug() <<  this->my_name <<  " Running.......";

    for (int i = 0; i< 10000; i++)
    {
        qDebug() <<  this->my_name <<  " - " << i;
    }
}






/*
MyThread::MyThread()
   :m_nValue(10)
{   
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
    QTimer timer;
    connect (&timer, SIGNAL(timeout()), SLOT(slotNextValue()));
    timer.start(1000); 
    exec();  
}
*/
