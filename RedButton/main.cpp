#include <redbutton.h>
#include <QApplication>

int main(int argc, char *argv[])
{ 
    QApplication app(argc,argv);
    RedButton redb;
    redb.show();
    return app.exec();
}
