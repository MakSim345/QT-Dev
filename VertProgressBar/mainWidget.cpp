#include <QApplication>
#include <QLabel>

#include "mainWidget.h"
#include "customwidget.h"

#ifndef QT_RND_SERVER
 #include <time.h>
#endif 

ICSWidgetPB::ICSWidgetPB(QWidget *parent)
     : QWidget(parent)
 {
     // setFixedSize(450, 300);
	 initWidgets();
	 setStyleSheets();
	 setAllLayouts();
	 setConnectionsWidgets();
	 // this->setMaximumWidth(85);
 }

void ICSWidgetPB::closeApp()
{
 close();
}

void ICSWidgetPB::initWidgets()
{
  
  pcw = new CustomWidget();
  // bQuit = new QPushButton(tr("&Exit"));
  bShowNum = new QPushButton(tr("0"));
  bShowNum->setText(QString().setNum(0));
  bShowNum->setFont(QFont("Arial", 25, QFont::Bold));
  
  // line1 = new QLineEdit();      
  // line1->setText(QString().setNum(0));
  // line1->setFont(QFont("Arial", 25, QFont::Bold));
  // line1->setAlignment(Qt::AlignHCenter);
  // line1->setEnabled(false);
}


void ICSWidgetPB::showValue(int nVal)
{
 // qDebug ("showValue: %d", nVal);
 bShowNum->setText(QString().setNum(nVal));
}

void ICSWidgetPB::setStyleSheets()
{
 bShowNum->setStyleSheet("QPushButton {color: lightgreen ; \
                                       background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,  \
                                       stop: 0 black,  \
                                       stop: 0.1 lightgray  \
                                       stop: 0.3 black,  \
                                       stop: 0.8 black,  \
                                       stop: 10.0 lightblue);  \
                                       border: 1px solid black;border-radius: 6px;font: 25px;}  \
                          QPushButton:hover{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,  \
                                       stop: 0 black,  \
                                       stop: 0.1 lightgray  \
                                       stop: 0.3 black,  \
                                       stop: 0.8 black,  \
                                       stop: 1.0 RGB(105, 230,230));  \
                                       border: 1px solid red;}"); 
 
 // line1->setStyleSheet("QLineEdit {color: green; background-color: rgb(236, 233, 216);}");
}

void ICSWidgetPB::setAllLayouts()
{
  // layout setup:    
  mainVLayout = new QVBoxLayout;	 
  mainVLayout->addWidget(bShowNum);
  mainVLayout->addWidget(pcw);
  //pvbxLayout->addWidget(bQuit);
  this->setLayout(mainVLayout);
}

void ICSWidgetPB::setConnectionsWidgets()
{
  QObject::connect(pcw, SIGNAL(progressChanged(int)), this, SLOT( showValue(int) ) );
  // QObject::connect(pcw, SIGNAL(progressChanged(int)), pcw, SLOT(dummy(int)));
  QObject::connect(bShowNum, SIGNAL(clicked()), this, SLOT(close() ));
  //connect(bQuit, SIGNAL(clicked()), this, SLOT(closeApp() ));
}
