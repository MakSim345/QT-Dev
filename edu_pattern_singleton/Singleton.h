#ifndef SINGLETON_INST_H
#define SINGLETON_INST_H
/*********************************************************************

  Singleton.h  
  01.10.2011 Initial coding YS 
  
**********************************************************************/

class Singleton 
{
public: 
    static Singleton* Instance();

    //functions
    void aFunc1(); 
    void aFunc2(); 
    //data
    int aData;
    
protected: 
    Singleton();

private:
    static Singleton* _instance;
};

#endif