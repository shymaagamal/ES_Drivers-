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

	}

}
