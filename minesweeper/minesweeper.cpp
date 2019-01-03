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

        for(int x=0; x<gridW; x++)
        {
            for(int y=0; y<gridH; y++)
            {
                mines[x][y] = new Mine(x, y);
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
    firstClick = true;
    isBombed = false;
    gameWon = false;
    clearMines();
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

    drawObjects(&painter);
#ifdef YS_11_10_2018
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
            mines[x][y]->setMines(false);
            mines[x][y]->setFlags(false);
            mines[x][y]->setRevealed(false);
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
    minesFlagged(markedCounter);
    if ((matchCounter == numMines) && (matchCounter == markedCounter))
    {
        retVal = true;
        qDebug() << "WIN !";
        emit stopped(WINWIN);
        gameWon = true;
        gameStarted = false;
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
            int coordX = mines[x][y]->getRect().x();
            int coordY = mines[x][y]->getRect().y();

            if(false == mines[x][y]->isRevealed())
            {
                // draw untouched cover:
                painter->drawImage(mines[x][y]->getRect(), mines[x][y]->getImage());
            }

            if(mines[x][y]->isMined())
            {
                if (isBombed)
                    // painter->drawText(mines[x][y]->getRect(), Qt::AlignVCenter, " X");
                    painter->drawText(coordX+CELL_SIZE/3, coordY+CELL_SIZE/1.3, "X");
                //else                    
                    //painter->drawText(coordX+CELL_SIZE/3, coordY+CELL_SIZE/1.3, "O");

            }

            if(mines[x][y]->isMarked())
            {
                // painter->drawText(mines[x][y]->getRect(), Qt::AlignVCenter, " ?");
                if (!isBombed)
                { 
                    // after all bombs kaboom, no flags? 
                    painter->drawText(coordX+CELL_SIZE/3, coordY+CELL_SIZE/1.3, "?");
                }
            }

            if(mines[x][y]->isRevealed())
            {   
                // TODO: draw "opened" cell, add number later if any.
                // TODO: change color of the digit accordingly.
                if (near > 0)
                {
                    painter->drawText(coordX+CELL_SIZE/3, coordY+CELL_SIZE/1.3, QString::number(near));
                }
                
            }
        }
    }
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

void Minesweeper::bombExplosed()
{
    qDebug() << "Dang!";
    isBombed = true;
    gameStarted = false;
    emit stopped(LOSE);
}

void Minesweeper::mousePressEvent(QMouseEvent *event)
{
    if ((isBombed) || (gameWon))
        return;

    QPoint pressPos;
    pressPos = event->pos();
    
    int x = int(pressPos.x()/CELL_SIZE);
    int y = int(pressPos.y()/CELL_SIZE);

    if (event->button() == Qt::LeftButton)
    {        
        if(firstClick)
        {
            // prevent placing mine under first-clicked cell:
            startGame();
            do
            {
                clearMines();
                placeMines();
            }
            while(mines[x][y]->isMined());
        }
        
        if(mines[x][y]->isMined())
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
        mines[x][y]->setFlags(!mines[x][y]->isMarked());
        compareMines();
    }
    
    repaint();
}

void Minesweeper::startGame()
{
    if (!gameStarted)
    {
        firstClick = false;
        emit started();
        gameOver = false;
        gameWon = false;
        gameStarted = true;
    }
}

void Minesweeper::pauseGame()
{
    if (paused)
    {
        paused = false;
    }
    else
    {
        paused = true;     
    }
}

void Minesweeper::stopGame()
{   
    gameOver = true;
    gameStarted = false;
}

void Minesweeper::victory()
{
    gameWon = true;
    gameStarted = false;
}
