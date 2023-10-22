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
    LCD_writeData('D');
    while(1)
	{
		LCD_goToRowColumn(2,2);
		LCD_writeData('A');
		LCD_goToRowColumn(2,3);
		LCD_writeData('A');
		LCD_goToRowColumn(2,4);
		LCD_writeData('A');
		LCD_goToRowColumn(1,5);
		LCD_writeData('A');
	}


}
