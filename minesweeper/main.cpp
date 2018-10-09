#include <QtWidgets/QApplication>
#include "minesweeper.h"
#include "gen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    qDebug() << "DEBUG";
    // qDebug() ("DEBUG");    
    // qWarning() ("WARNING");
    Minesweeper window;
    window.setWindowTitle("Minesweeper");
    window.show();
    return a.exec();
}
