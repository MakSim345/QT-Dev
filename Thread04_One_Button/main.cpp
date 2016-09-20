// #include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>

#include <stdio.h>
#include "MyThread.h"
#include "MainWidget.h"

int main (int argc, char ** argv)
{
    // QCoreApplication app (argc, argv);
    QApplication app (argc, argv);
    QWidget *mainWidget = new QWidget();
    QVBoxLayout *vlayout = new QVBoxLayout();	 
	// QHBoxLayout *hlayout = new QHBoxLayout;    
    QProgressBar *prb = new QProgressBar();
    ThreadSignal *thrd = new ThreadSignal();
    MyWidget* b = new MyWidget("Do Not press");
    
    //printf ("START main application\n");    
    MyThread *mythread = new MyThread();    

    mythread->start();
    thrd->start();
    
    //b->show();
    //prb->show();
    vlayout->addWidget(b);
    vlayout->addWidget(prb);
    mainWidget->setLayout(vlayout);
    mainWidget->show();
    
    b->getThreadPointer(mythread);
    //b->setConnections();

    QObject::connect(b, SIGNAL(clicked()), &app, SLOT (quit()) );
    //QObject::connect(thrd, SIGNAL(progress(int)), prb, SLOT(setValue(int)) );
	QObject::connect(mythread, SIGNAL(thEvent(int)), prb, SLOT (setValue(int) ));
    
    return app.exec();
}
