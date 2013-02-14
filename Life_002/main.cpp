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
    QApplication a(argc, argv);
    mainView *w = new mainView();    
    a.connect(w->bQuit, SIGNAL( clicked() ), &a, SLOT( quit() ) );    
    w->show();
    return a.exec();
}
