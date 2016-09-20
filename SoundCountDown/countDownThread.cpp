#include <QtCore>
#include <QApplication>
#include "countDownThread.h"

countDownThread::countDownThread()
   :m_nValue(1)
{
    isRunning = 1;
    //printf ("Thread initiated!\n");
}

countDownThread::countDownThread(QString _file_to_play)
:m_nValue(20)
,fileUp(_file_to_play)
{
    isRunning = 1;
    //printf ("Thread initiated!\n");
}

void countDownThread::stopThread()
{
  isRunning = 0;
  //printf ("Thread will be stopped!\n") ;
}

void countDownThread::setFileDown(QString _file_to_play)
{
    fileDown = _file_to_play;
}

void countDownThread::setFileUp(QString _file_to_play)
{
    fileUp = _file_to_play;
}

void countDownThread::emitSignal(int i)
{
    //printf  ("Thread emit an event now!\n");
    emit thEvent(i);
}

void countDownThread::PlaySoundQt(QString file)
{
    /*The wrapper for QSound PLAY method. Given parameter is *.wav filename.*/
    // print "create QtGui.QSound for ", file
    QSound *snd = new QSound(file);
    snd->play();
}

void countDownThread::run()
{
    for (int i = 1; i<=m_nValue; i++)
    {
        sleep(1);      
        // emitSignal(i);
        if (i % 2)
        {
            PlaySoundQt(fileUp);
        }
        else
        {
            PlaySoundQt(fileDown);
        }
    }
    sleep(2);
    emitSignal(1);
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
