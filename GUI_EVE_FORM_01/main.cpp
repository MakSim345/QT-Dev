 #include <QApplication>

  #include "gui_form.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     GUIForm guiForm;
     guiForm.show();
     
     //QPushButton *quit = new QPushButton(tr("Quit"), this);
     //quit->setGeometry(62, 40, 75, 30);
     //quit->setFont(QFont("Times", 18, QFont::Bold));

     //connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
     return app.exec();
 }