#ifndef _REGIF_H
#define _REGIF_H
/*********************************************************************
  
  01.10.2008 Initial coding YS  		
  
**********************************************************************/
#include "gen.h"

class RegIf
{
public:
    RegIf();
	~RegIf();
    void Start();
	void Set(int); 
    int  Get();

#ifdef REGISTRY_IN_USE_123	
	int WriteIniDword(int *Value, TCHAR *SubKey, TCHAR *Key);
	int ReadIniDword (int *Value, TCHAR *SubKey, TCHAR *Key);	  
#endif
    
private:

	//HKEY hKey;
	//LONG Err;
	//DWORD m_dwSizeP, m_dwSizeS;

};

class CFGFile
    {
        // The filename:
        char m_szFileName[255];

    public: 
        // Constructor with an argument:
        CFGFile(char* szFileName); 
        // Default constructor:
        CFGFile(); 
  
        // Get integer from resource file
        BOOL GetProfileInt(char* lpszSection, char* lpszEntry,
                           int nDefaultValue, int * lpnResult);
        
        // Get integers (several from same entry line, divided with
        // whitespace) from resource file
        BOOL GetProfileInts(char* lpszSection, char* lpszEntry, int number,
                            int* pnDefaultValue, int * lpnResult);
        
        // Get a double from resource file
        BOOL GetProfileDouble(char* pszSection, char* pszEntry,
                              double fltDefaultValue, double* pnResult ); 

        // Get string from resource file
        BOOL GetProfileString(char* lpszSection, char* lpszEntry,
                              char* lpszDefaultValue,
                              char* lpszResult, int maxlen ) ;

        // Write integer to resource file
        BOOL WriteProfileInt(char* lpszSection, char* lpszEntry, int nValue );  

        // Write string to resource file
        BOOL WriteProfileString(char* lpszSection, char* lpszEntry, char* lpszValue);

        // Write float to resource file
        BOOL WriteProfileFloat(char* pszSection, char* pszEntry,float pszValue);  
};

#endif