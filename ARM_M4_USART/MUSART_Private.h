/*
 * MUSART_Private.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MUSART_PRIVATE_H_
#define MUSART_PRIVATE_H_



#define USART1_BASE_ADDRESS					0x40011000
#define USART2_BASE_ADDRESS					0x40004400
#define USART6_BASE_ADDRESS					0x40011400


#define TXE									7U
#define TC									6U
#define RXNE								5U


#define OVER8								15U
#define UE									13U
#define M									12U
#define PCE									10U
#define TCIE								6U
#define RXNEIE								5U
#define TE									3U
#define RE									2U


#define STOP1								13U
#define STOP0								12U

typedef	struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}UART_t;

#define USART1								((volatile UART_t*)USART1_BASE_ADDRESS)
#define USART2								((volatile UART_t*)USART2_BASE_ADDRESS)
#define USART6								((volatile UART_t*)USART6_BASE_ADDRESS)



#endif /* MUSART_PRIVATE_H_ */
