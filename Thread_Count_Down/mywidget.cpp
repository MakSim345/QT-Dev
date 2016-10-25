#include <QtCore>
#include <QApplication>
#include "MyThread.h"
#include "myWidget.h"
#include <iostream>

myWidget::myWidget(const QString &text, QWidget *parent)
: QPushButton(parent)
{
    setMinimumSize(150, 50);
    setText (text);
    std::cout << "myWidget constructor" << std::endl;
}

void myWidget::getThreadPointer(MyThread *pThr)
{
    m_pThr = pThr;
}

void myWidget::setConnections()
{
    //connect(m_pThr, SIGNAL(thEvent()), this, SLOT (recSignal(), Qt::QueuedConnection) );
    //connect(m_pThr, SIGNAL(thEvent(int)), this, SLOT (recSignal(), Qt::QueuedConnection) );
    connect(m_pThr, SIGNAL(thEvent(int)), this, SLOT (recSignal()) );
    
}

void myWidget::recSignal(void)
{
    //printf  ("myWidget receives event........\n");
    std::cout << "myWidget receives event........" << std::endl;
    setText ("Press Me NOW!!");
}

