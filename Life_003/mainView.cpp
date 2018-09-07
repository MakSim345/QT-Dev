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
     : QWidget(parent),
     timer(new QTimer(this))
 {
    setWindowTitle(tr("Life on Qt4."));
    //setFixedSize(550, 420);
    timer->setInterval(250);
    initWidgets();
    setWidgetLayout();
    setConnections();
 }

void mainView::setWidgetLayout()
{
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *hLayoutInfo = new QHBoxLayout;
    
    hLayoutInfo->addWidget(slider);
    hLayoutInfo->addWidget(lnMSTime);
    hLayoutInfo->addWidget(lnCells);
    hLayoutInfo->addWidget(lnIteration);

    hLayout->addWidget(bRnd);    
    hLayout->addWidget(bStart);
    hLayout->addWidget(bPause);
    hLayout->addWidget(bNextStep);
    hLayout->addWidget(bQuit);
    
    layout->addWidget(lifeWgt);
    layout->addLayout(hLayoutInfo);
    layout->addLayout(hLayout);
    
    setLayout(layout);
}

void mainView::initWidgets()
{
    lifeWgt = new lifeWidget();
    bQuit = new QPushButton(tr("&Quit"));
    bRnd = new QPushButton ("&RND");
    bStart = new QPushButton ("&Start");
    bPause = new QPushButton ("&Pause");
    bNextStep = new QPushButton ("&NextStep");

    bQuit->setFont(QFont("Consolas", 15, QFont::Bold));
    bRnd->setFont(QFont("Consolas", 15, QFont::Bold));
    bStart->setFont(QFont("Consolas", 15, QFont::Bold));
    bPause->setFont(QFont("Consolas", 15, QFont::Bold));
    bNextStep->setFont(QFont("Consolas", 15, QFont::Bold));

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 999);
    slider->setValue(0);

    lnCells =   new QLineEdit (this);
    lnMSTime =  new QLineEdit(this);
    lnIteration = new QLineEdit(this);
}


void mainView::setConnections()
 {
    connect(bQuit, SIGNAL(clicked()), this, SLOT(quit()));
    connect(bStart, SIGNAL(clicked()), this, SLOT(startGame()));
    // connect(bStart, SIGNAL(clicked()), this, SLOT (StartMyThread()));
    connect(bRnd, SIGNAL(clicked ()), this, SLOT (setValue ()));
    // connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    connect(timer, SIGNAL(timeout()), lifeWgt, SLOT(newGeneration()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLabels()));
    
    //QObject::connect (&m_thread, SIGNAL(currentValue(int)), lcd, SLOT(display(int)) );
    //QObject::connect (&m_thread, SIGNAL(finished()), qApp, SLOT(quit()));
 }

void mainView::startGame()
{
   timer->start();
   lifeWgt->startGame();   
}

void mainView::updateLabels()
{
    int value = lifeWgt->getCellsAlive();    
    lnCells->setText(QString::number(value));
}

void mainView::StartMyThread()
{
   //m_thread.setMValue( lcd->intValue() );
   //m_thread.start();
}

 void mainView::setValue()
{
    //lnMSTime->setText(QString::number(GetRNDValue()));
    //lcd->display(lnMSTime->text());
    // lnMSTime->setText(QString::number(Get1msTimeMS() ));
    QApplication::beep();
}

void mainView::onExit()
{
 close();
}
