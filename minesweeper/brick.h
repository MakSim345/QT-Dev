#pragma once

#include "gen.h"

class Brick
{
public:
    Brick(int, int);
    ~Brick();

public:
    QRect getRect();
    void setRect(QRect);
    QImage& getImageBrickUntouched();
    QImage& getImageBrickFlagged();
    QImage& getImageBrickOpened();
    QImage& getImageBrickTheBomb();
    // QImage& getImage();
    // QImage& getImage();

private:
    bool loadBrick;
    QImage imageBrickUntouched;
    QImage imageBrickOpened;
    QImage imageBrickFlagged;
    QImage imageBrickTheBomb;
    QRect rect;
};
