//============================================================
//
//
//============================================================
//
// File:           RND_Generator.cpp
//
//
//============================================================
// Description:
//============================================================
#include "RND_Generator.h"

RND_Generator::RND_Generator(void)
{
    srand (time (NULL));    
}

RND_Generator::~RND_Generator(void)
{
}

int RND_Generator::GetRNDValue(int minVal, int nMaxVal)
{
    int nRetVal=0;        
    // srand (time (NULL));
    nRetVal = minVal + (rand() % nMaxVal);
    return nRetVal;
}
