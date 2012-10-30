#include "battery.h"
#include <QtGui>
#include <QtCore>
#include "MyThread.h"
#include "AnimWidget.h" 

int main(int argc, char* argv[]) 
{
    QApplication app(argc, argv);
    AnimWidget w;
    w.resize(300, 300);
    w.show();
    return app.exec();
}

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *mainWindow = new QWidget();
    WidgetBattery *mBattery = new WidgetBattery();
    QVBoxLayout *vlayout = new QVBoxLayout();	 
    QHBoxLayout *hlayout = new QHBoxLayout();	 
    MyThread *mythread = new MyThread();    

    mBattery->UpdateBatteryStatus(0);
    hlayout->addStretch();
    hlayout->addWidget(mBattery);
    hlayout->addStretch();
    vlayout->addLayout(hlayout);    
    mainWindow->setLayout(vlayout);
    mainWindow->setMinimumSize(200, 150);
    
    mythread->start();
    QObject::connect(mythread, SIGNAL(thEvent(int)), mBattery, SLOT (UpdateBatteryStatus(int) ));

    mainWindow->show();
    return a.exec();
}
*/