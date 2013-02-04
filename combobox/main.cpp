#include <QtGui>
#include <QPushButton>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton button (QString::fromLocal8Bit("&Close"));
    button.setFont(QFont("Arial", 16, QFont::Bold));
    QObject::connect(&button,
                     SIGNAL(clicked()),
                     &app,
                     SLOT(quit()) );
    QString s =
            "QComboBox {"
            "   border: 1 px solid gray;"
            "   border-radius: 3px;"
            "   padding: 1px, 18px, 1px, 3px;"
            "   min-width: 16em;"
            "   }"
            "QComboBox::editable {"
            "   background: white;"
            "}"

            "QComboBox:!editable, QComboBox::drop-down:editable {"
            "   background: qlineargradient("
            "       x1: 0, y1: 0, x2: 0, y2: 1,"
            "       stop: 0   #E1E1E1,"
            "       stop: 0.4 #DDDDDD,"
            "       stop: 0.5 #D8D8D8,"
            "       stop: 1.0 #D3D3D3);"
            "}"

            "QComboBox:!editable:on, QComboBox::drop-down:editable:on {"
            "   background: qlineargradient("
            "       x1: 0, y1: 0, x2: 0, y2: 1,"
            "       stop: 0   #D3D3D3,"
            "       stop: 0.4 #D8D8D8,"
            "       stop: 0.5 #DDDDDD,"
            "       stop: 1.0 #E1E1E1);"
            "}"

            // shift text in open list:
            "QComboBox::on {"
            "   padding-top: 3px;"
            "   padding-left: 3px;"
            "}"



            "QComboBox:down-arrow {"
            "   image: url(downarrow.png);"
            "}"
            "QComboBox::down-arrow:on {"
            "   top: 1px;"
            "   left: 1px;"
            "}";
    app.setStyleSheet(s);
    //QApplication::setGlobalStrut(QSize(100, 50));
    QWidget widget;
    QVBoxLayout *layout = new QVBoxLayout(&widget);
    QComboBox *cb = new QComboBox(&widget);
    cb->setFont(QFont("Arial", 16, QFont::Bold));
    cb->addItem("1 line");
    cb->addItem("2 line");
    cb->addItem("3 line");
    cb->addItem("4 line");
    layout->addWidget(cb);
    layout->addWidget(&button);

    widget.show();
    return app.exec();
}
