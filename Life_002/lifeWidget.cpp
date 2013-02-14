//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           lifeWidget.cpp
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//============================================================
//#include <QMessageBox>
//#include <QTimer>
//#include <QMouseEvent>
//#include <QDebug>
//#include <QRectF>
//#include <qmath.h>

#include "lifeWidget.h"

lifeWidget::lifeWidget(QWidget *parent) :
    QWidget(parent),    
    generations(-1),
    universeSize(100)
{
    my_colony = new colony();
    my_colony->init(universeSize, universeSize);    
    
    m_masterColor = "#000";
    // connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
    memset(&universe, false, sizeof(universe));
    
    this->setMinimumSize(universeSize*5, universeSize*5);
}

void lifeWidget::startGame(const int &number)
{
    generations = number;
    // timer->start();
}

void lifeWidget::stopGame()
{
    // timer->stop();
}

void lifeWidget::clear()
{
    for(int k = 1; k <= universeSize; k++) 
    {
        for(int j = 1; j <= universeSize; j++) 
        {
            universe[k][j] = false;
        }
    }
    update();
}

int lifeWidget::cellNumber()
{
    return universeSize;
}

int lifeWidget::getLifeIteration()
{
    return my_colony->getLifeIteration();
}
    
int lifeWidget::getCellsAlive()
{
    return my_colony->getCellsAlive();
}

void lifeWidget::setCellNumber(const int &s)
{
    universeSize = s;
    update();
}

QString lifeWidget::dump()
{
    char temp;
    QString master = "";
    for(int k = 1; k <= universeSize; k++) 
    {
        for(int j = 1; j <= universeSize; j++) 
        {
            if(universe[k][j] == true) 
            {
                temp = '*';
            } 
            else 
            {
                temp = 'o';
            }
            master.append(temp);
        }
        master.append("\n");
    }
    return master;
}

void lifeWidget::setDump(const QString &data)
{
    int current = 0;
    for(int k = 1; k <= universeSize; k++) 
    {
        for(int j = 1; j <= universeSize; j++) 
        {
            universe[k][j] = data[current] == '*';
            current++;
        }
        current++;
    }
    update();
}

int lifeWidget::interval()
{
    //return timer->interval();
    return 1 ;
}

void lifeWidget::setInterval(int msec)
{
    //timer->setInterval(msec);
}

bool lifeWidget::isAlive(int k, int j)
{
    int power = 0;
    power += universe[k+1][j];
    power += universe[k-1][j];
    power += universe[k][j+1];
    power += universe[k][j-1];
    power += universe[k+1][j+1];
    power += universe[k-1][j-1];
    power += universe[k-1][j+1];
    power += universe[k+1][j-1];
    if(universe[k][j] == false && power == 3)
        return true;
    if ((universe[k][j] == true) && ((power == 2) || (power == 3)))
        return true;
    return false;
}

void lifeWidget::newGeneration()
{

    my_colony->calculate();
    my_colony->update();
    
    this->update();

#ifdef YS_TEST_JULY_2012    
    if(generations < 0)
    {
        generations++;
    }
    bool next[102][102];
    memset(&next, false, sizeof(next));
    
    int notChanged=0;
    
    for(int k=1; k <= universeSize; k++) 
    {
        for(int j=1; j <= universeSize; j++) 
        {
            next[k][j] = isAlive(k, j);
            if(next[k][j] == universe[k][j])
            {
                notChanged++;
            }
        }
    }
    
    if(notChanged == universeSize*universeSize) 
    {
        QMessageBox::information(this,
                                 tr("Game lost sense"),
                                 tr("The End. Now game finished because all the next generations will be the same."),
                                 QMessageBox::Ok);
        stopGame();
        return;
    }

    for(int k=1; k <= universeSize; k++) 
    {
        for(int j=1; j <= universeSize; j++) 
        {
            universe[k][j] = next[k][j];
        }
    }
    update();
    generations--;
    
    if(generations == 0) 
    {
        stopGame();
        QMessageBox::information(this,
                                 tr("Game finished."),
                                 tr("Iterations finished."),
                                 QMessageBox::Ok,
                                 QMessageBox::Cancel);
    }

#endif    
}

void lifeWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    paintGrid(p);
    paintUniverse(p);
}   

void lifeWidget::mousePressEvent(QMouseEvent *e)
{
    startGame(0);
    /*
    double cellWidth = (double)width()/universeSize;
    double cellHeight = (double)height()/universeSize;
    int k = floor(e->y()/cellHeight)+1;
    int j = floor(e->x()/cellWidth)+1;
    universe[k][j] = !universe[k][j];
    update();
    */
}

void lifeWidget::paintGrid(QPainter &p)
{
    QRect borders(0, 0, width()-1, height()-1);
    QColor gridColor = Qt::blue; //m_masterColor;
    gridColor.setAlpha(10);
    p.setPen(gridColor);

    double cellWidth = (double)width()/universeSize;
    
    for(double k = cellWidth; k <= width(); k += cellWidth)
    {
        p.drawLine(k, 0, k, height());
    }
    double cellHeight = (double)height()/universeSize;
    for(double k = cellHeight; k <= height(); k += cellHeight)
    {
        p.drawLine(0, k, width(), k);
    }
    
    p.drawRect(borders);
}

void lifeWidget::paintUniverse(QPainter &p)
{
    double cellWidth = (double)width()/universeSize;
    double cellHeight = (double)height()/universeSize;
    
    for(int k=1; k < universeSize; k++) 
    {
        for(int j=1; j < universeSize; j++) 
        {
            //qDebug("getCellAliveStatus: %d, %d\n", k, j);    
            if(1 == my_colony->getCellAliveStatus(k, j)) 
            {
                qreal left = (qreal)(cellWidth*j - cellWidth);
                qreal top = (qreal)(cellHeight*k - cellHeight);
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                // p.fillRect(r, QBrush(m_masterColor));
                p.fillRect(r, QBrush(my_colony->getCellColor(k, j)));
            }
        }
    }

#ifdef YS_TEST_JULY_2012
    double cellWidth = (double)width()/universeSize;
    double cellHeight = (double)height()/universeSize;
    for(int k=1; k <= universeSize; k++) 
    {
        for(int j=1; j <= universeSize; j++) 
        {
            if(universe[k][j] == true) 
            {
                qreal left = (qreal)(cellWidth*j-cellWidth);
                qreal top = (qreal)(cellHeight*k-cellHeight);
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                p.fillRect(r, QBrush(m_masterColor));
            }
        }
    }
#endif

}

QColor lifeWidget::masterColor()
{
    return m_masterColor;
}

void lifeWidget::setMasterColor(const QColor &color)
{
    m_masterColor = color;
    update();
}
