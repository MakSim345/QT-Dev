//============================================================
//
//
//============================================================
//
// File:           mControl.h
//
//============================================================
// Description:
//============================================================

#include "mControl.h"

mControl::mControl(mModel *pointerToModel, mView *pointerToView)
{        
    // mName = 'mControl component'
    __goOn = true;
    pModel = pointerToModel;
    pView = pointerToView;
    pointerToView->_show();
    actionFlag = false;
    setPointerToModelView();
}

mControl::mControl()
{   

}


void mControl::run()
{

}

void mControl::setON(bool n = true)
{
    __goOn = n;
     // printf (setON: __goOn set to ',  __goOn);
}

void mControl::kill ()
{
    setON(false);
    // time.sleep(0.1) // wait for thread shutdown!
}
    
void mControl::setActionFLag(bool bVal)
{
    actionFlag = bVal;
}

void mControl::setPointerToModelView()
{
    //gives pointer to model and view components
    pModel->getControlPointer(this);
    pView->getControlPointer(this);
    //connect( pView, QtCore.SIGNAL("SIG_pControl_calcArray"),  calcArray);
}

void mControl::showView()
{
    pView->_show();
    pModel->startTimer();
}

    
void mControl::showResult(std::vector<int> val)
{
    pView->showResult(val);
}

void mControl::appendStrEditBox(std::string strToApp)
{
    pView->appendStrEditBox(strToApp);
}

void mControl::setRunBtnName(std::string strName)
{
    pView->setRunBtnName(strName);
}

void mControl::cmdDestroy()
{
    pView->cmdDestroy();
    kill();
    //QtCore.quit()
}

void mControl::calcArray()
{
    //print "Control: calcArray() - calls model"
    //pModel->calcArray()
    //pModel->calcArray_th()
    setActionFLag(1);
}

void mControl::startThread()
{
    //print "Control: startThread() - calls model"
    pModel->startThread();
    //pModel->calcArray_th()
}
        
void mControl::initArray()
{
    //print "Control: initArray() - calls model"
    pModel->initArray();
    //pModel->initArray_th()
}
    
void mControl::RNDArray()
{
    pModel->RNDArray();
    //pModel->RNDArray_th()
}
    
void mControl::onRun()
{
    //function linked to "Run/Stop" button press event
    pModel->onRun();
}   
    
void mControl::onExit()
{
    //function linked to "Exit" button press event
    pModel->onExit();
}


