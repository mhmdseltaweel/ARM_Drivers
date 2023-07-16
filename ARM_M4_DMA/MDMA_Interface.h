/*
 * MDMA_Interface.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MDMA_INTERFACE_H_
#define MDMA_INTERFACE_H_


#include "STD_TYPES.h"



void MDMA1_VoidInit(u8 Copy_U8StreamID);

void MDMA1_VoidSetAddresses(u8 Copy_U8StreamID,u8 Copy_U8SrcAddress,u8 Copy_U8DestinatiionAddress,u16 Copy_U8DataLenght);

void MDMA1_VoidStartTransfer(u8 Copy_U8StreamID);
void MDMA1_VoidSetCallBack(u8 Copy_U8StreamID,void (*Ptr_func)(void));





#endif /* MDMA_INTERFACE_H_ */
