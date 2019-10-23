#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator mainCalcWindow;
    mainCalcWindow.show();

    return a.exec();
}
