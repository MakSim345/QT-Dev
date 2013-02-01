/********************************************************************
 *    Datex-Ohmeda Inc.
 *    Ohmeda Drive
 *    PO Box 7550
 *    Madison, WI 53707-7550
 *
 *    Copyright 2003, Datex-Ohmeda Inc.
 *
 *
 *     $Archive:: /DisplayComputer/Software/sourceNT/lib/Iris/IrisCo $
 *    $Workfile:: DOIrisSerialPort.h                                 $
 *
 *    $Revision: 1.1.1.1 $
 *
 *     $Modtime:: 3/08/06 1:54p                                      $
 *      $Author: aa027762 $
 *
 *    Purpose:    Defines the DOIrisSerialPort class, which allows the Iris communications
 *                library to access the serial port on the Display Computer platform.
 *                    
 ********************************************************************/

#ifndef _DO_IRIS_SERIAL_PORT_H_
#define _DO_IRIS_SERIAL_PORT_H_

#pragma warning( disable : 4201 4514 )
//#include <windows.h>
//#include "opsyslib.h"
#include "IRIS_NodeInterface.h"

// Forward declarations.
typedef unsigned int	 (WINAPI ThreadFunction)(LPVOID pArg) ;
class DORnDLog;


/************************************************************************
** Author:    Jeff Kenyon
** Purpose:   Defines an interface that must be implemented by classes that receive
**            Iris messages from the DOIrisSerialPort class.
** Comments:  
*************************************************************************/
class DOIrisMsgReceiver
{
public:
    virtual ~DOIrisMsgReceiver()    {}

    virtual void InitializeThread() = 0;
    virtual void ShutdownThread() = 0;
};


/************************************************************************
** Author:    Bill Theisen
** Purpose:   Allows the Iris communications library to access the serial port on the
**            Display Computer platform.
** Comments:  
*************************************************************************/
class DOIrisSerialPort //: public DOSerialPortInterface 
{
// DO start
public:        // DO public
    // DOIrisSerialPort( DOIrisMsgReceiver *msgReceiver );		
    DOIrisSerialPort();		
		virtual ~DOIrisSerialPort();

	bool OpenPort(unsigned int PortNumber, int maxMsgLength,
                  IRIS_NodeInterface *irisNode, unsigned long Baudrate = 19200,
                  bool threadSafe = false);
	void WritePort(char * pPacketBuffer, unsigned long Length);	
	void ClosePort();
	DWORD GetPortStatus( void );

protected:     // DO protected
	
private:       // DO private
    // Don't allow these to be used
    DOIrisSerialPort( const DOIrisSerialPort& );
    DOIrisSerialPort& operator=( const DOIrisSerialPort& );

	// static ThreadFunction ReadThread;
	static DWORD __stdcall ReadThread(LPVOID hwnd);
  //void ReadThread (void *dummy);	
	static char *FindChr( char *searchString, int c, unsigned long length );
	void PktCallRelay(char *buffer, unsigned long length);
	
	HANDLE  m_hPort;

	bool m_bReadThreadIsRunning;	
	bool m_bStopReadThread;

	unsigned long m_iInBufferLength;
	unsigned long m_iPacketBufferLength;

  DOIrisMsgReceiver *m_msgReceiver;

	IRIS_NodeInterface *m_irisNode;

    // Critical section to allow multiple threads to the WritePort() method.
  //DOCriticalSection m_critSecWritePort;

    // Pointer to the R&D log.
    // DORnDLog *m_pRnDLog; -- YS

#if !defined(_WIN32_WCE)
    OVERLAPPED m_overlapped;
#endif
// DO end
}; // DOIrisSerialPort

typedef DOIrisSerialPort *LPSerial;

#endif // _DO_IRIS_SERIAL_PORT_H_