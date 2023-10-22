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
	sevenSeg_Display(0,DISPLAY_ON_SEG2);
    sint8 countseg1=0;
	sint8 countseg2=0;
	while(1)
	{

		if(countseg1==9 && countseg2<9)
		{
			countseg2++;
			countseg1=0;
		}
		else if(countseg2 >=9)
		{
			countseg2=0;
			countseg1=0;
		}

		sevenSeg_Display(countseg1,DISPLAY_ON_SEG1);
		_delay_ms(2);
		sevenSeg_Display(countseg2,DISPLAY_ON_SEG2);
		countseg1++;
		_delay_ms(200);


	}
	return 0;
}
