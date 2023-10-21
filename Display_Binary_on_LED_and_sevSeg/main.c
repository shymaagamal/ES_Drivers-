/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "HAL/LED.h"
#include "HAL/sevenSeg.h"
int  main(void)
{
	setup_LED_Direction();
	sevenSeg_setPin_direction();
	sevenSeg_Display(0,DISPLAY_ON_SEG1);

	while(1)
	{
		for(uint8 i=0;i<=9;i++ )
		{
			sevenSeg_Display(i,DISPLAY_ON_SEG1);

			LED(PORTA_ID,PA4,GET_BIT(i,0));
			LED(PORTA_ID,PA5,GET_BIT(i,1));
			LED(PORTA_ID,PA6,GET_BIT(i,2));
			LED(PORTB_ID,PB7,GET_BIT(i,3));
			_delay_ms(1000);


		}
	}
	return 0;
}
