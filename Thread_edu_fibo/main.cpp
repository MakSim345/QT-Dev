//#include "mythwidget.h"
#include "fib_widget.h"

#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fib_widget w;
    
    w.show();
    
    return a.exec();
}
