#include <QtGui>
#include <QtGui/QApplication>
#include "gui_eve.h"
#include "gen.h"

#include "eve_main.h"

//#include "utils.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    EVEMainClass EVE_Core;

    MainClass w;
    w.setWindowTitle("SW Pilot project GUI");
    w.show();
    
    return a.exec();
    
}
