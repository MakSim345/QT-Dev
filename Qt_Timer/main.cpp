#include "QtTimer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtTimer w;
    w.show();
    return a.exec();
}
