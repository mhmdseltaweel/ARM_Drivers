/*
 * SEOS_Private.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef SEOS_PRIVATE_H_
#define SEOS_PRIVATE_H_

#include "STD_TYPES.h"




#define VALUE_ZERO			0U

typedef enum
{
	DORMANT,
	READY,
	RUNNING,
	BLOCKED
}task_state_t;

typedef struct
{
	void(*Task_Func)(void);
	u8 Task_Periodicity;
	u8 Task_Priority;
	u8 Task_First_Delay;
	task_state_t Task_State;
}Task_t;





#endif /* SEOS_PRIVATE_H_ */
