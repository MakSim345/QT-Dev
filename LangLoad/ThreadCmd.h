#pragma once

#include "gen.h"

class ThreadCmd: public QThread
{
    
    bool quitFlag;
    int id;
public:
    ThreadCmd(const string& cmdP, int ident = 0):
      quitFlag(false),
          id (ident)
      {
          
      }

      ~ThreadCmd()
      {
          
      }

      void run()
      {
          while (getline(in, line) && !quitFlag)
          { 
              // std::cout << "thread num:" << id << " - " << countDown << "\n";
              std::cout << line << endl;
              _sleep(500);
          }
      }

      void quit() {quitFlag = true;}
};