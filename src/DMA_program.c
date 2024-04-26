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
// Library Inclusion
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
# include "../include/DMA_interface.h"
# include "../include/DMA_private.h"
# include "../include/DMA_config.h"

void MDMA1_voidInit(DMA_CHANNELS_t Copy_u8ChannelDMA)
{
    if(Copy_u8ChannelDMA>=DMA_Channel_0 && Copy_u8ChannelDMA<=DMA_Channel_7)
    {
        MDMA1->Channel[Copy_u8ChannelDMA].SCR = DMA_INIT;
        MDMA1->Channel[Copy_u8ChannelDMA].SCR &= ~(DMA_CH_MASK << DMA_CH_BIT_OFFST);
        MDMA1->Channel[Copy_u8ChannelDMA].SCR |= (Copy_u8ChannelDMA << DMA_CH_BIT_OFFST);
    }
    else
    {
      // Error
    }
}

void MDMA1_voidStartTransfer(u32 * Copy_pu32SourceAddress, u32 * Copy_pu32DestinationAddress, u16 Copy_u16BlockSize, DMA_CHANNELS_t Copy_u8ChannelDMA)
{
    if(Copy_u8ChannelDMA>=DMA_Channel_0 && Copy_u8ChannelDMA<=DMA_Channel_7)
    {
    // DMA Channel is Disabled
    CLR_BIT(MDMA1->Channel[Copy_u8ChannelDMA].SCR, DMA_BIT_0);
    // Load Src Address
    MDMA1->Channel[Copy_u8ChannelDMA].SPAR = Copy_pu32SourceAddress;
    //Load Dest Address
    MDMA1->Channel[Copy_u8ChannelDMA].SM0AR = Copy_pu32DestinationAddress;
    //Set the Block Size
    MDMA1->Channel[Copy_u8ChannelDMA].SNDTR = Copy_u16BlockSize;
    //Enable The DMA Channel
    SET_BIT(MDMA1->Channel[Copy_u8ChannelDMA].SCR, DMA_BIT_0);
    }
    else
    {
      // Error
    }
}

static void MDMA1_voidClearAllFlags(void)
{
    SET_BIT(MDMA1 -> LIFCR, DMA_BIT_0);
    SET_BIT(MDMA1 -> LIFCR, DMA_BIT_2);
    SET_BIT(MDMA1 -> LIFCR, DMA_BIT_3);
    SET_BIT(MDMA1 -> LIFCR, DMA_BIT_4);
    SET_BIT(MDMA1 -> LIFCR, DMA_BIT_5);
}

void DMA1_Stream0_IRQHandler(void)
{

}
