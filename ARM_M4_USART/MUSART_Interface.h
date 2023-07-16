/*
 * MUSART_Interface.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_




void MUSART1_VoidInit(void);
void MUSART1_VoidEnable(void);
void MUSART1_VoidEnableTXInterrupt(void);
void MUSART1_VoidEnableRXInterrupt(void);
void MUSART1_VoidSendData(u8 Copy_U8Data);
u8 MUSART1_VoidReceiveData(void);
u8 MUSART1_VoidReadDataSynch(u8* Copy_U8PtrData);
void MUSART1_VoidSetCallBack(void (*Ptr_Func)(void));



#endif /* MUSART_INTERFACE_H_ */
