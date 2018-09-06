#include "mywin.h"

MyWin::MyWin(const QString title)
    : QMainWindow(0)
{
    setWindowTitle(title);
    resize(500, 320);
    move(150, 200);
}

MyWin::~MyWin() { }
