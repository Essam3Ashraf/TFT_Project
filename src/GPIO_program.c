// Library Inclusion
# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"

// Lower Layer Inclusion

// Self Layer Inclusion

// Self Files Inclusion
# include "../include/GPIO_interface.h"
# include "../include/GPIO_private.h"
# include "../include/GPIO_config.h"


void MGPIO_voidSetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8Pin>=GPIO_PIN0 && Copy_u8Pin<=GPIO_PIN15 && (Copy_u8Mode==GPIO_INPUT || Copy_u8Mode==GPIO_OUTPUT || Copy_u8Mode==GPIO_ALT_FUNC|| Copy_u8Mode==GPIO_ANALOG))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       GPIOA_MODER &= ~ (GPIO_PIN_MODE_MASK << (Copy_u8Pin*PIN_OFFSET));
       GPIOA_MODER |= (Copy_u8Mode << (Copy_u8Pin*PIN_OFFSET));
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       GPIOB_MODER &= ~ (GPIO_PIN_MODE_MASK << (Copy_u8Pin*PIN_OFFSET));
       GPIOB_MODER |= (Copy_u8Mode << (Copy_u8Pin*PIN_OFFSET));
    }

    else if(Copy_u8Port == GPIO_PORTC && Copy_u8Pin>=GPIO_PIN13 && Copy_u8Pin<=GPIO_PIN15)
    {
       GPIOC_MODER &= ~ (GPIO_PIN_MODE_MASK << (Copy_u8Pin*PIN_OFFSET));
       GPIOC_MODER |= (Copy_u8Mode << (Copy_u8Pin*PIN_OFFSET));
    }    
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPinOutputMode(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8OutputMode)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8OutputPin>=GPIO_PIN0 && Copy_u8OutputPin<=GPIO_PIN15 && (Copy_u8OutputMode==GPIO_PUSH_PULL || Copy_u8OutputMode==GPIO_OPEN_DRAIN))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       CLR_BIT(GPIOA_OTYPER, Copy_u8OutputPin);
       GPIOA_OTYPER |= (Copy_u8OutputMode << Copy_u8OutputPin);
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       CLR_BIT(GPIOB_OTYPER, Copy_u8OutputPin);
       GPIOB_OTYPER |= (Copy_u8OutputMode << Copy_u8OutputPin);
    }
   
    else if(Copy_u8Port == GPIO_PORTC && Copy_u8OutputPin>=GPIO_PIN13 && Copy_u8OutputPin<=GPIO_PIN15)
    {
       CLR_BIT(GPIOC_OTYPER, Copy_u8OutputPin);
       GPIOC_OTYPER |= (Copy_u8OutputMode << Copy_u8OutputPin);
    }
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8Speed)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8OutputPin>=GPIO_PIN0 && Copy_u8OutputPin<=GPIO_PIN15 && (Copy_u8Speed==GPIO_LOW_SPEED || Copy_u8Speed==GPIO_MEDIUM_SPEED || Copy_u8Speed==GPIO_HIGH_SPEED || Copy_u8Speed==GPIO_VERY_HIGH_SPEED))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       GPIOA_OSPEEDR &= ~ (GPIO_PIN_OUTPUT_SPEED_MASK << (Copy_u8OutputPin*PIN_OFFSET));
       GPIOA_OSPEEDR |= (Copy_u8Speed << (Copy_u8OutputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       GPIOB_OSPEEDR &= ~ (GPIO_PIN_OUTPUT_SPEED_MASK << (Copy_u8OutputPin*PIN_OFFSET));
       GPIOB_OSPEEDR |= (Copy_u8Speed << (Copy_u8OutputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == GPIO_PORTC && Copy_u8OutputPin>=GPIO_PIN13 && Copy_u8OutputPin<=GPIO_PIN15)
    {
       GPIOC_OSPEEDR &= ~ (GPIO_PIN_OUTPUT_SPEED_MASK << (Copy_u8OutputPin*PIN_OFFSET));
       GPIOC_OSPEEDR |= (Copy_u8Speed << (Copy_u8OutputPin*PIN_OFFSET));
    }
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPinOutputValue(u8 Copy_u8Port, u8 Copy_u8OutputPin, u8 Copy_u8Value)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8OutputPin>=GPIO_PIN0 && Copy_u8OutputPin<=GPIO_PIN15 && (Copy_u8Value==GPIO_LOW || Copy_u8Value==GPIO_HIGH))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
      if(Copy_u8Value == GPIO_LOW)
      {
        GPIOA_BSRR = (ONE << (Copy_u8OutputPin + BIT16_LOCATION));
      }
      else
      {
        GPIOA_BSRR = (ONE << Copy_u8OutputPin);
      }
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
      if(Copy_u8Value == GPIO_LOW)
      {
        GPIOB_BSRR = (ONE << (Copy_u8OutputPin + BIT16_LOCATION));
      }
      else
      {
        GPIOB_BSRR = (ONE << Copy_u8OutputPin);
      }
    } 

    else if(Copy_u8Port == GPIO_PORTC && Copy_u8OutputPin>=GPIO_PIN13 && Copy_u8OutputPin<=GPIO_PIN15)
    {
      if(Copy_u8Value == GPIO_LOW)
      {
        GPIOC_BSRR = (ONE << (Copy_u8OutputPin + BIT16_LOCATION));
      }
      else
      {
        GPIOC_BSRR = (ONE << Copy_u8OutputPin);
      }
    }
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetInputPinState(u8 Copy_u8Port, u8 Copy_u8InputPin, u8 Copy_u8State)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8InputPin>=GPIO_PIN0 && Copy_u8InputPin<=GPIO_PIN15 && (Copy_u8State==GPIO_No_PULL_UP_PULL_DOWN || Copy_u8State==GPIO_PULL_UP || Copy_u8State==GPIO_PULL_DOWN))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       GPIOA_PUPDR &= ~ (GPIO_INPUT_PIN_STATE_MASK << (Copy_u8InputPin*PIN_OFFSET));
       GPIOA_PUPDR |= (Copy_u8State << (Copy_u8InputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       GPIOB_PUPDR &= ~ (GPIO_INPUT_PIN_STATE_MASK << (Copy_u8InputPin*PIN_OFFSET));
       GPIOB_PUPDR |= (Copy_u8State << (Copy_u8InputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == GPIO_PORTC && Copy_u8InputPin>=GPIO_PIN13 && Copy_u8InputPin<=GPIO_PIN15)
    {
       GPIOC_PUPDR &= ~ (GPIO_INPUT_PIN_STATE_MASK << (Copy_u8InputPin*PIN_OFFSET));
       GPIOC_PUPDR |= (Copy_u8State << (Copy_u8InputPin*PIN_OFFSET));
    }
  }

  else
  {
    // error    
  }
}


u8 MGPIO_u8GetInputPinValue(u8 Copy_u8Port, u8 Copy_u8InputPin)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8InputPin>=GPIO_PIN0 && Copy_u8InputPin<=GPIO_PIN15)
  {
    u8 LOC_u8PinValue;
    if(Copy_u8Port == GPIO_PORTA)
    {
       LOC_u8PinValue = GET_BIT(GPIOA_IDR, Copy_u8InputPin);
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       LOC_u8PinValue = GET_BIT(GPIOB_IDR, Copy_u8InputPin);
    }

    else if(Copy_u8Port == GPIO_PORTC && Copy_u8InputPin>=GPIO_PIN13 && Copy_u8InputPin<=GPIO_PIN15)
    {
       LOC_u8PinValue = GET_BIT(GPIOC_IDR, Copy_u8InputPin);
    }
    return LOC_u8PinValue;
  }

  else
  {
    // error
  }
}


