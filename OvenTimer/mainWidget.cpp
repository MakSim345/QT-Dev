#include <QApplication>
#include <QLabel>

#include "mainWidget.h"

//#define QT_RND_SERVER
#ifndef QT_RND_SERVER
 #include <time.h>
#endif 

const double DegreesPerMinute = 7.0;
const double DegreesPerSecond = DegreesPerMinute / 60;
const int MaxMinutes = 45;
const int MaxSeconds = MaxMinutes * 60;
const int UpdateInterval = 1;

void mainWidget::showMessageBox()
{
 QMessageBox::about(this, "Application", "Vista aero style");
}

void mainWidget::closeApp()
{
 close();
}

void mainWidget::StartMyThread()
{
    m_thread.setMValue( lcd->intValue() );
    m_thread.start();
}

void mainWidget::setValue()
{ 
  static int nFirsTime = 1;
  if (nFirsTime)
  {
    //lnMSTime->setText(QString::number(GetRNDValue()));
    //lcd->display(lnMSTime->text());
    lcd->display(QString::number(GetRNDValue()));
    // lnMSTime->setText(QString::number(Get1msTimeMS() ));
   StartMyThread();
   mainWidget::test->setDisabled(1);
   nFirsTime = 0;    
   }
 QApplication::beep();
}

int mainWidget::GetRNDValue()
{
  int nRetVal=0;
  static int nFirstTime = 1;

#ifdef QT_RND_SERVER

 if (1 == nFirstTime)
 {
  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
  nFirstTime = 0;
 }
 nRetVal = (int)qrand(); 

#else

 int RND_MAX = 900;
 
 if (1 == nFirstTime)
 {
  srand (time (NULL));
  nFirstTime = 0;
 }
 nRetVal = 1 + (rand() % RND_MAX); 
 
 //qDebug() << "Time: " << nRetVal;    
 //qDebug() << "Execution done";
#endif  

return nRetVal;
} 
mainWidget::mainWidget(QWidget *parent)
     : QWidget(parent)
 {
     // setFixedSize(450, 300);

     // button_power = new QPower(this);
	 // aerobutton_test = new AeroButton("Test", this);
	 test = new QPushButton(tr("T&est"));
	 quit = new QPushButton(tr("&Exit"));
	 vumeter = new QVUMeter();
	 vlayout = new QVBoxLayout;	 
	 hlayout = new QHBoxLayout;
	 ovenTimer = new OvenTimer;
	 
	 // This is a main layout:
	 mlayout = new QHBoxLayout;
	 
	 //quit->setFont(QFont("Times", 25, QFont::Bold));
	 //aerobutton_test->setFont(QFont("Times", 12, QFont::Bold));
	 //aerobutton_quit->setGeometry(10, 20, 230, 40);
	 //aerobutton_test->setGeometry(10, 70, 230, 40);
	 
	 //quit->setStyleSheet("QPushButton {color: black; border: 1px solid black; border-radius: 6px;font: bold 18px;} QPushButton:pressed {background-color: red;}");
	 //quit->setStyleSheet("QPushButton#exitButton { color: black; };");
	 // QString("QPushButton {background-color: red;} QPushButton:checked{background-color: red;} QPushButton:pressed {background-color: red;}"));

quit->setStyleSheet("QPushButton {color: lightgray;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 10.0 lightblue); border: 1px solid black;border-radius: 6px;font: 25px;} QPushButton:hover{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230)); border: 1px solid red;}");
test->setStyleSheet("QPushButton {color: lightgray;background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 10.0 lightblue); border: 1px solid black;border-radius: 6px;font: 25px;} QPushButton:hover{ background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 lightgray stop: 0.3 black, stop: 0.8 black, stop: 1.0 RGB(105, 230,230)); border: 1px solid red;}");
/*
QPushButton:pressed 
{
   background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 black, stop: 0.1 gray stop: 0.3 RGB(0, 0, 0), stop: 0.8 RGB(50, 50,50), stop: 1.0 RGB(105, 230,230));
}
*/
	 
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
	  
	 
    lcd = new QLCDNumber(3);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    
    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 999);
    slider->setValue(0);
    
    hlayout->addWidget(vumeter);  
    
    vlayout->addWidget(lcd);
    vlayout->addWidget(slider); 
    vlayout->addWidget(test); 
    vlayout->addWidget(quit);
    vlayout->addWidget(ovenTimer);
	
    
    // layout->addWidget(aerobutton_test);
    // layout->addLayout(grid);
    // layout->addWidget(button_power);
     
     //layout->addWidget(slider);
     mlayout->addLayout(hlayout);
     mlayout->addLayout(vlayout);
     setLayout(mlayout);
        
	 //QObject::connect(aerobutton_quit, SIGNAL(clicked()), &app, SLOT(quit()));
     // connect(aerobutton_quit, SIGNAL(clicked()), qApp, SLOT(quit()));
     // connect(aerobutton_quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
     //connect(aerobutton_test, SIGNAL(clicked()), this, SLOT(showMessageBox() ));
     connect(quit, SIGNAL(clicked()), this, SLOT(closeApp() ));
     connect(test, SIGNAL(clicked()), this, SLOT(setValue() ));

     connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
     connect(slider, SIGNAL(valueChanged(int)), vumeter, SLOT(setLeftValue(2.8)));
     connect (&m_thread, SIGNAL(currentValue(int)), lcd, SLOT(display(int)) );
     // connect(quit, SIGNAL(clicked()), this, SLOT(close() ));
     // connect(button_power, SIGNAL(mousePressEvent()), this, SLOT(close() ));
 }


