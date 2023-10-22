/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "HAL/lcd.h"
#include "util/delay.h"

int  main(void)
{


	LCD_init();
	uint8 flagrow=1;
	uint8 row=0;
	uint8 col=0;
    while(1)
	{





		uint8 row = 3, col = 0;
		uint8 rising = 1, falling = 0;
		while(col < 20)
		{

			LCD_goToRowColumn(row,col);
			LCD_writeData('0');
			_delay_ms(10);

			LCD_writeCommand(0x01);
			LCD_writeCommand(0x10);
			col++;

			if(rising)
			{
				row--;
			}
			if(falling)
			{
				row++;
			}

			if(row < 0)
			{
				rising = 0;
				falling = 1;
				row = 1;
			}

			if(row > 3)
			{
				rising = 1;
				falling = 0;
				row = 2;
			}
		}
	}



}
