/*
 * Application.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */
#include "../MCAL/GPIO/GPIO_Config.h"
#include "LED.h"

void setup_LED_Direction(void)
{
	GPIO_SetupPin_Direction(PORTB_ID,PB7, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTA_ID,PA4, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTA_ID,PA5, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTA_ID,PA6, PIN_OUTPUT);

}

void LED_ON(uint8 port_id,uint8 pin_num)
{
	GPIO_SetupPin_Value(port_id,pin_num,LOGIC_HIGH);
}
void LED_OFF(uint8 port_id,uint8 pin_num)
{
	GPIO_SetupPin_Value(port_id,pin_num,LOGIC_LOW);
}

void LED(uint8 port_id,uint8 pin_num,uint8 Logic)
{
	GPIO_SetupPin_Value(port_id,pin_num,Logic);
}
