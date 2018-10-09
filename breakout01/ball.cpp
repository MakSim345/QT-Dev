#include <iostream>
#include "ball.h"

Ball::Ball() 
{
    xDir = 1;
    yDir = -1;

    imageBall.load("Resources/ball.png");
    
    rect = imageBall.rect();
    resetState();
}

Ball::~Ball() 
{
    std::cout << ("Ball deleted") << std::endl;
}

void Ball::autoMove() 
{
    rect.translate(xDir, yDir);

    if (rect.left() == LEFT_EDGE) 
    {
        xDir = 1;
    }

    if (rect.right() == RIGHT_EDGE) 
    {
        xDir = -1;
    }

    if (rect.top() == TOP_EDGE) 
    {
        yDir = 1;
    }

    if (rect.bottom() == BOTTOM_EDGE + 79) 
    {
        yDir = -1;
    }
    
}

void Ball::resetState() 
{
    rect.moveTo(INITIAL_X, INITIAL_Y);
}

void Ball::setXDir(int x) 
{
    xDir = x;
}

void Ball::setYDir(int y)
{
    yDir = y;
}

int Ball::getXDir() 
{
    return xDir;
}

int Ball::getYDir() 
{
    return yDir;
}

QRect Ball::getRect() 
{
    return rect;
}

QImage& Ball::getImage() 
{
    return imageBall;
}