void MGPIO_voidAltFuncPin(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8AltFunc)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8Pin>=GPIO_PIN0 && Copy_u8Pin<=GPIO_PIN15 && Copy_u8AltFunc>=GPIO_AF00 && Copy_u8AltFunc<=GPIO_AF15)
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
      if(Copy_u8Pin>=GPIO_PIN0 && Copy_u8Pin<=GPIO_PIN7)
      {
        GPIOA_AFRL &= ~(GPIO_ALT_FUNC_PIN_MASK << (Copy_u8Pin*ALT_FUNC_PIN_OFFSET));
        GPIOA_AFRL |= (Copy_u8AltFunc << (Copy_u8Pin*ALT_FUNC_PIN_OFFSET));
      }
      else
      {
        GPIOA_AFRH &= ~(GPIO_ALT_FUNC_PIN_MASK << ((Copy_u8Pin-GPIO_PIN8)*ALT_FUNC_PIN_OFFSET));
        GPIOA_AFRH |= (Copy_u8AltFunc << ((Copy_u8Pin-GPIO_PIN8)*ALT_FUNC_PIN_OFFSET));
      }
    } 
    else if(Copy_u8Port == GPIO_PORTB)
    {
      if(Copy_u8Pin>=GPIO_PIN0 && Copy_u8Pin<=GPIO_PIN7)
      {
        GPIOB_AFRL &= ~(GPIO_ALT_FUNC_PIN_MASK << (Copy_u8Pin*ALT_FUNC_PIN_OFFSET));
        GPIOB_AFRL |= (Copy_u8AltFunc << (Copy_u8Pin*ALT_FUNC_PIN_OFFSET));
      }
      else
      {
        GPIOB_AFRH &= ~(GPIO_ALT_FUNC_PIN_MASK << ((Copy_u8Pin-GPIO_PIN8)*ALT_FUNC_PIN_OFFSET));
        GPIOB_AFRH |= (Copy_u8AltFunc << ((Copy_u8Pin-GPIO_PIN8)*ALT_FUNC_PIN_OFFSET));
      }
    } 
    else if(Copy_u8Port == GPIO_PORTC && Copy_u8Pin>=GPIO_PIN13 && Copy_u8Pin<=GPIO_PIN15)
    {
        GPIOC_AFRH &= ~(GPIO_ALT_FUNC_PIN_MASK << ((Copy_u8Pin-GPIO_PIN8)*ALT_FUNC_PIN_OFFSET));
        GPIOC_AFRH |= (Copy_u8AltFunc << ((Copy_u8Pin-GPIO_PIN8)*ALT_FUNC_PIN_OFFSET));
    }
  }
  else
  {
    // error    
  }
}


