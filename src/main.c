
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"
#include "../include/SPI_interface.h"
#include "../include/TFT_interface.h"
#include "../include/Picture.h"

void main(void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB_BUS, RCC_AHB_GPIOAEN);
	MRCC_voidEnablePeripheralClock(RCC_APB2_BUS, RCC_APB2_SPI1EN);
	MSTK_voidInit();
	MSPI_voidInit();
	HTFT_voidInit();

	while (1)
  {
	  HTFT_voidDisplayImage(Picture);
  }
}

