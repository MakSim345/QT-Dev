
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




/********************************************************************

  Declaration: Function prints dump of message store
  Call: PrintDump()
  Input: nothing
  Returns: nothing
  08.05.2008 Initial coding YS.

*********************************************************************/
void DynBuff::PrintDump ()
{
   printf ("Dump: \n");
   /*
   for (int i=0; i<m_ArraySize; i++)
   {
    // printf ("%d:[%c]  ", i, MsgSent[i]);
   }
   */
   printf ("\n---------------------------------------------------------\n");
}

/********************************************************************

  Declaration: Constructor with one parameter - buffer size.
  Call: DynBuff()
  Input: nothing
  Returns: nothing
  08.05.2008 Initial coding YS.

*********************************************************************/
DynBuff::DynBuff(int buffer_size ):
  m_ArraySize(buffer_size),
  m_CellCntr(0),
  m_Tail(0),
  m_Head(0)
{
 //printf ("Constructor. buffer_size  = %d\n", buffer_size );
 // ringbuffer = new unsigned char[m_ArraySize];

}
	 
/********************************************************************

  Declaration:  Default constructor. 
  Call: DynBuff()
  Input: nothing
  Returns: nothing
  08.05.2008 Initial coding YS.

*********************************************************************/
DynBuff::DynBuff():
  m_ArraySize(30),
  m_CellCntr(0),
  m_Tail(0),
  m_Head(0),
  m_MsgExistFlag(0)
{
 
 for (m_IntCtr=0; m_IntCtr < m_ArraySize; m_IntCtr++)
     ResetCell(m_IntCtr);  
}

/********************************************************************

  Declaration:  Default destructor. 
  Call: ~DynBuff()
  Input: nothing
  Returns: nothing
  08.05.2008 Initial coding YS.

*********************************************************************/

DynBuff::~DynBuff()
{
 return;
}

/********************************************************************

  Declaration: Function resets the given cell.
  Call: ResetCell()
  Input: cell number, int.
  Returns: none
  08.05.2008 Initial coding YS

*********************************************************************/
void DynBuff::ResetCell(int nNbr)
{
  MsgSent[nNbr].FreeCell      =  1;
  MsgSent[nNbr].MsgId         = -1;  
  MsgSent[nNbr].Param         = -1;
  MsgSent[nNbr].MsgCntr       = -1;
  MsgSent[nNbr].ReSendCntr    = -1;

  decCellCtr();
}

/********************************************************************

  Declaration: Function decrement the cell counter and set MsgExistFlag
               to zero if no cells are in use.
  Call: decCellCtr()
  Input: none
  Returns: none
  15.05.2008 Initial coding YS

*********************************************************************/
void DynBuff::decCellCtr(void)
{
  // Check if there any cell are in use. 
  // If not - reset global flag: nothing to send anymore.
  m_CellCntr--;
  
  if (m_CellCntr < 0)
      m_CellCntr=0;
      
  if (0 == m_CellCntr)
     setMsgExistFlag(0);
}

/********************************************************************

  Declaration: Function increment the cell counter and set MsgExistFlag.
  Call: incCellCtr()
  Input: none
  Returns: none
  15.05.2008 Initial coding YS

*********************************************************************/
void DynBuff::incCellCtr(void)
{
  m_CellCntr++;
  
  if (m_CellCntr < 0)
      m_CellCntr=0;
      
  if (m_CellCntr)
     setMsgExistFlag(1);
}

/********************************************************************

  Declaration: Function returns number of cells in use.
  Call: getCellCtr()
  Input: none
  Returns: int
  15.05.2008 Initial coding YS

*********************************************************************/
int DynBuff::getCellCtr(void)
{
  return m_CellCntr;  
}

/********************************************************************

  Declaration: Function returns m_Head value.
  Call: getHead()
  Input: nothing
  Returns: int
  15.05.2008 Initial coding YS

*********************************************************************/
int DynBuff::getHead()
{ 
  return m_Head; 
}

/********************************************************************

  Declaration: Function returns m_Tail value.
  Call: getTail()
  Input: nothing
  Returns: int
  15.05.2008 Initial coding YS

*********************************************************************/
int DynBuff::getTail()
{ 
  return m_Tail; 
}