void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8Pin>=GPIO_PIN0 && Copy_u8Pin<=GPIO_PIN15)
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       GPIOA_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));
       GPIOA_LCKR &= (ONE << Copy_u8Pin);
       GPIOA_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));
    } 

    else if(Copy_u8Port == GPIO_PORTB)
    {
       GPIOB_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));
       GPIOB_LCKR &= (ONE << Copy_u8Pin);
       GPIOB_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));      
    }

    else if(Copy_u8Port == GPIO_PORTC && Copy_u8Pin>=GPIO_PIN13 && Copy_u8Pin<=GPIO_PIN15)
    {
       GPIOC_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));
       GPIOC_LCKR &= (ONE << Copy_u8Pin);
       GPIOC_LCKR |= ((ONE << BIT16_LOCATION) + (ONE << Copy_u8Pin));   
    }
  }

  else
  {
    // error    
  }
}


void MGPIO_voidSetPortMode(u8 Copy_u8Port, u8 Copy_u8Mode)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && (Copy_u8Mode==GPIO_INPUT || Copy_u8Mode==GPIO_OUTPUT || Copy_u8Mode==GPIO_ALT_FUNC || Copy_u8Mode==GPIO_ANALOG))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       if(Copy_u8Mode == GPIO_INPUT) {GPIOA_MODER &= GPIO_INPUT_MODE;}
       else if(Copy_u8Mode == GPIO_OUTPUT) {GPIOA_MODER &= ZERO; GPIOA_MODER |= GPIO_OUTPUT_MODE;}
       else if(Copy_u8Mode == GPIO_ALT_FUNC) {GPIOA_MODER &= ZERO; GPIOA_MODER |= GPIO_ALT_FUNC_MODE;}
       else {GPIOA_MODER |= GPIO_ANALOG_MODE;}
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       if(Copy_u8Mode == GPIO_INPUT) {GPIOB_MODER &= GPIO_INPUT_MODE;}
       else if(Copy_u8Mode == GPIO_OUTPUT) {GPIOB_MODER &= ZERO; GPIOB_MODER |= GPIO_OUTPUT_MODE;}
       else if(Copy_u8Mode == GPIO_ALT_FUNC) {GPIOB_MODER &= ZERO; GPIOB_MODER |= GPIO_ALT_FUNC_MODE;}
       else {GPIOB_MODER |= GPIO_ANALOG_MODE;}
    }

    else
    {
       if(Copy_u8Mode == GPIO_INPUT) {GPIOC_MODER &= GPIO_INPUT_MODE;}
       else if(Copy_u8Mode == GPIO_OUTPUT) {GPIOC_MODER &= ZERO; GPIOC_MODER |= GPIO_OUTPUT_MODE;}
       else if(Copy_u8Mode == GPIO_ALT_FUNC) {GPIOC_MODER &= ZERO; GPIOC_MODER |= GPIO_ALT_FUNC_MODE;}
       else {GPIOC_MODER |= GPIO_ANALOG_MODE;}
    }    
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPortOutputMode(u8 Copy_u8Port, u8 Copy_u8OutputMode)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && (Copy_u8OutputMode==GPIO_PUSH_PULL || Copy_u8OutputMode==GPIO_OPEN_DRAIN))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       if(Copy_u8OutputMode == GPIO_PUSH_PULL) { GPIOA_OTYPER &= GPIO_PUSH_PULL_MODE;}
       else {GPIOA_OTYPER |= GPIO_OPEN_DRAIN_MODE;}
    } 

    else if(Copy_u8Port == GPIO_PORTB)
    {
       if(Copy_u8OutputMode == GPIO_PUSH_PULL) { GPIOB_OTYPER &= GPIO_PUSH_PULL_MODE;}
       else {GPIOB_OTYPER |= GPIO_OPEN_DRAIN_MODE;}     
    }

    else
    {
       if(Copy_u8OutputMode == GPIO_PUSH_PULL) { GPIOC_OTYPER &= GPIO_PUSH_PULL_MODE;}
       else {GPIOC_OTYPER |= GPIO_OPEN_DRAIN_MODE;}     
    }
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPortOutputSpeed(u8 Copy_u8Port, u8 Copy_u8Speed)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && (Copy_u8Speed==GPIO_LOW_SPEED || Copy_u8Speed==GPIO_MEDIUM_SPEED || Copy_u8Speed==GPIO_HIGH_SPEED || Copy_u8Speed==GPIO_VERY_HIGH_SPEED))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       if(Copy_u8Speed == GPIO_LOW_SPEED) {GPIOA_OSPEEDR &= GPIO_LOW_SPD;}
       else if(Copy_u8Speed == GPIO_MEDIUM_SPEED) {GPIOA_OSPEEDR &= ZERO; GPIOA_OSPEEDR |= GPIO_MEDIUM_SPD;}
       else if(Copy_u8Speed == GPIO_HIGH_SPEED) {GPIOA_OSPEEDR &= ZERO; GPIOA_OSPEEDR |= GPIO_HIGH_SPD;}
       else {GPIOA_OSPEEDR |= GPIO_VERY_HIGH_SPD;}
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       if(Copy_u8Speed == GPIO_LOW_SPEED) {GPIOB_OSPEEDR &= GPIO_LOW_SPD;}
       else if(Copy_u8Speed == GPIO_MEDIUM_SPEED) {GPIOB_OSPEEDR &= ZERO; GPIOB_OSPEEDR |= GPIO_MEDIUM_SPD;}
       else if(Copy_u8Speed == GPIO_HIGH_SPEED) {GPIOB_OSPEEDR &= ZERO; GPIOB_OSPEEDR |= GPIO_HIGH_SPD;}
       else {GPIOB_OSPEEDR |= GPIO_VERY_HIGH_SPD;}
    }

    else
    {
       if(Copy_u8Speed == GPIO_LOW_SPEED) {GPIOC_OSPEEDR &= GPIO_LOW_SPD;}
       else if(Copy_u8Speed == GPIO_MEDIUM_SPEED) {GPIOC_OSPEEDR &= ZERO; GPIOC_OSPEEDR |= GPIO_MEDIUM_SPD;}
       else if(Copy_u8Speed == GPIO_HIGH_SPEED) {GPIOC_OSPEEDR &= ZERO; GPIOC_OSPEEDR |= GPIO_HIGH_SPD;}
       else {GPIOC_OSPEEDR |= GPIO_VERY_HIGH_SPD;}
    }   
  }

  else
  {
    // error
  }
}


