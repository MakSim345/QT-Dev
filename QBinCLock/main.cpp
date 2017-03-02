/*
 * main.cpp
 */

//#include <QApplication>
#include <QTranslator>
#include <QTextCodec>
#include <QString>

#include "clockapplication.h"
#include "clockframe.h"

int main(int argc, char *argv[])
{
    ClockApplication app(argc, argv);

/*    
    QTranslator translator;
    if(translator.load(QString("qbinclock_") + QTextCodec::locale(), "."))
        app.installTranslator(&translator);
    else
        qWarning(QString("Locale ") + QTextCodec::locale() + QString(" not supported."));
*/
    
    ClockFrame* clock = new ClockFrame();    
    clock->show();
    clock->move(100, 100);
    clock->resize(200, 200);
    
    return app.exec();
}

