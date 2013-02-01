
#include "gen.h" 
#include <time.h>
#include "stdio.h"
//#include <sys/stat.h>
//#include <stdlib.h>
#include "utils.h"

// Timer class
// Constructor:
CTimer::CTimer() 
{ 
 ::QueryPerformanceFrequency(&m_liFreq);
 Start();
 // printf ("QueryPerformanceFrequency : %u\n", m_liFreq.QuadPart);
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
void CTimer::Start()
{ 
 ::QueryPerformanceCounter(&m_liStart);  
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
unsigned int CTimer::GetElapsedTimeMs() const
{
  LARGE_INTEGER liEnd;
  ::QueryPerformanceCounter(&liEnd);  
  return static_cast<unsigned int>((liEnd.QuadPart - m_liStart.QuadPart) * 1000 / m_liFreq.QuadPart);
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
unsigned __int64 CTimer::GetElapsedTimeMks() const 
{
  LARGE_INTEGER liEnd;
  ::QueryPerformanceCounter(&liEnd);
  return static_cast<unsigned __int64>((liEnd.QuadPart - m_liStart.QuadPart) * 1000000 / m_liFreq.QuadPart);
}

// End of the class.

long g_lTimeTick;

// #define TEST12341412343
#ifdef TEST12341412343
 // test
#endif	

/*-----------------------------------------------------------------------

 Get 1 ms Time Count from midnight

  -----------------------------------------------------------------------*/

// this also works but gives some warning when compiling
//long long rdtsc(void)
//{
//__asm__("rdtsc");
//}

/*
inline long long rdtsc (void)
{
        long long result;
        asm volatile ("rdtsc" : "=A"(result));
        return result;
}
*/
/**********************************************
From Wikipedia, the free encyclopedia
In the X86 assembly language, the RDTSC instruction is a mnemonic for 
Read Time Stamp Counter. The instruction returns a 64 bit value in 
registers EDX:EAX the count of ticks from processor reset. 
Added in Pentium. Opcode: 0F 31.
Examples of using it in Microsoft Visual C++:
************************************************/
__declspec(naked)
unsigned __int64 __cdecl rdtsc(void)
{
   __asm
   {
      rdtsc
      ret       ; return value at EDX:EAX
   }
}

/********************************************************************

  Declaration:  Get 1 ms Time Count from midnight
  Call: Get1msTime(void)
  Input: none
  Returns: milliseconds.
  	  
*********************************************************************/ 

long  Get1msTime(void)
  {
#if defined PENTIUM   
   unsigned __int64  tsc;
   tsc=rdtsc();      
   return( (long)(tsc/(MHz*1000)));
#else
  // not pentium
  return g_lTimeTick;
#endif
  }

/********************************************************************

  Declaration: implementation of Get1msTime() for Microsoft env. 
  Call: Get1msTimeMS(void)
  Input: none
  Returns: milliseconds.
  	  
*********************************************************************/ 
long  Get1msTimeMS(void)
{
  /*
  // 1. Use function  _ftime
   struct _timeb timebuffer;

  _ftime( &timebuffer );
  // g_lTimeTick = (timebuffer.time*1000)+timebuffer.millitm;
  return (timebuffer.time*1000)+timebuffer.millitm;
  */
  
  /*
  // 2. Use function GetTickCount():
  // after 49 days it will reset. Check it!
  return GetTickCount();
  */
  
  /*
   // 3. Use  QueryPerformanceCounter () function:
  __int64 nTick, f; 

  // This function must be called once!
  QueryPerformanceFrequency((PLARGE_INTEGER)&f); 
  
  QueryPerformanceCounter((PLARGE_INTEGER)&nTick);
  // printf ("Freq : %u\n",f);
  // printf ("nTick: %u, nTick/f:%u\n",nTick, nTick/f);
  return (long)(nTick/3000000); // divide to processor speed!!!
  */
   
   // 3. Use class based on QueryPerformanceCounter () functions:
   //static int nFirsTime = 1;
   static CTimer *t = new CTimer(); // take memory from heap, not from stack!
    
/*   if (1 == nFirsTime)
	{
      t.Start();
	  nFirsTime = 0;
	}
 */
   return t->GetElapsedTimeMs();
   //return t.GetElapsedTimeMs();
   //return t.GetElapsedTimeMks();
}


/********************************************************************

  Declaration:
  Call: GetSystemCount()
  Input: None
  Returns: System count
  12.10.2006 Initial coding

*********************************************************************/

long GetSystemCount()
  {		
	// return (long)(_farpeekw(0x0040,0x006C) + _farpeekw(0x0040,0x006E)*65536l);
	return (long) GetTickCount();  
  }


/********************************************************************

  Declaration: Output string to the latest origin
  Call: SendStr(string,dest)
  Input:  char * string, int destination (0 only display)
  Returns:
  27.11.2000 Initial coding

*********************************************************************/

void SendStr(char * SendString,int dest,int length)
{
  //int Port;
int j;

for (j=0;j<length;j++)
{
  if (dest)
  {
   //printf("%c",SendString[j]);
  }
  else
  {
   printf("%c",*(SendString+j));
  }
 }
 
} 

/********************************************************************

  Declaration: Constructor. Print string to console and/or to file
  Call: 
  Input:
  Returns:
  26.10.2006 Initial coding

*********************************************************************/

 CTRACE::CTRACE(int toFile, int toConsol)
 {
    const char* ClassFileNaMe = "allegro.log";
	m_FileIsOpen = 0;
	m_TraceToFile = toFile;
	m_TraceToCons = toConsol;
	m_FileNameF = new char[11];
	sprintf(m_FileNameF, ClassFileNaMe);
	TRACE_Init();
 }

CTRACE::CTRACE(int toFile, int toConsol, char* UserFileName)
 {
    const int nFNameLen = 20;
	m_FileIsOpen = 0;
	m_TraceToFile = toFile;
	m_TraceToCons = toConsol;
	m_FileNameF = new char[nFNameLen];
	if (strlen(UserFileName) > nFNameLen )
	 {
	   // UserFileName does not have any validation!
	   const char* ClassFileNaMe = "allegro.log";
	   printf ("ATTN! Filename '%s' has more than %d characters.\n", UserFileName, nFNameLen);
	   printf ("All TRACE will go to file 'allegro.log'\n")	;
	   sprintf(m_FileNameF, ClassFileNaMe);
	 }
	 else
	 {
	   sprintf(m_FileNameF, UserFileName);
	 }
	 TRACE_Init();
 }

 CTRACE::~CTRACE()
 {
  
  TRACEY("End time: %d\n", Get1msTimeMS());
  //printf ("CTRACE - closing file\n");
  if (1 == m_FileIsOpen)
  {
   fclose (fi);
  }
	//printf ("CTRACE - after close file\n");
	// delete [] m_FileNameF;
	//printf ("CTRACE - after delete name\n");
 }
 
 void CTRACE::TRACE_Init()
 {
  // open the file for input:	
  if ( (fi = fopen(m_FileNameF, "w") ) != NULL)
  {
   // printf ("file %s was open succesfully\n", FileNameF);
   m_FileIsOpen = 1;
  }
  else
  {
   printf ("file %s was not open\n", m_FileNameF);
   // getchar(); // nay3a, xyLe...
   m_FileIsOpen = 0;
  }	  
  // TRACE("Start time: %d\n", Get1msTimeMS());
  TIMESTAMP();
  return;
 }
 
void CTRACE::TRACEY(char* sStr, int nVal)
{
  //printf (" TRACE char-int. string: %s \n", sStr);
	if (1 == m_TraceToFile)
	  fprintf(fi, sStr, nVal);
	if (1 == m_TraceToCons)
	  printf(sStr, nVal);
}

void CTRACE::TRACEY(char* sStr, int nVal1, int nVal2)
{
  //printf (" TRACE char-int. string: %s \n", sStr);
	if (1 == m_TraceToFile)
	  fprintf(fi, sStr, nVal1, nVal2);
	if (1 == m_TraceToCons)
	  printf(sStr, nVal1, nVal2);
}

void CTRACE::TRACEY(char* sStr, int nVal1, int nVal2, int nVal3)
{
  //printf (" TRACE char-int. string: %s \n", sStr);
	if (1 == m_TraceToFile)
	  fprintf(fi, sStr, nVal1, nVal2, nVal3);
	if (1 == m_TraceToCons)
	  printf(sStr, nVal1, nVal2, nVal3);
}

void CTRACE::TRACEY(char* sStr, int nVal1, int nVal2, int nVal3, int nVal4)
{
  //printf (" TRACE char-int. string: %s \n", sStr);
	if (1 == m_TraceToFile)
	  fprintf(fi, sStr, nVal1, nVal2, nVal3, nVal4);
	if (1 == m_TraceToCons)
	  printf(sStr, nVal1, nVal2, nVal3, nVal4);
}

void CTRACE::TRACEY(char* sStr, long nVal)
{
 //printf (" TRACE char-long. string: %s \n", sStr);
	if (1 == m_TraceToFile)
    fprintf(fi, sStr, nVal);
	if (1 == m_TraceToCons)
	  printf(sStr, nVal);
}

void CTRACE::TRACEY(char* sStr, double nVal)
{
	//printf (" TRACE char-double. string: %s \n", sStr);
  if (1 == m_TraceToFile)
	  fprintf(fi, sStr, nVal);
	if (1 == m_TraceToCons)
		printf(sStr, nVal);
}

void CTRACE::TRACEY(char* sStr1, char* sStr2)
{
 //printf (" TRACE. string-string: %s || %s\n", sStr1, sStr2);
 if (1 == m_TraceToFile)
	fprintf(fi, "%s%s", sStr1, sStr2);
 if (1 == m_TraceToCons)
	printf( "%s%s", sStr1, sStr2);
}

void CTRACE::TRACEY(char* sStr)
{
 //printf (" TRACE. string: %s \n", sStr);
 if (1 == m_TraceToFile)
	fprintf(fi, "%s", sStr);
 if (1 == m_TraceToCons)
	printf( "%s", sStr);
}

void CTRACE::TRACEY(char cChar)
{
	//printf (" TRACE. char: %c \n", cChar);
 if (1 == m_TraceToFile)
	fprintf(fi, "%c", cChar);
 if (1 == m_TraceToCons)
	printf("%c", cChar);
}

/********************************************************************

  Declaration: Put a time-stamp to TRACE stream
  Call: 
  Input: none
  Returns: none
  10.11.2006 Initial coding

*********************************************************************/
void CTRACE::TIMESTAMP()
{
 //long ltime;
 //time(&ltime);
 
  time_t system_time;
 system_time = time(NULL); 
 //ctime(&system_time) << endl;
 TRACEY("TIMESTAMP: ");
 TRACEY(ctime(&system_time), "\n");
 
 //TRACEY("TIMESTAMP: ");
 //TRACEY(ctime(&ltime), "\n");
 // printf("TIMESTAMP: %s\n", ctime(&ltime));
}

/********************************************************************

  Declaration: Print string in Hexadecimal format to file or/and console
  Call: 
  Input: char* bufer, int buffersize.
  Returns: none
  10.11.2006 Initial coding YS.

*********************************************************************/
void CTRACE::TRACE_HEX(char* ReceiveBuffer, int NbrOfReadBytes)
{	
  unsigned char tmpchr;
  
	TRACEY("Bytes: \n"); 		
	for (int j=0; j < NbrOfReadBytes; j++)
	  {
	    tmpchr=(unsigned char) ReceiveBuffer[j];
	    TRACEY("\\0x%X", tmpchr); 
		}	  
	 TRACEY("\n"); 		
}
