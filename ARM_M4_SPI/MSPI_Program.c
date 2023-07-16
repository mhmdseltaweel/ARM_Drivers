/*
 * MSPI_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */



#include "MSPI_Interface.h"
#include "MSPI_Private.h"
#include "MSPI_CNFG.h"
#include "BIT_MATH.h"
static void (*PTR_FUNC)(void);

void MSPI_VoidInit(void)
{
	/*SELECT THE DATA FORMAT AS 8 BITS*/
	CLR_BIT(MSPI1->CR1,11);
	/*set the receive only bit to 1 to transmit and receive*/
	SET_BIT(MSPI1->CR1,10);
	/*SET THE FRAME FORMAT TO SEND THE MSB FIRST*/
	CLR_BIT(MSPI1->CR1,7);

	/*SELECT THE SPI AS SLAVE OR MASTER*/
#if	SPI_MASTER_SLAVE== MSPI_SLAVE
	CLR_BIT(MSPI1->CR1,2);
#elif	SPI_MASTER_SLAVE == MSPI_MASTER
	SET_BIT(MSPI1->CR1,2);
	/*SET THE PRESCALLER OF THE CLOCK OF THE SYSTEM Fclk/2*/
	CLR_BIT(MSPI1->CR1,5);
	CLR_BIT(MSPI1->CR1,4);
	CLR_BIT(MSPI1->CR1,3);
#else
#error ("error in slave master mode")
#endif
	/*SET THE CLOCK POLARITY TO 1, LEADING EDGE IS FALLING EDGE*/
	SET_BIT(MSPI1->CR1,1);
	/*SET THE CLOCK PHASAE TO 1,SETUP THEN SAMPLE*/
	SET_BIT(MSPI1->CR1,0);
	/*ENABLE THE RX INTERRUPT */
	SET_BIT(MSPI1->CR2,6);
	/*ENABLE THE SPI*/
	SET_BIT(MSPI1->CR1,6);
}

void MSPI_VoidSendData(u8 Copy_U8Data)
{
	while (GET_BIT(MSPI1->SR,1)==0);
	MSPI1->DR=Copy_U8Data;
}
u8 MSPI_U8RecieveData(void)
{
	return MSPI1->DR;
}
void MSPI_VoidSetCallBack(void (*ptr)(void))
{
	PTR_FUNC=ptr;
}

void SPI1_IRQHandler(void)
{
	PTR_FUNC();
}


