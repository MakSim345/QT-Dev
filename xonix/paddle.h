#pragma once

#include <QImage>
#include <QRect>

class Paddle 
{
public:
    Paddle();
    ~Paddle();

public:
    void resetState();
    void move();
    void setDx(int);
    void loadImages();
    QRect getRect();
    QImage& getImage();

private:
    QImage imagePaddle;
    QRect rect;
    int dx;
    static const int INITIAL_X = 200;
    static const int INITIAL_Y = 370;
};