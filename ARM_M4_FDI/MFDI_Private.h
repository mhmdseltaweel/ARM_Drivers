/*
 * MFDI_Private.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MFDI_PRIVATE_H_
#define MFDI_PRIVATE_H_


#define FLASHDRIVER_BASE_ADDRESS	0x40023C00

typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 OPTCR;
}Flash_Driver_t;

#define MFlashDriver		((volatile Flash_Driver_t*)FLASHDRIVER_BASE_ADDRESS)


#define WRITE_HALF_WORD 01


#endif /* MFDI_PRIVATE_H_ */
