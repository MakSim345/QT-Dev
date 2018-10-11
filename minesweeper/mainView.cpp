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
    setWindowTitle(tr(STR_MAIN_TITLE));
    //setFixedSize(550, 420);
    timer->setInterval(1000);
    initWidgets();
    setWidgetLayout();
    setConnections();
    m_seconds = 0;
    gameOver = false;
    gameWon = false;
    gameStarted = false;
}

void mainView::setWidgetLayout()
{
    QVBoxLayout *layout = new QVBoxLayout;
    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *hLayoutInfo = new QHBoxLayout;
    QHBoxLayout *hLayoutCenter = new QHBoxLayout;

    hLayoutInfo->addWidget(lcdMineCounter);
    hLayoutInfo->addStretch();
    hLayoutInfo->addWidget(btnRedo);
    hLayoutInfo->addStretch();
    hLayoutInfo->addWidget(lcdTimeDisplay);    
    
    //hLayout->addWidget(bStart);    
    // vLayout->addWidget(bNextStep);
    vLayout->addStretch();
    vLayout->addWidget(bQuit);

    hLayoutCenter->addWidget(mineswpWgt);
    hLayoutCenter->addLayout(vLayout);

    layout->addLayout(hLayoutInfo);
    layout->addLayout(hLayoutCenter);
    layout->addLayout(vLayout);

    setLayout(layout);
}

void mainView::initWidgets()
{
    mineswpWgt = new Minesweeper();
    bQuit = new QPushButton(tr("&Quit"));
    btnRedo = new QPushButton ("&Check mines");
    
    bQuit->setFont(QFont("Consolas", 15, QFont::Bold));
    btnRedo->setFont(QFont("Consolas", 15, QFont::Bold));    
    
    lcdTimeDisplay = new QLCDNumber(3);
    lcdTimeDisplay->setSegmentStyle(QLCDNumber::Flat);
    lcdTimeDisplay->setAutoFillBackground(1);    
    lcdTimeDisplay->setStyleSheet("QLCDNumber{color: rgb(255, 9, 9); background-color: rgb(0, 0, 0);}");
    
    lcdMineCounter = new QLCDNumber(3);
    lcdMineCounter->setSegmentStyle(QLCDNumber::Flat);
    lcdMineCounter->setAutoFillBackground(1);
    lcdMineCounter->setStyleSheet("QLCDNumber{color: rgb(255, 9, 9); background-color: rgb(0, 0, 0);}");

    lcdTimeDisplay->display("000");
    lcdMineCounter->display("000");
    btnRedo->setText("&Check mines");
}

void mainView::setConnections()
{
    connect(btnRedo, SIGNAL(clicked ()), this, SLOT (clickBtnRedo()));    
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimerDisplay()));
    
    connect (mineswpWgt, SIGNAL(started()), this, SLOT(startGame()) );
    connect (mineswpWgt, SIGNAL(stopped(bool)), this, SLOT(stopGame(bool)) );
    connect (mineswpWgt, SIGNAL(minesFlagged(int)), this, SLOT(updateMinesDisplay(int)));
}

void mainView::startGame()
{
    gameStarted = true;    
    timer->start();
}

void mainView::stopGame(bool pWinLose)
{
    if (pWinLose)
        btnRedo->setText("Win! - &Restart");
    else
        btnRedo->setText("Loose - &Restart");
    
    gameStarted = false;
    timer->stop();
}

QString mainView::getThreeDigit(int pnumToConvert)
{
    QString retVal = QString::number(pnumToConvert);

    if (pnumToConvert < 100)
    {
        retVal = "0" + QString::number(pnumToConvert);
    }
    if (pnumToConvert < 10)
    {
        retVal = "00" + QString::number(pnumToConvert);
    }    

    return retVal;
}

void mainView::updateMinesDisplay(int pFlaggedMines)
{
    lcdMineCounter->display(getThreeDigit(pFlaggedMines));
}

void mainView::updateTimerDisplay()
{   
    m_seconds++;
    if (m_seconds>999)
    {
        m_seconds = 999;
    }
        
    lcdTimeDisplay->display(getThreeDigit(m_seconds));

    // value = lifeWgt->getCellsAlive();    
    // lnCells->setText(QString::number(value));

    // value = lifeWgt->getLifeIteration();    
    // lnIteration->setText(QString::number(value));
}

void mainView::StartMyThread()
{
    //m_thread.setMValue( lcd->intValue() );
    //m_thread.start();
}

void mainView::clickBtnRedo()
{
    if (gameStarted)
    {
        // call mineswpWgt->checkTheMines();
    }
    else
    {
        lcdTimeDisplay->display("000");
        lcdMineCounter->display("000");
        m_seconds = 0;
        btnRedo->setText("&Check mines");
        mineswpWgt->startNewGame();
    }
}

void mainView::onExit()
{
    close();
}
