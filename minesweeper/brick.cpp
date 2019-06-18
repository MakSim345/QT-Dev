#include "brick.h"

Brick::Brick(int x, int y)
{
    // imageBrick.load("Resources/brickie.png");
    // bool loadPaddle = imagePaddle_tmp.load("Resources/paddle.png");
    // bool loadBrick = imageBrick.load("Resources/brickie.png");
    // bool loadBrick = imageBrick.load("Resources/marked.png");
    // bool loadBrick = imageBrick_tmp.load("Resources/brickie.png");
    // imageBrick = imageBrick_tmp.scaled(40, 40, Qt::KeepAspectRatio);

    // getImageUntouched();
    // TODO: make 'lazy' image upload?
    //  - default for all
    //  - bomb only for mined
    loadBrick = imageBrickTheBomb.load("Resources/bomb.png");
    loadBrick = imageBrickOpened.load("Resources/opened.png");
    loadBrick = imageBrickFlagged.load("Resources/marked.png");
    loadBrick = imageBrickUntouched.load("Resources/brickie.png");
    rect = imageBrickUntouched.rect();
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

QImage & Brick::getImageBrickUntouched()
{
    return imageBrickUntouched;
}

QImage & Brick::getImageBrickFlagged()
{
    return imageBrickFlagged;
}

QImage & Brick::getImageBrickOpened()
{
    return imageBrickOpened;
}

QImage & Brick::getImageBrickTheBomb()
{
    return imageBrickTheBomb;
}
