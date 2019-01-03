#pragma once

#include <QImage>
#include <QRect>

class Brick 
{
public:
    Brick(int, int);
    ~Brick();

public:    
    QRect getRect();
    void setRect(QRect);
    QImage& getImageUntouched();
    // QImage& getImage();
    // QImage& getImage();

private:
    QImage imageBrick;
    QRect rect;    
};

class Mine 
{
public:
    Mine(int x, int y)
        : mine(false)
        , flags(false)
        , revealed(false)
    {        
        brick = new Brick(x*CELL_SIZE, y*CELL_SIZE);
    }
    ~Mine();

public:
    bool isMined()     { return mine; };
    bool isMarked()    { return flags; };
    bool isRevealed()  { return revealed; };
    QRect getRect()    { return brick->getRect(); };

    QImage getImage()  
    { 
        return brick->getImageUntouched(); 
    };

    void setMines(bool pMine)      { mine = pMine; };
    void setFlags(bool pFlagValue) { flags = pFlagValue; };
    void setRevealed(bool pRev)    { revealed = pRev; };
    
private:    
    bool mine;     // entry is 1 for having a mine and 0 for not
    bool flags;    // entry is true if you have flagged that spot
    bool revealed; // entry is true if that spot is revealed

    Brick *brick;
};