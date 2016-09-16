#include "AeroButton.h"
#include <QtWidgets/QApplication>
#include "MyWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget window;
    //QLabel my_label("Hello world!");
    //my_label.show();
    // connect(quit, SIGNAL(clicked()), qApp, SLOT(closeApp() ));
    window.show();
    return app.exec();
    
    /*
    QApplication a(argc, argv);
    AeroButton w;
    w.show();
    return a.exec();
    */
}
