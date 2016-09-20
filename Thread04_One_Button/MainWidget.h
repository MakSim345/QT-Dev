#ifndef _MAINWIDGET_
#define _MAINWIDGET_

#include <QPushButton>
#include "MyThread.h"

class MyWidget : public QPushButton
{
  Q_OBJECT
  public:   
    MyWidget(const QString &text, QWidget * parent = 0);
    void getThreadPointer(MyThread*);
    void setConnections();
  
    MyThread *m_pThr;
 
  public slots:  
    void recSignal(int);

};

#endif

