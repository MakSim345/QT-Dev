//#define _LIB_IN_USE_

#ifndef _LIB_IN_USE_

#pragma once

#include "gen.h"
#include "TCHAR.h"
#include "utils.h"
#include "commport.h"
//#include <stdlib.h>
#include <stdio.h>
#include <iostream>
//#include <windows.h>


  extern  CTRACE t;	 
  extern long GenSentBytes;
/********************************************************************/

/********************************************************************

  Declaration:  CommPort constructor with 2 parameters
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
CommPort::CommPort(const int ComPortNumber, BitRate brBitRate)
{
  SetBufferSizeVar(1200);
	m_BitRate = brBitRate;
//printf ("CommPort constructor X X start.\n");	 
 t.TRACEY("CommPort constructor start: port#%d, speed-%d bps\n", ComPortNumber, brBitRate);
	if (ComPortNumber <= 0)
	{
	  CommPort(); // if error - call default.
	}
	else 
	{
	 m_sComPort = new TCHAR[50];
	 //_stprintf(m_sComPort, _T("COM%d:"), ComPortNumber);
	 // sprintf(m_sComPort, "COM%d:", ComPortNumber);
	 OpenPort();
	}
	
}

/********************************************************************

  Declaration:  CommPort constructor with 1 parameter
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
CommPort::CommPort(const int ComPortNumber)
{
  SetBufferSizeVar(1200);
	m_BitRate = br9600;

//printf ("CommPort constructor X start.\n");	

	if (ComPortNumber <= 0)
	{
	  CommPort(); // if error - call default.
	}
	else 
	{
	 m_sComPort = new TCHAR[50];
	 //sprintf(m_sComPort, "COM%d:", ComPortNumber);
	 OpenPort();
	}
}

/********************************************************************

  Declaration:  CommPort constructor without parameters
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
CommPort::CommPort()
{
    m_sComPort = new TCHAR[50];  
	SetBufferSizeVar(1200);
    printf ("CommPort constructor MAIN start.\n");
	m_BitRate = br9600;
    m_lGenRecBytes = 0;
	m_lGenSenBytes = 0;
	//sprintf(m_sComPort, "%s", "COM1");  
    OpenPort();
}

/********************************************************************

  Declaration: CommPort destructor  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
CommPort::~CommPort()
{
	ClosePort();
	delete [] m_sComPort;
	//printf ("CommPort Destructor.\n");
}


/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
void CommPort::OpenPort()
{
 
 m_bPortReady = TRUE; // everything is OK so far
 m_lGenRecBytes = 0;
 m_lGenSenBytes = 0;

 m_hCom = CreateFile( m_sComPort, 
		GENERIC_READ | GENERIC_WRITE,
		0, // exclusive access
		NULL, // no security
		OPEN_EXISTING,
		0, // no overlapped I/O = 0
		NULL); // null template 

 if ((unsigned)m_hCom == HFILE_ERROR)
 {
	 char *MessageBuffer = new char[50];
	 sprintf(MessageBuffer, "CommPort: %s failed to open.", m_sComPort);
	 printf(MessageBuffer);
	 m_bPortReady = FALSE;
 	 throw std::runtime_error (MessageBuffer);	 
	 //throw std::runtime_error ("CommPort failed to open!");	 
	 delete [] MessageBuffer;
 } 

  m_bPortReady = setBufferComm(); //SetupComm(m_hCom, XX, XX);
  //m_bPortReady = SetupComm(m_hCom, 128, 128);
  //SetBaudRate(0);
	
	m_bPortReady = GetCommState(m_hCom, &m_dcb);
  // Port settings are specified in a Data Communication Block (DCB). 
  // The easiest way to initialize a DCB is to call GetCommState to fill in
  // its default values, override the values that you want to change and
  // then call SetCommState to set the values.
	m_dcb.BaudRate = m_BitRate;	
	m_dcb.ByteSize = 8;
	m_dcb.Parity = NOPARITY;
	m_dcb.StopBits = ONESTOPBIT;
	m_dcb.fAbortOnError = TRUE;
	// later add-ons:
	m_dcb.fBinary = TRUE;
  m_dcb.fOutxCtsFlow = FALSE;        // ignore possible hangups
	m_dcb.fOutxDsrFlow = FALSE;        // don't wait on the DSR line
	m_dcb.fDtrControl  = DTR_CONTROL_ENABLE;
	m_dcb.fRtsControl         = RTS_CONTROL_ENABLE;
/*
    PortDCB.BaudRate            = Baudrate;
    PortDCB.fBinary             = TRUE;
    PortDCB.fParity             = TRUE;
    PortDCB.fOutxCtsFlow        = FALSE;        // ignore possible hangups
    PortDCB.fOutxDsrFlow        = FALSE;        // don't wait on the DSR line
    PortDCB.fDtrControl         = DTR_CONTROL_ENABLE;
    PortDCB.fDsrSensitivity     = FALSE;
    PortDCB.fTXContinueOnXoff   = TRUE;
    PortDCB.fOutX               = FALSE;        // no XON/XOFF control 
    PortDCB.fInX                = FALSE;
    PortDCB.fErrorChar          = FALSE;
    PortDCB.fNull               = FALSE;
    PortDCB.fRtsControl         = RTS_CONTROL_ENABLE;
    PortDCB.fAbortOnError       = FALSE;
    PortDCB.ByteSize            = 8; 
    PortDCB.Parity              = NOPARITY;
    PortDCB.StopBits            = ONESTOPBIT; 
    PortDCB.EvtChar             = IRIS_PACKET_END_FLAG;
*/
	m_bPortReady = SetCommState(m_hCom, &m_dcb); 
  

	// Communication timeouts are optional but can be set similarly to DCB values:
	m_bPortReady = GetCommTimeouts (m_hCom, &m_CommTimeouts);
  
  m_CommTimeouts.ReadIntervalTimeout = 50;
	m_CommTimeouts.ReadTotalTimeoutConstant = 50;
	m_CommTimeouts.ReadTotalTimeoutMultiplier = 10;
	m_CommTimeouts.WriteTotalTimeoutConstant = 50;
	m_CommTimeouts.WriteTotalTimeoutMultiplier = 10;

	m_bPortReady = SetCommTimeouts (m_hCom, &m_CommTimeouts);

	// If all of these API's were successful then the port is ready for use.
	if (m_bPortReady)
	{
		printf ("Comm Port %s open successfully.\n", m_sComPort);
	}
	else
	{
	  printf ("Comm Port %s opening failed.\n", m_sComPort);
	}
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
void CommPort::SetByteSize(const DataBits nDataBits)
{
  getState();// GetCommState(m_hCom, &m_dcb);
	m_dcb.ByteSize = nDataBits;
  setState();// SetCommState(m_hCom, &m_dcb); 
}
/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
void CommPort::SetParity(const Parity nParity)
{
  getState();// GetCommState(m_hCom, &m_dcb);
	m_dcb.Parity = nParity;
  setState();// SetCommState(m_hCom, &m_dcb); 

}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
void CommPort::SetStopBits(const StopBits nStopBits)
{
  getState();// GetCommState(m_hCom, &m_dcb);
	m_dcb.StopBits = nStopBits;
  setState();// SetCommState(m_hCom, &m_dcb); 

}

