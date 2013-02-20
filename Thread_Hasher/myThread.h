#ifndef _MY_THREAD_
#define _MY_THREAD_

#include <QtGui>
#include <QtCore>
#include <QApplication>

#include "Counter.h"

class MyThread : public QThread
{
  Q_OBJECT
  public:
    MyThread();
    // MyThread(Counter ctr);
    int m_nValue;
    void run();
    void stopThread();
    void emitSignal(int i);

    int isRunning;
    // Counter p_counter;

  signals:  
    void thEvent(int i);
};

#endif

