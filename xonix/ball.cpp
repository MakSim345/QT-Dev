#include "ball.h"

Ball::Ball() 
{
    xDir = 1;
    yDir = -1;

    imageBall.load("Resources/ball.png");
    
    rect = imageBall.rect();
    // resetState();
}

Ball::~Ball() 
{
    std::cout << ("Ball deleted") << std::endl;
}

void Ball::brickCollision(Brick* pBrick)
{
    int ballLeft = this->getRect().left();
    int ballHeight = this->getRect().height();
    int ballWidth = this->getRect().width();
    int ballTop = this->getRect().top();

    QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
    QPoint pointLeft(ballLeft - 1, ballTop);
    QPoint pointTop(ballLeft, ballTop -1);
    QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);
    
    if (!pBrick->isDestroyed())
    {
        if(pBrick->getRect().contains(pointRight))
        {
            this->setXDir(-1);
        }
        else if(pBrick->getRect().contains(pointLeft))
        {
            this->setXDir(1);
        }

        if(pBrick->getRect().contains(pointTop))
        {
            this->setYDir(1);
        }

        else if(pBrick->getRect().contains(pointBottom))
        {
            this->setYDir(-1);
        }

        pBrick->setDestroyed(true);
    }
#ifdef YS2018_09_20
#endif
}

void Ball::autoCollision(const int& pPaddleLPos)
{
    int first = pPaddleLPos + 22; //8;
    int second = pPaddleLPos + 42;//16;
    int third = pPaddleLPos + 62; //24;
    int fourth = pPaddleLPos + 84;//32;
    
    int ballLPos = this->getRect().left();

    if (ballLPos < first)
    {
        this->setXDir(-1);
        this->setYDir(-1);
    }

    if (ballLPos >= first && ballLPos < second)
    {
        this->setXDir(-1);
        this->setYDir(-1*this->getYDir());
    }

    if (ballLPos >= second && ballLPos < third)
    {
        this->setXDir(0);
        this->setYDir(-1);
    }

    if (ballLPos >= third && ballLPos < fourth)
    {
        this->setXDir(1);
        this->setYDir(-1*this->getYDir());
    }

    if (ballLPos > fourth)
    {
        this->setXDir(1);
        this->setYDir(-1);
    }
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

void Ball::resetState(const int pInitialX, const int pInitialY) 
{
    rect.moveTo(pInitialX, pInitialY);
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