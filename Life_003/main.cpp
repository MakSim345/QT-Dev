//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           main.cpp
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
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
