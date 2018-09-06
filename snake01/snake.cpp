#include <QPainter>
#include <QTime>
#include "snake.h"

Snake::Snake(QWidget *parent) : QWidget(parent), 
    leftDirection(false),
    rightDirection(false),
    upDirection(false),
    downDirection(false),
    inGame(true),
    gameOverShow(false),
    currentNumerDots(INIT_NUMBER_OG_DOTS)
{
    // setStyleSheet("background-color:black;");
    setStyleSheet("background-color:white;");    
    resize(B_WIDTH, B_HEIGHT);
    loadImages();
    initGame();
}

void Snake::loadImages() 
{
    bool loadApple = imageApple.load("Resources/apple.png");
    bool loadDot = imageDot.load("Resources/dot.png");
    bool loadHead = imageHead.load("Resources/head.png");
}

void Snake::initGame() 
{
    for (int z = 0; z < currentNumerDots; z++) 
    {
        x[z] = 50 - z * 10;
        y[z] = 50;
    }
    createNewApple();
    m_timerId = startTimer(DELAY);
}

void Snake::paintEvent(QPaintEvent *e) 
{
    Q_UNUSED(e);
    doDrawing();
}    

void Snake::doDrawing() 
{
    QPainter qPainter(this);

    if (inGame) 
    {
        qPainter.drawImage(apple_x, apple_y, imageApple);

        for (int z = 0; z < currentNumerDots; z++) 
        {
            if (z == 0) 
            {
                qPainter.drawImage(x[z], y[z], imageHead);
            } 
            else 
            {
                qPainter.drawImage(x[z], y[z], imageDot);
            }
        }
    }
    else 
    {
        gameOver(qPainter);
    }        
}

void Snake::gameOver(QPainter &qPainterP) 
{
    QString msgGameOver = "Game over";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(msgGameOver);

    qPainterP.setFont(font);
    int h = height();
    int w = width();

    qPainterP.translate(QPoint(w/2, h/2));
    qPainterP.drawText(-textWidth/2, 0, msgGameOver);
}

void Snake::checkApple() 
{
    if ((x[0] == apple_x) && (y[0] == apple_y)) 
    {
        currentNumerDots++;
        createNewApple();
    }
}

void Snake::move() 
{
    for (int z = currentNumerDots; z > 0; z--) 
    {
        x[z] = x[(z - 1)];
        y[z] = y[(z - 1)];
    }

    if (leftDirection) 
    {
        x[0] -= DOT_SIZE;
    }

    if (rightDirection) 
    {
        x[0] += DOT_SIZE;
    }

    if (upDirection) 
    {
        y[0] -= DOT_SIZE;
    }

    if (downDirection) 
    {
        y[0] += DOT_SIZE;
    }
}

void Snake::checkCollision()
{
    for (int z = currentNumerDots; z > 0; z--) 
    {
        if ((z > 4) && (x[0] == x[z]) && (y[0] == y[z])) 
        {
            inGame = false;
        }
    }

    if (y[0] >= B_HEIGHT) 
    {
        inGame = false;
    }

    if (y[0] < 0) 
    {
        inGame = false;
    }

    if (x[0] >= B_WIDTH) 
    {
        inGame = false;
    }

    if (x[0] < 0) 
    {
        inGame = false;
    }

    if(!inGame) 
    {
        killTimer(m_timerId); 
    }
}

void Snake::createNewApple() 
{
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    int r = qrand() % RAND_POS;
    apple_x = (r * DOT_SIZE);

    r = qrand() % RAND_POS;
    apple_y = (r * DOT_SIZE);
}

void Snake::timerEvent(QTimerEvent *e) 
{
    Q_UNUSED(e);  

    if (inGame) 
    {
        checkApple();
        checkCollision();
        move();
    }
    repaint();
}    

void Snake::keyPressEvent(QKeyEvent *e) 
{
    int key = e->key();

    if ((key == Qt::Key_Left) && (!rightDirection)) 
    {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Right) && (!leftDirection)) 
    {
        rightDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Up) && (!downDirection)) 
    {
        upDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    if ((key == Qt::Key_Down) && (!upDirection)) 
    {
        downDirection = true;
        rightDirection = false;
        leftDirection = false;
    }    

    QWidget::keyPressEvent(e);    
}