void MGPIO_voidSetPortOutputValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && (Copy_u8Value==GPIO_LOW || Copy_u8Value==GPIO_HIGH))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
      if(Copy_u8Value == GPIO_LOW) {GPIOA_ODR &= GPIO_LOW_VALUE;}
      else {GPIOA_ODR |= GPIO_HIGH_VALUE;}
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
      if(Copy_u8Value == GPIO_LOW) {GPIOB_ODR &= GPIO_LOW_VALUE;}
      else {GPIOB_ODR |= GPIO_HIGH_VALUE;}
    }

    else
    {
      if(Copy_u8Value == GPIO_LOW) {GPIOC_ODR &= GPIO_LOW_VALUE;}
      else {GPIOC_ODR |= GPIO_HIGH_VALUE;}
    }
  }

  else
  {
    // error
  }
}  


void MGPIO_voidSetInputPortState(u8 Copy_u8Port, u8 Copy_u8State)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && (Copy_u8State==GPIO_No_PULL_UP_PULL_DOWN || Copy_u8State==GPIO_PULL_UP || Copy_u8State==GPIO_PULL_DOWN))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       if(Copy_u8State == GPIO_No_PULL_UP_PULL_DOWN) {GPIOA_PUPDR &= GPIO_No_PULL_UP_PULL_DOWN_STATE;}
       else if(Copy_u8State == GPIO_PULL_UP) {GPIOA_PUPDR &= ZERO; GPIOA_PUPDR |= GPIO_PULL_UP_STATE;}
       else {GPIOA_PUPDR &= ZERO; GPIOA_PUPDR |= GPIO_PULL_DOWN_STATE;}
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       if(Copy_u8State == GPIO_No_PULL_UP_PULL_DOWN) {GPIOB_PUPDR &= GPIO_No_PULL_UP_PULL_DOWN_STATE;}
       else if(Copy_u8State == GPIO_PULL_UP) {GPIOB_PUPDR &= ZERO; GPIOB_PUPDR |= GPIO_PULL_UP_STATE;}
       else {GPIOB_PUPDR &= ZERO; GPIOB_PUPDR |= GPIO_PULL_DOWN_STATE;}
    }

    else
    {
       if(Copy_u8State == GPIO_No_PULL_UP_PULL_DOWN) {GPIOC_PUPDR &= GPIO_No_PULL_UP_PULL_DOWN_STATE;}
       else if(Copy_u8State == GPIO_PULL_UP) {GPIOC_PUPDR &= ZERO; GPIOC_PUPDR |= GPIO_PULL_UP_STATE;}
       else {GPIOC_PUPDR &= ZERO; GPIOC_PUPDR |= GPIO_PULL_DOWN_STATE;}
    }
  }

  else
  {
    // error    
  }
}


