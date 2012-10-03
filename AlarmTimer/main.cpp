#include "AlarmWidget.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(new QCleanlooksStyle);
    AlarmWidget w;
    w.show();
    return a.exec();
}
