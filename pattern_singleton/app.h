#ifndef _APP_H
#define _APP_H
/*********************************************************************

  Singleton.h  
  01.10.2011 Initial coding YS 
  
**********************************************************************/
#include "gen.h"
#include "utils.h"

//#include <windows.h>
//#include <MMsystem.h>
// #include "resource.h"
#include <cstdlib>
#include <vector>
#include <string>
#include "Singleton.h"

//using namespace std;
using std::string; 
class Window; 

class Application 
{
 static Application* _self; 
 Window *wnd; 

protected:
 Application();

public:
 static Application* Instance();

 int loadIniInt(string& section, string& var);
 void saveIniInt(string& section, string& var, int val);
 void Run();

};

# endif