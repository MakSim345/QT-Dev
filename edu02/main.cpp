#include "mywin.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //QTextCodec *codec = QTextCodec::codecForName("CP1251");
    //QTextCodec::setCodecForLocale(codec);

    MyWin win(QString::fromLocal8Bit("�� ����"));
    // MyWin win(QObject::tr("�� ����"));
    win.show();
    return app.exec();
}
