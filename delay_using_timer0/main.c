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


int  main(void)
{

	LED_setUpDirection(PORTB_ID, 7, PIN_OUTPUT);
	LED_OFF(PORTB_ID, 7);
	TIM0_start();

while(1)
{
	delay_ms(500);
	LED_Toggle(PORTB_ID,7);

}
}




