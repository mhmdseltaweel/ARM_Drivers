/*
 * MGPIO_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGPIO_Private.h"
#include "MGPIO_Interface.h"




void MGPIO_VoidSetPinDirection(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Mode)
{

	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	MGPIOA->MODER |=(u32) ((Copy_U8Mode)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOB_PORT:	MGPIOB->MODER |=(u32) ((Copy_U8Mode)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOC_PORT:	MGPIOC->MODER |=(u32) ((Copy_U8Mode)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	}

}


void MGPIO_VoidSetPinValue(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Value)
{
	if(Copy_U8Value==MGPIO_OUTPUT_HIGH)
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT:	SET_BIT(MGPIOA->ODR,Copy_U8PinID); break;
		case MGPIOB_PORT:	SET_BIT(MGPIOB->ODR,Copy_U8PinID); break;
		case MGPIOC_PORT:	SET_BIT(MGPIOC->ODR,Copy_U8PinID); break;
		}
	}
	else
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT:	CLR_BIT(MGPIOA->ODR,Copy_U8PinID); break;
		case MGPIOB_PORT:	CLR_BIT(MGPIOB->ODR,Copy_U8PinID); break;
		case MGPIOC_PORT:	CLR_BIT(MGPIOC->ODR,Copy_U8PinID); break;
		}
	}
}
void MGPIO_VoidSetOutputType(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Type)
{
	if(Copy_U8Type==MGPIO_TYPE_OPEN_DRAIN)
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT:	SET_BIT(MGPIOA->OTYPER,Copy_U8PinID); break;
		case MGPIOB_PORT:	SET_BIT(MGPIOB->OTYPER,Copy_U8PinID); break;
		case MGPIOC_PORT:	SET_BIT(MGPIOC->OTYPER,Copy_U8PinID); break;
		}
	}
	else
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT:	CLR_BIT(MGPIOA->OTYPER,Copy_U8PinID); break;
		case MGPIOB_PORT:	CLR_BIT(MGPIOB->OTYPER,Copy_U8PinID); break;
		case MGPIOC_PORT:	CLR_BIT(MGPIOC->OTYPER,Copy_U8PinID); break;
		}
	}
}
void MGPIO_VoidSetPinSpeed(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Speed)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	MGPIOA->OSPEEDR |= (u32) ((Copy_U8Speed)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOB_PORT:	MGPIOB->OSPEEDR |= (u32) ((Copy_U8Speed)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOC_PORT:	MGPIOC->OSPEEDR |= (u32) ((Copy_U8Speed)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	}
}
void MGPIO_VoidSetPullState(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8State)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	MGPIOA->PUPDR |= (u32) ((Copy_U8State)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOB_PORT:	MGPIOB->PUPDR |= (u32) ((Copy_U8State)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	case MGPIOC_PORT:	MGPIOC->PUPDR |= (u32) ((Copy_U8State)<<(MGPIO_VALUE_TWO*Copy_U8PinID));	break;
	}
}
u8 MGPIO_VoidGetPinValue(u8 Copy_U8PortID,u8 Copy_U8PinID)
{
	u8 result;
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	result = ((MGPIOA->IDR)>>Copy_U8PinID)&MGPIO_VALUE_ONE;	break;
	case MGPIOB_PORT:	result = ((MGPIOB->IDR)>>Copy_U8PinID)&MGPIO_VALUE_ONE;	break;
	case MGPIOC_PORT:	result = ((MGPIOC->IDR)>>Copy_U8PinID)&MGPIO_VALUE_ONE;	break;
	}
	return result;
}
void MGPIO_VoidDirectReset(u8 Copy_U8PortID,u8 Copy_U8PinID)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	SET_BIT(MGPIOA->BSRR,Copy_U8PinID+MGPIO_VALUE_SIXTEEN); break;
	case MGPIOB_PORT:	SET_BIT(MGPIOB->BSRR,Copy_U8PinID+MGPIO_VALUE_SIXTEEN); break;
	case MGPIOC_PORT:	SET_BIT(MGPIOC->BSRR,Copy_U8PinID+MGPIO_VALUE_SIXTEEN); break;
	}
}
void MGPIO_VoidDirectSet(u8 Copy_U8PortID,u8 Copy_U8PinID)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	SET_BIT(MGPIOA->BSRR,Copy_U8PinID); break;
	case MGPIOB_PORT:	SET_BIT(MGPIOB->BSRR,Copy_U8PinID); break;
	case MGPIOC_PORT:	SET_BIT(MGPIOC->BSRR,Copy_U8PinID); break;
	}
}

void MGPIO_VoidTogglePin(u8 Copy_U8PortID,u8 Copy_U8PinID)
{
	switch(Copy_U8PortID)
	{
	case MGPIOA_PORT:	TOGGLE_BIT(MGPIOA->ODR,Copy_U8PinID); break;
	case MGPIOB_PORT:	TOGGLE_BIT(MGPIOB->ODR,Copy_U8PinID); break;
	case MGPIOC_PORT:	TOGGLE_BIT(MGPIOC->ODR,Copy_U8PinID); break;
	}
}

void MGPIO_VoidSetAlternativeFunc(u8 Copy_U8PortID, u8 Copy_U8PinID,u8 Copy_U8Mode)
{
	if(Copy_U8PinID<8)
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT: MGPIOA->AFRL |=(u32)(Copy_U8Mode<<(4*Copy_U8PinID)); break;
		case MGPIOB_PORT: MGPIOB->AFRL |=(u32)(Copy_U8Mode<<(4*Copy_U8PinID)); break;
		case MGPIOC_PORT: MGPIOC->AFRL |=(u32)(Copy_U8Mode<<(4*Copy_U8PinID)); break;
		}
	}
	else if (Copy_U8PinID>7&&Copy_U8PinID<16)
	{
		switch(Copy_U8PortID)
		{
		case MGPIOA_PORT: MGPIOA->AFRH |=(u32)(Copy_U8Mode<<(4*(Copy_U8PinID%8))); break;
		case MGPIOB_PORT: MGPIOB->AFRH |=(u32)(Copy_U8Mode<<(4*(Copy_U8PinID%8))); break;
		case MGPIOC_PORT: MGPIOC->AFRH |=(u32)(Copy_U8Mode<<(4*(Copy_U8PinID%8))); break;
		}
	}
}



