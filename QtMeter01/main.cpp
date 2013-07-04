#include "mainWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    mainWidget win;
    win.setWindowTitle("GUI - Ventialtor visualization widgets. V 0.0.2");
	win.show(); 
    
    return a.exec();
}
