#include "calculator.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   
   Calculator calculator;
   calculator.setWindowTitle("QT Calculator");
   calculator.resize(230, 200);
   
   calculator.show();
   
   return app.exec();
}