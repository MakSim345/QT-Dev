#include "TetrixPiece.h"

void TetrixPiece::setRandomShape()
{
    // setShape(TetrixShape(QRandomGenerator::global()->bounded(7) + 1));
    setShape(TetrixShape(getRand() + 1));
}



void TetrixPiece::setShape(TetrixShape shapeP)
{
    static const int coordsTable[8][4][2] = {
      { {0,  0}, {0,  0}, {0,  0}, {0,  0} }, //NoShape
      { {0, -1}, {0,  0}, {-1, 0}, {-1, 1} }, //ZShape
      { {0, -1}, {0,  0}, {1,  0}, {1,  1} }, //SShape
      { {0, -1}, {0,  0}, {0,  1}, {0,  2} }, //LineShape
      { {-1, 0}, {0,  0}, {1,  0}, {0,  1} }, //TShape
      { {0,  0}, {1,  0}, {0,  1}, {1,  1} }, //SquareShape
      { {-1,-1}, {0, -1}, {0,  0}, {0,  1} }, //LShape
      { {1, -1}, {0, -1}, {0,  0}, {0,  1} }, //MirroredLShape
    };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; ++j)
            coords[i][j] = coordsTable[shapeP][i][j];
    }

    pieceShape = shapeP;
}

int TetrixPiece::minX() const
{
    int min = coords[0][0];
    for (int i = 0; i < 4; ++i)
    {
        min = qMin(min, coords[i][0]);
    }
    return min;
}

int TetrixPiece::maxX() const
{
    int max = coords[0][0];
    for (int i = 0; i < 4; ++i)
    {
        max = qMin(max, coords[i][0]);
    }
    return max;
}

TetrixPiece TetrixPiece::rotatedLeft() const
{
    if (pieceShape == SquareShape)
        return *this;

    TetrixPiece retVal;
    retVal.pieceShape = pieceShape;
    for (int i = 0; i < 4; i++)
    {
        retVal.setX(i, y(i));
        retVal.setY(i, -x(i));
    }

    return retVal;
}


TetrixPiece TetrixPiece::rotatedRight() const
{
    if (pieceShape == SquareShape)
        return *this;

    TetrixPiece retVal;
    retVal.pieceShape = pieceShape;
    for (int i = 0; i < 4; i++)
    {
        retVal.setX(i, -y(i));
        retVal.setY(i, x(i));
    }

    return retVal;
}

int TetrixPiece::getRand()
{
    static int nFirstTime = 0;
    int nRandomValue = 0;
    QString tmp;

    if (0 == nFirstTime)
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        nFirstTime = 1;
    }

    nRandomValue = (int)qrand() % 7; 
    
    return nRandomValue;
}

