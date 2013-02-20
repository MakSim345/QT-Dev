#include "myButton.h"

MyButton::MyButton(const QString &text, QWidget *parent)
    : QPushButton(parent)
{
    setMinimumSize(150, 50);
    setText (text);
}

void MyButton::getThreadPointer(MyThread *pThr)
{
    m_pThr = pThr;
    setConnections();
}

void MyButton::setConnections()
{
    connect(m_pThr, SIGNAL(thEvent(int)), this, SLOT (recSignal(int), Qt::QueuedConnection) );
}

void MyButton::recSignal(int i)
{
    qDebug() << "MyButton receives event........";
    setText ("Press to EXIT!!");
}

