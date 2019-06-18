#include "minesweeper.h"
#include <QPainter>
#include <QApplication>

Minesweeper::Minesweeper(QWidget *parent)
    : QWidget(parent)
{
        x = 0;
        gameOver = false;
        isGameWon = false;
        isGamePaused = false;
        isGameStarted = false;

        for(int x=0; x<gridW; x++)
        {
            for(int y=0; y<gridH; y++)
            {
                bombOn[x][y] = new Mine(x, y);
             }
        }
        startNewGame();
        this->setFixedSize(CELL_SIZE*gridW, CELL_SIZE*gridW);
}

Minesweeper::~Minesweeper()
{
    //delete ball;
    //delete paddle;
}

void Minesweeper::startNewGame()
{
    isFirstClick = true;
    isBombed = false;
    isGameWon = false;
    clearMines();
}

bool Minesweeper::outBounds(int x, int y)
{
    bool retVal = x<0||y<0||x>=gridW||y>=gridH;
    return retVal;
}

int Minesweeper::calcBombsNearMe(int x, int y)
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
            if (bombOn[oX+x][oY+y]->isMined())
                i++;
        }
    }
    return i;
}


void Minesweeper::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);

    drawObjects(&painter);
#ifdef YS_11_10_2018
    if (gameOver)
    {
        finishGame(&painter, "Game lost");
    }
    else if(isGameWon)
    {
        finishGame(&painter, "Victory");
    }
    else
    {
        drawObjects(&painter);
    }
#endif
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

int Minesweeper::getRandom(int pCoord)
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
        int x = int(getRandom(gridW));
        int y = int(getRandom(gridH));
        if(bombOn[x][y]->isMined())
        {
            continue;
        }
        // qDebug() << "set bomb to" << x << "," << y;
        bombOn[x][y]->setMines(1);
        i++;
    }

    // calculate and remember bombs near me:
    for(int x=0; x<gridW; x++)
    {
        for(int y=0; y<gridH; y++)
        {
            bombOn[x][y]->setBombNumberNearMe(calcBombsNearMe(x, y));
        }
    }
}

void Minesweeper::clearMines()
{
    for(int x=0; x<gridW; x++)
    {
        for(int y=0; y<gridH; y++)
        {
            bombOn[x][y]->setMines(false);
            bombOn[x][y]->setTheFlag(false);
            bombOn[x][y]->setRevealed(false);
        }
    }
    repaint();
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
            if (bombOn[x][y]->isMined() && bombOn[x][y]->isFlagged())
            {
                matchCounter++;
            }
            if (bombOn[x][y]->isFlagged())
            {
                markedCounter++;
            }
        }
    }

    qDebug() << "Marked:" << markedCounter << "Match: "<< matchCounter;
    emit minesFlagged(markedCounter);
    if ((matchCounter == numMines) && (matchCounter == markedCounter))
    {
        retVal = true;
        qDebug() << "WIN !";
        emit stopped(WINWIN);
        isGameWon = true;
        isGameStarted = false;
    }

    return retVal;
}

void Minesweeper::drawObjects(QPainter *painter)
{
    for(int x=0; x<gridW; x++)
    {
        for(int y=0; y<gridH; y++)
        {
            int bombsNearMe = bombOn[x][y]->getNumberMinesNearMe();
            int coordX = bombOn[x][y]->getRect().x();
            int coordY = bombOn[x][y]->getRect().y();

            if(bombOn[x][y]->isRevealed())
            {
                // draw "opened" cell, add a number later if any bombs near me
                painter->drawImage(bombOn[x][y]->getRect(), bombOn[x][y]->getImageOpened());

                // TODO: change the digit color in dependency of bombs numbers around.
                if (bombsNearMe > 0)
                {
                    painter->drawText(coordX+CELL_SIZE/3, coordY+CELL_SIZE/1.3, QString::number(bombsNearMe));
                }
            }
            else
            {
                // draw untouched cover:
                painter->drawImage(bombOn[x][y]->getRect(), bombOn[x][y]->getImageUntouched());
            }

            if(bombOn[x][y]->isFlagged())
            {
                // painter->drawImage(bombOn[x][y]->getRect(), bombOn[x][y]->getImageMarked());
                // painter->drawText(coordX+CELL_SIZE/3, coordY+CELL_SIZE/1.3, "?");
                painter->drawImage(bombOn[x][y]->getRect(), bombOn[x][y]->getImageFlagged());
            }

            if(bombOn[x][y]->isMined())
            {
                if (isBombed)
                {
                    // painter->drawText(coordX+CELL_SIZE/3, coordY+CELL_SIZE/1.3, "*");
                    painter->drawImage(bombOn[x][y]->getRect(), bombOn[x][y]->getImageTheBomb());
                }
                else
                {
                    // this is for DEBUG only
                    //painter->drawText(coordX+CELL_SIZE/3, coordY+CELL_SIZE/1.3, "O");
                }
            }
        }
    }
}

void Minesweeper::mineReveal(int x, int y)
{
    /************************************************************************/
    /*
    /*  Recursive function. Can cause the stack overflow.
    */
    /************************************************************************/

    if(outBounds(x, y))
        return;

    if(bombOn[x][y]->isRevealed())
        return;

    if(bombOn[x][y]->isFlagged())
        return;

    bombOn[x][y]->setRevealed(true);

    if (bombOn[x][y]->getNumberMinesNearMe() > 0)
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

void Minesweeper::bombExplosed()
{
    qDebug() << "Dang!";
    isBombed = true;
    isGameStarted = false;
    emit stopped(LOSE);
}

void Minesweeper::mousePressEvent(QMouseEvent *event)
{
    if ((isBombed) || (isGameWon))
        return;
}

void Minesweeper::mouseReleaseEvent(QMouseEvent *event)
{
    if ((isBombed) || (isGameWon))
        return;

    QPoint pressPos;
    pressPos = event->pos();

    int x = int(pressPos.x()/CELL_SIZE);
    int y = int(pressPos.y()/CELL_SIZE);

    if (event->button() == Qt::LeftButton)
    {
        if(isFirstClick)
        {
            // prevent placing bomb under first-clicked cell:
            startGame();
            do
            {
                clearMines();
                placeMines();
            }
            while(bombOn[x][y]->isMined());
        }

        if(bombOn[x][y]->isMined())
        {
            bombExplosed();
        }
        else
        {
            mineReveal(x, y);
        }
    }

    if (event->button() == Qt::RightButton)
    {
        bool bFlagged = bombOn[x][y]->isFlagged();
        bool bRevealed = bombOn[x][y]->isRevealed();

        if (!bRevealed)
        {
            bombOn[x][y]->setTheFlag(!bFlagged);
        }
        compareMines();
    }

    repaint();
}

void Minesweeper::startGame()
{
    if (!isGameStarted)
    {
        isFirstClick = false;
        emit started();
        gameOver = false;
        isGameWon = false;
        isGameStarted = true;
    }
}

void Minesweeper::pauseGame()
{
    if (isGamePaused)
    {
        isGamePaused = false;
    }
    else
    {
        isGamePaused = true;
    }
}

void Minesweeper::stopGame()
{
    gameOver = true;
    isGameStarted = false;
}

void Minesweeper::victory()
{
    isGameWon = true;
    isGameStarted = false;
}
