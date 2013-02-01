/*********************************************************************

  MessageSimul.h
	IRIS EVE messages binary simulator
  12.10.2006 Initial coding

**********************************************************************/
#ifndef _MESSAGESIMUL_H_
#define _MESSAGESIMUL_H_	
	
int SendMessageRequestInternal (int msgID, int nCOM);
void SendRequestMessage (int nNum, int nCOM);
void Send_32_Message (int nSize, int nCOM);
void Send_34_Message (int nSize, int nCOM);
void Send_35_Message (int nSize, int nCOM);
void Send_36_Message (int nSize, int nCOM);
void Send_37_Message (int nSize, int nCOM);
void Send_38_Message (int nSize, int nCOM);
void Send_55_Message(int nSize, int nCOM);
void Send_56_Message (int nSize, int nCOM);
void Send_84_Message (int nSize, int nCOM);

// void Send_0x20_Message(int nSize, int nCOM);

#endif // _MESSAGESIMUL_H_