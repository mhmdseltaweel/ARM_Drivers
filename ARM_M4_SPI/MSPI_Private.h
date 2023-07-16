/*
 * MSPI_Private.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_



#define MSPI1_BASE_ADDRESS	0x40013000


typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}MSPI_t;

#define MSPI1	((volatile MSPI_t*)MSPI1_BASE_ADDRESS)


#define MSPI_MASTER		0
#define MSPI_SLAVE 		1



#endif /* MSPI_PRIVATE_H_ */
