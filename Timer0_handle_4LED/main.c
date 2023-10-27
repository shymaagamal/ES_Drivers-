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
uint8 count=0;
void toggle_led(void);

int  main(void)
{
	GINT_Enable();
	TIM0_init();

	TIM0_start();
	TIM0_setPreload(195);


	LED_setUpDirection(PORTB_ID, 7, PIN_OUTPUT);
	LED_OFF(PORTB_ID, 7);

	LED_setUpDirection(PORTB_ID, 6, PIN_OUTPUT);
	LED_OFF(PORTB_ID, 6);

	LED_setUpDirection(PORTB_ID, 5, PIN_OUTPUT);
	LED_OFF(PORTB_ID, 5);

	LED_setUpDirection(PORTA_ID, 7, PIN_OUTPUT);
	LED_OFF(PORTA_ID, 7);

	TIM0_EnableOVFInterrupt(toggle_led);
	while(1)
	{

	}

}


void toggle_led(void)
{

	LED_Toggle(PORTB_ID, 7);
	if(count%3==0)
	{

		LED_Toggle(PORTB_ID, 6);

	}
	else if(count%5==0)
	{
		LED_Toggle(PORTB_ID, 5);
		//LED_Toggle(PORTA_ID, 7);
	}

	count++;

}

