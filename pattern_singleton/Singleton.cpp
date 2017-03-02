#include <iostream>

#include "gen.h"
#include "utils.h"

#include <cstdlib>
#include <vector>
#include <string>

#include "Singleton.h"

/*********************************************************************

  Singleton.cpp
  01.10.2011 Initial coding YS 
  
**********************************************************************/

// Implementation 
Singleton* Singleton::_instance = NULL;

Singleton* Singleton::Instance() 
{
    if (_instance == 0) 
    {
        _instance = new Singleton;
    }
    
    return _instance;
}

Singleton::Singleton()
{

}

void Singleton::aFunc1()
{

} 

void Singleton::aFunc2()
{

} 
