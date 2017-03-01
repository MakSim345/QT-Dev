 #include <QtGui>
 #include "digitalclock.h"

 DigitalClock::DigitalClock(QWidget *parent)
     : QLCDNumber(parent)
     , prev_seconds(0)
 {
     setSegmentStyle(Filled);

     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
     timer->start(1000);

     showTime();

     setWindowTitle(tr("Digital Clock"));
     resize(150, 60);
 }

 void DigitalClock::showTime()
 {
     QTime time = QTime::currentTime();     
     QString text = time.toString("hh:mm");
     
     int tmp_seconds = time.second();

     if ((time.second() % 2) == 0)
         text[2] = ' ';
     if (tmp_seconds != prev_seconds)
     {
         prev_seconds = time.second();
         std::cout << "1";         
     }

     // this->display("12 + " + " -sec");
     // this->display(text);
     this->display(text);// + ":" + time.second());
 }