#include "gen.h"
#include "brick.h"

Brick::Brick(int x, int y) 
{
    // imageBrick.load("Resources/brickie.png");
    // bool loadPaddle = imagePaddle_tmp.load("Resources/paddle.png");

    QImage imageBrick_tmp;
    
    bool loadBrick = imageBrick.load("Resources/brickie.png");
    //bool loadBrick = imageBrick_tmp.load("Resources/brickie.png");
    //imageBrick = imageBrick_tmp.scaled(50, 150, Qt::KeepAspectRatio);

    destroyed = false;
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

QImage & Brick::getImage() 
{
    return imageBrick;
}

bool Brick::isDestroyed() 
{
    return destroyed;
}

void Brick::setDestroyed(bool destr) 
{
    destroyed = destr;
}