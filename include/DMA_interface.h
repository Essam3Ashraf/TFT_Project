/*********************************************
 * Author:				Essam A. Elhamalawy
 * Creation Data:		20 Apr, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		20 Apr, 2024	Essam A. Elhamalawy		    Initial Creation
*********************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

typedef enum
{
  DMA_Channel_0 = 0,
  DMA_Channel_1,
  DMA_Channel_2,
  DMA_Channel_3,
  DMA_Channel_4,
  DMA_Channel_5,
  DMA_Channel_6,
  DMA_Channel_7
}DMA_CHANNELS_t;

void MDMA1_voidInit(DMA_CHANNELS_t Copy_u8ChannelDMA);
void MDMA1_voidStartTransfer(u32 * Copy_pu32SourceAddress, u32 * Copy_pu32DestinationAddress, u16 Copy_u16BlockSize, DMA_CHANNELS_t Copy_u8ChannelDMA);

#endif
