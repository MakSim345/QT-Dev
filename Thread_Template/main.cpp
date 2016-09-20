#include "mythwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyThWidget w;
    w.show();
    return a.exec();
}
