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
    QApplication app(argc, argv);
    // lifeWidget w;
    mainView w;
    //starsMainView w;
    
    w.show();
    return app.exec();
}
