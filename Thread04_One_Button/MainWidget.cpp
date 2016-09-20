#include <QtCore>
#include <QApplication>
#include "MyThread.h"
#include "MainWidget.h"

MyWidget::MyWidget(const QString &text, QWidget *parent)
    : QPushButton(parent)
  {
      setMinimumSize(150, 50);
      setText (text);
  }

void MyWidget::getThreadPointer(MyThread *pThr)
{
  m_pThr = pThr;
  setConnections();
}

void MyWidget::setConnections()
{
  connect(m_pThr, SIGNAL(thEvent(int)), this, SLOT (recSignal(int), Qt::QueuedConnection) );
}

void MyWidget::recSignal(int i)
  {
    //printf  ("MyWidget receives event........\n");
    setText ("Press Me NOW!!");
  }

