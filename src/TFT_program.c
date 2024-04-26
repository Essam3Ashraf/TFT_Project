/*********************************************
 * Author:				Essam A. Elhamalawy
 * Creation Data:		19 Apr, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				HAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		19 Apr, 2024	Essam A. Elhamalawy		    Initial Creation
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"

#include "../include/TFT_interface.h"
#include "../include/SPI_interface.h"
#include "../include/TFT_private.h"
#include "../include/TFT_config.h"

void HTFT_voidInit(void)
{
    // Set A0 of TFT (Output, PushPull, LowSpeed)
   MGPIO_voidSetPinMode(HTFT_A0_PORT_PIN, GPIO_OUTPUT);      
   MGPIO_voidSetPinOutputMode(HTFT_A0_PORT_PIN, GPIO_PUSH_PULL);
   MGPIO_voidSetPinOutputSpeed(HTFT_A0_PORT_PIN, GPIO_LOW_SPEED);

    // Set RST of TFT (Output, PushPull, LowSpeed)
   MGPIO_voidSetPinMode(HTFT_RST_PORT_PIN, GPIO_OUTPUT);      
   MGPIO_voidSetPinOutputMode(HTFT_RST_PORT_PIN, GPIO_PUSH_PULL);
   MGPIO_voidSetPinOutputSpeed(HTFT_RST_PORT_PIN, GPIO_LOW_SPEED);

    // Initialization Sequence
   MGPIO_voidSetPinOutputValue(HTFT_RST_PORT_PIN, GPIO_HIGH);
   MSTK_voidSetBusyWait(100);
   MGPIO_voidSetPinOutputValue(HTFT_RST_PORT_PIN, GPIO_LOW);
   MSTK_voidSetBusyWait(1);
   MGPIO_voidSetPinOutputValue(HTFT_RST_PORT_PIN, GPIO_HIGH);
   MSTK_voidSetBusyWait(100);
   MGPIO_voidSetPinOutputValue(HTFT_RST_PORT_PIN, GPIO_LOW);
   MSTK_voidSetBusyWait(100);
   MGPIO_voidSetPinOutputValue(HTFT_RST_PORT_PIN, GPIO_HIGH);
   MSTK_voidSetBusyWait(120000);

   HTFT_voidSendCommand(SLPOUT_CMD);
   MSTK_voidSetBusyWait(150000);
   HTFT_voidSendCommand(COLMOD_CMD);
   HTFT_voidSendData(TFT_COLOR_MODE);
   HTFT_voidSendCommand(DISPON_CMD);
}

static void HTFT_voidSendCommand(u8 Copy_u8Command)
{
  u8 Local_u8Dummy;
  // Set A0 Pin To Be Low For Cmd
  MGPIO_voidSetPinOutputValue(HTFT_A0_PORT_PIN, GPIO_LOW);
  Local_u8Dummy = MSPI_u8TrancieveSynchronous(MSPI_1, Copy_u8Command);
}

void HTFT_voidSendData(u8 Copy_u8Data)
{
    u8 Local_u8Dummy;
    // Set A0 Pin To Be High For Data
    MGPIO_voidSetPinOutputValue(HTFT_A0_PORT_PIN, GPIO_HIGH);
    Local_u8Dummy = MSPI_u8TrancieveSynchronous(MSPI_1, Copy_u8Data);
}

void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1)
{
    // Send Set X Addresses Command
    HTFT_voidSendCommand(X_ADD_CMD);
    HTFT_voidSendData(ZERO);
    HTFT_voidSendData(Copy_u8X0);
    HTFT_voidSendData(ZERO);
    HTFT_voidSendData(Copy_u8X1);
    // Send Set Y Addresses Command
    HTFT_voidSendCommand(Y_ADD_CMD);
    HTFT_voidSendData(ZERO);
    HTFT_voidSendData(Copy_u8Y0);
    HTFT_voidSendData(ZERO);
    HTFT_voidSendData(Copy_u8Y1);
}

void HTFT_voidDisplayImage(u16 * Copy_pu16Image)
{
    u16 Local_u16LoopCounter = ZERO;
    u8 Local_u8Data;
    // TFT Full Screen
    HTFT_voidSetWindow(X_0, X_1, Y_0, Y_1);    
    // Send Write RAM Command
    HTFT_voidSendCommand(RAM_WR_CMD);
    for(Local_u16LoopCounter = ZERO; Local_u16LoopCounter < PIX_MAX; Local_u16LoopCounter++)
    {
        // Send MSB First
        Local_u8Data = (u8)(Copy_pu16Image[Local_u16LoopCounter] >> EIGHT_BITS);
        HTFT_voidSendData(Local_u8Data);
        // Send LSB Then
        Local_u8Data = (u8)Copy_pu16Image[Local_u16LoopCounter];
        HTFT_voidSendData(Local_u8Data);
    }
}
