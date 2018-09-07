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
#include "mainView.h"
#include "starsMainView.h"
#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MandelbrotWidget w;
    //starsMainView w;
    w.show();
    return a.exec();
}
