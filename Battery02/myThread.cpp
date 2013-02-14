#include <QtCore>
#include <QApplication>
#include "MyThread.h"
/*
void ThreadSignal::run()
{
    for (int i = 0; i<=100; i++)
    {
      usleep(100000);      
      //emit progress(i);
    }
}
*/

MyThread::MyThread()
   :m_nValue(10002)
{
    isRunning = 1;
    printf ("Thread initiated!\n");
}

void MyThread::stopThread()
{
  isRunning = 0;
  //printf ("Thread will be stopped!\n") ;
}

void MyThread::emitSignal(int i)
{
    printf  ("Thread emit an event now!\n");
    emit thEvent(i);
}

void MyThread::run()
{
    for (int i = 0; i<=100; i++)
    {
        usleep(100000);      
        // emitSignal(i);
        emit thEvent(i);
    }
/*
    for (int i = 0;i < m_nValue; i++)
    {
      printf ("Thread is running! %d time\n", i) ;
      if (i == 1500)
        emitSignal(i);
    }
  
   while(isRunning)
   {
    printf ("1. Thread is running!---\n") ;
    exec();
    printf ("2. Thread is running!---\n") ;
   }
   */ 
}
