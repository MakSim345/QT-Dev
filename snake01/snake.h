#ifndef SNAKE_H
#define SNAKE_H

#include <QtWidgets/QMainWindow>
#include <QKeyEvent>


class Snake : public QWidget
{
    Q_OBJECT

public:
    Snake(QWidget *parent = 0);
    // ~Snake();

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    QImage imageDot;
    QImage imageHead; 
    QImage imageApple;

    static const int B_WIDTH = 300;
    static const int B_HEIGHT = 300;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900;
    static const int RAND_POS = 29;
    static const int DELAY = 140;    
    static const int INIT_NUMBER_OG_DOTS = 3;

    int m_timerId;
    int currentNumerDots;
    int apple_x;
    int apple_y;      

    int x[ALL_DOTS]; 
    int y[ALL_DOTS]; 

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;
    bool gameOverShow;

    void loadImages();
    void initGame();
    void createNewApple();
    void checkApple();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);   
};

#endif // SNAKE_H
