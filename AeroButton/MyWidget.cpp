#include <QApplication>
#include <QLabel>
#include "AeroButton.h"
#include "AeroButton2.h"
#include "MyWidget.h"

 MyWidget::MyWidget(QWidget *parent)
      : QWidget(parent)
{
    /*
    
    labplus = new QLabel ("+", this);
    labis = new QLabel ("=", this);
       
    */
    setWindowTitle("AeroButton Test");
    // setWindowIcon(QPixmap(":/images/qBinClock.png"));
    
    // setFixedSize(350, 220);
     
    line1 = new QLineEdit (this);
    line2 = new QLineEdit (this);
    line3 = new QLineEdit (this);
    
    line3->setReadOnly (true);
    aerobutton_clear = new AeroButton("Clear", this);
    aerobutton_calc = new AeroButton("Calc", this);
    aerobutton_quit = new AeroButton("Quit", this);
    aerobutton_new = new AeroButton("Test Aero Button", this);
    
    // aerobutton_new->setColor(QColor(Qt::black));
    // aerobutton_new->setShadow(QColor(Qt::black));
    aerobutton_clear->setHighlight(QColor(Qt::darkCyan));
    aerobutton_calc->setHighlight(QColor(Qt::darkCyan));
    aerobutton_quit->setHighlight(QColor(Qt::darkCyan));
    aerobutton_new->setHighlight(QColor(Qt::darkCyan));    
    // aerobutton_new->setRoundness(20);
    // aerobutton_new->setOpacity(0.65);
    aerobutton_new->setFont(QFont("Times", 15, QFont::Bold));

    aerobutton_clear->setFont(QFont("Times", 15, QFont::Bold));
    aerobutton_calc->setFont(QFont("Times", 15, QFont::Bold));
    aerobutton_quit->setFont(QFont("Times", 15, QFont::Bold));
 
 
 //aerobutton_quit->setGeometry(10, 20, 230, 40);
 //aerobutton_test->setGeometry(10, 70, 230, 40);
         
    QVBoxLayout *mainLayout = new QVBoxLayout;     
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    QHBoxLayout *buttonLayout2 = new QHBoxLayout;
    QHBoxLayout *buttonLayout3 = new QHBoxLayout;
    QHBoxLayout *editBoxLayout = new QHBoxLayout;
 
    // QGridLayout *buttonLayout = new QGridLayout;
    
    buttonLayout2->addWidget(aerobutton_calc);
    buttonLayout2->addWidget(aerobutton_clear);
    
    // buttonLayout->addLayout(buttonLayout2);
    
    editBoxLayout->addWidget(line1);
    editBoxLayout->addWidget(line2);
    editBoxLayout->addWidget(line3);
    
    buttonLayout3->addWidget(aerobutton_new);
    buttonLayout3->addWidget(aerobutton_quit);
    
    mainLayout->addLayout(buttonLayout2);
    mainLayout->addLayout(editBoxLayout);
    mainLayout->addLayout(buttonLayout3);
    
    //layout->addWidget(slider);
    setLayout(mainLayout);
    // setLayout(editBoxLayout);
   
    //connect (bcalc, SIGNAL(clicked ()), this, SLOT (slotCalc ()));
    //connect (bclear, SIGNAL(clicked ()), this, SLOT (slotClear ()));
    
    connect (aerobutton_calc, SIGNAL(clicked ()), this, SLOT (slotCalc ()));
    connect (aerobutton_clear, SIGNAL(clicked ()), this, SLOT (slotClear ()));
        
    // connect(aerobutton_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    // connect(aerobutton_quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
    // connect(aerobutton_test, SIGNAL(clicked()), this, SLOT(showMessageBox() ));
    connect(aerobutton_quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
}
 
MyWidget::~MyWidget ()
{
 
}
 
void MyWidget::slotCalc ()
{
    double d;
    QString tmp;
    d = line1->text().toDouble ();
    d += line2->text().toDouble ();
    line3->setText(tmp.setNum (d));
}

void MyWidget::slotClear ()
{
    line1->setText ("");
    line2->setText ("");
    line3->setText ("");
}

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


#ifdef YS_23423442234LL
/*
 MyWidget::MyWidget(QWidget *parent)
      : QWidget(parent)
      */
MyWidget::MyWidget()
 {
     setFixedSize(350, 220);

     aerobutton_quit = new AeroButton("Exit", this);
     aerobutton_test = new AeroButton("Test", this);
     
     QPushButton *quit = new QPushButton(tr("Quit"), this);
     
     aerobutton_quit->setFont(QFont("Times", 15, QFont::Bold));
     aerobutton_test->setFont(QFont("Times", 15, QFont::Bold));
     //aerobutton_quit->setGeometry(10, 20, 230, 40);
     //aerobutton_test->setGeometry(10, 70, 230, 40);
     quit->setFont(QFont("Times", 20, QFont::Bold));
        
     QVBoxLayout *layout = new QVBoxLayout;
     
     layout->addWidget(aerobutton_test);
     layout->addWidget(aerobutton_quit);
     layout->addWidget(quit);
     //layout->addWidget(slider);
     setLayout(layout);
        
     //QObject::connect(aerobutton_quit, SIGNAL(clicked()), &app, SLOT(quit()));
     // connect(aerobutton_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
     // connect(aerobutton_quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
     connect(aerobutton_test, SIGNAL(clicked()), this, SLOT(showMessageBox() ));
     connect(quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
 }
 
MyWidget::~MyWidget ()
{
 
} 
 
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

#endif // #ifdef YS_23423442234LL
