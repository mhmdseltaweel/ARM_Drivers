/*
 * MSPI_Interface.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_


#include "STD_TYPES.h"

void MSPI_VoidInit(void);
void MSPI_VoidSendData(u8 Copy_U8Data);
u8 MSPI_U8RecieveData(void);
void MSPI_VoidSetCallBack(void (*ptr)(void));





#endif /* MSPI_INTERFACE_H_ */
