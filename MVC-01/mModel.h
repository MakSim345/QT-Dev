#ifndef _M_MODEL_H_
#define _M_MODEL_H_
//============================================================
//
//
//============================================================
//
// File:           mModel.h
//
//============================================================
// Description:
//============================================================
#include <QtGui>
#include <time.h>
#include "mythread.h"
#include "mControl.h"
#include "FTime.h"
#include <stdlib.h>
#include <math.h>

class mControl;

class mModel: public QWidget
{
    Q_OBJECT

public:
    mModel(QWidget *parent = 0);
    ~mModel();

    void initThread();
    void initTimer();
    void eventTimer();
    void startTimer();
    void stopTimer();
    void onExit();
    void onRun();
    void setRunBtnName(QString strName);
    void getControlPointer(mControl *pCtr);
    void appendStrEditBox(QString strToApp);
    void showResult();
    void startThread();
    void initArray();
    void initArray_th();
    void RNDArray();
    void RNDArray_th();
    void calcArray();
    void calcArray_th();
    int mkRnd();
    void printDump();

private:
    
    FTime *f;
    int nSizeArr;
    int counter;
    int timerInterval;
    bool state;    
    std::vector <int> mArray;
    QString mName;
    MyThread *mythread;
    QTimer *timer;
    mControl *pControl;

    //mName = 'mModel component'
};

#endif



        
