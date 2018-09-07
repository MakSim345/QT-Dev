//============================================================
//
//
//============================================================
//
// File:           main.cpp
//
//============================================================
// Description:
//============================================================
#include "lifeWidget.h"
#include "mainView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainView *w = new mainView();    
    a.connect(w->bQuit, SIGNAL( clicked() ), &a, SLOT( quit() ) );    
    w->show();
    return a.exec();
}
