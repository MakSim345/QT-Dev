#ifndef CANDY_H
#define CANDY_H

#include <QtWidgets/QMainWindow>
#include "ui_candy.h"

class Candy : public QMainWindow
{
    Q_OBJECT

public:
    Candy(QWidget *parent = 0);
    ~Candy();

private:
    Ui::CandyClass ui;
};

#endif // CANDY_H