OvenTimer::OvenTimer(QWidget *parent)
    : QWidget(parent)
{
    finishTime = QDateTime::currentDateTime();
    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    finishTimer = new QTimer(this);
    finishTimer->setSingleShot(true);
    connect(finishTimer, SIGNAL(timeout()), this, SIGNAL(timeout()));
    connect(finishTimer, SIGNAL(timeout()), updateTimer, SLOT(stop()));
}

void OvenTimer::mousePressEvent(QMouseEvent *event)
{
    QPointF point = event->pos() - rect().center();
    double theta = atan2(-point.x(), -point.y()) * 180 / 3.14159265359;
    setDuration(duration() + int(theta / DegreesPerSecond));
    update();
}

void OvenTimer::setDuration(int secs)
{
    if (secs > MaxSeconds) {
        secs = MaxSeconds;
    } else if (secs <= 0) {
        secs = 0;
    }
    finishTime = QDateTime::currentDateTime().addSecs(secs);
    if (secs > 0) {
        updateTimer->start(UpdateInterval * 1000);
        finishTimer->start(secs * 1000);
    } else {
        updateTimer->stop();
        finishTimer->stop();
    }
    update();
}

int OvenTimer::duration() const
{
    int secs = QDateTime::currentDateTime().secsTo(finishTime);
    if (secs < 0)
        secs = 0;
    return secs;
}


void OvenTimer::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    int side = qMin(width(), height());
    painter.setViewport((width() - side) / 2, (height() - side) / 2,
                        side, side);
    painter.setWindow(-50, -50, 100, 100);
    draw(&painter);
}

void OvenTimer::draw(QPainter *painter)
{
    static const int triangle[3][2] = { { -2, -49 }, { +2, -49 }, { 0, -47 } };
    QPen thickPen(palette().foreground(), 1.5);
    QPen thinPen(palette().foreground(), 0.5);
    QColor niceBlue(150, 150, 200);
    painter->setPen(thinPen);
    painter->setBrush(palette().foreground());
    painter->drawPolygon(QPolygon(3, &triangle[0][0]));

    QConicalGradient coneGradient(0, 0, -90.0);
    coneGradient.setColorAt(0.0, Qt::darkGray);
    coneGradient.setColorAt(0.2, niceBlue);
    coneGradient.setColorAt(0.5, Qt::white);
    coneGradient.setColorAt(1.0, Qt::darkGray);
    painter->setBrush(coneGradient);
    painter->drawEllipse(-46, -46, 92, 92);

    QRadialGradient haloGradient(0, 0, 20, 0, 0);
    haloGradient.setColorAt(0.0, Qt::lightGray);
    haloGradient.setColorAt(0.8, Qt::darkGray);
    haloGradient.setColorAt(0.9, Qt::white);
    haloGradient.setColorAt(1.0, Qt::black);
    painter->setPen(Qt::NoPen);
    painter->setBrush(haloGradient);
    painter->drawEllipse(-20, -20, 40, 40);

    QLinearGradient knobGradient(-7, -25, 7, -25);
    knobGradient.setColorAt(0.0, Qt::black);
    knobGradient.setColorAt(0.2, niceBlue);
    knobGradient.setColorAt(0.3, Qt::lightGray);
    knobGradient.setColorAt(0.8, Qt::white);
    knobGradient.setColorAt(1.0, Qt::black);
    painter->rotate(duration() * DegreesPerSecond);
    painter->setBrush(knobGradient);
    painter->setPen(thinPen);
    painter->drawRoundRect(-7, -25, 14, 50, 150, 50);

    for (int i = 0; i <= MaxMinutes; ++i) 
    {
        if (i % 5 == 0) 
        {
            painter->setPen(thickPen);
            painter->drawLine(0, -41, 0, -44);
            painter->drawText(-15, -41, 30, 25,
                              Qt::AlignHCenter | Qt::AlignTop,
                              QString::number(i));
        }
        else
        {
            painter->setPen(thinPen);
            painter->drawLine(0, -42, 0, -44);
        }
        painter->rotate(-DegreesPerMinute);
    }

for (int i = 0; i <= MaxMinutes; ++i) 
{
    painter->save();
    painter->rotate(-i * DegreesPerMinute);
    if (i % 5 == 0) 
    {
        painter->setPen(thickPen);
        painter->drawLine(0, -41, 0, -44);
        painter->drawText(-15, -41, 30, 25,
                          Qt::AlignHCenter | Qt::AlignTop,
                          QString::number(i));
    }
     else 
    {
        painter->setPen(thinPen);
        painter->drawLine(0, -42, 0, -44);
    }
    painter->restore();
}

}