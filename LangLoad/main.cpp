#include "gen.h"
#include "LangLoad.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LangLoad llUi;
    llUi.show();

    return a.exec();
}