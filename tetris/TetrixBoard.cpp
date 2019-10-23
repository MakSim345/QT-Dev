#include "TetrixBoard.h"

TetrixBoard::TetrixBoard(QWidget *parent)
    :QFrame(parent)
{
    this->setFrameStyle(QFrame::Panel || QFrame::Sunken);
}

TetrixBoard::~TetrixBoard()
{
    std::cout << ("Board deleted") << std::endl;
}

