/*
 * MFDI_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#include "STD_TYPES.h"
#include "MFDI_Private.h"
#include "BIT_MATH.h"


void MFlashDriver_VoidSectorErase(u8 Copy_U8SectorNumber)
{
	/*WAIT FOR NO OPERATION ON FLASH MEMORY*/
	while (GET_BIT(MFlashDriver->SR,16)==1);
	/*unlock sequence*/
	if (GET_BIT(MFlashDriver->CR,31)==1)
	{
		MFlashDriver->CR=0x45670123;
		MFlashDriver->CR=0xCDEF89AB;
	}
	/*SELECTING ERASE SECTOR*/
	SET_BIT(MFlashDriver->CR,1);
	CLR_BIT(MFlashDriver->CR,2);
	/*SELECLT THE SECTOR TO ERASE, MUST BE BETWEEN 0 AND 5*/
	/*CLEARING THE FOUR BITS FOR SECTOR NUMBERE*/
	MFlashDriver->CR=0xFFFFFF87;
	MFlashDriver->CR|=Copy_U8SectorNumber<<3;
	/*START ERASE OPERATION*/
	SET_BIT(MFlashDriver->CR,16);
	/*LOCK THE CONTROL REGISTER*/
	SET_BIT(MFlashDriver->CR,31);
	/*wait til the erase is completed*/
	while (GET_BIT(MFlashDriver->SR,16)==1);
	/*CLEAR THE EOP BIT*/
	SET_BIT(MFlashDriver->SR,0);
	/*CLEAR THE SER BTI*/
	CLR_BIT(MFlashDriver->CR,1);

}

void MFlashDriverEraseMultiSector(u8 Copy_U8StartSector,u8 Copy_U8NumberToErase)
{
	for(u8 Loc_U8Iterator=Copy_U8StartSector;Loc_U8Iterator<Copy_U8NumberToErase;Loc_U8Iterator++)
	{
		MFlashDriver_VoidSectorErase(Loc_U8Iterator);
	}
}




void MFlashDriver_VoidProgram(u32 Copy_u32Address,u16* Copy_ptrData, u8 Copy_u8Datalenght)
{
	/*WAIT FOR NO OPERATION ON FLASH MEMORY*/
	while (GET_BIT(MFlashDriver->SR,16)==1);
	/*unlock if locked*/
	if (GET_BIT(MFlashDriver->CR,31)==1)
	{
		MFlashDriver->CR=0x45670123;
		MFlashDriver->CR=0xCDEF89AB;
	}
	/*set the psize for halfword */
	MFlashDriver->CR=0xFFFFFCFF;
	MFlashDriver->CR|=WRITE_HALF_WORD;

	for (u8 LOC_u8Iterator=0;LOC_u8Iterator<Copy_u8Datalenght;LOC_u8Iterator++)
	{
		/*set the PG BIT IN CR*/
		SET_BIT(MFlashDriver->CR,0);
		/*SET ADDRESS TO WRITE OT IT
		 *
		 * */
		*((volatile u16*)Copy_u32Address)= Copy_ptrData[LOC_u8Iterator];
		Copy_u32Address +=2;

		/*wait if busy ==1 in SR */
		while (GET_BIT(MFlashDriver->SR,16)==1);
		/*clear the end of operation flag in SR*/
		SET_BIT(MFlashDriver->SR,0);
		/*clear PG bit */
		CLR_BIT(MFlashDriver->CR,0);
	}


}

