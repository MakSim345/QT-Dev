//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           FTime.cpp
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//============================================================

#include "FTime.h"

// Timer class
// Constructor:
FTime::FTime() 
{ 
 ::QueryPerformanceFrequency(&m_liFreq);
 Start();
 // printf ("QueryPerformanceFrequency : %u\n", m_liFreq.QuadPart);
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
void FTime::Start()
{ 
 ::QueryPerformanceCounter(&m_liStart);  
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
unsigned int FTime::GetElapsedTimeMs() const
{
  LARGE_INTEGER liEnd;
  ::QueryPerformanceCounter(&liEnd);  
  return static_cast<unsigned int>((liEnd.QuadPart - m_liStart.QuadPart) * 1000 / m_liFreq.QuadPart);
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
unsigned __int64 FTime::GetElapsedTimeMks() const 
{
  LARGE_INTEGER liEnd;
  ::QueryPerformanceCounter(&liEnd);
  return static_cast<unsigned __int64>((liEnd.QuadPart - m_liStart.QuadPart) * 1000000 / m_liFreq.QuadPart);
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
long FTime::get1MSTime(void)
{
    return GetElapsedTimeMs();
}
// End of the class.
