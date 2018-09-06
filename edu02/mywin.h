#ifndef MYWIN_H
#define MYWIN_H

#include <QtWidgets/QMainWindow>
#include <QtGui>

class MyWin : public QMainWindow
{
    Q_OBJECT

public:
    // MyWin(QWidget *parent = 0);
    MyWin(const QString title);
    ~MyWin();
};

#endif // MYWIN_H
