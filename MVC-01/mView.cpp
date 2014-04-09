#include "mView.h"

mView::mView(QWidget *parent)
     : QWidget(parent)
 {
    setWindowTitle(tr("Test thread project"));
    setFixedSize(550, 420);
    mName = "mView component";
    // connect(bQuit, SIGNAL(clicked()), qApp, SLOT(quit()));    
    initDialog();
 }

void mView::initDlgLayouts()
{
    QHBoxLayout *mainLayout = new QHBoxLayout();
    QVBoxLayout *buttonsLayout = new QVBoxLayout();

    buttonsLayout->addWidget(btnRun);
    buttonsLayout->addWidget(btnInitArr);
    buttonsLayout->addWidget(btnRNDArr);
    buttonsLayout->addWidget(btnCalcArr);
    buttonsLayout->addWidget(btnStartThread);
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(btnExit);
    
    mainLayout->addWidget(editBoxRun);
    mainLayout->addLayout(buttonsLayout);
    
    setLayout(mainLayout);
}

void mView::initDialog()
{
    initButtons();
    initWidgets();
    initDlgLayouts();
    initConnections();
    setMinimumSize(700, 400);
}

void mView::initConnections()
{
    connect(btnRun,         SIGNAL(clicked()), this, SLOT(onRun()));
    connect(btnInitArr,     SIGNAL(clicked()), this, SLOT(onInitArray()));
    connect(btnRNDArr,      SIGNAL(clicked()), this, SLOT(onRNDArray()));
    connect(btnCalcArr,     SIGNAL(clicked()), this, SLOT(onCalcArray()));
    connect(btnStartThread, SIGNAL(clicked()), this, SLOT(onStartThread()));
    connect(btnExit,        SIGNAL(clicked()), this, SLOT(onExit()));
}

void mView::initButtons()
{
    btnExit = new QPushButton("&Exit");
    btnRun = new QPushButton();
    setRunBtnName("&Run");
    btnInitArr = new QPushButton("&Init Array");
    btnRNDArr = new QPushButton("&RND Array");
    btnCalcArr = new QPushButton("&Calc Array");
    btnStartThread = new QPushButton("&Start Thread");
}

void mView::setRunBtnName(std::string name)
{
    btnRun->setText(QString::fromStdString(name)); 
}

void mView::initWidgets()
{
    editBoxRun = new QTextEdit();   
}

void mView::getControlPointer(mControl *pCtr)
{
    //pControl = pCtr;
    // connect(self.btnCalcArr,  QtCore.SIGNAL("clicked()"), self.pControl.calcArray)
    // qDebug(mName, " obtain pointer to ", pControl.mName);
}
    
void mView::onCalcArray()
{
    // - pControl.calcArray()

    //print "Emit signal SIG_pControl_calcArray."
    // emit( QtCore.SIGNAL("SIG_pControl_calcArray")
}

void mView::onInitArray()
{
    //print "View: initArray() - START"
    //pControl.initArray()
    //print "View: initArray() -  STOP"
}

void mView::_show()
{
    show();
    //self.exec_()
}
    
void mView::onStartThread()
{
    //pControl.startThread();
}

void mView::onRNDArray()
{
    // pControl.RNDArray();
}

void mView::onRun()
{
    pControl->onRun();
}
    
void mView::onExit()
{
    pControl->onExit();
}
    
void mView::showResult(std::vector <int> nArray)
{
    /*
    if not nArray:
            print "nArray = 0, init with 100 serial numbers"
            nArray = range(100)

    print "View: showResult for ", nArray.__len__()
    stamp = (str(nArray))
    self.appendStrEditBox(stamp)
    */ 
}   
void mView::appendStrEditBox(std::string strToApp)
{
    //stamp = (str(strToApp));
    editBoxRun->append(QString::fromStdString(strToApp));
    //editBoxRun->append(stamp);
}

void mView::cmdDestroy()
{
    close();
}

void mView::StartMyThread()
 {
   //m_thread.setMValue( lcd->intValue() );
   //m_thread.start();
 }

void mView::setValue()
{
 QApplication::beep();
}

int mView::GetRNDValue()
{
int nRetVal=0;
static int nFirstTime = 1;

#ifdef QT_RND_SERVER

 if (1 == nFirstTime)
 {
  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
  nFirstTime = 0;
 }
 nRetVal = (int)qrand();

#else

 int RND_MAX = 65;

 if (1 == nFirstTime)
 {
  srand (time (NULL));
  nFirstTime = 0;
 }
 nRetVal = 1 + (rand() % RND_MAX);

 //qDebug() << "Time: " << nRetVal;
 //qDebug() << "Execution done";
#endif

return nRetVal;
}

