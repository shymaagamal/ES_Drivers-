/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "HAL/LED.h"
int  main(void)
{
	setup_LED_Direction();



	while(1)
	{


		LED_ON(PORTB_ID,PB7);
		_delay_ms(1000);
		LED_OFF(PORTB_ID,PB7);
		_delay_ms(1000);

		LED_ON(PORTA_ID,PA4);
		_delay_ms(1000);
		LED_OFF(PORTA_ID,PA4);
		_delay_ms(1000);

		LED_ON(PORTA_ID,PA5);
		_delay_ms(1000);
		LED_OFF(PORTA_ID,PA5);
		_delay_ms(1000);

		LED_ON(PORTA_ID,PA6);
		_delay_ms(1000);
		LED_OFF(PORTA_ID,PA6);
		_delay_ms(1000);
	}
	return 0;
}
