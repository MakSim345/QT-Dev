#include "gen.h"
#include "TurboButton.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QApplication::setStyle(new QCleanlooksStyle);
    TurboButton w;    
    w.show();
    return a.exec();
}

