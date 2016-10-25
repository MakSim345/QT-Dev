#include "MyThread.h"

void ThreadSignal::run()
{
    for (int i = 0; i<=100; i++)
    {
      usleep(100000);      
      //emit progress(i);
    }
}


MyThread::MyThread()
   :m_nValue(10002)
{
    isRunning = 1;
    //printf ("Thread initiated!\n");
}

MyThread::MyThread(QString _file_to_play)
    : m_nValue(10002),
     file(_file_to_play)
{
    isRunning = 1;
    //printf ("Thread initiated!\n");
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

void MyThread::PlaySoundQt()
{
    /*The wrapper for QSound PLAY method. Given parameter is *.wav filename.*/
    // print "create QtGui.QSound for ", file
    QSound *snd = new QSound(file);
    snd->play();
}

void MyThread::run()
{
    for (int i = 0; i<=20; i++)
    {
        sleep(1);
        emitSignal(i);
        PlaySoundQt();
    }
    // emitSignal(1);
    /*
    for (int i = 0; i<=100; i++)
	{
		usleep(100000);      
		emitSignal(i);
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
}
