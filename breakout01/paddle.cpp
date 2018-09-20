#include "paddle.h"

#include <iostream>
#include "paddle.h"

Paddle::Paddle()
{
    dx = 0;
    loadImages();
    resetState();
}

void Paddle::loadImages() 
{
    QImage imagePaddle_tmp;
    bool loadPaddle = imagePaddle_tmp.load("Resources/paddle.png");    
    imagePaddle = imagePaddle_tmp.scaled(100, 100, Qt::KeepAspectRatio);
    rect = imagePaddle.rect();
}

Paddle::~Paddle()
{
    std::cout << ("Paddle deleted") << std::endl;
}

void Paddle::setDx(int xP)
{
    dx = xP;
}

void Paddle::move()
{
    int _x = rect.x() + dx;
    int _y = rect.top();

    rect.moveTo(_x, _y);
}

void Paddle::resetState()
{
    rect.moveTo(INITIAL_X, INITIAL_Y);
}

QRect Paddle::getRect()
{
    return rect;
}

QImage & Paddle::getImage()
{
    return imagePaddle;
}