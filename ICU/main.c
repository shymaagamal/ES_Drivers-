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
#include"MCAL/Timer0/Timer0_interface.h"
#include "HAL/KeyPad/KeyPad.h"
#include "MCAL/SPI/SPI_interface.h"
#include"MCAL/UART/USART_interface.h"

volatile uint8 g_count=1;
volatile uint16 T_period;
volatile uint32 T_ON;

void EXT_calculateTime();
int  main(void)
{
	LCD_init();

	TIM0_init();
	TIM0_start();
	TIM0_dutyCycle(50);

	TIM1_init();
	TIM1_start();


	GPIO_SetupPin_Direction(PORTB_ID, 3, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTD_ID, 6, PIN_INPUT);

	EXTI_Enable(INT0, EXT_calculateTime, rising_edge);

	GINT_Enable();


	while(1)
	{




	}
}

void EXT_calculateTime()
{


	if(g_count==1)
	{
		TIM1_setPreload(0);
		EXTI_initINT0(rising_edge);
		g_count=2;
	}
	else if(g_count==2)
	{

		TIM1_setPreload(0);
		EXTI_initINT0(falling_edge);
		g_count=3;
	}
	else if(g_count==3)
	{
		T_ON= TIM1_getVal();

		LCD_goToRowColumn(1, 0);
		LCD_displayString("TON is :");
		LCD_goToRowColumn(1, 12);
		LCD_intgerToString(T_ON);
		EXTI_initINT0(rising_edge);
		TIM1_setPreload(0);
		g_count=4;
	}
	else if(g_count==4)
	{
		T_period = TIM1_getVal();


		LCD_goToRowColumn(2, 0);
		LCD_displayString("TOFF is :");
		LCD_goToRowColumn(2, 12);
		LCD_intgerToString(T_period);
		TIM1_setPreload(0);
		g_count=0;
	}
}
