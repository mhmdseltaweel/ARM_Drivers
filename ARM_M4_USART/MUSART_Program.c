/*
 * MUSART_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MUSART_Private.h"

void (*PTR_FUNC)(void);
void MUSART1_VoidInit(void)
{
	/*setting the baud rate equals 9600, while working on the HSI Clock*/
	USART1->BRR=0x683;
	/*set the oversampling over 16*/
	CLR_BIT(USART1->CR1,OVER8);
	/*SET THE DATA WORD TO BE 8 BITS*/
	CLR_BIT(USART1->CR1,M);
	/*DISABLE PARITY BIT*/
	CLR_BIT(USART1->CR1,PCE);
	/*ENABLE THE RECEIVE INTERRUPT ENABLE*/
	SET_BIT(USART1->CR1,RXNEIE);
	/*SET THE STOP BITS IN THE FRAME TO BE 1 STOP BIT*/
	CLR_BIT(USART1->CR2,STOP1);
	CLR_BIT(USART1->CR2,STOP0);
	/*ENABLE THE TRANSMITTER CCT*/
	SET_BIT(USART1->CR1,TE);
	/*ENABLE THE RECEIVER CCT*/
	SET_BIT(USART1->CR1,RE);
}


void MUSART1_VoidEnableTXInterrupt(void)
{
	/*enable transmission complete interrupt enable*/
	SET_BIT(USART1->CR1,TCIE);
}
void MUSART1_VoidEnableRXInterrupt(void)
{
	/*Enable receive interrupt enable*/
	SET_BIT(USART1->CR1,RXNEIE);
}



void MUSART1_VoidEnable(void)
{
	/*ENABLE THE USART*/
	SET_BIT(USART1->CR1,UE);
}


void MUSART1_VoidSendData(u8 Copy_U8Data)
{
	while(GET_BIT(USART1->SR,TXE)==0);
	USART1->DR=Copy_U8Data;
	while(GET_BIT(USART1->SR,TC)==0);
}
u8 MUSART1_VoidReceiveData(void)
{
	while (GET_BIT(USART1->SR,RXNE)==0);
	return USART1->DR;
}
u8 MUSART1_VoidReadDataSynch(u8* Copy_U8PtrData)
{
	u8 LOC_U8Status=0;
	if(GET_BIT(USART1->SR,RXNE)==1)
	{
		*Copy_U8PtrData=USART1->DR;
		LOC_U8Status=1;
	}
	else
	{
		return LOC_U8Status;
	}
	return LOC_U8Status;
}
void MUSART1_VoidSetCallBack(void (*Ptr_Func)(void))
{
	PTR_FUNC=Ptr_Func;
}


void USART1_IRQHandler(void){
	PTR_FUNC();
}


