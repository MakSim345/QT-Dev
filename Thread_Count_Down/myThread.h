#ifndef _MY_THREAD_
#define _MY_THREAD_

#include <QtGui>
#include <QtCore>
#include <QApplication>
#include <QSound>

class ThreadSignal: public QThread
{
 Q_OBJECT
    public:
     void run();

    signals:
     void progress(int);
};

class MyThread : public QThread
{
  Q_OBJECT
  public:
    MyThread();  
    MyThread(QString file); 
    int m_nValue;
    void run();
    void stopThread();
    void emitSignal(int i);
    void PlaySoundQt();

    int isRunning;
    QString file;

  signals:  
    void thEvent(int i);
};

#endif

