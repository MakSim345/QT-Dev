#include <QtGui>
#include <QtCore>
#include <stdio.h>
#include "HasherWidget.h"

int main (int argc, char ** argv)
{
    QApplication app (argc, argv);
    QWidget *mainWidget = new HasherWidget();    
    mainWidget->setMinimumSize(500, 150);
    mainWidget->show();
    return app.exec();
}
