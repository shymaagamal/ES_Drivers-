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
#include "MCAL/Timer0/Timer_registers.h"

uint8 step=0;
void control_Intensity(void);
int  main(void)
{
	GINT_Enable();
	LCD_init();
	LCD_clearScreen();


	TIM0_init();
	TIM0_start();

	LED_setUpDirection(PORTB_ID, 3, PIN_OUTPUT);
	EXTI_Enable(INT0, control_Intensity, falling_edge);


while(1)
{



}
}

void control_Intensity(void)
{

	step+=5;
	if(step>100)
	{
		step=0;
	}
	LCD_goToRowColumn(0, 0);
	LCD_intgerToString(step);
	OCR0_REG=step;


}


