/*
 * MSYSTICK_Private.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MSYSTICK_PRIVATE_H_
#define MSYSTICK_PRIVATE_H_


#define SYSTICK_BASE_ADDRESS	0xE000E010

#define SYSTICK_SINGLE_INT		0U
#define SYSTICK_PERODIC_INT		1U

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}SYSTICK_t;


#define MSYSTICK_REG			((volatile SYSTICK_t*)SYSTICK_BASE_ADDRESS)

#define VALUE_ZERO				0U

#define STK_CTRL_ENABLE			0U
#define STK_CTRL_TICK_INT		1U
#define STK_CTRL_CLKSRC			2U
#define STK_CTRL_COUNTFLAG		16U




#endif /* MSYSTICK_PRIVATE_H_ */
