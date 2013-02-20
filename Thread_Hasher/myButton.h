#ifndef _MY_BUTTON_H_
#define _MY_BUTTON_H_

#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QVBoxLayout>

#include "MyThread.h"

class MyButton : public QPushButton
{
  Q_OBJECT
  public:   
    MyButton(const QString &text, QWidget * parent = 0);
    void getThreadPointer(MyThread*);
    void setConnections();
  
    MyThread *m_pThr;
 
  public slots:  
    void recSignal(int);

};

#endif

