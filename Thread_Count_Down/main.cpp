#include "mywidget.h"
#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QVBoxLayout>
#include <QProgressBar>
#include <stdio.h>
#include "MyThread.h"
#include <iostream>

using namespace std;

int main (int argc, char ** argv)
{
    // QCoreApplication app (argc, argv);
    QApplication app (argc, argv);
    QWidget *mainWindow = new QWidget();
    QVBoxLayout *vlayout = new QVBoxLayout();	 
    // QHBoxLayout *hlayout = new QHBoxLayout;    
    QProgressBar *prb = new QProgressBar();
    ThreadSignal *thrd = new ThreadSignal();
    
    myWidget* newButton = new myWidget("Do Not press");
    std::cout << "In BasicDataChannel run" << std::endl;

    //printf ("START main application\n");    
    MyThread *mythread = new MyThread("24ClockEffect1.wav");    

    vlayout->addWidget(newButton);
    vlayout->addWidget(prb);
    mainWindow->setLayout(vlayout);
    mainWindow->show();

    newButton->getThreadPointer(mythread);
    newButton->setConnections();

    QObject::connect(newButton, SIGNAL(clicked()), &app, SLOT (quit()) );
    //QObject::connect(newButton, SIGNAL(clicked()), &app, SLOT (setName(int)) );
    //QObject::connect(thrd, SIGNAL(progress(int)), prb, SLOT(setValue(int)) );
    //QObject::connect(mythread, SIGNAL(thEvent(int)), newButton, SLOT (recSignal()));
    QObject::connect(mythread, SIGNAL(thEvent(int)), prb, SLOT (setValue(int) ));
    //QObject::connect(mythread, SIGNAL(thEvent(int)), &app, SLOT (quit() ));

    mythread->start();
    //thrd->start();

    return app.exec();
}
