#include <QApplication>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>

#include "qpower.h"


class LCDRange : public QWidget
{
public:
    LCDRange(QWidget *parent = 0);
};


LCDRange::LCDRange(QWidget *parent)
    : QWidget(parent)
{
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 99);
    slider->setValue(0);
    connect(slider, SIGNAL(valueChanged(int)),
            lcd, SLOT(display(int)));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}


class MyWidget : public QWidget
{
  public:
    MyWidget(QWidget *parent = 0);    
    
    QPower *button_power;
    // QPower *aerobutton_test;
    
  public slots:  
    void showMessageBox();  
    void closeApp();
    void on_aerobutton_test_clicked();
    
 };

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
     setFixedSize(500, 500);

     button_power = new QPower(this);
	 // aerobutton_test = new AeroButton("Test", this);
	 QPushButton *quit = new QPushButton(tr("Quit"));
	 QVBoxLayout *layout = new QVBoxLayout;
	 
	 quit->setFont(QFont("Times", 25, QFont::Bold));
	 // aerobutton_test->setFont(QFont("Times", 12, QFont::Bold));
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
     // connect(quit, SIGNAL(clicked()), qApp, SLOT(closeApp() ));
     connect(quit, SIGNAL(clicked()), this, SLOT(close() ));
     connect(button_power, SIGNAL(mousePressEvent()), this, SLOT(close() ));
 }


int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	// DialogImpl win;
	MyWidget win;
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
 