/********************************************************************

  Declaration: Function saves a message to a next free cell.
  Call: putMsgToStore()
  Input: nothing
  Returns: nothing
  08.05.2008 Initial coding

*********************************************************************/
void  DynBuff::putMsgToStore(int nMsgId, int nParam)
{  
  int i = 0;   
 /*
 if ( m_CellCntr >= m_ArraySize )
    return -1;
 */   
  MsgSent[m_Tail].FreeCell =  0; // set to "reserved"...
  
  //********overflow warning****************************************
  //if (nMsgId > 500)
  //	printf ("ERROR: DynBuffer overflow!!, > %d", nMsgId);
  //****************************************************************
  
  MsgSent[m_Tail].MsgId = nMsgId;  
  MsgSent[m_Tail].Param = nParam;
  MsgSent[m_Tail].MsgCntr = 0;  
  
  m_Tail++;
  if ( m_Tail >= m_ArraySize )
      m_Tail = 0;
  
  incCellCtr();
}

/********************************************************************

  Declaration: Function reads the cell with given number and returns
               the value. Reserved for future use.
  Call: readMsgFromStore(int)
  Input: int
  Returns: int
  08.05.2008 Initial coding

*********************************************************************/
int DynBuff::readMsgFromStore(int nNbr)
{
 
 int nRetVal = 0;
 
 nRetVal = MsgSent[nNbr].Param;    
    
 return nRetVal;
}
/********************************************************************

  Declaration: Function 
  Call: getMsgFromStore()
  Input: nothing
  Returns: nothing
  08.05.2008 Initial coding

*********************************************************************/
int DynBuff::getMsgFromStore(int *nRetParam, int *nRetMsgId)
{ 
 int nRetVal = 0;
 
 if ( !m_CellCntr )
   return -1;
  
  *nRetParam = MsgSent[m_Head].Param;
  *nRetMsgId = MsgSent[m_Head].MsgId;
  
  ResetCell(m_Head);
  
  m_Head++;
  if ( m_Head >= m_ArraySize )
    m_Head = 0;
        
 return nRetVal;
} 

/********************************************************************

  Declaration: Check if message buffer is empty.
  Call: incCellCtr()
  Input: none
  Returns: if any message exist in buffer - returns 1, else 0.
  15.05.2008 Initial coding YS

*********************************************************************/
int DynBuff::isEmpty()
{
  return m_MsgExistFlag;
} 

/********************************************************************

  Declaration: Get the message size from the cell.
  Call: getMsgSize(int)
  Input: int - cell number.
  Returns: function returns 1 all the time. Reserved for future use.
  15.05.2008 Initial coding YS

*********************************************************************/
int DynBuff::getMsgSize(int Nbr) 
{
 return 1;  
}

/********************************************************************

  Declaration: Get the message ID from the cell.
  Call: getMsgId(int)
  Input: int - cell number.
  Returns: integer - message ID.
  15.05.2008 Initial coding YS

*********************************************************************/
int DynBuff::getMsgId(int Nbr) 
{
 return MsgSent[Nbr].MsgId; 
}

/********************************************************************

  Declaration: Set private member m_MsgExistFlag to given value.
  Call: setMsgExistFlag()
  Input: int
  Returns: none
  08.05.2008 Initial coding YS

*********************************************************************/ 
void DynBuff::setMsgExistFlag(int Value)
{
  if (1 == Value)
  {
    m_MsgExistFlag = 1; // there is something to send
  }
  else
  {
   m_MsgExistFlag = 0; // nothing to send at all.
  }
}

/********************************************************************

  Declaration: Get the m_ArraySize, number of all cells in buffer.
  Call: getAllCellCtr(int)
  Input: none
  Returns: int
  15.05.2008 Initial coding YS

*********************************************************************/
int DynBuff::getAllCellCtr(void) 
{
 return m_ArraySize;
}

/********************************************************************

  Declaration: Check if given cell is busy. Reserved for future use.
  Call: getCellBusy(int)
  Input: int.
  Returns: 1 if cell is free, else 0.
  15.05.2008 Initial coding YS

*********************************************************************/
int DynBuff::getCellBusy(int Nbr)
{
  if (0 == MsgSent[Nbr].FreeCell)
    return 1;
  else
   return 0;
}

// End of class implementation.
