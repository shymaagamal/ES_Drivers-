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
#include "MCAL/TIM1/TIM1_interface.h"
#include "HAL/SERVO/SERVO_interface.h"
#include "MCAL/TIM1/TIM_registers.h"

//#include"MCAL/Timer0/Timer0_interface.h"

#undef F_CPU
#define F_CPU 16000000U



/** ========================== User-defined Macros ========================== */
int main(void)
{
	HAL_SERVO_Init();
	while(1)
	{
		for(uint16 i=1500; i<=5000; i += 100)
		{
			HAL_SERVO_SetAngle(i);
			_delay_ms(1000);
		}

	}
}

