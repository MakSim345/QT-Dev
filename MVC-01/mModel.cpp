//============================================================
//
//============================================================
//
// File:           mModel.cpp
//
//============================================================
// Description:
//============================================================

#include "mModel.h"

mModel::mModel(QWidget *parent)
     : QWidget(parent)
{
    mName = "mModel component";
    f = new FTime();
    nSizeArr = 1000;
    counter = 0;
    state = false;
    timerInterval = 500;        
    initTimer();
    initThread();
}
 
mModel::~mModel()
{
    // TODO:
}

void mModel::initThread()
{
    mythread = new MyThread (100);
    // mythread.getTimerCtr(f);
    connect(mythread, SIGNAL(threadEvent()),  this, SLOT(calcArray));
}

void mModel::initTimer()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(eventTimer)); 
    //print "mModel: initTimer - ok"
}

void mModel::eventTimer()
{
    //function linked to a timer event. 
    counter =  counter + 1;
    QString stamp;
    // stamp = "Sending ping to wachdog - " + str( counter) + " time";
    //print stamp:
    appendStrEditBox(stamp);
}   

void mModel::startTimer()
{
    timer->start(timerInterval);
}

    
void mModel::stopTimer()
{
    timer->stop();
}

void mModel::onExit()
{
    //function linked to "Exit" button press event
    // do some demolition actions before exit...
    // send close event to main form:
    pControl->cmdDestroy();
}
       
void mModel::onRun()
{
// function linked to "Run/Stop" button press event
    state = !state;
    if  (state)
    {
        startTimer();
        setRunBtnName("&Stop");
    }
    else
    {
        stopTimer();
        setRunBtnName("&Run");
    }
}
   
void mModel::setRunBtnName(QString strName)
{
    pControl->setRunBtnName(strName.toStdString());
} 

void mModel::getControlPointer(mControl *pCtr)
{
    //pControl = new mControl();
    pControl = pCtr;
    //void* test = pCtr;
}

void mModel::appendStrEditBox(QString strToApp)
{
    //print "MODEL calls appendStrEditBox..."
    //editBoxRun.append(stamp)
    pControl->appendStrEditBox(strToApp.toStdString());
}

    
void mModel::showResult()
{
    //Sending a pointer to whole array to show it on the view
    //print "MODEL calls showResult..."
    pControl->showResult(mArray);
}  

void mModel::startThread()
{
    //response to pressed button on View: start thread
    mythread->start();
    //print "Model: Thread started."
    // appendStrEditBox("%d - Thread started" % ( f->get1MSTime()));
}

    
void mModel::initArray()
{
    //init array with serial numbers and show it on the view
    long start =  f->get1MSTime();
    // appendStrEditBox("%d - InitArray Calculation starts" % (start));    
    
    long stop =  f->get1MSTime();
    //appendStrEditBox("%d - InitArray Calculation stops" % (stop) );
    //appendStrEditBox("InitArray Calculation takes %d ms" % (stop-start) );
    
    //appendStrEditBox("Result: Array[%d]=%d" % (len( mArray)-1,  mArray[len( mArray)-1]) );
    //appendStrEditBox("%d - InitArray Calculation results show" % ( f->get1MSTime()));
}
        

void mModel::initArray_th()
{
    //thread.start_new_thread ( initArray, ());
}

void mModel::RNDArray()
{
    //fill array with RND numbers and show it on the view
    long start =  f->get1MSTime();
    // appendStrEditBox("%d - RNDArray Calculation starts" % (start) );
    
    for( int i = 0; i < mArray.size(); i++ ) 
    {
        //  mArray.append( mkRnd())
        mArray.push_back(mkRnd());
        // appendStrEditBox( mArray[i])            
    }
    //showResult()    
    
    long stop =  f->get1MSTime();
    //appendStrEditBox("%d - RNDArray Calculation stops" % (stop) );
    //appendStrEditBox("RNDArray Calculation takes %d ms" % (stop-start) );
    //appendStrEditBox("Result: Array[%d]=%d" % (len( mArray)-1,  mArray[len( mArray)-1]) );
    //appendStrEditBox("%d - RNDArray Calculation results show" % ( f.get1MSTime()));
}

void mModel::RNDArray_th()
{
    //thread.start_new_thread ( RNDArray, ());
}


void mModel::calcArray()
{
    // do some heavy calculation with array and show results on the view.
    long start =  f->get1MSTime();
    //print "%d - calcArray Calculation starts" % (start)
    // appendStrEditBox("%d - calcArray Calculation starts" % (start) );
    for( int i = 0; i < mArray.size(); i++ ) 
    {

        // mArray.append( mkRnd())
        // mArray[i] = sqrt( mArray[i])**4
        // mArray[i] = sqrt( mArray[i])*2
        for( int j = 0; j < mArray.size(); j++ ) 
        {
            mArray[i] = sqrt((long double)mArray[j]) * mkRnd();
            //appendStrEditBox( mArray[i])            
            //appendStrEditBox("%d - calcArray Calculation goes on with %d" % ( f.get1MSTime(), i ))
        }
    }
    //showResult()    
    long stop =  f->get1MSTime();
    //appendStrEditBox("%d - calcArray Calculation stops" % (stop) )
    //print "%d - calcArray Calculation stops" % (stop) 
    //appendStrEditBox("calcArray Calculation takes %d ms" % (stop-start) )
    //appendStrEditBox("Result: Array[%d]=%f" % (len( mArray)-1,  mArray[len( mArray)-1]) )
    //appendStrEditBox( mArray[len( mArray)-1] )
    //appendStrEditBox("%d - calcArray Calculation results show" % ( f.get1MSTime()))
}
    
    
void mModel::calcArray_th()
{
  //thread.start_new_thread ( calcArray, ())
}


int mModel::mkRnd()
{
    return 1;// random.randint(1, 1000)
}

void mModel::printDump()
{
    //print  mArray;
}
