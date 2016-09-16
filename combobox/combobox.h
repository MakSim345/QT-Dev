#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QtWidgets/QMainWindow>
#include "ui_combobox.h"

class Combobox : public QMainWindow
{
    Q_OBJECT

public:
    Combobox(QWidget *parent = 0);
    ~Combobox();

private:
    Ui::ComboboxClass ui;
};

#endif // COMBOBOX_H
