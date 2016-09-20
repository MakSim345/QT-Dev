#ifndef _MY_WIDGET_
#define _MY_WIDGET_

#include <QtGui>
#include <QtCore>
#include <QApplication>
#include <QPushButton>
#include <countDownThread.h>

class myWidget : public QPushButton
{
    Q_OBJECT
public:   
    myWidget(const QString &text, QWidget * parent = 0);
    void getThreadPointer(countDownThread*);
    void setConnections();

    countDownThread *m_pThr;

    public slots:  
        void recSignal(void);

};

#endif


