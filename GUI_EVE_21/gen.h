#ifndef _GEN_H_
#define _GEN_H_

// to prevent "warning C4996: 'foo' was declared deprecated":
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE 

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#define IRIS_WIN32_VCC

#define NTEL_PLATFORM_CONVERT

#define TIME_TICK_INTERVAL 1000

#define VERSION "0.6.2"

// This didn't work:
// #define rdtsc __asm __emit 0fh __asm __emit 031h

#define PENTIUM
#define MHz 3000
#define WIN32_APP

#define NO_CONNECT 1009
//#define USE_OUTPUT_FILE

#include <windows.h>

#include <conio.h>
#include "dos.h"
#include <stdio.h>
#include <string.h>
#include "stdlib.h"
#include "time.h"
#include "utils.h"

#define NBR_OF_PORTS 6

// this file included for "rdtsc"
//#include "intrin.h"

// Basic types

#define byte  unsigned char
#define word  unsigned int
#define dword unsigned long int
#define sel   void _seg *
#define fptr  void*

#define RECV_DATA_BUF_SIZE 1200 // old was: 150
#define COM_PORTS 6

typedef unsigned char  BYTE;   // 8-bit unsigned entity
typedef unsigned short WORD;   // 16-bit unsigned number
typedef unsigned int   UINT;   // machine sized unsigned number (preferred)
typedef long           LONG;   // 32-bit signed number
typedef unsigned long  DWORD;  // 32-bit unsigned number
typedef int            BOOL;   // BOOLean (0 or !=0)
typedef char *         PSTR;   // pointer to a string
typedef const char *   PCSTR;  // pointer to a read-only string
typedef char *         LPSTR;  // far pointer to a string
typedef const char *   LPCSTR; // far pointer to a read-only string
typedef volatile unsigned char  VBYTE;   // 8-bit volatile unsigned entity
typedef volatile unsigned short VWORD;   // 16-bit volatile unsigned number
typedef volatile unsigned long  VDWORD;  // 32-bit volatile unsigned number

typedef struct
{
  int nTotalFlow;
  int nOxygenFlow;
  int nAirFlow;
  int nTotalCurrentTemp;
  int nOxygenCurrentTemp;
  int nAirCurrentTemp;
}
uVcbSensorInfo;

typedef struct
{
  int CpuLoadAvg;
  int O2Comp;  
}
uVcbOtherVcbData;

#endif