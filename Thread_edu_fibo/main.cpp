#include "fib_widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fib_widget w;
    
    w.show();
    
    return a.exec();
}
