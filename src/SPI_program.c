/*********************************************
 * Author:				  Essam A. Elhamalawy
 * Creation Data:		06 Apr, 2024
 * Version:				  v1.0
 * Compiler:			  GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				    MCAL
 ********************************************/
/*********************************************
 * Version	  Date				      Author				           Description
 * v1.0		    06 Apr, 2024	    Essam A. Elhamalawy		  Initial Creation
*********************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/SPI_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/SPI_private.h"
#include "../include/SPI_config.h"

//Pre-build Controled by SPI_config.h
void MSPI_voidInit(void)
{
  u8 Local_u8SPIPins;
  #if MSPI1_STATE == MSPI_DISABLE
  CLR_BIT(MSPI1 -> CR1, SPE);
  #elif (MSPI1_STATE == MSPI_ENABLE && (MSPI1_DIV_FACT >= MSPI_DIV_FACT_2 && MSPI1_DIV_FACT <= MSPI_DIV_FACT_256))
  #if MSPI1_MODE == MSPI_SLAVE
  CLR_BIT(MSPI1 -> CR1, MSTR);
  MSPI1 -> CR1 &= ~(MSPI_DIV_FACT_MASK << BR);
  MSPI1 -> CR1 |= (MSPI1_DIV_FACT << BR);
  #elif MSPI1_MODE == MSPI_MASTER
  SET_BIT(MSPI1 -> CR1, MSTR);
  MSPI1 -> CR1 &= ~(MSPI_DIV_FACT_MASK << BR);
  MSPI1 -> CR1 |= (MSPI1_DIV_FACT << BR);
  #if(MSPI1_CPOL == CK_LOW_IDLE || MSPI1_CPOL == CK_HIGH_IDLE)
  CLR_BIT(MSPI1 -> CR1, CPOL);
  MSPI1 -> CR1 |= (MSPI1_CPOL << CPOL);
  #else
    #error "MSPI1_CPOL Configuration Error"
  #endif
  #if(MSPI1_CPHA == LEADING_EDGE_RECEIVE_TRAILING_EDGE_TRANSMIT || MSPI1_CPHA == LEADING_EDGE_TRANSMIT_TRAILING_EDGE_RECEIVE)
  CLR_BIT(MSPI1 -> CR1, CPHA);
  MSPI1 -> CR1 |= (MSPI1_CPHA << CPHA);
  #else
    #error "MSPI1_CPHA Configuration Error"
  #endif
  #else
    #error "MSPI1_MODE Configuration Error"
  #endif
  for(Local_u8SPIPins=GPIO_PIN4; Local_u8SPIPins<=GPIO_PIN7; Local_u8SPIPins++)
  {
    MGPIO_voidSetPinMode(GPIO_PORTA, Local_u8SPIPins, GPIO_ALT_FUNC);
    MGPIO_voidAltFuncPin(GPIO_PORTA, Local_u8SPIPins, GPIO_AF05);
  }
  CLR_BIT(MSPI1 -> CR1, SSM);
  SET_BIT(MSPI1 -> CR1, SPE);
  #else
    #error "MSPI1 Configuration Error"
  #endif
  #if MSPI2_STATE == MSPI_DISABLE
  CLR_BIT(MSPI2 -> CR1, SPE);
  #elif (MSPI2_STATE == MSPI_ENABLE && (MSPI2_DIV_FACT >= MSPI_DIV_FACT_2 && MSPI2_DIV_FACT <= MSPI_DIV_FACT_256))
  #if MSPI2_MODE == MSPI_SLAVE
  CLR_BIT(MSPI2 -> CR1, MSTR);
  MSPI2 -> CR1 &= ~(MSPI_DIV_FACT_MASK << BR);
  MSPI2 -> CR1 |= (MSPI2_DIV_FACT << BR);
  #elif MSPI2_MODE == MSPI_MASTER
  SET_BIT(MSPI2 -> CR1, MSTR);
  MSPI2 -> CR1 &= ~(MSPI_DIV_FACT_MASK << BR);
  MSPI2 -> CR1 |= (MSPI2_DIV_FACT << BR);
  #if(MSPI2_CPOL == CK_LOW_IDLE || MSPI2_CPOL == CK_HIGH_IDLE)
  CLR_BIT(MSPI2 -> CR1, CPOL);
  MSPI2 -> CR1 |= (MSPI2_CPOL << CPOL);
  #else
    #error "MSPI2_CPOL Configuration Error"
  #endif
  #if(MSPI2_CPHA == LEADING_EDGE_RECEIVE_TRAILING_EDGE_TRANSMIT || MSPI2_CPHA == LEADING_EDGE_TRANSMIT_TRAILING_EDGE_RECEIVE)
  CLR_BIT(MSPI2 -> CR1, CPHA);
  MSPI2 -> CR1 |= (MSPI2_CPHA << CPHA);
  #else
    #error "MSPI2_CPHA Configuration Error"
  #endif
  #else
   #error "MSPI2_MODE Configuration Error"
  #endif
  SET_BIT(MSPI2 -> CR1, SPE);
  for(Local_u8SPIPins=GPIO_PIN12; Local_u8SPIPins<=GPIO_PIN15; Local_u8SPIPins++)
  {
    MGPIO_voidSetPinMode(GPIO_PORTB, Local_u8SPIPins, GPIO_ALT_FUNC);
    MGPIO_voidAltFuncPin(GPIO_PORTB, Local_u8SPIPins, GPIO_AF05);
  }
  #else
    #error "MSPI2 Configuration Error"
  #endif
}

u8 MSPI_u8TrancieveSynchronous(MSPI_Number_t Copy_tSPINumber, u8 Copy_u8Data)
{
   u8 Local_u8ReceivedData;
   switch(Copy_tSPINumber)
   {
     case MSPI_1:
     MSPI1 -> DR = Copy_u8Data;
     while(GET_BIT(MSPI1 -> SR, BUSY_FLAG));
     Local_u8ReceivedData = MSPI1 -> DR;
     break;
     case MSPI_2:
     MSPI2 -> DR = Copy_u8Data;
     while(GET_BIT(MSPI2 -> SR, BUSY_FLAG));
     Local_u8ReceivedData = MSPI2 -> DR;
     break;
     default:
      // Error
     break;
   }
     return Local_u8ReceivedData;
}

u8 MSPI_u8ReceiveSynchronous(MSPI_Number_t Copy_tSPINumber)
{
  u8 Local_u8ReceivedData;
   switch(Copy_tSPINumber)
   {
     case MSPI_1:
     while(!GET_BIT(MSPI1 -> SR, RXNE));
     if(RXNE){Local_u8ReceivedData = MSPI1 -> DR;}
     break;
     case MSPI_2:
     while(!GET_BIT(MSPI2 -> SR, RXNE));
     if(RXNE){Local_u8ReceivedData = MSPI2 -> DR;}
     break;
     default:
     // Error
     break;
   }
  return Local_u8ReceivedData;
}
