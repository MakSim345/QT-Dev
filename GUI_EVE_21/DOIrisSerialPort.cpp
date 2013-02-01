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
 *    $Workfile:: DOIrisSerialPort.cpp                               $
 *
 *    $Revision: 1.2 $
 *
 *     $Modtime:: 3/08/06 1:57p                                      $
 *      $Author: aa027762 $
 *
 *    Purpose:    Defines methods of the DOIrisSerialPort class, which allows the Iris
 *                communications library to access the serial port on the Display
 *                Computer platform.
 *                    
 ********************************************************************/
#define IRIS_MAX_MESSAGE_LENGTH 8192

#define IRIS_PACKET_END_FLAG 0x7E
	// This is the first (control) character in a replacement sequence
#define IRIS_PACKET_CONTROL_CHAR 0x7D
	// This is the second character in the sequence replacing 0x7D
#define IRIS_PACKET_CONTROL_SEQUENCE_0x7D_REPLACEMENT 0x5D
	// This is the second character in the sequence replacing 0x7E
#define IRIS_PACKET_CONTROL_SEQUENCE_0x7E_REPLACEMENT 0x5E

#include <windows.h>
#include <process.h>    /* _beginthread, _endthread */
#include <atlbase.h>

extern long GenSentBytes;
extern long GenRecBytes;

//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
class CExeModule : public CComModule
{
public:
	LONG Unlock();
	DWORD dwThreadID;
	HANDLE hEventShutdown;
	void MonitorShutdown();
	bool StartMonitor();
	bool bActivity;
};
extern CExeModule _Module;
#pragma warning( push, 3 )
#include <atlwin.h>
#pragma warning( pop )

#include "TCHAR.h"
//#include "iris_if.h"
//#include "RnDLog.h"
#include "DOIrisSerialPort.h"
//#include "FailedStateBase.h"
//#include "PrivateHeap.h"
//#include "Thread.h"
//#include "IrisBase.h"
//#include "ThreadSettingsBase.h"

#ifdef _WIN32_WCE
#include <Pegdser.h>		//	For GetPortStatus()
#endif

#define IN_BUFFER_MULT	20	// So input buffer can hold 20 messages
#define PKT_BUFFER_MULT	2	// So packet buffer can hold 2 messages

#define EXIT_EVENT		0	// Event used to exit serial read thread


/*******************************************************************************
** Author:    Bill Theisen
** Purpose:   Constructor, initialize a few variables.
** Comments:  
*******************************************************************************/
// DOIrisSerialPort::DOIrisSerialPort( DOIrisMsgReceiver *msgReceiver ) :
DOIrisSerialPort::DOIrisSerialPort() :
	m_hPort(INVALID_HANDLE_VALUE),
	m_bReadThreadIsRunning(FALSE),
	m_bStopReadThread(FALSE),
	m_iInBufferLength(0),
	m_iPacketBufferLength(0),
  //m_msgReceiver(msgReceiver),
  m_irisNode(0)
{    
    // Initialize R&D logging.
    // HRESULT hRes = E_FAIL;
    // m_pRnDLog = DONew<DORnDLog>( hRes );
    // DO_ASSERT( m_pRnDLog != NULL );
    // DO_ASSERT( SUCCEEDED(hRes) );
      // -YS
#if !defined(_WIN32_WCE)
    ZeroMemory(&m_overlapped, sizeof(OVERLAPPED));
    m_overlapped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
#endif

}

/*******************************************************************************
** Author:    Bill Theisen
** Purpose:   Destructor.
** Comments:  
*******************************************************************************/
DOIrisSerialPort::~DOIrisSerialPort()
{

#if !defined(_WIN32_WCE)
    CloseHandle(m_overlapped.hEvent);
#endif
    //DODelete( m_pRnDLog );

	m_hPort = INVALID_HANDLE_VALUE;
	m_msgReceiver = NULL;
	m_irisNode  = NULL;
	//m_pRnDLog = NULL;
}



