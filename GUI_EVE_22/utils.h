#ifndef UTILS_H
#define UTILS_H		
/*********************************************************************

  utils.h  
  01.10.2004 Initial coding YS  		
  Consists CRC routins definitions.
**********************************************************************/
#include <gen.h>

#ifdef WIN32_APP
  #include <windows.h>
#endif
		
#define CRC32_POLYNOMIAL 0xEDB88320L

typedef struct
{
 int CRC[2];
}
CRC_Struct;

unsigned long CalculateBlockCRC32(unsigned long, unsigned char*);

unsigned char CalcCS(int, unsigned char * , int, unsigned char);

CRC_Struct CRC_Calculation (unsigned char * str, int NumbOfChars);
		
void AddTimeStamp(int *pos,char * msg);
void AddStringPan(char * destStr, char * strToAdd,int len);
void AddShortTimeStamp(int *pos,char * msg);
//int rand();
int RND_Array(int);
long  Get1msTime(void);
long  Get1msTimeMS(void);
char* PrintTime(void); // return string with time
void PrintIntroduction();
void SendStr(char * SendString, int dest, int length);

long GetSystemCount();

class CTimer
{
public:
    CTimer();
	~CTimer();
    void Start();
    unsigned int GetElapsedTimeMs() const;
	unsigned __int64 GetElapsedTimeMks() const; 
    
private:
  LARGE_INTEGER m_liFreq;
  LARGE_INTEGER m_liStart;
  LARGE_INTEGER m_liEnd;
};

class CTRACE
{
public:
    CTRACE(int, int);
	CTRACE(int, int, char*);
	~CTRACE();
    void TRACEY(char*, int);
	void TRACEY(char*, int, int);
	void TRACEY(char*, int, int, int);
	void TRACEY(char*, int, int, int, int);
	void TRACEY(char*, long);
	void TRACEY(char*, double);
	void TRACEY(char*, char*);
	void TRACEY(char*);
	void TRACEY(char);
	void TIMESTAMP();
	void TRACE_HEX(char*, int);
    
private:
    void TRACE_Init();
	char *m_FileNameF;// = "allegro.log";
	FILE *fi;// = NULL;   
	int m_FileIsOpen;
	int m_TraceToFile;
	int m_TraceToCons;
};

typedef struct
{	
  char Msg[500]; // for messages.
  int MsgLen;
  int MobId;
  int MsgCntr;
  int MsgId;
  int ReSendCntr;
  int FreeCell;  	  

} PCCMsgSent1;  


typedef struct
{  
  int FreeCell;
  int MsgId;  
  int Param;
  
  // reserved:
  int ReSendCntr;
  int MsgCntr;

} PCCMsgSent; 

//-----------------------------------------
class DynBuff
{
 public:
 // Constructor
  DynBuff();
  DynBuff(int);
  ~DynBuff();

  int isEmpty();
  int getMsgId(int);
  int getMsgSize(int);
  int getAllCellCtr(); // Msg's array returns
  int getCellCtr(void);
  int getHead();
  int getTail();

  int getMsgFromStore(int*, int*);
  void putMsgToStore(int, int);
  
  int readMsgFromStore(int);
  
  int getCellBusy(int); // returns TRUE if cell free; FALSE if it's busy. Obvious..
  
  void PrintDump(void);

 protected:
	 
  PCCMsgSent MsgSent[30];
  // PCCMsgSent *MsgSent;
  int m_MsgExistFlag; // something to send

  int m_IntCtr;
  int m_Tail;
  int m_Head;
  int m_CellCntr;  
  int m_ArraySize;

  void ResetCell(int);  
  void decCellCtr(void);
  void incCellCtr(void);
  void setMsgExistFlag(int);
  
};

#endif