u8 MGPIO_u8GetInputPortValue(u8 Copy_u8Port)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC)
  {
     u8 LOC_u8Flag = GPIO_LOW;
     volatile u16 LOC_u16GpioIdrValue;

    if(Copy_u8Port == GPIO_PORTA) 
    {
      LOC_u16GpioIdrValue = GPIOA_IDR;
      if(LOC_u16GpioIdrValue==GPIO_HIGH_VALUE) {LOC_u8Flag = GPIO_HIGH;}
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
      LOC_u16GpioIdrValue = GPIOB_IDR;
      if(LOC_u16GpioIdrValue==GPIO_HIGH_VALUE) {LOC_u8Flag = GPIO_HIGH;}
    }

    else
    {
      LOC_u16GpioIdrValue = GPIOC_IDR;
      if(LOC_u16GpioIdrValue==GPIO_HIGH_VALUE) {LOC_u8Flag = GPIO_HIGH;}
    }

    return LOC_u8Flag;
  }

  else
  {
    // error
  }
}


void MGPIO_voidLockPort(u8 Copy_u8Port)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC)
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       GPIOA_LCKR |= ((ONE << BIT16_LOCATION) + GPIO_HIGH_VALUE);
       GPIOA_LCKR &= GPIO_HIGH_VALUE;
       GPIOA_LCKR |= ((ONE << BIT16_LOCATION) + GPIO_HIGH_VALUE);
    } 

    else if(Copy_u8Port == GPIO_PORTB)
    {
       GPIOB_LCKR |= ((ONE << BIT16_LOCATION) + GPIO_HIGH_VALUE);
       GPIOB_LCKR &= GPIO_HIGH_VALUE;
       GPIOB_LCKR |= ((ONE << BIT16_LOCATION) + GPIO_HIGH_VALUE);      
    }

    else
    {
       GPIOC_LCKR |= ((ONE << BIT16_LOCATION) + GPIO_HIGH_VALUE);
       GPIOC_LCKR &= GPIO_HIGH_VALUE;
       GPIOC_LCKR |= ((ONE << BIT16_LOCATION) + GPIO_HIGH_VALUE);   
    }
  }

  else
  {
    // error    
  }
}
