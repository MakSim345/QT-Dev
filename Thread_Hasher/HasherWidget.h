#ifndef _HASHER_WIDGET_H_
#define _HASHER_WIDGET_H_

#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include "MyThread.h"
#include "Counter.h"
#include "hasherthread.h"

class HasherWidget : public QWidget
{
  Q_OBJECT

public:
    HasherWidget(QWidget *parent = 0);
    
    MyThread *_test_thread_1;
    MyThread *_test_thread_2;
    QPushButton *_exit_button;
    QPushButton *_hash_button;
    QProgressBar *prb;
    // Counter *_counter;

    QTime timeStamp;
    HasherThread *hasher;

    void count();

public slots:
    //void onExitClick();
    // void onThreadEvent(int);
    void hashPressed();

private:
    QVBoxLayout *vlayout;
    QLineEdit *filenameEdit;
    QLineEdit *resultEdit;
    void setConnections();
    QString fileNameStr;
    

    int i_start;
    int i_stop;

};

#endif

