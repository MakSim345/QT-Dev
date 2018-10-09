#pragma once

#include "gen.h"
#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include "active_brick.h"

class Xonix : public QWidget 
{
    Q_OBJECT

public:
    Xonix(QWidget *parent = 0);
    ~Xonix();

public slots:
    void timerTick();

protected:
    void paintEvent(QPaintEvent *);    
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void drawObjects(QPainter *pPainter);
    void paintGrid(QPainter *pPainter);
    void finishGame(QPainter *pPainter, QString pStrToShow);
    void moveObjects();

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();

private:
    int x;
    int timerId;
    QTimer* timerGame;
    static const int N_OF_BRICKS = 30;    
    static const int DELAY = 3;//10;
    static const int BOTTOM_EDGE = 400;
    Ball *ball;
    BallArray *ballArray;
    Paddle *paddle;
    ActiveBrick *aBrick;
    Brick *bricks[N_OF_BRICKS];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
};
