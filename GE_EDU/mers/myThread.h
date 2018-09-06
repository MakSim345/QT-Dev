#ifndef _MY_THREAD_
#define _MY_THREAD_

#include <QtGui>
#include <QtCore>
#include <QApplication>

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
    int m_nValue;
    void run();
    void stopThread();
    void emitSignal(int i);

    int isRunning;

  signals:  
    void thEvent(int i);
};

#endif

