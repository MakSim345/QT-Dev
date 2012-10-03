#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>

class AnalogClock : public QWidget
{

 Q_OBJECT

 public:
     AnalogClock(QWidget *parent = 0);

 protected:
     void paintEvent(QPaintEvent *event);
};


/*
#include <QtGui/QMainWindow>
#include "ui_analogclock.h"

class AnalogClock : public QMainWindow
{
    Q_OBJECT

public:
    AnalogClock(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~AnalogClock();

private:
    Ui::AnalogClockClass ui;
};
*/
#endif // ANALOGCLOCK_H
