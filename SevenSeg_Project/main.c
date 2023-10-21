/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "HAL/sevenSeg.h"
int  main(void)
{


	sevenSeg_setPin_direction();
	sevenSeg_Display(0,DISPLAY_ON_SEG1);

	while(1)
	{
		for(uint8 i=0;i<=9;i++)
		{
			sevenSeg_Display(i,DISPLAY_ON_SEG1);
			_delay_ms(4000);
		}

		
	}
	return 0;
}
