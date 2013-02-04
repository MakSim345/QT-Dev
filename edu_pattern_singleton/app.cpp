/*********************************************************************

  app.cpp
  01.10.2011 Initial coding YS 
  
**********************************************************************/
#include <cstdlib>
#include <string>
#include "app.h"
#include "window.h"

//using namespace std;
using std::string; 

class Window; 

Application::Application()
{

} 

Application* Application::Instance() 
{
 if(!_self)
 {
     _self = new Application(); 
 }
 return _self;
} 

int Application::loadIniInt(string& section, string& var) 
{
    printf("loadIni\n");
    return 100;
}

 void Application::saveIniInt(string& section, string& var, int val) 
{
    printf("saveIni\n");
}

void Application::Run() 
{
    wnd=new Window(); 
    //main loop?
    delete wnd;
}

Application* Application::_self=NULL; 
