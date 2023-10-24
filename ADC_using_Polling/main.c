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



uint16 result = 0;
char data[10];

int  main(void)
{
	ADC_init();
	LCD_init();
	ADC_selectChannel(ADC1);


	while(1)
	{
		ADC_startConversionPolling();
		result = ADC_read_channel();
		sprintf(data, "%d", result);
		LCD_goToRowColumn(0, 0);
		LCD_displayString(data);
	}

}


