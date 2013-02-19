#include "spinbusyindicator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BusyIndicator w;
    w.show();
    return a.exec();
}


