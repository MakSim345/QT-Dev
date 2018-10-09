#pragma once

#include "gen.h"
#include "brick.h"

class Ball 
{
public:
    Ball();
    ~Ball();

public:
    void resetState();
    void resetState(const int pInitialX, const int pInitialY);
    void autoMove();
    void autoCollision(const int& paddleLPos);
    void brickCollision(Brick* brick);
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage& getImage();

private:
    int xDir;
    int yDir;
    QImage imageBall;
    QRect rect;
    static const int INITIAL_X = 230;
    static const int INITIAL_Y = 355;

    static const int RIGHT_EDGE = 639;
    static const int LEFT_EDGE = 0;
    static const int TOP_EDGE = 0;
    static const int BOTTOM_EDGE = 400;
};

class BallArray
{
public:
    BallArray(void)
    {
        ball[0] = new Ball();
        ball[1] = new Ball();
        resetStateRnd();
    }

    void resetStateRnd()
    {
        // Initialize sequence
        qsrand(QDateTime::currentMSecsSinceEpoch()/ 1000);        
        ball[0]->resetState(qrand() % 230, qrand() % 350);
        ball[1]->resetState(qrand() % 230, qrand() % 350);
    }

   ~BallArray(void)
   {
       delete ball[0];
       delete ball[1];
   }
   
   Ball* ball[NUMBER_OF_BALLS];

private:
    
};