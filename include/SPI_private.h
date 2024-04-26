/*********************************************
 * Author:				  Essam A. Elhamalawy
 * Creation Data:	  06 Apr, 2024
 * Version:				  v1.0
 * Compiler:			  GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				    MCAL
 ********************************************/
/*********************************************
 * Version	   Date				     Author				             Description
 * v1.0		     06 Apr, 2024	   Essam A. Elhamalawy	    Initial Creation
*********************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct 
{
  volatile u32 CR1;
  volatile u32 CR2;
  volatile u32 SR;
  volatile u32 DR;
}SPI_t;

#define  MSPI1  ((volatile SPI_t *)0x40013000)
#define  MSPI2  ((volatile SPI_t *)0x40003800)

#define  SSM   9
#define  SSI   8
#define  BUSY_FLAG  7
#define  SPE    6
#define  MSTR   2
#define  BR     3
#define  CPOL   1
#define  CPHA   0
#define  RXNE   0

#define  MSPI_DISABLE  0
#define  MSPI_ENABLE  1

#define  MSPI_MASTER  2
#define  MSPI_SLAVE   3

#define  CK_LOW_IDLE   0
#define  CK_HIGH_IDLE  1

#define  LEADING_EDGE_RECEIVE_TRAILING_EDGE_TRANSMIT   0
#define  LEADING_EDGE_TRANSMIT_TRAILING_EDGE_RECEIVE   1

#define  MSPI_DIV_FACT_MASK  0b111

enum
{
  MSPI_DIV_FACT_2 = 0,
  MSPI_DIV_FACT_4,
  MSPI_DIV_FACT_8,
  MSPI_DIV_FACT_16,
  MSPI_DIV_FACT_32,
  MSPI_DIV_FACT_64,
  MSPI_DIV_FACT_128,
  MSPI_DIV_FACT_256
};

#endif
