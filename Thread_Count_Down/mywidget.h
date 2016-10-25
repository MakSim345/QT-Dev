#ifndef _MY_WIDGET_
#define _MY_WIDGET_

//#include <QtGui>
//#include <QtCore>
//#include <QApplication>
#include <QPushButton>
#include <myThread.h>

class myWidget : public QPushButton
{
    Q_OBJECT
public:   
    myWidget(const QString &text, QWidget * parent = 0);
    void getThreadPointer(MyThread*);
    void setConnections();

    MyThread *m_pThr;

    public slots:  
        void recSignal(void);

};

#endif


