/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */


#include "HAL/KeyPad.h"
#include "HAL/lcd.h"
#include "util/delay.h"
int  main(void)
{
	uint8 num=0XFF ;
	LCD_init();
	KeyPad_init();


	while(1)
	{

		num=KeyPad_getPressedKey();


		if(num != 0xFF)
		{
			LCD_writeData(num);
		}
		//while(num != 0xFF);


	}




}
