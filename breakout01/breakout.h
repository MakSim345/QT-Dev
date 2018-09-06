#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QtWidgets/QMainWindow>

class Breakout : public QMainWindow
{
    Q_OBJECT

public:
    Breakout(QWidget *parent = 0);
    ~Breakout();

private:
    Ui::breakoutClass ui;
};

#endif // BREAKOUT_H
