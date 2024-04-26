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

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

typedef enum
{
  MSPI_1 = 0,
  MSPI_2
}MSPI_Number_t;

void MSPI_voidInit(void);
u8 MSPI_u8TrancieveSynchronous(MSPI_Number_t Copy_tSPINumber, u8 Copy_u8Data);
u8 MSPI_u8ReceiveSynchronous(MSPI_Number_t Copy_tSPINumber);

#endif
