#ifndef _RND_GENERATOR_H_
#define _RND_GENERATOR_H_

//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           Worker.cpp
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//============================================================
#include <math.h>
#include <time.h> 
#include <stdlib.h> 

#pragma once
class random_generator
{
public:
    random_generator(void);
    ~random_generator(void);
    int GetRNDValue(int minVal, int nMaxVal);
};

#endif