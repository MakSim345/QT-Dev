/*----------------------------------------------------------------
 * colony.cpp -- colony module
 *----------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "colony.h"

colony::colony():
    cell_block(6)
{    
    life_iteration = 0;
    live_cells = 0;
    nGlydeConfig = 0;
    nRandomConfig = 1;
    nRandomLine = 0;
    _isReadyToDraw = 0;    
}

colony::~colony()
{
    // TODO: delete:
    //cell_array = new cell*[dimention_x];
    // int i = 0;
}

int colony::getCellAliveStatus(int i, int j)
{
    return cell_array[i][j].getAliveStatus();
}

int colony::getCellColor(int i, int j)
{
    return cell_array[i][j].getCellColor();
}

/********************************************************************

  Declaration:
  Call: InitColony()
  Input: none
  Returns: none
  23.12.2006 Initial coding YS

*********************************************************************/
void colony::init(int screen_dimention_x, int screen_dimention_y)
{
    int i, j;

    if (life_iteration)
        return;

    //dimention_x = (screen_dimention_x/cell_block)*1.05; //+(cell_block/2);
    //dimention_y = (screen_dimention_y/cell_block)*1.04;

    //dimention_x = (screen_dimention_x/(cell_block+3));
    //dimention_y = (screen_dimention_y/(cell_block+3));
    
    dimention_x = screen_dimention_x;
    dimention_y = screen_dimention_y;

    cell_array = new cell*[dimention_x];

    for(int i = 0; i < dimention_x; i++)
    {
        cell_array[i] = new cell[dimention_y];
        // m_rect[i] = new CRect[dimention_y];
    }
    
    
    for (i=0; i<dimention_x;i++)
    {
        for (j=0; j<dimention_y; j++)
        {
            // cell_array[i][j] = new cell();
            cell_array[i][j].setCoord(i, j);
        }
    }
    
    
    if (1 == nRandomConfig)
    {
        this->set_random_config();
    }

    if (1 == nGlydeConfig)
    {
        this->set_glyde_config();
    }
}

void colony::set_all_alive_config()
{
    for (int i=0; i<dimention_x; i++)
    {
        for (int j=0; j<dimention_y; j++)
        {
            cell_array[i][j].setCellAlive();
        }
    }
}

void colony::set_random_config()
{
    // init random table:
    srand(time(NULL));
    int max_cell_alive = (1 + rand() % (dimention_x * dimention_y)); 
    // t.TRACEY("Total amount of cells: %d\n", max_cell_alive);
    for (int r = 0; r < max_cell_alive; r++)
    {
        int i = (1+rand()%(dimention_x-1));
        int j = (1+rand()%(dimention_y-1));
        //i=(1+rand()%50);
        //j=(1+rand()%50);
        if ( (j > nRandomLine) && ( j != 0))
        {
            cell_array[i][j].setCellAlive();
            // cell_array[i][j].nColor = makecol(0, 255, 0);
        }
    }
}

//#define LINE_VERT
//#define LINE_HORIZ
#ifdef LINE_HORIZ

    Rand = dimention_x;
    live_cells = Rand;
    for (r = 0; r < Rand; r++)
    {
        cell_array[r][50].setCellAlive();
    }

#endif


#ifdef LINE_VERT

    Rand = dimention_y;
    live_cells = Rand;
    for (r = 0; r < Rand; r++)
    {
        cell_array[i][j].setCellAlive();
    }

#endif

void colony::set_glyde_config()
{
    cell_array[81][7].setCellAlive();
    cell_array[82][7].setCellAlive();
    cell_array[82][6].setCellAlive();
    cell_array[91][5].setCellAlive();
    cell_array[91][6].setCellAlive();
    cell_array[91][7].setCellAlive();
    cell_array[92][4].setCellAlive();
    cell_array[93][3].setCellAlive();
    cell_array[94][3].setCellAlive();
    cell_array[92][8].setCellAlive();
    cell_array[93][9].setCellAlive();
    cell_array[94][9].setCellAlive();
    cell_array[104][6].setCellAlive();
    cell_array[105][6].setCellAlive();
    cell_array[105][5].setCellAlive();
    cell_array[104][10].setCellAlive();
    cell_array[105][10].setCellAlive();
    cell_array[105][11].setCellAlive();
    cell_array[94][9].setCellAlive();
    cell_array[94][9].setCellAlive();
    cell_array[94][9].setCellAlive();
    cell_array[107][7].setCellAlive();
    cell_array[107][8].setCellAlive();
    cell_array[107][9].setCellAlive();
    cell_array[108][7].setCellAlive();
    cell_array[108][8].setCellAlive();
    cell_array[108][9].setCellAlive();
    cell_array[109][8].setCellAlive();
    cell_array[115][9].setCellAlive();
    cell_array[116][9].setCellAlive();
    cell_array[116][8].setCellAlive();
}

