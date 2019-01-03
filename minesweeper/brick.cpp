#include "gen.h"
#include "brick.h"

Brick::Brick(int x, int y) 
{
    // imageBrick.load("Resources/brickie.png");
    // bool loadPaddle = imagePaddle_tmp.load("Resources/paddle.png");

    QImage imageBrick_tmp;
    
    bool loadBrick = imageBrick.load("Resources/brickie.png");
    // bool loadBrick = imageBrick_tmp.load("Resources/brickie.png");
    // imageBrick = imageBrick_tmp.scaled(40, 40, Qt::KeepAspectRatio);
    
    rect = imageBrick.rect();
    rect.translate(x, y);
}

Brick::~Brick() 
{
    std::cout << ("Brick deleted") << std::endl;
}

QRect Brick::getRect() 
{
    return rect;
}

void Brick::setRect(QRect rct) 
{
    rect = rct;
}

QImage & Brick::getImageUntouched() 
{
    return imageBrick;
}