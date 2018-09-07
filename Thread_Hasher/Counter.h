#ifndef _COUNTER_H_
#define _COUNTER_H_
//============================================================
//
//============================================================
//
// File:           Counter.h
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
