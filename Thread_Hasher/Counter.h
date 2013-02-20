#ifndef _COUNTER_H_
#define _COUNTER_H_
//============================================================
//
// Copyright (c) 2011 GENERAL ELECTRIC COMPANY
//
//============================================================
//
// File:           Counter.h
// Project:        Genie Carestation SW
//
// Author:         YS / Genie SW Team
//
//============================================================
// Description:
//==========================================================

#include <QMutex.h>

class Counter
{
public:
    Counter();
    void increment();
    void decrement();

    int value () const;
     
private:
    mutable QMutex my_mutex;
    int _internal_value;	
};

#endif 