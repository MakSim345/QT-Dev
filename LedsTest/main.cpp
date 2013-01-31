/* main.cpp */
#include <QtGui>
#include <iostream>
#include "mywidget.h"
 
  int main (int argc, char** argv)
  {
      QApplication *qapp; 
      qapp = new QApplication (argc, argv); 
      MyWidget *myw;
      myw = new MyWidget ();      
      myw->show (); 
      std::cout << "my output" << std::endl;
      return qapp->exec (); 
  }