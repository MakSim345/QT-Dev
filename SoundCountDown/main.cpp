#include <QApplication>
#include <QWidget>
#include <QMessageBox>
#include <QtMultimedia/QSound>
#include <QHBoxLayout>
#include <QProgressBar>

#include <stdio.h>
#include "countDownThread.h"
#include "mywidget.h"
#include <iostream>

using namespace std;

int main (int argc, char ** argv)
{
    QApplication app (argc, argv);
    QWidget *mainWindow = new QWidget();
    QVBoxLayout *vlayout = new QVBoxLayout();	 
    QProgressBar *prb = new QProgressBar();
    
    myWidget* newButton = new myWidget("Do Not press");

    countDownThread *cntDwnThread = new countDownThread();    
    
    cntDwnThread->setFileUp  ("alarmEtCO2.wav");
    cntDwnThread->setFileDown("alarmEtCO2.wav");
    // cntDwnThread->setFileUp("24ClockEffect1.wav");
    //cntDwnThread->setFileDown("24ClockEffect2.wav");
    

    cntDwnThread->start();

    vlayout->addWidget(newButton);
    vlayout->addWidget(prb);
    mainWindow->setLayout(vlayout);
    mainWindow->show();

    newButton->getThreadPointer(cntDwnThread);
    newButton->setConnections();

    QObject::connect(newButton, SIGNAL(clicked()), &app, SLOT (quit()) );
    //QObject::connect(newButton, SIGNAL(clicked()), &app, SLOT (setName(int)) );
    //QObject::connect(thrd, SIGNAL(progress(int)), prb, SLOT(setValue(int)) );
    //QObject::connect(countDownThread, SIGNAL(thEvent(int)), newButton, SLOT (recSignal()));
    //QObject::connect(countDownThread, SIGNAL(thEvent(int)), prb, SLOT (setValue(int) ));
    //QObject::connect(cntDwnThread, SIGNAL(thEvent(int)), &app, SLOT (quit() ));

    return app.exec();
}
