#ifndef MYTHWIDGET_H
#define MYTHWIDGET_H

#include <QWidget>
#include <QThread>
#include <QString>
#include <QLineEdit>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <time.h>
#include "mythread.h"

class MyThWidget : public QWidget
{
    Q_OBJECT
public:    
    MyThWidget(QWidget *parent = 0);    
    ~MyThWidget(){};

    int GetRNDValue();

    QLineEdit* line3;
    QLineEdit* lnMSTime;
    
    QPushButton* bCountDown;
    QPushButton* bRnd;
    QPushButton *bQuit;

    QLCDNumber *lcd;

    MyThread m_thread;
    int fib(int f);

 public slots:
    void setValue();
    void onExit ();
    void StartMyThread();
    // int GetRNDValue();
};

#endif // MYTHWIDGET_H
