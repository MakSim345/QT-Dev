#include "mainView.h"

mainView::mainView(QWidget *parent)
     : QWidget(parent)
 {
    w_thread = new Worker();
    setWindowTitle(tr("Simple Threading Example"));
    initWidgets();
    initLayouts();
    setConnections();
    setFixedSize(550, 420);

    pixmap = new QPixmap(viewer->size());
    pixmap->fill(Qt::black);
    viewer->setPixmap(*pixmap);
 }

void mainView::initLayouts()
{
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(lblNumOfStars, 0, 0);
    mainLayout->addWidget(spinBox, 0, 1);
    mainLayout->addWidget(btnStart, 0, 3);
    mainLayout->addWidget(btnQuit, 3, 3);
    mainLayout->addWidget(viewer, 2, 0, 2, 3);
    setLayout(mainLayout);
}


void mainView::initWidgets()
{
    lblNumOfStars = new QLabel(tr("Number Of Stars:"));
    spinBox = new QSpinBox();
    spinBox->setMaximum(10000);
    spinBox->setValue(100);    
    //spinBox.setMinimumSize(100, 35)
    
    viewer = new QLabel(tr("The Viewer"));
    btnStart = new QPushButton(tr("&Start"));
    btnStart->setMinimumSize(100, 35);
    btnQuit =  new QPushButton (tr("&Exit"));
    btnQuit->setMinimumSize(100, 35); 

    //bQuit->setFont(QFont("Courier", 18, QFont::Bold));
    //bRnd->setFont(QFont("Courier", 18, QFont::Bold));
    //bCountDown->setFont(QFont("Courier", 18, QFont::Bold));
}

void mainView::setConnections()
{
    //And connect the action to the event "button has been clicked"
    
    connect(w_thread, SIGNAL(finished()), this, SLOT (updateUI()));
    connect(w_thread, SIGNAL(terminated()), this, SLOT (updateUI()));
    connect(w_thread, SIGNAL(output(QRect, QImage)), this, SLOT(addImage(QRect, QImage)));

    connect(btnStart, SIGNAL(clicked()), this, SLOT (makePicture()));
    connect(btnQuit, SIGNAL(clicked()), this, SLOT (wExit()));
}


void mainView::test_foo()
{
 qDebug("void mainView::test_foo()");
}

void mainView::addImage(QRect rect, QImage image)
{
    //const QPixmap *pixmap = viewer->pixmap();
    // QPixmap pixmap(viewer->pixmap());
    
    QPixmap pixmap(viewer->size());    
    QPainter *painter = new QPainter();
    painter->begin(&pixmap);
    painter->drawImage(rect, image);
    painter->end();
    viewer->update(rect);
}

void mainView::updateUI()
{
    spinBox->setReadOnly(false);
    btnStart->setEnabled(true);
}

void mainView::makePicture()
{
    spinBox->setReadOnly(true);
    btnStart->setEnabled(false);
    pixmap = new QPixmap(viewer->size());
    pixmap->fill(Qt::black);
    viewer->setPixmap(*pixmap);
    w_thread->render(viewer->size(), spinBox->value());    
 }

void mainView::StartMyThread()
 { 
   //m_thread.start();
   // makePicture();    
 }

void mainView::setValue()
{
    QApplication::beep();
}

int mainView::GetRNDValue()
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

void mainView::wExit()
{
 close();
}

//*****************************************************
#ifdef YS_TEST_15_SEP_2011

        
    def keyPressEvent( event):
        if event.key() == QtCore.Qt.Key_Escape:
            close()
        
    def sayHello(:
        print "Hello, World!"
#endif

