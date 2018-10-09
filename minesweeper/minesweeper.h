#pragma once
#include "gen.h"
// #include "ball.h"
#include "brick.h"
// #include "paddle.h"

class Minesweeper : public QWidget 
{
    Q_OBJECT

public:
    Minesweeper(QWidget *parent = 0);
   ~Minesweeper();

public slots:
        void timerTick();

protected:
    int calcNear(int x, int y);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void drawObjects(QPainter *);    
    
    void startGame();
    void finishGame(QPainter *, QString); 
    void pauseGame();
    void stopGame();
    void victory();    
    bool outBounds(int x, int y);
    void mineReveal(int x,int y);
    bool compareMines();
    void placeMines();
    void clearMines();
    int getRndVal(int pCoord);

private:
    int x;
    int timerId;
    QTimer* timerGame;
    
    static const int DELAY = 3;//10;
    
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    bool firstClick;
    bool isBombed;
    int markedMines;
        
    static const int gridW = GRID_W;
    static const int gridH = GRID_H;
    static const int numMines = 40;// number of mines on the board    
    
    static const int N_OF_BRICKS = gridW * gridH;

    Mine *mines[gridW][gridH];
};

