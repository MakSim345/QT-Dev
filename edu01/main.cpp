#include <QtGui>
#include <QApplication>
#include <QWidget>
#include <QRect>
#include "mainView.h"


int main (int argc, char **argv)
{

	QApplication app(argc,argv);

    QWidget *w = new mainView();
    
    // put application to center:
    //QRect scr = QApplication::desktop()->screenGeometry();
    //w->move( scr.center() - w->rect().center() ); 
    w->show();
    return app.exec();
}


/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageButton w;
    w.show();
    return a.exec();
}
*/