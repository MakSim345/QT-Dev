#include "minesweeper.h"
#include <QPainter>
#include <QApplication>

Minesweeper::Minesweeper(QWidget *parent)
    : QWidget(parent)
{
        x = 0;
        gameOver = false;
        gameWon = false;
        paused = false;
        gameStarted = false;
        firstClick = true;
        isBombed = false;
        
        for(int x=0; x<gridW; x++)
        {
            for(int y=0; y<gridH; y++)
            {
                mines[x][y] = new Mine(x, y);
             }
        }
                
        this->setFixedSize(CELL_SIZE*gridW, CELL_SIZE*gridW);
        
        timerGame = new QTimer(this);
        connect(timerGame, SIGNAL(timeout()), this, SLOT(timerTick()));
}

Minesweeper::~Minesweeper()
{
    //delete ball;
    //delete paddle;
}

bool Minesweeper::outBounds(int x, int y)
{
    bool retVal = x<0||y<0||x>=gridW||y>=gridH;
    return retVal;
}

int Minesweeper::calcNear(int x, int y) 
{
    if(outBounds(x,y))
    {
        return 0;
    }
    int i=0;

    for(int oX=-1; oX<=1; oX++)
    {
        for(int oY=-1; oY<=1; oY++)
        {
            if(outBounds(oX + x, oY+y))
                continue;
            if (mines[oX+x][oY+y]->isMined())
                i++;
        }
    }
    return i;
}


void Minesweeper::paintEvent(QPaintEvent *e)
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

void Minesweeper::finishGame(QPainter *painter, QString message)
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

int Minesweeper::getRndVal(int pCoord)
{
    static int nFirstTime = 0;
    int nRandomValue = 0;
    QString tmp;

    if (0 == nFirstTime)
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        nFirstTime = 1;
    }

    nRandomValue = (int)(qrand() % pCoord);
    
    return nRandomValue;
}

void Minesweeper::placeMines()
{
    int i = 0;
    while(i < numMines)
    {
        int x = int(getRndVal(gridW));
        int y = int(getRndVal(gridH));
        if(mines[x][y]->isMined())
        {
            continue;
        }
        // qDebug() << "set mine to" << x << "," << y;
        mines[x][y]->setMines(1);
        i++;
    }
}

void Minesweeper::clearMines()
{
    for(int x=0; x<gridW; x++)
    {
        for(int y=0; y<gridH; y++)
        {
            mines[x][y]->setMines(0);
        }
    }
}

bool Minesweeper::compareMines()
{
    int matchCounter = 0;
    int markedCounter = 0;
    bool retVal = false;
    for(int x=0; x<gridW; x++)
    {
        for(int y=0; y<gridH; y++)
        {
            if (mines[x][y]->isMined() && mines[x][y]->isMarked())
            {
                matchCounter++;
            }
            if (mines[x][y]->isMarked())
            {
                markedCounter++;
            }
        }
    }
    
    qDebug() << "Marked:" << markedCounter << "Match: "<< matchCounter;
    if ((matchCounter == numMines) && (matchCounter == markedCounter))
    {
        retVal = true;
        qDebug() << "Return: TRUE";
    }

    return retVal;
}

void Minesweeper::drawObjects(QPainter *painter)
{
    for(int x=0; x<gridW; x++)
    {
        for(int y=0; y<gridH; y++)
        {
            int near=calcNear(x, y);

            if(false == mines[x][y]->isRevealed())
            {
                // draw untouched cover:
                painter->drawImage(mines[x][y]->getRect(), mines[x][y]->getImage());
            }

            if(mines[x][y]->isMined())
            {
                if (isBombed)
                    painter->drawText(mines[x][y]->getRect(), Qt::AlignVCenter, " X");
                // else
                    // painter->drawText(mines[x][y]->getRect(), Qt::AlignVCenter, " O");

            }

            if(mines[x][y]->isMarked())
            {
                painter->drawText(mines[x][y]->getRect(), Qt::AlignVCenter, " ?");
            }

            if(near > 0 && mines[x][y]->isRevealed())
            {
                // painter->drawImage(mines[x][y]->getRect(), mines[x][y]->getImage());
                painter->drawText(mines[x][y]->getRect(), Qt::AlignVCenter, QString::number(near));
            }
        }
    }
}

void Minesweeper::timerTick()
{    
    repaint();
}

void Minesweeper::mineReveal(int x,int y)
{
    if(outBounds(x,y))
        return;

    if(mines[x][y]->isRevealed())
        return;    

    mines[x][y]->setRevealed(true);
    
    if (calcNear(x, y) > 0)
        return;

    mineReveal(x-1, y-1);
    mineReveal(x-1, y+1);
    mineReveal(x+1, y-1);
    mineReveal(x+1, y+1);

    mineReveal(x-1, y);
    mineReveal(x+1, y);
    mineReveal(x, y-1);
    mineReveal(x, y+1);
}


void Minesweeper::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos;
    pressPos = event->pos();
    
    int x = int(pressPos.x()/CELL_SIZE);
    int y = int(pressPos.y()/CELL_SIZE);

    if (event->button() == Qt::LeftButton)
    {        
        if(firstClick)
        {
            // prevent mine under first opened cell:
            firstClick = false;
            do
            {
                clearMines();
                placeMines();
            }
            while(mines[x][y]->isMined());
        }
        
        if(mines[x][y]->isMined())
        {        
            qDebug() << "Dang!";
            isBombed = true;
            // reveal(x,y); // for DEBUG only
            // exit();
        }
        else
        {
            mineReveal(x,y);
        }
    }
    
    if (event->button() == Qt::RightButton)
    {        
        mines[x][y]->setFlags(!mines[x][y]->isMarked());
        compareMines();
    }
    
    repaint();

#ifdef YS2018_09_20
    event->ignore();

    if (event->button() != Qt::LeftButton)
        return;

    if (d->ignoreList.removeAll(event))
        return;

    switch (d->state) {

    case FlickablePrivate::Steady:
        event->accept();
        d->state = FlickablePrivate::Pressed;
        d->pressPos = event->pos();
        break;

    case FlickablePrivate::AutoScroll:
        event->accept();
        d->state = FlickablePrivate::Stop;
        d->speed = QPoint(0, 0);
        d->pressPos = event->pos();
        d->offset = scrollOffset();
        d->ticker->stop();
        break;

    default:
        break;
    }
#endif
}

void Minesweeper::startGame()
{
    if (!gameStarted)
    {
        //ball->resetState();
        //paddle->resetState();

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

void Minesweeper::pauseGame()
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

void Minesweeper::stopGame()
{
    killTimer(timerId);
    gameOver = true;
    gameStarted = false;
}

void Minesweeper::victory()
{
    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
}
