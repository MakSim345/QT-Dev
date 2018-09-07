#ifndef _RND_GENERATOR_H_
#define _RND_GENERATOR_H_

//============================================================
//
//
//============================================================
//
// File:           Worker.cpp
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
