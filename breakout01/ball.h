#pragma once

#include <QImage>
#include <QRect>

class Ball {

public:
    Ball();
    ~Ball();

public:
    void resetState();
    void autoMove();
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage& getImage();

private:
    int xdir;
    int ydir;
    QImage imageBall;
    QRect rect;
    static const int INITIAL_X = 230;
    static const int INITIAL_Y = 355;

    static const int RIGHT_EDGE = 639;
    static const int LEFT_EDGE = 0;
    static const int TOP_EDGE = 0;
    static const int BOTTOM_EDGE = 400;
};