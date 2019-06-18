#pragma once
#include "gen.h"
// #include "ball.h"
#include "brick.h"
#include "mine.h"

class Minesweeper : public QWidget
{
    Q_OBJECT

public:
    Minesweeper(QWidget *parent = 0);
   ~Minesweeper();
   void startNewGame();

signals:
   void started();
   void stopped(bool pWinLoose);
   void minesFlagged(int pnumberOfMines);

protected:
    int calcBombsNearMe(int x, int y);

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void drawObjects(QPainter *);

    void startGame();
    void bombExplosed();
    void finishGame(QPainter *, QString);
    void pauseGame();
    void stopGame();
    void victory();
    bool outBounds(int x, int y);
    void mineReveal(int x,int y);
    bool compareMines();
    void placeMines();
    void clearMines();
    int getRandom(int pCoord);

private:
    int x;
    int timerId;

    static const int DELAY = 3;//10;

    bool gameOver;
    bool isGameWon;
    bool isGameStarted;
    bool isGamePaused;
    bool isFirstClick;
    bool isBombed;
    int markedMines;

    static const int gridW = GRID_W;
    static const int gridH = GRID_H;
    static const int numMines = MINES_TOTAL;// 40;// number of mines on the board

    static const int N_OF_BRICKS = gridW * gridH;

    Mine *bombOn[gridW][gridH];
};
