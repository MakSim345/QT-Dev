#include "candydialog.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file(":/candy.qss");
    file.open(QFile::ReadOnly);
    app.setStyleSheet(file.readAll());
    
    CandyDialog dialog;
    dialog.show();

    return app.exec();
}
