#pragma once

#include "gen.h"

class TetrixBoard : public QFrame
{
public:
    TetrixBoard(QWidget *parent = nullptr);
    ~TetrixBoard();

public:
    
private:
    bool loadBrick;
};
