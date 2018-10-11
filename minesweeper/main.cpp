#include <QtWidgets/QApplication>
#include "mainView.h"
#include "gen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::unique_ptr <mainView> window(new mainView());

    window->setWindowTitle("Minesweeper");
    window->show();
    a.connect(window->bQuit, SIGNAL( clicked() ), &a, SLOT( quit() ) );
    
    return a.exec();
}
