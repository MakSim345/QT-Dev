/*----------------------------------------------------------------
 * cell.cpp -- celle module
 *----------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "gen.h"
#include "cell.h"

cell::cell()
{
    mAlive     = 0;
    mLifeLevel = 0;
    mNextLife   = 0;
    mColor  = makecol(255, 255, 255);
}

cell::~cell()
{
    //printf ("I'm dead.");
}

void cell::killCell()
{
    mAlive = 0;
    mLifeLevel = 0;
    mColor  = makecol(255, 255, 255);
}

int cell::getAliveStatus()
{
    int i = this->m_i;
    int j = this->m_j;
    return mAlive;
}

void cell::setCellAlive()
{
    mAlive = 1;
    mLifeLevel = 1;
    mColor  = makecol(0, 255, 0);
}

void cell::setNextLife(int i)
{
    mNextLife = i;
}

void cell::setNextLevel()
{
    mLifeLevel++;
    if (mLifeLevel > 5)
    {
       mLifeLevel = 5;
    }
}

void cell::setAliveStatus(int i)
{
    mAlive = i;
}

void cell::setCoord(int i, int j)
{
    m_i = i;
    m_j = j;
}

int cell::getCellColor()
{
 return mColor;
}

void cell::setCellColor()
{
    switch (mLifeLevel)
    {
        case 0:
        {
            // dead cell:
            mColor = makecol(255, 255, 255);
            break;
        }
        
        case 1:
        {
            // new born cell, GREEN
            mColor = makecol(0, 255, 0);
            break;
        }
        case 2:
        {
            //  cell RED
            mColor = makecol(255, 0, 0);
            break;
        }
        case 3:
        {
            // YELLOW ?
            mColor = makecol(0, 255, 255);
            break;
        }
        case 4:
        {
            //BLUE
            mColor = makecol(0, 0, 255);
            break;
        }
        case 5:
        {
            // last level - BLACK
            mColor = makecol(0, 0, 0);
            break;
        }
    }// switch end
}

int makecol(int R, int G, int B)
{
    // TODO: RGB function has to be independent from windows.h
    // use API or interface?
    return RGB(R,G,B);
}


// #endif
