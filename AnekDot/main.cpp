#include "anekdot.h"
#include <QtGui>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(new QCleanlooksStyle);
    anekdot w;
    w.show();    
    return a.exec();
}
