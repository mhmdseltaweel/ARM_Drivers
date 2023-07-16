/*
 * SEOS_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */




#include "SEOS_Private.h"
#include "SEOS_Interface.h"
#include "SEOS_CNFG.h"

Task_t stack[TASKS_NUMBER];



void OS_VoidCreateTask(void(*func)(void),u8 Copy_U8Task_Priority,u32 Copy_U8TaskPeriodicity,u8 Copy_U8TaskFirstDelay)
{
	stack[Copy_U8Task_Priority].Task_Func=func;
	stack[Copy_U8Task_Priority].Task_Periodicity=Copy_U8TaskPeriodicity;
	stack[Copy_U8Task_Priority].Task_State=READY;
	stack[Copy_U8Task_Priority].Task_First_Delay=Copy_U8TaskFirstDelay;
}


void OS_VoidScheduler(void)
{
	for(u8 Copy_U8Counter=VALUE_ZERO;Copy_U8Counter<TASKS_NUMBER;Copy_U8Counter++)
	{
		if(stack[Copy_U8Counter].Task_State==READY)
		{
			if(stack[Copy_U8Counter].Task_First_Delay==VALUE_ZERO)
			{
				stack[Copy_U8Counter].Task_First_Delay=stack[Copy_U8Counter].Task_Periodicity;
				stack[Copy_U8Counter].Task_Func();
			}
			else
			{
				stack[Copy_U8Counter].Task_First_Delay--;
			}
		}
	}
}

