#ifndef _COLONY_H_
#define _COLONY_H_

/*----------------------------------------------------------------
 * colony.h -- 
 *----------------------------------------------------------------
 * 
 */

#include "gen.h"
#include "cell.h"

class colony // Storage of SCR id's for giving them grant to talk.
{
  public:
    // Constructor
    //cell(struct input_t *);
    colony();

    // Destructor
    ~colony();
    void update();
    void init(int screen_dimention_x, int screen_dimention_y);
    void calculate();
    int neigb_calculate (int i, int j);
    void set_glyde_config();
    void set_manual_config();
    void set_random_config();
    void set_all_alive_config();

    int isReadyToDraw() {return _isReadyToDraw;}
    void setReadyToDraw(int set_val) {_isReadyToDraw = set_val;}

    int get_dimention_x() {return dimention_x;}
    int get_dimention_y() {return dimention_y;}

    int get_cell_block() {return cell_block;}
    int getCellAliveStatus(int i, int j);
    int getCellColor(int i, int j);

    int getLifeIteration() {return life_iteration;}
    int getCellsAlive() {return live_cells;}
    
 private:
    int mLifeLevel;
    int life_iteration;
    int live_cells;
    int nGlydeConfig;
    int nRandomConfig;
    int nRandomLine;
    int _isReadyToDraw;
    int dimention_x;
    int dimention_y;
    int cell_block;
    cell **cell_array;
};

#endif

