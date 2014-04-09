#include <QtWidgets/QApplication>

#include "mainWidget.h"

int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    
    mainWidget win;
	win.show(); 
    //QVUMeter vumeter;
    //vumeter.show();
    //app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    
    return app.exec();
}