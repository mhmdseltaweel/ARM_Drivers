/*
 * MDMA_Private.h
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */

#ifndef MDMA_PRIVATE_H_
#define MDMA_PRIVATE_H_


#define MDMA1_BASE_ADDRESS				0x40026000
#define MDMA2_BASE_ADDRESS				0x40026400


#define CFEIF0							0U
#define CDMIF0							2U
#define CTEIF0							3U
#define CHTIF0							4U
#define CTCIF0							5U


#define EN								0U
#define TCIE							4U
#define DIR0							6U
#define DIR1							7U
#define CIRC							8U
#define PINC							9U
#define MINC							10U
#define PSIZE0							11U
#define PSIZE1							12U
#define MSIZE0							13U
#define MSIZE1							14U

#define PL0								16U
#define PL1								17U


#define FTH0							0U
#define FTH1							1U
#define DMDIS							2U



typedef struct
{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
}Stream_t;

typedef struct
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	volatile Stream_t STREAMCH[8];
}DMA_t;


#define DMA1			((volatile DMA_t*)MDMA1_BASE_ADDRESS)
#define DMA2			((volatile DMA_t*)MDMA2_BASE_ADDRESS)







#endif /* MDMA_PRIVATE_H_ */
