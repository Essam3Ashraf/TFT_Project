/*********************************************
 * Author:				Essam A. Elhamalawy
 * Creation Data:		06 Apr, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				Author				      Description
 * v1.0		  06 Apr, 2024	    Essam A. Elhamalawy		 Initial Creation
*********************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

// Select SPI State (SPIx_STATE).
// There Are Two Options: [MSPI_DISABLE, MSPI_ENABLE].
#define  MSPI1_STATE  MSPI_ENABLE
#define  MSPI2_STATE  MSPI_DISABLE

// Select SPI Mode (SPIx_MODE).
// There Are Two Options: [MSPI_MASTER, MSPI_SLAVE].
#define  MSPI1_MODE  MSPI_MASTER
#define  MSPI2_MODE  MSPI_MASTER

// Select SPI Baud Rate (SPIx_BAUD_RATE) ->  SPI_BAUD_RATE = F_PCLK / DIV_FACT.
// There Are Eight Options: [MSPI_DIV_FACT_2, MSPI_DIV_FACT_4, MSPI_DIV_FACT_8, MSPI_DIV_FACT_16, MSPI_DIV_FACT_32, MSPI_DIV_FACT_64, MSPI_DIV_FACT_128, MSPI_DIV_FACT_256].
#define  MSPI1_DIV_FACT  MSPI_DIV_FACT_2
#define  MSPI2_DIV_FACT  MSPI_DIV_FACT_2

// Select SPI Clock Polarity (SPIx_CPOL).
// There Are Two Options: [CK_LOW_IDLE, CK_HIGH_IDLE].
#define  MSPI1_CPOL  CK_HIGH_IDLE
#define  MSPI2_CPOL  CK_LOW_IDLE

// Select SPI Clock Phase (SPIx_CPHA).
// There Are Two Options: [LEADING_EDGE_RECEIVE_TRAILING_EDGE_TRANSMIT, LEADING_EDGE_TRANSMIT_TRAILING_EDGE_RECEIVE].
#define  MSPI1_CPHA  LEADING_EDGE_TRANSMIT_TRAILING_EDGE_RECEIVE
#define  MSPI2_CPHA  LEADING_EDGE_RECEIVE_TRAILING_EDGE_TRANSMIT

#endif
