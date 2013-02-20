#ifndef _MY_WIDGET_H_
#define _MY_WIDGET_H_

#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "MyThread.h"
#include "myButton.h"
#include "Counter.h"

class MainWidget : public QWidget
{
  Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);

    MyThread *_test_thread_1;
    MyThread *_test_thread_2;
    MyThread *_test_thread_3;
    MyThread *_test_thread_4;

    QPushButton *_exit_button;
    QPushButton *_serial_button;
    QPushButton *_thread_button;
    QProgressBar *prb;
    Counter *_counter;

    QTime timeStamp;

    void count();

public slots:
    //void onExitClick();
    void onThreadEvent(int);
    void onStartThreadsPressed();
    void onStartCalcPressed();

private:
    QVBoxLayout *vlayout;
    QLineEdit *filenameEdit;
    QLineEdit *resultEdit;

    QLabel *lblThreadsResult;
    QLabel *lblSerialResult;

    void setConnections();


    int i_start;
    int i_stop;

};

#endif

