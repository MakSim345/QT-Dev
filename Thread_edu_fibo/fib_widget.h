#ifndef _FIB_WIDGET_H_
#define _FIB_WIDGET_H_

#include <gen.h>

#include "fibo_thread.h"

class fib_widget : public QWidget
{
    Q_OBJECT
public:    
    fib_widget(QWidget *parent = 0);    
    ~fib_widget(){};

    QLineEdit* line3;
    QLineEdit* line4;
    QLineEdit* lnResut;
    
    QPushButton* bCountDown;
    QPushButton* bRnd;
    QPushButton *bQuit;

    QLCDNumber *lcd;
    QLCDNumber* lsdFibNumber;

    FiboThread m_thread;
    void hello(QString name);

 public slots:
    void calcFib();
    void onExit ();
    void StartMyThread();
    void EndOfCalculation();
    void DisplayIteration(double iteration_counter);
    void DisplayResult(double result);
    // int GetRNDValue();
};

#endif // MYTHWIDGET_H
