//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           RND_Generator.cpp
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
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
