#ifndef _FTIME_H_
#define _FTIME_H_		
//============================================================
//
//
//============================================================
//
// File:           FTime.h
//
//============================================================
// Description:
//============================================================

#include <Windows.h>
#include <time.h>
#include "stdio.h"
		
// Timer class
// Constructor:
class FTime
{
public:
    FTime();
	~FTime();
    void Start();
    unsigned int GetElapsedTimeMs() const;
	unsigned __int64 GetElapsedTimeMks() const; 

    long  get1MSTime();

private:
  LARGE_INTEGER m_liFreq;
  LARGE_INTEGER m_liStart;
  LARGE_INTEGER m_liEnd;
};
#endif
