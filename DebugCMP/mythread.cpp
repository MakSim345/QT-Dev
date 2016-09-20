 #include <QApplication>
 // #include "uiform.h"
 #include "mythread.h"
 
 
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
  QString str;
  m_nValue--;
  if (!m_nValue)
  {   
   emit finished(); 
  }
   
  str = "TEST message: this is a test message without any parameters.";
  emit currentValue(str);
  emit currentNumValue(m_nValue);
  emit pushTheButton();
}


void MyThread::run()
{
 QTimer timer;
 connect (&timer, SIGNAL(timeout()), SLOT(slotNextValue()));
 timer.start(1000);
 
 exec();  
}

