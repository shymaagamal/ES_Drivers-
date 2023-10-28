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

uint32 g_tempVal = 0;
void readTempSensor(void);
int  main(void)
{
	GINT_Enable();
	ADC_init();
	ADC_selectChannel(ADC1);
	LCD_init();
	LCD_clearScreen();

	LCD_goToRowColumn(0, 0);
	LCD_displayString("Map Value :");


	EXTI_Enable(INT0, NULL, falling_edge);

	LED_setUpDirection(PORTB_ID, 3, PIN_OUTPUT);
	TIM0_init();
	TIM0_start();
	//TIM0_dutyCycle(g_tempVal);
	ADC_setCallBackFunction(readTempSensor);
while(1)
{
	TIM0_dutyCycle(g_tempVal);
	ADC_startConversion();
}
}

void readTempSensor(void)
{
	g_tempVal = ADC_readChannel();
	g_tempVal=(g_tempVal*100)/(1023);
	LCD_goToRowColumn(0, 12);
	LCD_intgerToString(g_tempVal);



}


