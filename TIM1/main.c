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
#include "MCAL/Timer1/Timer1_interface.h"
//#include"MCAL/Timer0/Timer0_interface.h"

#undef F_CPU
#define F_CPU 16000000U


int  main(void)
{
	TIM1_init();
	TIM1_setICR(5000);
	GPIO_SetupPin_Direction(PORTD_ID,5, PIN_OUTPUT);
	TIM1_start();
	//TIM1_setPreload(0);

	uint16 angle=0;
	while(1)
	{

			TIM1_dutyCycle_OCRA(1500);
			_delay_ms(1000);



	}
}



