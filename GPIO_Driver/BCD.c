/*
 * BCD.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */
#include "std_types.h"
uint8 BCD_Decoder(uint8 num)
{
	uint8 val=0x00;
	switch(num)
	{
		case 0:
		  val=0x3F;
		  break;
		case 1:
		  val=0x06;
		  break;
		case 2:
		  val=0x5B;
		  break;
		case 3:
			val=0x4F;
		  break;
		case 4:
			val=0x66;
		  break;
		case 5:
			val=0x3F;
		  break;
		case 6:
			val=0x6D;
		  break;
		case 7:
			val=0x07;
		  break;
		case 8:
			val=0x7F;
		  break;
		case 9:
			val=0x6F;
		  break;

	}
	return val;

}
