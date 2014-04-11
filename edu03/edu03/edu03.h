#ifndef EDU03_H
#define EDU03_H

#include <QtWidgets/QMainWindow>
#include "ui_edu03.h"

class edu03 : public QMainWindow
{
    Q_OBJECT

public:
    edu03(QWidget *parent = 0);
    ~edu03();

private:
    Ui::edu03Class ui;
};

#endif // EDU03_H