/*******************************************************************************
** Author:    Bill Theisen
** Purpose:   Opens the serial port.
** Comments:  
**  Parameter(s):   PortNumber - serial port number e.g. 1... 4
**					maxMsgLength - maximum message length
**                  m_irisNode - pointer to class method called when packet is 
**							   received. Method prototype is:
**							   Func( char * pPacketBuffer, unsigned long Length );
**                  Baudrate - pseudo standard set baudrates, e.g. 300, 1200,
**                             2400, 4800, 9600, 19200, 38400, 57600, 115200 
**
**  Return type:    boolean - TRUE(1) if successful, FALSE(0) otherwise
*******************************************************************************/
bool DOIrisSerialPort::OpenPort( unsigned int PortNumber,
                                 int maxMsgLength,
                                 IRIS_NodeInterface *irisNode,
                                 unsigned long Baudrate,
                                 bool /* threadSafe */)
{ 
    DCB PortDCB;
    
	this->m_irisNode = irisNode;
    m_bStopReadThread = FALSE;

	TCHAR szDeviceName[50];
	_stprintf(szDeviceName, _T("COM%d:"), PortNumber);
	
#if defined(_WIN32_WCE)
    // Open the COM device.
    if( INVALID_HANDLE_VALUE == (m_hPort = CreateFile( (szDeviceName),
  		GENERIC_READ|GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0) ) ) 
    {
#else
    if( INVALID_HANDLE_VALUE == (m_hPort = CreateFile( (szDeviceName),
  		GENERIC_READ|GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0) ) ) 
    {
#endif	
        //m_pRnDLog->LogRnDEvent( IDS_IRISCOMMON_CREATEFILE_FAILED,static_cast<int>(GetLastError()) );
        return FALSE;
    }

	//delete [] szDeviceName;

    // Set the port.
    PortDCB.DCBlength = sizeof(DCB);
    GetCommState(m_hPort, &PortDCB);

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

    if( !SetCommState( m_hPort, &PortDCB ) )
    {
        //m_pRnDLog->LogRnDEvent( IDS_IRISCOMMON_SETCOMMSTATE_FAILED, static_cast<int>(GetLastError()) );
        return FALSE;
    }

    // Set comm timeouts (nonblocking read, and write waiting for completion).
    COMMTIMEOUTS CommTimeouts;
    GetCommTimeouts( m_hPort, &CommTimeouts );
    CommTimeouts.ReadIntervalTimeout         = MAXDWORD;
    CommTimeouts.ReadTotalTimeoutMultiplier  = 0;
    CommTimeouts.ReadTotalTimeoutConstant    = 0;   
    CommTimeouts.WriteTotalTimeoutMultiplier = 0;
    CommTimeouts.WriteTotalTimeoutConstant   = 0;   
    SetCommTimeouts(m_hPort, &CommTimeouts);

    m_iInBufferLength	  = static_cast<unsigned long>(maxMsgLength * IN_BUFFER_MULT);
	m_iPacketBufferLength = static_cast<unsigned long>(maxMsgLength * PKT_BUFFER_MULT);

    // Create and start the receiver thread.
	unsigned long threadID;
	/*
	DOThread receiveThread( THREAD_NAME_BASE_IRISRECEIVE, ReadThread, this,
                          DOThread::DO_THREAD_RUN, &threadID );

	*/
   // _beginthread( ReadThread, 0, NULL );
	 HANDLE hthread = CreateThread(0, 0, ReadThread, (LPVOID)this, 0, 0);

   m_bReadThreadIsRunning  = TRUE;

   return TRUE;
}

/*******************************************************************************
** Author:    Bill Theisen
** Purpose:   Writes the specified byte stream to the serial port.
** Comments:  
**  Parameter(s):   pPacketBuffer - pointer to char buffer contianing packet
**                  Length - number of chars in packet being written
**
**  Return type:    None
**
*******************************************************************************/
void DOIrisSerialPort::WritePort(char * pPacketBuffer, unsigned long Length)
{
    unsigned long nBytesWritten;
	 //m_critSecWritePort.Lock();
#if defined(_WIN32_WCE)
    WriteFile( m_hPort, pPacketBuffer, Length, &nBytesWritten, 0 );
#else
    WriteFile(m_hPort, pPacketBuffer, Length, &nBytesWritten, &m_overlapped);
#endif
    FlushFileBuffers(m_hPort);
	//m_critSecWritePort.Unlock();
		GenSentBytes = GenSentBytes + Length;
}


/*******************************************************************************
** Author:    Bill Theisen
** Purpose:   Closes the serial port by setting flag to stop ReadThread and signaling
**            the EXIT_EVENT to cause WaitCommEvent to stop pending.  Then waits for
**            ReadThread to exit.
** Comments:  
*******************************************************************************/
void DOIrisSerialPort::ClosePort( void )
{
    if( m_bReadThreadIsRunning ){
    
        // Set flag for exit and signal exit event so 
        // that WaitCommEvent() stops pending 
        m_bStopReadThread = TRUE;
        SetCommMask(m_hPort, EXIT_EVENT);
        
        
        while( m_bReadThreadIsRunning ) {
            Sleep(200);
        }
    }
    
    //m_critSecWritePort.Lock();
    if(m_hPort != INVALID_HANDLE_VALUE)
			   CloseHandle( m_hPort );
    m_hPort = INVALID_HANDLE_VALUE;
    //m_critSecWritePort.Unlock();
}


/*******************************************************************************
** Author:    Bill Theisen
** Purpose:   Provide access to inherited protected member function	receivePacket of
**            IRIS_NodeInterface.
** Comments:  
*******************************************************************************/
void DOIrisSerialPort::PktCallRelay(char *buffer, unsigned long length)
{
	m_irisNode->receivePacket(buffer, length);
}

/*******************************************************************************
** Author:    Bill Theisen
** Purpose:   This is the thread that reads serial data, parses IRIS packets and 
**            transfers them to the specified receiving method.
** Comments:  
*******************************************************************************/
// unsigned int WINAPI DOIrisSerialPort::ReadThread( LPVOID pArg )
DWORD __stdcall DOIrisSerialPort::ReadThread( LPVOID pArg )
// DWORD __stdcall ReadThread(LPVOID hwnd)
{
    unsigned long fdwCommMask;
     
    unsigned long CharsInBuffer = 0;
    unsigned long NonPacketCharsInBuffer;
    unsigned long packetlength;
 
	char * pEndChar;

    LPSerial pCaller = reinterpret_cast<LPSerial>(pArg);
	//DO_ASSERT( pCaller != NULL );
    pCaller->m_bReadThreadIsRunning = TRUE;
    
		/*
    if ( pCaller->m_msgReceiver )
    {
        pCaller->m_msgReceiver->InitializeThread();
    }
    */
    // Enable logging from this thread via pCaller->m_pRnDLog.
    
	//HRESULT hRes = E_FAIL;
    //pCaller->m_pRnDLog->AddThread( hRes );   
    //DO_ASSERT( SUCCEEDED(hRes) );

	// Setup the input and packet buffers 
    char *cBuffer = new char[pCaller->m_iInBufferLength];
    //DO_ASSERT( cBuffer != NULL );
    char *cPacketBuffer = new char[pCaller->m_iPacketBufferLength];
    //DO_ASSERT( cPacketBuffer != NULL );

    if( !SetCommMask( pCaller->m_hPort, EV_RXCHAR | EXIT_EVENT ) )
	{
        //pCaller->m_pRnDLog->LogRnDEvent( IDS_IRISCOMMON_SETCOMMMASK_FAILED );
    }

    // Main loop of read thread.
    while( !pCaller->m_bStopReadThread )
    {
        if( !WaitCommEvent(pCaller->m_hPort, &fdwCommMask, 0))
        {
            //pCaller->m_pRnDLog->LogRnDEvent( IDS_IRISCOMMON_WAITCOMMEVENT_FAILED, 
            //                                 static_cast<int>(GetLastError()) );
            break;	//	Get out of read thread while loop 
        }
        
        // Reset the comm Mask.
        if( !SetCommMask(pCaller->m_hPort, EV_RXCHAR | EXIT_EVENT)) 
		{
            //pCaller->m_pRnDLog->LogRnDEvent( IDS_IRISCOMMON_SETCOMMMASK_FAILED,
            //                                 static_cast<int>(GetLastError()));
        }
    
        if( fdwCommMask & EV_RXCHAR )
        {
            unsigned long num;
#ifdef _WIN32_WCE
            // Read all bytes received into cBuffer.
			ReadFile(pCaller->m_hPort, &cBuffer[CharsInBuffer], pCaller->m_iInBufferLength-CharsInBuffer, &num, 0);
#else
            ReadFile(pCaller->m_hPort, &cBuffer[CharsInBuffer], pCaller->m_iInBufferLength-CharsInBuffer, &num, &(pCaller->m_overlapped));
#endif // _WIN32_WCE
            CharsInBuffer += num;
            GenRecBytes = GenRecBytes+num;	
            // Check for a packet in the buffer
            while( CharsInBuffer && (pEndChar = FindChr( cBuffer, IRIS_PACKET_END_FLAG, CharsInBuffer )) != NULL )
            {
                packetlength = static_cast<unsigned long>((pEndChar - cBuffer) + 1);  // Includes IRIS_PACKET_END_FLAG char
                
                // Make sure IRIS_PACKET_END_FLAG is in new message area of buffer
                if ( packetlength <= CharsInBuffer && packetlength <= pCaller->m_iPacketBufferLength )
                {
                    // Move packet to buffer and send
                    memcpy( cPacketBuffer, cBuffer, packetlength);	// PC-Lint warning 688 expected
		    		        pCaller->PktCallRelay( cPacketBuffer, packetlength );	
                }

                // Move remaining chars in buffer to beginning of buffer and adjust char counts
                NonPacketCharsInBuffer = CharsInBuffer - packetlength;

                if( NonPacketCharsInBuffer > 0 )
				{
					// PC-Lint warning 688 expected
                    memcpy( cBuffer, &cBuffer[CharsInBuffer-NonPacketCharsInBuffer], NonPacketCharsInBuffer);
                }
                else
                {
                    NonPacketCharsInBuffer = 0;
                }
				CharsInBuffer = NonPacketCharsInBuffer; 
            }

			// Handle the case were the buffer is full but no packet is found
            if( CharsInBuffer >= pCaller->m_iInBufferLength )
            {
                CharsInBuffer = 0;
                //pCaller->m_pRnDLog->LogRnDEvent( IDS_IRISCOMMON_BUFFER_OVERFLOW );
            }
        }
        
        // Clear buffers to prevent problem when exiting thread
        if( fdwCommMask & EXIT_EVENT )
		{
            PurgeComm(pCaller->m_hPort, PURGE_RXCLEAR | PURGE_TXCLEAR | 
                                        PURGE_RXABORT | PURGE_TXABORT );
        }
    }
    

	delete [] cBuffer;
	delete [] cPacketBuffer;

    //pCaller->m_pRnDLog->RemoveThread();
/*
    if ( pCaller->m_msgReceiver )
    {
        pCaller->m_msgReceiver->ShutdownThread();
    }
*/
    pCaller->m_bReadThreadIsRunning = FALSE;


    return 0;
}

/*******************************************************************************
** Author:    Bill Theisen
** Purpose:   Searches the string for the specified character - ignores	NULL chars
**            in string.
** Comments:  Note, this method searchs entire string for character rather than stopping
**       	  at NULL.
**  Parameter(s):   char *string - string to search
**					int c - value to search for
**					int size - string size
**
**  Return type:    char * - pointer to char if found, otherwise NULL 
*******************************************************************************/
char *DOIrisSerialPort::FindChr( char *searchString, int c, unsigned long size )
{
	if( searchString != NULL )
	{
		while( size > 0 )
		{
			if( *searchString == c )
				return searchString;
			searchString++;
			size--;
		}
	}
    return NULL;
}


/*******************************************************************************
** Author:    Bill Theisen
** Purpose:   Read and return the serial port communication status
** Comments:  
*******************************************************************************/
DWORD DOIrisSerialPort::GetPortStatus( void )
{
#if defined(_WIN32_WCE)
    SERIAL_DEV_STATUS statusStruct;
    DWORD BytesReturned;
    int Result;

    Result = DeviceIoControl( m_hPort,
                              IOCTL_SERIAL_GET_COMMSTATUS,
                              NULL,
                              0,
                              &statusStruct,
                              sizeof(statusStruct),
                              &BytesReturned,
                              NULL
                            );

	//	Return 0 for status if call fails	
    if( !Result || BytesReturned == 0 )
	{
		return 0;
	}
	
	return statusStruct.Errors;
#else
    return 0;
#endif	
}

#if 0
#endif