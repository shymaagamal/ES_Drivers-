/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "HAL/sevenSeg.h"
#include "HAL/LED.h"
int  main(void)
{


	setup_LED_Direction();
	sevenSeg_setPin_direction();
	sevenSeg_Display(0,DISPLAY_ON_SEG1);
	while(1)
	{
	   LED_ON(PORTB_ID,PB7);
	   for(uint8 i=0;i<=9;i++)
	   {
		   sevenSeg_Display(i,DISPLAY_ON_SEG1);
		   _delay_ms(300);
	   }
	   LED_OFF(PORTB_ID,PB7);

	   LED_ON(PORTA_ID,PA4);
	   for(uint8 i=0;i<=9;i++)
	   {
		   sevenSeg_Display(i,DISPLAY_ON_SEG1);
		   _delay_ms(300);
	   }
	   LED_OFF(PORTA_ID,PA4);


	   LED_ON(PORTA_ID,PA6);
	   for(uint8 i=0;i<=9;i++)
	   {
		   sevenSeg_Display(i,DISPLAY_ON_SEG1);
		   _delay_ms(300);
	   }
	   LED_OFF(PORTA_ID,PA6);




	}
}
