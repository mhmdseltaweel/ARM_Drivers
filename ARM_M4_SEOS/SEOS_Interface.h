/*
 * SEOS_Interface.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef SEOS_INTERFACE_H_
#define SEOS_INTERFACE_H_


#include "STD_TYPES.h"

void OS_VoidCreateTask(void(*func)(void),u8 Copy_U8Task_Priority,u32 Copy_U8TaskPeriodicity,u8 Copy_U8TaskFirstDelay);
void OS_VoidScheduler(void);


#endif /* SEOS_INTERFACE_H_ */
