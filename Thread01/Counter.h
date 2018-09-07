#ifndef _COUNTER_H_
#define _COUNTER_H_
//============================================================
//
//
//============================================================
//
// File:           Counter.h
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
