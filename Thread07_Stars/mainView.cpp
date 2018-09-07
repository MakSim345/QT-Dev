//============================================================
//
//
//============================================================
//
// File:           mainView.cpp
//
//============================================================
// Description:
//============================================================
#include "mainView.h"

mainView::mainView(QWidget *parent)
     : QWidget(parent)
 {
    w_thread = new Worker();
    img_thread = new timeConsumingThread();
    setWindowTitle(tr("Simple Threading Example"));
    initWidgets();
    initLayouts();
    setConnections();
    //setFixedSize(550, 420);

    QImage img_Image(600, 600, QImage::Format_RGB32);
    img_Image.fill(Qt::black);
    addImage(img_Image);

    //pixmap = new QPixmap(imageWindow->size());
    //pixmap->fill(Qt::black);
    // imageWindow->set->setPixmap(*pixmap);
 }

void mainView::initLayouts()
{
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(lblNumOfStars, 0, 0);
    mainLayout->addWidget(spinBox, 0, 1);
    mainLayout->addWidget(btnStart, 0, 3);
    mainLayout->addWidget(btnQuit, 3, 3);
    mainLayout->addWidget(imageWindow, 2, 0, 2, 3);
    setLayout(mainLayout);
}

void mainView::initWidgets()
{
    lblNumOfStars = new QLabel(tr("Number Of Stars:"));
    spinBox = new QSpinBox();
    spinBox->setMaximum(10000);
    spinBox->setValue(100);    
    //spinBox.setMinimumSize(100, 35)
    
    // imageWindow = new QLabel(tr("The imageWindow"));
    imageWindow = new ImageWindow();
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

    connect(img_thread, SIGNAL(finished()), this, SLOT (updateUI()));
    connect(img_thread, SIGNAL(terminated()), this, SLOT (updateUI()));
    
    // connect(img_thread, SIGNAL(theImage(const QImage &)), this, SLOT(addImage(const QImage &)));
    
    // connect(img_thread, SIGNAL(theImage(QRect, const QImage &)), this, SLOT(addImage(QRect, const QImage &)));

    connect(w_thread, SIGNAL(output(QRect, const QImage &)), this, SLOT(addImage(QRect, const QImage &)));
    

    connect(btnStart, SIGNAL(clicked()), this, SLOT (makePicture()));
    connect(btnQuit, SIGNAL(clicked()), this, SLOT (wExit()));
}


void mainView::test_foo()
{
 qDebug("void mainView::test_foo()");
}

// display the QImage
void mainView::addImage(const QImage &image)
{
   imageWindow->plot = QPixmap::fromImage(image);
   //imageWindow->show();
   imageWindow->update();
   //imageWindow->raise();
   //imageWindow->activateWindow();
}

void mainView::addImage(QRect rect, const QImage &image)    
{
    //const QPixmap *pixmap = imageWindow->pixmap();
    // QPixmap pixmap(imageWindow->pixmap());
    //qDebug("rect = %d, %d \n", rect.x(), rect.y());
    imageWindow->plot = QPixmap::fromImage(image);
    imageWindow->rect_plot_to_drow = rect;
    //imageWindow->update(rect);
    imageWindow->update();

#ifdef YS_TEST_16SEP2011    
    QPixmap pixmap(imageWindow->size());    
    QPainter *painter = new QPainter();
    painter->begin(&pixmap);
    painter->drawImage(rect, image);
    painter->end();
    imageWindow->update(rect);
#endif
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
    w_thread->render(imageWindow->size(), spinBox->value());    
    //img_thread->start();    
 }

void mainView::StartMyThread()
 { 
   //m_thread.start();
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

