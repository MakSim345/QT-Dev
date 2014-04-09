#ifndef _M_CONTROL_H_
#define _M_CONTROL_H_
//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           mControl.h
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//==========================================================

#include "mythread.h"
#include "mView.h"
#include "mModel.h"
#include "FTime.h"
#include <stdlib.h>

class mModel;
class mView;

class mControl
{
public:
    mControl(mModel *pModel, mView *pView);
    mControl();
    ~mControl() {};

    void run();
    void setON(bool n);
    void kill ();
    void setActionFLag(bool bVal);
    void setPointerToModelView();
    void showView();
    void showResult(std::vector<int> val);
    void appendStrEditBox(std::string strToApp);
    void setRunBtnName(std::string strName);
    void cmdDestroy();
    void calcArray();
    void startThread();
    void initArray();
    void RNDArray();
    void onRun();
    void onExit();

    mModel *pModel;
    mView  *pView;

private:
    int m_FileIsOpen;
	int m_TraceToFile;
	int m_TraceToCons;
    // string mName = 'mControl component'
    bool __goOn;
    bool actionFlag;

    
    

};

#endif
