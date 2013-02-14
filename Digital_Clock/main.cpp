/* ======================================================================
**  main.cpp
** ======================================================================
**
** ======================================================================
**  Copyright (c) 
** ======================================================================
*/
#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QApplication>

 #include "digitalclock.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     DigitalClock clock;
     QIcon *mainWinIcon;
     mainWinIcon = new QIcon();
     mainWinIcon->addFile(":/Clock");
     clock.setGeometry(200, 200, 350, 100);
     clock.setWindowIcon(*mainWinIcon);
     clock.show();
     return app.exec();
 }
 
 