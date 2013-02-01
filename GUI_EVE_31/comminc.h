/*********************************************************************

  cominc.h
	communication incapsulate
  12.10.2006 Initial coding

**********************************************************************/
#ifndef _COMINC_H_
#define _COMINC_H_	
	
void ResetSerialInterrupts();
int InitSerialPorts(int);
int InitSerialPorts(int PortNumber, int nSpeed);
void RemoveSerialPortFromPoll();
int TxData(int , char * ,int );
int ReadRxData(int , char * );
void SendTestMes(int nSize, int nCOM);
void SendZEROMessage(int nSize, int nCOM);
void SendGPSTESTMessage (int nSize, int nCOM);
void Send_TEST_Message (int nSize, int nCOM);
void Send_EMPTY_Message (int nNumber, int nCOM);
#endif // _COMINC_H_


