#include "find_dialog02.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindDialog w;
    w.show();
    return a.exec();
}
