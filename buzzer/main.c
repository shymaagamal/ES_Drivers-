/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */


#include <stdio.h>
#include "MCAL/GINT/GINT_config.h"
#include "HAL/LCD/lcd.h"
#include "HAL/LED/LED.h"
#include "MCAL/EXTI/EXTI_config.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/Timer0/Timer_interface.h"
#include "HAL/KeyPad/KeyPad.h"
uint32 g_tempVal = 0;
int  main(void)
{
	KeyPad_init();
	GPIO_SetupPin_Direction(PORTC_ID, 6, PIN_OUTPUT);
	GPIO_SetupPin_Value(PORTC_ID, 6, LOGIC_HIGH);
	LCD_init();
	LCD_displayString("shymaa");
	TIM0_init();
	TIM0_start();
	uint8 key;

while(1)
{
	key=KeyPad_getPressedKey();



	if(key!=0xff)
	{
		TIM0_dutyCycle((key*10));

	}
}
}



