//	*************************************************
//	* Datex-Ohmeda Inc.
//	* Ohmeda Drive
//	* PO Box 7550
//	* Madison, WI 53707-7550
//	*
//	* Copyright 2000, Datex-Ohmeda, Inc.
//	*
//	* Archive Name:              $Archive: /DisplayComputer/Software/DCCommonSnapshot/Iris/Source/RoseSrc/LinkTestMessage.cpp $
//	* Working File Name:         $Workfile: LinkTestMessage.cpp $
//	*
//	* Version:                   $Revision: 1.1.1.1 $
//	*
//	* Last Modification Time:    $Modtime: 3/24/03 11:54a $
//	* Author:                    $Author: aa027762 $
//	*
//	*************************************************

// LinkTestMessage

#include "LinkTestMessage.h"
#ifdef NTEL_PLATFORM_CONVERT
#define BYTE_SWAP_COPY_16(A,B) byteSwapCopy16(A,B);
#define BYTE_SWAP_COPY_32(A,B) byteSwapCopy32(A,B);
#else
#define BYTE_SWAP_COPY_16(A,B) *((IRIS_UINT16 *)B) = *((IRIS_UINT16 *)A);
#define BYTE_SWAP_COPY_32(A,B) *((IRIS_UINT32 *)B) = *((IRIS_UINT32 *)A);
#endif

// Class LinkTestMessage 

LinkTestMessage::LinkTestMessage()
	: Message(IRIS_NodeInterface::LINK_TEST_MESSAGE, LINK_TEST_SERIALIZED_MSG_SIZE) // ID and size
{
}


LinkTestMessage::~LinkTestMessage()
{
}


//	See super class documentation.
int LinkTestMessage::getID ()
{
	return IRIS_NodeInterface::LINK_TEST_MESSAGE;
}

//	See super class documentation.
int LinkTestMessage::deserialize (IRIS_UBYTE *bufPtr, IRIS_UINT32 length)
{
	IRIS_UBYTE *pktPtr = bufPtr;
	IRIS_UINT16 calcCrc, rcedCrc;

		// Restore the Message ID and check the CRC
	calcCrc = NetworkServices::calcCRC(bufPtr, serializedSize - 2);
	BYTE_SWAP_COPY_16(&bufPtr[serializedSize - 2], &rcedCrc);  // set received crc to network order
	
	if(calcCrc != rcedCrc)
		return IRIS_NodeInterface::CRC_FAIL;
	
	// Copy individual members into the serial buffer

	pktPtr += 1;  // Skip past the Message class data

		// Compatability code
	BYTE_SWAP_COPY_32(pktPtr, &compatabilityCode);
	pktPtr += 4;

		// Control Number
	BYTE_SWAP_COPY_32(pktPtr, &controlNumber);
		
	return IRIS_NodeInterface::OK;
}

//	See super class documentation.
int LinkTestMessage::serialize (IRIS_UBYTE *bufPtr)
{
	IRIS_UBYTE *pktPtr = bufPtr;
	IRIS_UINT16 crc;

	// Fill in the Message members (ID, Dest, Orig)
	Message::pktBuild(&pktPtr);

	// Copy individual members into the serial buffer

		// Compatability code
	BYTE_SWAP_COPY_32(&compatabilityCode, pktPtr);
	pktPtr += 4;

		// Compatability code
	BYTE_SWAP_COPY_32(&controlNumber, pktPtr);
	pktPtr += 4;

	// Now add the CRC
	crc = NetworkServices::calcCRC(bufPtr, ((IRIS_UINT32)(serializedSize - 2)));
	BYTE_SWAP_COPY_16(&crc, pktPtr);  // set crc to network order and copy into the serialized packet

	return serializedSize;  // Length of packet is auto generated
}
