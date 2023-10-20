/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include <util/delay.h>
#include "Application.h"
int  main(void)
{
	sevenSeg_setPin_direction();
	sevenSeg_Display(0);
	while(1)
	{
		for(uint8 i=0;i<=9 ;i++)
		{
			sevenSeg_Display(i);
			_delay_ms(10000);
		}
	}
	return 0;
}