void colony::set_manual_config()
{
    cell_array[1][0].setCellAlive();
    cell_array[2][0].setCellAlive();
    cell_array[3][0].setCellAlive();
    cell_array[10][0].setCellAlive();

    cell_array[1][1].setCellAlive();
    cell_array[2][1].setCellAlive();
    cell_array[3][1].setCellAlive();
    cell_array[4][1].setCellAlive();

}

/* neigb_calculate:
 *  This calculates the cell lives
 */
int colony::neigb_calculate(int i, int j)
{
    int k;
    int RecLife[8] = {0,0,0,0,0,0,0,0};
    int ReturnValue = 0;
    //int i;
    //int j;
    
//#ifdef TEST_2
    if ((0 == i) && ((dimention_y-1) >= j))
    {
        if (0 == j) // upper left corner
        {
            RecLife[3] = cell_array[0][1].getAliveStatus();
            RecLife[4] = cell_array[1][1].getAliveStatus();
            RecLife[5] = cell_array[1][0].getAliveStatus();
            ReturnValue = RecLife[3]+RecLife[4]+RecLife[5];
            return ReturnValue;
        }
        else if ((dimention_y-1) == j)// lower left corner
        {
            RecLife[1] = cell_array[0][j-1].getAliveStatus();
            RecLife[2] = cell_array[1][j-1].getAliveStatus();
            RecLife[3] = cell_array[1][j].getAliveStatus();
            ReturnValue =  RecLife[1]+RecLife[2]+RecLife[3];
            return ReturnValue;
        }
        else // left column
        {
            RecLife[1] = cell_array[i][j-1].getAliveStatus();
            RecLife[2] = cell_array[i+1][j-1].getAliveStatus();
            RecLife[3] = cell_array[i+1][j].getAliveStatus();
            RecLife[4] = cell_array[i+1][j+1].getAliveStatus();
            RecLife[5] = cell_array[i][j+1].getAliveStatus();
            ReturnValue =  RecLife[1]+RecLife[2]+RecLife[3]+RecLife[4]+RecLife[5];
            return ReturnValue;
        }
     }

        if (((dimention_x-1) == i) && ((dimention_y-1) >= j))
        {
     if (0 == j) // upper right corner
         {
             RecLife[5] = cell_array[i][1].getAliveStatus();
             RecLife[6] = cell_array[i-1][j+1].getAliveStatus();
             RecLife[7] = cell_array[i-1][j].getAliveStatus();
             ReturnValue =  RecLife[5]+RecLife[6]+RecLife[7];
             return ReturnValue;
         }
         else if ((dimention_y-1) == j )// lower right corner
         {
            RecLife[7] = cell_array[i-1][j].getAliveStatus();
            RecLife[0] = cell_array[i-1][j-1].getAliveStatus();
            RecLife[1] = cell_array[i][j-1].getAliveStatus();
            ReturnValue =  RecLife[0]+RecLife[1]+RecLife[7];
            return ReturnValue;
         }
     else // right column
         {
            RecLife[5] = cell_array[i][j+1].getAliveStatus();
            RecLife[6] = cell_array[i-1][j+1].getAliveStatus();
            RecLife[7] = cell_array[i-1][j].getAliveStatus();
            RecLife[0] = cell_array[i-1][j-1].getAliveStatus();
            RecLife[1] = cell_array[i][j-1].getAliveStatus();
            ReturnValue =  RecLife[0]+RecLife[1]+RecLife[5]+RecLife[6]+RecLife[7];
            return ReturnValue;
         }
      }

    if ((0 < i) && (0 == j))
        {
          // upper row
            RecLife[3] = cell_array[i+1][j].getAliveStatus();
            RecLife[4] = cell_array[i+1][j+1].getAliveStatus();
            RecLife[5] = cell_array[i][j+1].getAliveStatus();
            RecLife[6] = cell_array[i-1][j+1].getAliveStatus();
            RecLife[7] = cell_array[i-1][j].getAliveStatus();
            ReturnValue =  RecLife[3]+RecLife[4]+RecLife[5]+RecLife[6]+RecLife[7];
            return ReturnValue;
        }

        if ((0 < i) && ((dimention_y-1) == j))
        {
          // lower row
            RecLife[7] = cell_array[i-1][j].getAliveStatus();
            RecLife[0] = cell_array[i-1][j-1].getAliveStatus();
            RecLife[1] = cell_array[i][j-1].getAliveStatus();
            RecLife[2] = cell_array[i+1][j-1].getAliveStatus();
            RecLife[3] = cell_array[i+1][j].getAliveStatus();
            ReturnValue = RecLife[0]+RecLife[1]+RecLife[2]+RecLife[3]+RecLife[7];
            return ReturnValue;
        }
        //normal situation - 8 neigborough cells around:
        RecLife[0] = cell_array[i-1][j-1].getAliveStatus();
        RecLife[1] = cell_array[i][j-1].getAliveStatus();
        RecLife[2] = cell_array[i+1][j-1].getAliveStatus();
        RecLife[3] = cell_array[i+1][j].getAliveStatus();
        RecLife[4] = cell_array[i+1][j+1].getAliveStatus();
        RecLife[5] = cell_array[i][j+1].getAliveStatus();
        RecLife[6] = cell_array[i-1][j+1].getAliveStatus();
        RecLife[7] = cell_array[i-1][j].getAliveStatus();

 for (k=0; k<8; k++)
    {
      // count how much live cells are around:
        if(RecLife[k]>0)
        {
         ReturnValue = ReturnValue + RecLife[k];
        }
    }
    //#endif //ifdef TEST_2
    return ReturnValue;

}

