#include <QtGui>
#include <QApplication>
#include <QLabel>
#include <QScrollBar>
#include <QPushButton>
#include <QVBoxLayout>
#include "customwidget.h"
 
 
int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     QWidget wgt;
     CustomWidget *pcw = new CustomWidget();
     QScrollBar *phsb = new QScrollBar(Qt::Horizontal);
     phsb->setRange(0, 100);
     
     QPushButton *bQuit = new QPushButton("&Exit");


     QObject::connect(phsb, SIGNAL(valueChanged(int)), pcw, SLOT(slotSetProgress(int)) );
     QObject::connect(bQuit, SIGNAL(clicked()), &wgt, SLOT(close() ));
     // layout setup:
     QVBoxLayout *pvbxLayout = new QVBoxLayout();

     pvbxLayout->addWidget(pcw);
     pvbxLayout->addWidget(phsb);
     pvbxLayout->addWidget(bQuit);
     
     wgt.setLayout(pvbxLayout);

     wgt.show();
     return app.exec();
 } 

