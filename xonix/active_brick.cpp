#include "gen.h"
#include "active_brick.h"

ActiveBrick::ActiveBrick()
{
    dx = 0;
    loadImages();
    resetState();
}

void ActiveBrick::loadImages()
{    
    bool loadPaddle = imageActiveBrick.load("Resources/brickie.png");        
    rect = imageActiveBrick.rect();
}

ActiveBrick::~ActiveBrick()
{
    std::cout << ("Active Brick deleted") << std::endl;
}

void ActiveBrick::setDx(int xP)
{
    dx = xP;
}

void ActiveBrick::move()
{
    int _x = rect.x() + dx;
    int _y = rect.top();

    rect.moveTo(_x, _y);
}

void ActiveBrick::resetState()
{
    rect.moveTo(INITIAL_X, INITIAL_Y);
}

QRect ActiveBrick::getRect()
{
    return rect;
}

QImage & ActiveBrick::getImage()
{
    return imageActiveBrick;
}
