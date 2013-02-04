/*********************************************************************

  window.cpp
  01.10.2011 Initial coding YS 
  
**********************************************************************/
#include <cstdlib>
#include <string>
#include "window.h"

//using namespace std;
#include "app.h" 

Window::Window()
{
  Application *p=Application::Instance();
  p->loadIniInt(string("Window"), string("width"));
  p->loadIniInt(string("Window"), string("height"));
 }

Window::~Window()
{
  Application *p=Application::Instance(); 
  p->saveIniInt(string("Window"), string("width"), width);
  p->saveIniInt(string("Window"), string("height"), height);
 }
