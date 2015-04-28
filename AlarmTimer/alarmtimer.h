#ifndef ALARMTIMER_H
#define ALARMTIMER_H

#include <QtWidgets/QMainWindow>
#include "ui_alarmtimer.h"

class AlarmTimer : public QMainWindow
{
    Q_OBJECT

public:
    AlarmTimer(QWidget *parent = 0);
    ~AlarmTimer();

private:
    Ui::AlarmTimerClass ui;
};

#endif // ALARMTIMER_H
