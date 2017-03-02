#include <QtCore/QCoreApplication>

#include <QStringList>
#include <QDebug>

#include <iostream>

#include "gen.h"
#include "utils.h"

//#include <windows.h>
//#include <MMsystem.h>
// #include "resource.h"
#include <cstdlib>
#include <string>
#include "Singleton.h"
#include "password_generator.h"
#include "app.h"

using namespace std;


void test_fun_01()
{
    int counter = 2;
    do 
    {
        cout << counter << endl;
        counter += 2;
    } while (counter < 102);

    return;
}

void factorial()
{
    int factArg = 0;
    int i = 2;
    long int fact(1);

    do
    {
        cout << "Enter a number for factorial calculation: \n";
        cin >> factArg;

        if (factArg < 0)
        {
            cout << "No negative values, please" << endl;
        }   

    } while (factArg < 0);    
    
	// fact = factArg;

    while (i <= factArg)
    {
		cout << fact << " * " << i << endl;        
		fact = fact * i;
        cout << "middle result: " << fact << endl;
        i++;
    }
    
    cout << "The factorial of " << factArg << " is: " << fact << endl;

}


int main(int argc, char *argv[])
{
    
    long LastTimeIn=0;	
	long LastTimeInMS = 0;	
	int RValue = false;
	int Counter=0;  
	int CaptureModeHex = 0;
	int NewChar=0;
	int nResult = 0;

    printf ("main - start\n");
    
    //vector<string> letters;
    
    PassGenerator *pg = new PassGenerator();
    cout << pg->genPass(8);
    cout << endl; 
    cout << pg->genPass(8);
    cout << endl;
    cout << pg->genPass(8);
    cout << endl;
    cout << pg->genPass(8);
    cout << endl;
    cout << pg->genPass(8);
    cout << endl;
    cout << endl; 
    
    // factorial();
     Application* application = Application::Instance(); 
     application->Run(); 
     delete application;

    QString winter = "December, January, February";
    QString spring = "March, April, May";
    QString summer = "June, July, August";
    QString fall = "September, October, November";

    QStringList list;
    
    list << winter;
    list.append(summer);
    list += spring;
    qDebug() << "The Spring months are: " << list[0] ;


    if (argc >= 2)
    {
        // i = atoi(argv[1]);
        if ( (strcmp(argv[1], "/?") ==0) || (strcmp(argv[1], "-?") ==0) || (strcmp(argv[1], "help") ==0) )
        {
            PrintIntroduction();
            return 1;
        }
    }

    // test_fun_01();    
    
//*************MAIN LOOP*****************//
 do 
 {
   //This is simple Windows way:
   Sleep(1000);
   std::cout << ". ";
   /*
   nResult = produceRND();   
   printf ("1-Time: %ld. RND: %d\n", Get1msTimeMS(), nResult);
   
   nResult = produceRND();   
   printf ("2-Time: %ld. RND: %d\n", Get1msTimeMS(), nResult);
 	*/

 /*
 // This is complicated one-thread way:
  if ((( Get1msTimeMS() - LastTimeInMS)>1000-1) || (LastTimeInMS > Get1msTimeMS() ))
	{	
     printf ("Time: %ld.\n",Get1msTimeMS());
     Sleep(100);
     	  
	 LastTimeInMS = Get1msTimeMS();
   }   
*/

  // control of endless loop (may be also in monitor.cpp)
	if (kbhit())  // has anything been pressed from keyboard ?
	    {
		RValue = true;
   
	    NewChar=(unsigned char)getch();

	    if ((NewChar & 0xff) == 24)  // CTRL-X   pressed
	        {
	            RValue = true; // END mark
	        }
	    if (NewChar == 'd')  // pressed
	        {
	            if (1 == CaptureModeHex) 
		            CaptureModeHex = 1;
		        else
 		            CaptureModeHex = 0;
	        }
	    }


} while (!RValue);  
 
printf ("Application complete.\n");
return 0;
}
//QCoreApplication a(argc, argv);
//return a.exec();

