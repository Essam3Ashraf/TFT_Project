#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


                 /*****GPIOA Registers Definitions*****/

// GPIOA Base Address Definition:
 #define  GPIOA_BASE_ADDRESS   0x40020000

// GPIOA Registers Definitions:
#define GPIOA_MODER          *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X00))
#define GPIOA_OTYPER         *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X04))
#define GPIOA_OSPEEDR        *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X08))
#define GPIOA_PUPDR          *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X0C))
#define GPIOA_IDR            *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X10))
#define GPIOA_ODR            *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X14))
#define GPIOA_BSRR           *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X18))
#define GPIOA_LCKR           *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X1C))
#define GPIOA_AFRL           *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X20))
#define GPIOA_AFRH           *((volatile u32 *) (GPIOA_BASE_ADDRESS+0X24))


                 /*****GPIOB Registers Definitions*****/

// GPIOB Base Address Definition:
 #define  GPIOB_BASE_ADDRESS   0x40020400

// GPIOB Registers Definitions:
#define GPIOB_MODER          *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X00))
#define GPIOB_OTYPER         *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X04))
#define GPIOB_OSPEEDR        *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X08))
#define GPIOB_PUPDR          *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X0C))
#define GPIOB_IDR            *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X10))
#define GPIOB_ODR            *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X14))
#define GPIOB_BSRR           *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X18))
#define GPIOB_LCKR           *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X1C))
#define GPIOB_AFRL           *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X20))
#define GPIOB_AFRH           *((volatile u32 *) (GPIOB_BASE_ADDRESS+0X24))



                 /*****GPIOC Registers Definitions*****/

// GPIOC Base Address Definition:
 #define  GPIOC_BASE_ADDRESS   0x40020800

// GPIOC Registers Definitions:
#define GPIOC_MODER          *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X00))
#define GPIOC_OTYPER         *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X04))
#define GPIOC_OSPEEDR        *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X08))
#define GPIOC_PUPDR          *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X0C))
#define GPIOC_IDR            *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X10))
#define GPIOC_ODR            *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X14))
#define GPIOC_BSRR           *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X18))
#define GPIOC_LCKR           *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X1C))
#define GPIOC_AFRL           *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X20))
#define GPIOC_AFRH           *((volatile u32 *) (GPIOC_BASE_ADDRESS+0X24))


// BIT Number 16 Location
#define   BIT16_LOCATION   16

// Numbers
#ifndef  ZERO
#define  ZERO  0
#endif
#ifndef  ONE
#define  ONE  1
#endif
#define  PIN_OFFSET  2
#define  ALT_FUNC_PIN_OFFSET  4

// Masks
#define  GPIO_PIN_MODE_MASK   0b11
#define  GPIO_PIN_OUTPUT_SPEED_MASK  0b11
#define  GPIO_INPUT_PIN_STATE_MASK   0b11
#define  GPIO_ALT_FUNC_PIN_MASK   0b1111

// PORTS MODES
#define  GPIO_INPUT_MODE  0
#define  GPIO_OUTPUT_MODE 0x55555555
#define  GPIO_ALT_FUNC_MODE 0xAAAAAAAA
#define  GPIO_ANALOG_MODE  0xFFFFFFFF

// OUTPUT PORTS MODES
#define  GPIO_PUSH_PULL_MODE  0
#define  GPIO_OPEN_DRAIN_MODE 0xFFFF

// OUTPUT PORTS SPEEDS 
#define  GPIO_LOW_SPD        0
#define  GPIO_MEDIUM_SPD     0x55555555
#define  GPIO_HIGH_SPD       0xAAAAAAAA
#define  GPIO_VERY_HIGH_SPD  0xFFFFFFFF

// OUTPUT PORTS VALUES 
#define  GPIO_LOW_VALUE   0
#define  GPIO_HIGH_VALUE  0xFFFF

// INPUT PORT STATES 
#define  GPIO_No_PULL_UP_PULL_DOWN_STATE    0
#define  GPIO_PULL_UP_STATE                 0x55555555
#define  GPIO_PULL_DOWN_STATE               0xAAAAAAAA


#endif
