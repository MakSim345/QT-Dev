//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           random_generator.cpp
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//============================================================
#include "random_generator.h"

random_generator::random_generator(void)
{
    srand (time (NULL));    
}

random_generator::~random_generator(void)
{
}

int random_generator::GetRNDValue(int minVal, int nMaxVal)
{
    int nRetVal=0;        
    // srand (time (NULL));
    nRetVal = minVal + (rand() % nMaxVal);
    return nRetVal;
}