/********************************************************************

  Declaration: SetBaudRate for commport 
  Call: 
  Input: BitRate union type variable
  Returns:
  	  
*********************************************************************/ 
void CommPort::SetBaudRate(const BitRate nBaudRate)
 {
	// Set only the BaudRate, other stuff will set by deafault.

  m_bPortReady = getState();// GetCommState(m_hCom, &m_dcb);
  // Port settings are specified in a Data Communication Block (DCB). 
  // The easiest way to initialize a DCB is to call GetCommState to fill in
  // its default values, override the values that you want to change and
  // then call SetCommState to set the values.
	//m_dcb.BaudRate = BaudRate;
	m_dcb.BaudRate = nBaudRate;
	m_dcb.ByteSize = 8;
	m_dcb.Parity = NOPARITY;
	m_dcb.StopBits = ONESTOPBIT;
	m_dcb.fAbortOnError = TRUE;

	m_bPortReady = setState();// SetCommState(m_hCom, &m_dcb); 
 }

/********************************************************************

  Declaration:  Incapsulation of WinAPI SetCommState()
  Call: 
  Input: none
  Returns: true or false.
  	  
*********************************************************************/ 
BOOL CommPort::setState ()
{
	BOOL SetCommStateResult = false;
	
	SetCommStateResult = SetCommState(m_hCom, &m_dcb);
	if (!SetCommStateResult)
	{
		printf("CommPort: could not modify serial port state."); 
		throw std::runtime_error ("CommPort: could not modify serial port state.");   
	}
 return SetCommStateResult;
} // end setState ()


/********************************************************************

  Declaration:    Incapsulation of WinAPI GetCommState()
  Call: 
  Input: none
  Returns:
  	  
*********************************************************************/ 
BOOL CommPort::getState ()
{
  BOOL GetCommStateResult = false;
	
	GetCommStateResult = GetCommState(m_hCom, &m_dcb);
	if (!GetCommStateResult)
	{
   printf ("CommPort: could not retrieve serial port state.");   
   throw std::runtime_error ("CommPort: could not retrieve serial port state.");   
	} // endif
 return GetCommStateResult;
} // end getState () const

