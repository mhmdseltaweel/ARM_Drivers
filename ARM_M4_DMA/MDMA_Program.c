/*
 * MDMA_Program.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Mohamed Said
 */




#include "BIT_MATH.h"
#include "MDMA_Interface.h"
#include "MDMA_Private.h"
#include "MDMA_CNFG.h"


void (*PTR_FUNC_STREAM0)(void);
void (*PTR_FUNC_STREAM1)(void);

void MDMA1_VoidInit(u8 Copy_U8StreamID)
{
	/*clear enable to set the configuration of the stream, as we cannot change any thing while enable bit is high*/
	CLR_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,EN);

	/*Enable Transfer Complete Interrupt Flag*/
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,TCIE);
	/*SET THE DIRECTION OF THE TRANSFER FROM MEMORY TO MEMORY*/
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,DIR1);
	CLR_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,DIR0);
	/*ENABLE CIRCULAR MODE*/
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,CIRC);
	/*DISABLE DIRECT MODE*/
	CLR_BIT(DMA1->STREAMCH[Copy_U8StreamID].FCR,DMDIS);
	/*SET THE PINC AND MINC TO BE ENABLED AS WE DEAL WITH TWO MEMORIES*/
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,PINC);
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,MINC);
	/*set the psize to be byte*/
	CLR_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,PSIZE0);
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,PSIZE1);
	/*SET HTE MSIZE TO BE BYTE*/
	CLR_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,MSIZE0);
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,MSIZE1);
	/*SET THE PRIORITY LEVEL FOR THIS STREAM TO VERY HIGH*/
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,PL0);
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,PL1);
	/*SET THE FIFO TO BE FULL*/
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].FCR,FTH0);
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].FCR,FTH1);
}
void MDMA1_VoidSetAddresses(u8 Copy_U8StreamID,u8 Copy_U8SrcAddress,u8 Copy_U8DestinationAddress,u16 Copy_U8DataLenght)
{
	DMA1->STREAMCH[Copy_U8StreamID].NDTR=Copy_U8DataLenght;
	DMA1->STREAMCH[Copy_U8StreamID].M0AR=Copy_U8DestinationAddress;
	DMA1->STREAMCH[Copy_U8StreamID].PAR=Copy_U8SrcAddress;
}

void MDMA1_VoidStartTransfer(u8 Copy_U8StreamID)
{
	/*CLEAR ALL FLAGS for stream 0*/
	DMA1->LISR|=((CFEIF0<<0)||(1<<CDMIF0)||(1<<CTEIF0)||(1<<CHTIF0)||(1<<CTCIF0));

	/*ENABLE THE DMA IN CR REGISTER*/
	SET_BIT(DMA1->STREAMCH[Copy_U8StreamID].CR,EN);
}


void MDMA1_VoidSetCallBack(u8 Copy_U8StreamID,void (*Ptr_func)(void))
{
	switch (Copy_U8StreamID)
	{
	case 0:	PTR_FUNC_STREAM0=Ptr_func;	break;
	case 1:	PTR_FUNC_STREAM1=Ptr_func; 	break;

	}
}

void DMA1_Stream0_IRQHandler()
{
	PTR_FUNC_STREAM0();
}

