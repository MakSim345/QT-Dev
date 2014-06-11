#ifndef GLOBAL_H
#define GLOBAL_H
/*********************************************************************

  GLOBAL.H
  01.10.2006 Initial coding YS          

**********************************************************************/
#define WIN32_APP
#ifdef WIN32_APP
  #include <Windows.h>
#endif

#include <QDebug>

// nSpeedRegulator iteration changes in milliseconds. See ini-file.
const int nSpeedRegulator = 500;
const int nIterationNumber = 100;
// int nRunOnce = 0;

#define screen_width  800
#define screen_height 600

#define L_VERSION "0.0.2 "

#ifndef L_VERSION
 #define L_VERSION "VERSION UNDEFINE! "
#endif    

//#define SET_MM_LOENGLISH 
//#define SET_MM_HIMETRIC

#define _CRTDBG_MAP_ALLOC

#define MAX_VAL 5

#define TIME_TICK_INTERVAL 5

//#define dimention_x 198 - orig
// #define dimention_y 145 - orig

#ifndef TRUE
#define TRUE -1
#endif
#ifndef FALSE
#define FALSE 0
#endif

// #define TRACE printf
    
#define BUFFER_SIZE 150
#define MONITOR_TIMEOUT 18000  // about 30 minutes (10 Hz counter)
#define DISPLAY_STOPPED  0
#define DISPLAY_RUNNING  1
#define ORIGIN_KB 0    

#define  TX0023     "\n\rLast Compilation: %s, %s"
    
//#define MIN(x,y)     (((x) < (y)) ? (x) : (y))
//#define MAX(x,y)     (((x) > (y)) ? (x) : (y))    

#define MEAN_ARR 136
        
#define RND_MAX 10        

#define PENTIUM
            
#define MHz 1000

//int Y_p, X_p;
//int mY, mX;

/*
const int arena_width  = 640,
          arena_height = 384,
          arena_x      = 0,
          arena_y      = 8;
*/
const int arena_width  = 795,
          arena_height = 583,
          arena_x      = 0,
          arena_y      = 8;

const int status_width  = 620;
const int status_height = 8;
const int status_x      = 0;
const int status_y      = 0;

int makecol(int R, int G, int B);

#endif // GLOBAL_H
