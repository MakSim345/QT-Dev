#include <QApplication>
#include <QLabel>
// #include "AeroButton.h"
#include "MyWidget.h"


int main( int argc, char *argv[] )
{
    QApplication app(argc, argv);
    MyWidget window;
    //QLabel my_label("Hello world!");
    //my_label.show();
    // connect(quit, SIGNAL(clicked()), qApp, SLOT(closeApp() ));
    window.show();
    return app.exec();
}
