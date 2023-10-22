/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */


#include "HAL/KeyPad.h"
#include "HAL/lcd.h"
int  main(void)
{
	uint8 num=0XFF ;
	LCD_init();
	KeyPad_init();

	LCD_writeData('S');
	while(1)
	{

		 num=KeyPad_getPressedKey();
		LCD_writeData(num);
	}




}
