#include <QtCore>
#include "Counter.h"

Counter::Counter()
    : _internal_value(0)
{
    
}

int Counter::value () const 
{
    my_mutex.lock(); 
    int r = _internal_value; 
    my_mutex.unlock(); 
    return r;
}

void Counter::increment() 
{
    my_mutex.lock(); 
    ++_internal_value; 
    my_mutex.unlock();
}

void Counter::decrement()
{
    my_mutex.lock(); 
    --_internal_value; 
    my_mutex.unlock();
}