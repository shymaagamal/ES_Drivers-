/***************************************************************************************************/
/*                                       GPIO_Private.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: Defining Registers
 ***************************************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
#include "std_types.h"


#define PORTA_      *(volatile uint8 * 0x3B)
#define DDRA_	   *(volatile uint8 * 0x3A)          /*Registers in PORTA IN MCU*/
#define PINA_	   *(volatile uint8 * 0x39)

#define PORTB_      *((volatile uint8 *) 0x38)
#define DDRB_	   *((volatile uint8 *) 0x37)		/*Registers in PORTB IN MCU*/
#define PINB_       *((volatile uint8 *) 0x36)

#define PORTC_       *((volatile uint8 *) 0x35)
#define DDRC_		*((volatile uint8 *) 0x34)		/*Registers in PORTC IN MCU*/
#define PINC_		*((volatile uint8 *) 0x33)

#define PORTD_       *((volatile uint8 *) 0x32)
#define DDRD_		*((volatile uint8 *) 0x31)		/*Registers in PORTD IN MCU*/
#define PIND_		*((volatile uint8 *) 0x30)
#endif /* GPIO_PRIVATE_H_ */
