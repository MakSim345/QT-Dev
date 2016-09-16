#ifndef gf_included_cell_h
#define gf_included_cell_h

/*----------------------------------------------------------------
 * cell.h -- interface to cell module
 *----------------------------------------------------------------
 * 
 */

#include "gen.h"

/*
struct s
{
    int x, y;       // Coordinates (of top left point) on the screen
    int l;          // len
    int m_Count;    // len counter
    int colour;
    int m_Direction;

    //struct snake_count m_snake[dimention_x][dimention_y];
    struct input_t *input;     // input state

    // drawn_*:
     //  These next variables describe a rectangle in the arena
     //  that covers the snake's image; they're updated when the
     //  snake is drawn so that the erasing code knows which area
     //  of the display to restore.
     //
    int drawn_x,drawn_y,drawn_l,drawn_h;
};

*/

class cell // Storage of SCR id's for giving them grant to talk.
{
  public:
    // Constructor
    //cell(struct input_t *);
    cell();

    // Destructor
    ~cell();

    void setCellColor();
    int  getCellColor();

    void setNextLevel();
    int  getLifeLevel() {return mLifeLevel;}

    int  getAliveStatus();
    void setAliveStatus(int);

    void setNextLife(int);
    int  getNextLife() {return mNextLife;}

    void setCoord(int, int);
    
    void killCell();
    void setCellAlive();

 protected:

    struct input_t *input;     // input state
    int X;
    int Y;
    int m_i;
    int m_j;
    int mAlive;
    int mColor;
    int mNextLife;
    int mLifeLevel;

};
#endif

