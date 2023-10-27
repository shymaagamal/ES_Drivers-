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
#include "MCAL/Timer/Timer_interface.h"

#define NUM_OF_OVF     63

void toggle_led(void);
uint8 count=0;
int  main(void)
{
	GINT_Enable();
	TIM0_init();

	TIM0_start();



	LED_setUpDirection(PORTB_ID, 7, PIN_OUTPUT);
	LED_OFF(PORTB_ID, 7);
	TIM0_EnableOVFInterrupt(toggle_led);
	while(1)
	{

	}

}


void toggle_led(void)
{
	count++;
	if(count==NUM_OF_OVF)
	{

		LED_Toggle(PORTB_ID, 7);
		count=0;

	}
}

