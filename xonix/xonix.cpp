#include "gen.h"
#include "xonix.h"

Xonix::Xonix(QWidget *parent)
    : QWidget(parent)
{
        x = 0;
        gameOver = false;
        gameWon = false;
        paused = false;
        gameStarted = false;        
        paddle = new Paddle();
        aBrick = new ActiveBrick();
        ballArray = new BallArray();
        
        int k = 0;
        
        for (int i=0; i<5; i++)
        {
            for (int j=0; j<6; j++)
            {
                // bricks[k] = new Brick(j*40+30, i*10+50);
                bricks[k] = new Brick(j*60 + 30, i*30 + 50);
                k++;
            }
        }
        
        QRect qr = this->geometry();
        
        timerGame = new QTimer(this);
        connect(timerGame, SIGNAL(timeout()), this, SLOT(timerTick()));
}

Xonix::~Xonix()
{
    // delete ball;
    delete ballArray;
    delete paddle;
    delete aBrick;

    for (int i=0; i<N_OF_BRICKS; i++)
    {
        // delete bricks[i];
    }
}

void Xonix::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);

    if (gameOver)
    {
        finishGame(&painter, "Game lost");
    }
    else if(gameWon)
    {
        finishGame(&painter, "Victory");
    }
    else
    {
        drawObjects(&painter);
    }
}

void Xonix::finishGame(QPainter *painter, QString message)
{
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, 0, message);
}

void Xonix::paintGrid(QPainter *pPainter)
{
    QRect borders(0, 0, width()-1, height()-1);
    QColor gridColor = Qt::white;
    gridColor.setAlpha(10);
    pPainter->setPen(gridColor);

    double cellWidth = (double)width()/UNIVERSE_SIZE;
    
    for(double k = cellWidth; k <= width(); k += cellWidth)
    {
        pPainter->drawLine(k, 0, k, height());
    }
    /*
    double cellHeight = (double)height()/UNIVERSE_SIZE;    
    for(double k = cellHeight; k <= height(); k += cellHeight)
    {
        pPainter->drawLine(0, k, width(), k);
    }
    */
    pPainter->drawRect(borders);
}

void Xonix::drawObjects(QPainter *painter)
{
    //TODO: create a pool of objects and get images and rect from there?
    painter->drawImage(ballArray->ball[0]->getRect(), ballArray->ball[0]->getImage());
    painter->drawImage(ballArray->ball[1]->getRect(), ballArray->ball[1]->getImage());
    
    // paintGrid(painter);
    // painter->drawImage(paddle->getRect(), paddle->getImage());
    painter->drawImage(aBrick->getRect(), aBrick->getImage());    
    
    for (int i=0; i<N_OF_BRICKS; i++)
    {
        if (!bricks[i]->isDestroyed())
        {
            painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
        }
    }    
}

void Xonix::timerTick()
{
    moveObjects();
    checkCollision();
    repaint();
}

void Xonix::moveObjects()
{
    // ball->autoMove();
    ballArray->ball[0]->autoMove();
    ballArray->ball[1]->autoMove();
    aBrick->move();
}

void Xonix::keyReleaseEvent(QKeyEvent *e)
{
    const int dx = 0;

    switch (e->key())
    {
        case Qt::Key_Left:
            aBrick->setDx(dx);
            break;

        case Qt::Key_Right:
            aBrick->setDx(dx);
            break;
    }
}

void Xonix::keyPressEvent(QKeyEvent *e)
{
    int dx = 0;

    switch (e->key())
    {
        case Qt::Key_Left:
            dx = -1;
            aBrick->setDx(dx);
            break;

        case Qt::Key_Right:
            dx = 1;
            aBrick->setDx(dx);
            break;

        case Qt::Key_P:
            pauseGame();
            break;

        case Qt::Key_Space:
            startGame();
            break;

        case Qt::Key_Escape:
            stopGame();
            qApp->exit();
            break;

        default:
            QWidget::keyPressEvent(e);
    }
}

void Xonix::startGame()
{
    if (!gameStarted)
    {
        // ball->resetState();
        // ballArray->resetStateRnd();
        paddle->resetState();
        /*
        for (int i=0; i<N_OF_BRICKS; i++)
        {
            bricks[i]->setDestroyed(false);
        }
        */

        gameOver = false;
        gameWon = false;
        gameStarted = true;
        // timerId = startTimer(DELAY);
        timerGame->start(DELAY);        
    }
}

void Xonix::pauseGame()
{
    if (paused)
    {
        timerId = startTimer(DELAY);
        paused = false;
    }
    else
    {
        paused = true;
        killTimer(timerId);
    }
}

void Xonix::stopGame()
{
    killTimer(timerId);
    gameOver = true;
    gameStarted = false;
}

void Xonix::victory()
{
    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
}

void Xonix::checkCollision()
{
#ifdef YS2018_09_20
    if (ball->getRect().bottom() > BOTTOM_EDGE)
    {
        stopGame();
    }
#endif


    for (int i=0, j=0; i<N_OF_BRICKS; i++)
    {

        if (bricks[i]->isDestroyed())
        {
            j++;
        }

        if (j == N_OF_BRICKS)
        {
            victory();
        }
    }

    for (int i=0; i<NUMBER_OF_BALLS; i++)
    {
        if ((ballArray->ball[i]->getRect()).intersects(aBrick->getRect()))
        {
            int paddleLPos = aBrick->getRect().left();
            ballArray->ball[i]->autoCollision(paddleLPos);
        }
    }

    for (int i=0; i<NUMBER_OF_BALLS; i++)   
    {    
        for (int br=0; br<N_OF_BRICKS; br++)
        {
            if ((ballArray->ball[i]->getRect()).intersects(bricks[br]->getRect()))
            {
                ballArray->ball[i]->brickCollision(bricks[br]);
            }
        }
    }
}
