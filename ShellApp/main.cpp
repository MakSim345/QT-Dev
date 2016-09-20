/*
#include <QApplication>
#include <QwwRichTextButton>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  QwwRichTextButton b;
  b.setText("<B>Hello</B> <font color='red'>world</font>");
  b.show();
  return app.exec();
}
*/

#include <QApplication>
#include <QPushButton>
#include "shell.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   
   // QPushButton hello("Hello world!");
   MyWidget wgMyWidget;
   Shell wgMyShell;
   //  hello.resize(100, 30);   
   wgMyWidget.show();
   wgMyShell.show();
   
   return app.exec();
}
 