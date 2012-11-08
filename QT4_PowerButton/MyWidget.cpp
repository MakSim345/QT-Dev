#include <QApplication>
#include <QLabel>
// #include "AeroButton.h"
#include "qpower.h"
#include "MyWidget.h"

void MyWidget::showMessageBox()
{
 QMessageBox::about(this, "Application", "Vista aero style");
}

void MyWidget::closeApp()
{
 close();
}
 
void MyWidget::on_aerobutton_test_clicked()
{
 close();
}

 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 {
     //setFixedSize(150, 200);

     button_power = new QPower(this);
	 // aerobutton_test = new AeroButton("Test", this);
	 QPushButton *quit = new QPushButton(tr("Quit"));
	 
	 QVBoxLayout *layout = new QVBoxLayout;
	 // QHBoxLayout *layout = new QHBoxLayout;
	 
	 quit->setFont(QFont("Times", 25, QFont::Bold));
	 //aerobutton_test->setFont(QFont("Times", 12, QFont::Bold));
	 //aerobutton_quit->setGeometry(10, 20, 230, 40);
	 //aerobutton_test->setGeometry(10, 70, 230, 40);
	 
	 /*
	 QGridLayout *grid = new QGridLayout;
     for (int row = 0; row < 3; ++row)
     {
      for (int column = 0; column < 2; ++column) 
      {
       LCDRange *lcdRange = new LCDRange;
       grid->addWidget(lcdRange, row, column);
      }
     }
	*/	
	  
	QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);
    
    //QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    //setLayout(layout);
	     
     // layout->addWidget(aerobutton_test);
     // layout->addLayout(grid);
     layout->addWidget(button_power);
     layout->addWidget(quit);
     //layout->addWidget(slider);
     setLayout(layout);
        
	 //QObject::connect(aerobutton_quit, SIGNAL(clicked()), &app, SLOT(quit()));
     // connect(aerobutton_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
     // connect(aerobutton_quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
     //connect(aerobutton_test, SIGNAL(clicked()), this, SLOT(showMessageBox() ));
     connect(quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
     connect(button_power, SIGNAL(clicked()), this, SLOT(showMessageBox() ));
     connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
     
     //connect(quit, SIGNAL(clicked()), this, SLOT(close() ));
     // connect(button_power, SIGNAL(mousePressEvent()), this, SLOT(close() ));
 }


