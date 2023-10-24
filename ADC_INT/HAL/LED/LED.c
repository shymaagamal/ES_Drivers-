/*
 * Application.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */

#include "LED.h"

void setup_LED_Direction(void)
{
	GPIO_SetupPin_Direction(PORTB_ID,LED_RED_PIN, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTA_ID,LED_GREEN_PIN, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTA_ID,LED_BLUE_PIN, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTA_ID,LED_YELLOW_PIN, PIN_OUTPUT);

}

void LED_ON(uint8 port_id,uint8 pin_num)
{
	GPIO_SetupPin_Value(port_id,pin_num,LOGIC_HIGH);
}
void LED_OFF(uint8 port_id,uint8 pin_num)
{
	GPIO_SetupPin_Value(port_id,pin_num,LOGIC_LOW);
}

