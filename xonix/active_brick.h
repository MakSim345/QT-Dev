#pragma once

#include <QImage>
#include <QRect>

class ActiveBrick 
{
public:
    ActiveBrick();
    ~ActiveBrick();

public:
    void resetState();
    void move();
    void setDx(int);
    void loadImages();
    QRect getRect();
    QImage& getImage();

private:
    QImage imageActiveBrick;
    QRect rect;
    int dx;
    static const int INITIAL_X = 200;
    static const int INITIAL_Y = 370;
};