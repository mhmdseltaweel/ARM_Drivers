/*
 * MGPIO_Interface.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_


#define MGPIOA_PORT		0U
#define MGPIOB_PORT		1U
#define MGPIOC_PORT 	2U


#define MGPIO_PIN0							0U
#define MGPIO_PIN1							1U
#define MGPIO_PIN2							2U
#define MGPIO_PIN3							3U
#define MGPIO_PIN4							4U
#define MGPIO_PIN5							5U
#define MGPIO_PIN6							6U
#define MGPIO_PIN7							7U
#define MGPIO_PIN8							8U
#define MGPIO_PIN9							9U
#define MGPIO_PIN10							10U
#define MGPIO_PIN11							11U
#define MGPIO_PIN12 						12U
#define MGPIO_PIN13 						13U
#define MGPIO_PIN14							14U
#define MGPIO_PIN15							15U


#define MGPIO_MODE_INPUT					(0b00)
#define MGPIO_MODE_OUTPUT					(0b01)
#define MGPIO_MODE_ALTF						(0b10)
#define MGPIO_MODE_ANALOG					(0b11)


#define MGPIO_TYPE_PUSH_PULL				0U
#define MGPIO_TYPE_OPEN_DRAIN				1U



#define MGPIO_OUTPUT_SPEED_lOW				(0b00)
#define MGPIO_OUTPUT_SPEED_MEDIUM			(0b01)
#define MGPIO_OUTPUT_SPEED_HIGH				(0b10)
#define MGPIO_OUTPUT_SPEED_VERY HIGH		(0b11)


#define MGPIO_PULL_FLOATING					(0b00)
#define MGPIO_PULL_UP						(0b01)
#define MGPIO_PULL_DOWN						(0b10)


#define MGPIO_OUTPUT_HIGH					1U
#define MGPIO_OUTPUT_LOW					0U




#define AF0							0b0000
#define AF1							0b0001
#define AF2							0b0010
#define AF3							0b0011
#define AF4							0b0100
#define AF5							0b0101
#define AF6							0b0110
#define AF7							0b0111
#define AF8							0b1000
#define AF9							0b1001
#define AF10						0b1010
#define AF11						0b1011
#define AF12						0b1100
#define AF13						0b1101
#define AF14						0b1110
#define AF15						0b1111

void MGPIO_VoidSetPinDirection(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Mode);
void MGPIO_VoidSetPinValue(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Value);
void MGPIO_VoidSetOutputType(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Type);
void MGPIO_VoidSetPinSpeed(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8Speed);
void MGPIO_VoidSetPullState(u8 Copy_U8PortID,u8 Copy_U8PinID,u8 Copy_U8State);
u8 MGPIO_VoidGetPinValue(u8 Copy_U8PortID,u8 Copy_U8PinID);
void MGPIO_VoidDirectReset(u8 Copy_U8PortID,u8 Copy_U8PinID);
void MGPIO_VoidDirectSet(u8 Copy_U8PortID,u8 Copy_U8PinID);
void MGPIO_VoidTogglePin(u8 Copy_U8PortID,u8 Copy_U8PinID);
void MGPIO_VoidSetAlternativeFunc(u8 Copy_U8PortID, u8 Copy_U8PinID,u8 Copy_U8Mode);




#endif /* MGPIO_INTERFACE_H_ */
