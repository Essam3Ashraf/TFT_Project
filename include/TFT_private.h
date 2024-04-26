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
#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

#define   SLPOUT_CMD       0x11
#define   COLMOD_CMD       0x3A
#define   TFT_COLOR_MODE   0x05   // RGB(565)
#define   DISPON_CMD       0x29
#define   X_ADD_CMD        0x2A
#define   Y_ADD_CMD        0x2B
#define   RAM_WR_CMD       0x2C

#ifndef  ZERO
#define  ZERO  0
#endif
#ifndef  EIGHT_BITS
#define  EIGHT_BITS  8
#endif

#define  PIX_MAX  20480

// TFT Full Screen Cord
#ifndef  X_0
#define  X_0  0
#endif
#ifndef  Y_0
#define  Y_0  0
#endif
#ifndef  X_1
#define  X_1  127
#endif
#ifndef  Y_1
#define  Y_1  159
#endif

static void HTFT_voidSendCommand(u8 Copy_u8Command);

#endif
