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

#include <QMutex>

class Counter
{  

public:
    Counter() {n = 0};
    void increment() {_mutex.lock(); ++n; _mutex.unlock();}
    void decrement() {_mutex.lock(); --n; _mutex.unlock();}

    int value () const {_mutex.lock(); int r = n; _mutex.unlock(); return r;}
     
private:
    mutable QMutex _mutex;
    int n;
	
};

#endif 