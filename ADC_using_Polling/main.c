/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */


#include <stdio.h>
#include "MCAL/ADC/ADC_config.h"
#include "MCAL/GINT/GINT_config.h"
#include "HAL/LCD/lcd.h"
#include "HAL/LED/LED.h"

#include "MCAL/ADC/ADC_interface.h"

uint16 result = 0;
char data[10];
uint32 temp;
void ADC()
{
	result = ADC_read_channel();
	temp=((uint32)result*150*5)/(1023*1.5);

	LCD_writeData('d');

}
int  main(void)
{
	LCD_init();
	ADC_init();
	GINT_Enable();
	ADC_selectChannel(ADC1);
	ADC_setCallBack(ADC);

	while(1)
	{

	}

}


