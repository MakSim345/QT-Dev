/*********************************************************************

  monitor.h  
  Borland TURBO C++ 3.0
  13.11.2000
  
**********************************************************************/
#ifndef _MONITOR_H_
#define _MONITOR_H_

 #define OMRON_LOG 0
 #define S200_LOG  1
 #define GPS_LOG   2
 #define GYRO_LOG  3

  #define DISPLAY_STOPPED  0
  #define DISPLAY_RUNNING  1
  #define ORIGIN_KB 0

 int monitor(int);
 
 void ResetDisp();
 void WriteToLog(int);
 void ReadFromLog();
 void ProcessKeyDown(); 

#endif // _MONITOR_H_


