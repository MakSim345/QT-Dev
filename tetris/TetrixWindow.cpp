#include "TetrixWindow.h"

TetrixWindow::TetrixWindow(QWidget *parent)
    : QWidget(parent)
{
    // ui.setupUi(this);
    this->board = new TetrixBoard;
}

TetrixWindow::~TetrixWindow()
{

}
