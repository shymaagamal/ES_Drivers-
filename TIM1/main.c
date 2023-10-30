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

uint16 mapAngle(uint16 angle) {
    uint16 pulseWidth = (angle * (1750/180) + 750) * 2;
    return pulseWidth;
}

int  main(void)
{
	TIM1_init();
	TIM1_setICR(40000);
	GPIO_SetupPin_Direction(PORTD_ID,5, PIN_OUTPUT);
	TIM1_dutyCycle_OCRA(1000);
	TIM1_start();
//	TIM1_setPreload(0);


	while(1)
	{
		//for(uint8 i = 0; i <= 180; i += 10)

			//_delay_ms(100);

	}
}



