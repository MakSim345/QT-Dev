#ifndef GUI_EVE_22_H
#define GUI_EVE_22_H

#include <QtGui/QMainWindow>
#include "ui_gui_eve_22.h"

class GUI_EVE_22 : public QMainWindow
{
    Q_OBJECT

public:
    GUI_EVE_22(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~GUI_EVE_22();

private:
    Ui::GUI_EVE_22Class ui;
};

#endif // GUI_EVE_22_H
