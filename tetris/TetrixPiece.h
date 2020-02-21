#pragma once

#include "gen.h"

class TetrixPiece
{
public:
    TetrixPiece() { setShape(NoShape); }
    void setRandomShape();
    void setShape(TetrixShape shapeP);

    TetrixShape shape() const { return pieceShape; }

    int x(int index) const {return coords[index][0];}
    int y(int index) const {return coords[index][1];}

    int minX() const;
    int maxX() const;
    int maxY() const;
    int minY() const;

    TetrixPiece rotatedLeft() const;
    TetrixPiece rotatedRight() const;

    int getRand();
   
private:
    void setX(int index, int x) {coords[index][0] = x;}
    void setY(int index, int y) {coords[index][1] = y;}

    TetrixShape pieceShape;
    int coords[4][2];
};
