#include <QtGui>
#include <QApplication>
#include "mainWidget.h"

int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    
    ICSWidgetPB win;    
	win.show(); 
    //app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
