/* main.cpp */
 
  #include <qapplication.h>
  #include "mywidget.h"
 
  int main (int argc, char** argv)
  {
      QApplication *qapp;
 
      qapp = new QApplication (argc, argv);
 
      MyWidget myw;
      //myw = new MyWidget ();
      // qapp->setMainWidget (myw);
      myw.show ();
 
      return qapp->exec ();
 
  }