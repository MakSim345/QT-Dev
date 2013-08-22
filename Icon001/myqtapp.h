#ifndef MYQTAPP_H
#define MYQTAPP_H

#include "ui_myqtapp.h"


class myQtApp : public QMainWindow
{
	Q_OBJECT

public:
    myQtApp();

private:
    Ui::myQtAppDLG ui;
};


#endif
