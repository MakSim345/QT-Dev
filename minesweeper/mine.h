#pragma once

#include "gen.h"
#include "brick.h"

class Mine
{
public:
    Mine(int x, int y)
        : isBombHere(false)
        , isFlagSet(false)
        , isBlockRevealed(false)
        , bombsNearMe(0)
    {
        brick = new Brick(x*CELL_SIZE, y*CELL_SIZE);
    }
    ~Mine();

public:
    bool isMined()     { return isBombHere; };
    bool isFlagged()    { return isFlagSet; };
    bool isRevealed()  { return isBlockRevealed; };

    QRect getRect()
    {
        return brick->getRect();
    };

    QImage getImageUntouched()
    {
        return brick->getImageBrickUntouched();
    };

    QImage getImageFlagged()
    {
        return brick->getImageBrickFlagged();
    };

    QImage getImageOpened()
    {
        return brick->getImageBrickOpened();
    };

    QImage getImageTheBomb()
    {
        return brick->getImageBrickTheBomb();
    };

    void setMines(bool pMine)      { isBombHere = pMine; };
    void setRevealed(bool pRev)    { isBlockRevealed = pRev; };

    void setTheFlag(bool pFlagValue)
    {
        isFlagSet = pFlagValue;
    }

    int getNumberMinesNearMe() { return bombsNearMe; };
    void setBombNumberNearMe(int pBombNum)
    {
        bombsNearMe = pBombNum;
    }

private:
    bool isBombHere; // entry is 1 for having a mine and 0 for not
    bool isFlagSet;  // entry is true if you have flagged that spot
    bool isBlockRevealed; // entry is true if that spot is revealed

    int bombsNearMe; // entry is 1 for having a mine and 0 for not

    Brick *brick;
};
