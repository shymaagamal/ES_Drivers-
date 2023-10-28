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

	LED_setUpDirection(PORTB_ID, 3, PIN_OUTPUT);
	TIM0_init();
	TIM0_start();
	TIM0_dutyCycle(10);
while(1)
{


}
}




