/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "HAL/lcd.h"
int  main(void)
{
	LCD_init();

	uint8 row=0;
	uint8 col=0;
	LCD_writeData('A');
	while(1)
	{

		LCD_goToRowColumn(2,2);
		LCD_writeData('A');
		LCD_goToRowColumn(2,3);
		LCD_writeData('A');
		LCD_goToRowColumn(2,4);
		LCD_writeData('A');
		LCD_goToRowColumn(2,5);
		LCD_writeData('A');
	}

}
