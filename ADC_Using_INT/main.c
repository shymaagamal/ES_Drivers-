/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */


#include <stdio.h>
#include "MCAL/ADC/ADC_config.h"
#include "MCAL/GINT/GINT_config.h"
#include "MCAL/EXTI/EXTI_config.h"
#include "HAL/LCD/lcd.h"

volatile uint8 flag=0;
uint16 result = 0;
char data[10];


void system_init()
{
	flag=1;
	LCD_writeData('t');
}


void ADC_INT(void)
{
	LCD_writeData('k');
	result = ADC_read_channel();
	sprintf(data, "%d", result);
	LCD_goToRowColumn(0, 0);
	LCD_displayString(data);

}


int  main(void)
{

	ADC_init();
	LCD_init();
	ADC_selectChannel(ADC1);
	GINT_Enable();
	EXTI_Enable(INT1,system_init,falling_edge);

	while(1)
	{
		ADC_setCallBack(ADC_INT);
		if(flag==1)
		{
			ADC_startConversionINT();
			flag=0;
		}

	}

}


