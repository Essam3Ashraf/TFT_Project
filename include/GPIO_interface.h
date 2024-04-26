#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

// MC PORTS
#define  GPIO_PORTA  100
#define  GPIO_PORTB  101
#define  GPIO_PORTC  102

// PINS
#define  GPIO_PIN0   0
#define  GPIO_PIN1   1
#define  GPIO_PIN2   2
#define  GPIO_PIN3   3
#define  GPIO_PIN4   4
#define  GPIO_PIN5   5
#define  GPIO_PIN6   6
#define  GPIO_PIN7   7
#define  GPIO_PIN8   8
#define  GPIO_PIN9   9
#define  GPIO_PIN10  10
#define  GPIO_PIN11  11
#define  GPIO_PIN12  12
#define  GPIO_PIN13  13
#define  GPIO_PIN14  14
#define  GPIO_PIN15  15

// Alternative Function
#define  GPIO_AF00   0
#define  GPIO_AF01   1
#define  GPIO_AF02   2
#define  GPIO_AF03   3
#define  GPIO_AF04   4
#define  GPIO_AF05   5
#define  GPIO_AF06   6
#define  GPIO_AF07   7
#define  GPIO_AF08   8
#define  GPIO_AF09   9
#define  GPIO_AF10  10
#define  GPIO_AF11  11
#define  GPIO_AF12  12
#define  GPIO_AF13  13
#define  GPIO_AF14  14
#define  GPIO_AF15  15

// MODES
#define  GPIO_INPUT     0b00
#define  GPIO_OUTPUT    0b01
#define  GPIO_ALT_FUNC  0b10
#define  GPIO_ANALOG    0b11

// OUTPUT MODES 
#define  GPIO_PUSH_PULL   0
#define  GPIO_OPEN_DRAIN  1

// OUTPUT SPEEDS 
#define  GPIO_LOW_SPEED        0b00
#define  GPIO_MEDIUM_SPEED     0b01
#define  GPIO_HIGH_SPEED       0b10
#define  GPIO_VERY_HIGH_SPEED  0b11

// OUTPUT VALUES 
#define  GPIO_LOW   0
#define  GPIO_HIGH  1

// INPUT STATES 
#define  GPIO_No_PULL_UP_PULL_DOWN    0b00
#define  GPIO_PULL_UP                 0b01
#define  GPIO_PULL_DOWN               0b10

// Functions Prototypes for Pins
void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pins, u8 Copy_u8Mode);      
void MGPIO_voidSetPinOutputMode(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8OutputMode);  
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8Speed);   
void MGPIO_voidSetPinOutputValue(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8Value);  
void MGPIO_voidSetInputPinState(u8 Copy_u8Port, u8 Copy_u8InputPin, u8 Copy_u8State);   
u8 MGPIO_u8GetInputPinValue(u8 Copy_u8Port, u8 Copy_u8InputPin);
void MGPIO_voidAltFuncPin(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8AltFunc);    
void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin); 

// Functions Prototypes for Ports
void MGPIO_voidSetPortMode(u8 Copy_u8Port, u8 Copy_u8Mode);
void MGPIO_voidSetPortOutputMode(u8 Copy_u8Port, u8 Copy_u8OutputMode);
void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Speed);
void MGPIO_voidSetPortOutputValue(u8 Copy_u8Port, u8 Copy_u8Value);
void MGPIO_voidSetInputPortState(u8 Copy_u8Port, u8 Copy_u8State);
u8 MGPIO_u8GetInputPortValue(u8 Copy_u8Port);
void MGPIO_voidLockPort(u8 Copy_u8Port);

#endif