/********************************************************************

  Declaration:  Incapsulation of WinAPI SetComm()
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
BOOL CommPort::setBufferComm ()
{
  BOOL SetBufferCommResult = false;
	
	SetBufferCommResult = SetupComm(m_hCom, m_nBufferSize, m_nBufferSize); // set buffer sizes
	if (!SetBufferCommResult)
	{
   printf ("CommPort: could not set buffer size for a serial port.");   
   throw std::runtime_error ("CommPort: could not set buffer size for a serial port.");   
	} 
 return SetBufferCommResult;
} // end 

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
DWORD CommPort::WriteToPort(const void *inBuffer, const unsigned long inBufSize)
{
 
 DWORD charsWritten = 0;
 //OVERLAPPED OL;
 //OL.
 //bWriteRC = WriteFile(m_hCom, inBuffer, inBufSize, &iBytesWritten, NULL);
 //bWriteRC = WriteFile(m_hCom, "RE\r", 3, &iBytesWritten,NULL);
 if (!WriteFile(m_hCom, inBuffer, inBufSize, &iBytesWritten, NULL))
 {
   printf ("CommPort: write failed.");   
   throw std::runtime_error ("CommPort: write failed.");   
 } // endif
 GenSentBytes = GenSentBytes + iBytesWritten;
 return iBytesWritten; //returns number of written bytes
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
BOOL CommPort::WriteToPort(const char nBuffer)
{
 char buffer = nBuffer;
 bWriteRC = WriteFile(m_hCom, &buffer, sizeof(char), &iBytesWritten, NULL);
 //bWriteRC = WriteFile(m_hCom, "RE\r", 3, &iBytesWritten,NULL);
 // SetSenBytes(bWriteRC);
 GenSentBytes = GenSentBytes + bWriteRC;
 if (!bWriteRC)
 {
   printf ("CommPort: write failed.");   
   throw std::runtime_error ("CommPort: write failed.");   
 } 
 return bWriteRC;
}	

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
int CommPort::ReadFromPort(char *inBuffer, const unsigned long inCharsReq)
{
  //int i;
	bReadRC = FALSE;
  DWORD ErrorMask = 0; 
	COMSTAT CStat;

  ClearCommError(m_hCom, &ErrorMask, &CStat);
  
	DWORD quelen = CStat.cbInQue;
	
	//if (0 < quelen)
  // t.TRACEY ("CommPort::ReadFromPort. CStat.cbInQue = %ld\n", (long)quelen);
	
	bReadRC = ReadFile(m_hCom, inBuffer, quelen, &iBytesRead, NULL);
  
	//bReadRC = ReadFile(m_hCom, inBuffer, inCharsReq, &iBytesRead, NULL);
	 	
	//if (iBytesRead)
	//	printf ("Serial inside comes: %s\n", inBuffer);

	if (!bReadRC)
	{
   printf ("CommPort: read failed.");   
   throw std::runtime_error ("CommPort: read failed.");   
	}
 return iBytesRead;
}

/********************************************************************

  Declaration:  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
char CommPort::ReadFromPort ()
{

 char buffer = -1;
 DWORD charsRead = 0;
 bReadRC = FALSE;

   //t.TRACEY ("CommPort::ReadFromPort() - income\n"); 	 
 
	 bReadRC = ReadFile(m_hCom, &buffer, sizeof(char), &charsRead, NULL);
	 if (!bReadRC)
   {
     throw std::runtime_error ("CommPort:: read failed.");   
   } 
 // printf ("CommPort::ReadFromPort return %d, %c, 0x%X\n", buffer,buffer,buffer);
  //t.TRACEY ("CommPort::ReadFromPort() - exit\n");
return  buffer;
} 

/********************************************************************

  Declaration: Close commport.  
  Call: 
  Input:
  Returns:
  	  
*********************************************************************/ 
void CommPort::ClosePort()
{
	// close serial port device
  if (CloseHandle (m_hCom) == FALSE )
	 {
    printf ("CommPort: failed to close.");   
    throw std::runtime_error ("CommPort: failed to close.");   
	 } // endif
 printf ("Comm Port %s close successfully.\n", m_sComPort); 
}
/*********************************************************************/

/********************************************************************

  Declaration: Function returns a string contain current version 
	             and compilation date.
  Call: 
  Input:
  Returns: 
  	  
*********************************************************************/ 
void GetVersionString( char* sResString)
{
	 char t1[50];
	 sprintf(t1, TX0023, __DATE__,__TIME__);
	 sprintf(sResString, t1);	 
	 strcat(sResString, COMFILE_VERSION);	 
}


#endif // _LIB_IN_USE_