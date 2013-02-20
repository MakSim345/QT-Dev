#include <QtCore>
#include <QApplication>
#include "MyThread.h"

    
MyThread::MyThread()
   :m_nValue(0)
{
    isRunning = 0;
}
/*
MyThread::MyThread(Counter ctr)
   :m_nValue(0)
{
    isRunning = 0;
    //p_counter = ctr;
}
*/
void MyThread::stopThread()
{
    isRunning = 0;
    qDebug() << "Thread will be stopped!";
}

void MyThread::run()
{
    /*
    int n = 100000000;
    do
    {
        n--;
        // qDebug() << "thread n= " << n;
    } while (n > 0);
    */
    long n = 10000000000;
    int i = 0;
    for (n; n>0; n--)
    {
      i = i*n;
    }
    qDebug() << "thread n= " << n;
    emitSignal(1);
}
/*
void MyThread::run()
{
    int i = 0;
	for (i = 0; i<=100; i++)
	{
		usleep(100000);
		emitSignal(i);
	}
}
*/
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


void MyThread::emitSignal(int i)
{
    // qDebug() << "Thread emit an event now!";
    emit thEvent(i);
}
