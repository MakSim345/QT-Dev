#ifndef _MY_THREAD_
#define _MY_THREAD_

#include <QtGui>
#include <QtCore>
#include <QApplication>
#include <QtMultimedia/QSound>

class countDownThread : public QThread
{
  Q_OBJECT
  public:
    countDownThread();  
    countDownThread(QString file); 
    void setFileUp(QString file);
    void setFileDown(QString file);
    int m_nValue;
    void run();
    void stopThread();
    void emitSignal(int i);
    void PlaySoundQt(QString file);

    int isRunning;
    QString fileUp;
    QString fileDown;

  signals:  
    void thEvent(int i);
};

#endif

