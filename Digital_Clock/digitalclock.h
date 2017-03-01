#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>
#include <iostream>

 class DigitalClock : public QLCDNumber
 {
     Q_OBJECT

 public:
     DigitalClock(QWidget *parent = 0);

 private:
     int prev_seconds;

 private slots:
     void showTime();
 };

 #endif