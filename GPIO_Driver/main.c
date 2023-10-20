/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "Application.h"
int  main(void)
{
	setup_LED_Direction();

	sevenSeg_setPin_direction();
	sevenSeg_Display(0,DISPLAY_ON_SEG1);

	while(1)
	{
		for(uint8 i=0;i<=9 ;i++)
		{
			sevenSeg_Display(i,DISPLAY_ON_SEG1);
			_delay_ms(1000);
		}


		LED_ON(PORTB,PB7);
		_delay_ms(1000);
		LED_OFF(PORTB,PB7);

		LED_ON(PORTA,PA4);
		_delay_ms(1000);
		LED_OFF(PORTA,PA4);

		LED_ON(PORTA,PA5);
		_delay_ms(1000);
		LED_OFF(PORTA,PA5);

		LED_ON(PORTA,PA6);
		_delay_ms(1000);
		LED_OFF(PORTA,PA6);

	}
	return 0;
}