/* 
    colony calculate cell status for next step
*/
void colony::calculate()
{
  int i, j;
  int LivesAround = 0;
  
  life_iteration++;

    for (i=0; i<dimention_x; i++)
    {
        for (j=0; j<dimention_y; j++)
        {
            LivesAround = neigb_calculate(i, j);

            if (cell_array[i][j].getAliveStatus() == 1)
            {
                if ((LivesAround < 2 ) || (LivesAround > 3 )) // cell must die.
                {
                    //t.TRACEY("iter: %d. cell[%d][%d] alive. Has %d nb. Has to Die. \n", life_iteration, i, j, LivesAround);
                    cell_array[i][j].setNextLife(0);
                 }
                 else // cell goes to next level.
                 {
                    //t.TRACEY ("iter: %d. cell[%d][%d] alive. Has %d nb. GoTo Next Level. \n", life_iteration, i, j, LivesAround);
                    cell_array[i][j].setNextLife(1);
                    cell_array[i][j].setNextLevel(); // not more than 5!
                    cell_array[i][j].setCellColor();
                 }
            }
            else
            {
            //t.TRACEY ("iter: %d. Cell[%d][%d] dead. Has %d nb. \n", life_iteration, i, j, LivesAround);
                if (3 == LivesAround ) // new cell must born.
                 {
                    cell_array[i][j].setNextLife(1);
                    cell_array[i][j].setNextLevel(); // not more than 5!
                    cell_array[i][j].setCellColor();
                    //t.TRACEY ("iter: %d. Cell[%d][%d] was born. \n", life_iteration, i, j);
                }
            }
        }
    }
}

void colony::update()
{
    int i, j;
    live_cells = 0;

    for (i=0; i<dimention_x;i++)
    {
     for (j=0; j<dimention_y; j++)
     {
        // AliveStatus = NextLife;
        if (1 == cell_array[i][j].getAliveStatus())
        {
            if (0 == cell_array[i][j].getNextLife())
            {
                cell_array[i][j].killCell();
            }
        }
        else
        {
            cell_array[i][j].setAliveStatus(cell_array[i][j].getNextLife());
            cell_array[i][j].setNextLife(0);
        }
        if (1 == cell_array[i][j].getAliveStatus())
        {
             live_cells++;
        }
      }
    }

}
// #endif
