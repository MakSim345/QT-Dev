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
class RND_Generator
{
public:
    RND_Generator(void);
    ~RND_Generator(void);
    int GetRNDValue(int minVal, int nMaxVal);
};

#endif
