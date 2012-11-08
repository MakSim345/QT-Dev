#include <QtGui/QApplication>
#include "mainWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget w = mainWidget();
    w.show();
    w.setGeometry(100, 100, 500, 355);
    return a.exec();
}
