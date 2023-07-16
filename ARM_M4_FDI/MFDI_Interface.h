/*
 * MFDI_Interface.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_

#include "STD_TYPES.h"

void MFlashDriver_VoidSectorErase(u8 Copy_U8SectorNumber);
void MFlashDriver_VoidProgram(u8 Copy_U8Data);
void MFlashDriverEraseMultiSector(u8 Copy_U8StartSector,u8 Copy_U8NumberToErase);




#endif /* MFDI_INTERFACE_H_ */
