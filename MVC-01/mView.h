#ifndef M_VIEW_H
#define M_VIEW_H
//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           mView.h
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//==========================================================

#include <QtGui>
#include <QtWidgets>
#include <time.h>
#include "mythread.h"
#include "mControl.h"
#include "stdlib.h"

class mControl;

class mView : public QWidget
{
    Q_OBJECT
public:    
    mView(QWidget *parent = 0);    
    ~mView(){};

    int GetRNDValue();

    QString mName;

    QLineEdit* line3;
    QLineEdit* lnMSTime;
    
    QPushButton *btnExit;
    QPushButton *btnRun;
    QPushButton *btnInitArr;
    QPushButton *btnRNDArr;
    QPushButton *btnCalcArr;
    QPushButton *btnStartThread ;
    QTextEdit   *editBoxRun;

    MyThread m_thread;

    void getControlPointer(mControl *pCtr);
    void _show();
    void showResult(std::vector<int> nArray);
    void appendStrEditBox(std::string strToApp);
    void setRunBtnName(std::string name);
    void cmdDestroy();

    void initDialog();
    void initButtons();
    void initWidgets();
    void initDlgLayouts();
    void initConnections();    

public slots:
    void setValue();
    void onExit ();
    void StartMyThread();
    void onInitArray();
    void onCalcArray();
    void onStartThread();
    void onRNDArray();
    void onRun();    
    // int GetRNDValue();
private:
    mControl *pControl;
};

#endif 


