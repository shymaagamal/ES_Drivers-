/*
 * Application.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */
#include "sevenSeg.h"





void sevenSeg_setPin_direction(void)
{
	/*There are 4 7seg  ,all of them connected to PB0,PB1,PB2,PB4 */
	/*They are connected as common Anode*/

	GPIO_SetupPin_Direction(PORTB_ID,PB5, PIN_OUTPUT); /*  7seg 2  connected */
	GPIO_SetupPin_Direction(PORTB_ID,PB6, PIN_OUTPUT); /*  7seg 1  connected */
	GPIO_SetupPin_Direction(PORTA_ID,PA2, PIN_OUTPUT); /*  7seg 3  connected */
	GPIO_SetupPin_Direction(PORTA_ID,PA3, PIN_OUTPUT); /*  7seg 4  connected */


	GPIO_SetupPin_Direction(PORTB_ID,PB0, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTB_ID,PB1, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTB_ID,PB2, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTB_ID,PB4, PIN_OUTPUT);

}

void sevenSeg_DisplayNum(uint8 sevenSeg_for_display_num)
{
	switch(sevenSeg_for_display_num)
	{
	case 1:
		GPIO_SetupPin_Value(PORTB_ID,PB6,LOGIC_LOW);
		GPIO_SetupPin_Value(PORTB_ID,PB5,LOGIC_HIGH);
		GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_HIGH);
		GPIO_SetupPin_Value(PORTA_ID,PA3,LOGIC_HIGH);
		break;
	case 2:
		GPIO_SetupPin_Value(PORTB_ID,PB6,LOGIC_HIGH);
		GPIO_SetupPin_Value(PORTB_ID,PB5,LOGIC_LOW);
		GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_HIGH);
		GPIO_SetupPin_Value(PORTA_ID,PA3,LOGIC_HIGH);
		break;
	case 3:
		GPIO_SetupPin_Value(PORTB_ID,PB6,LOGIC_HIGH);
		GPIO_SetupPin_Value(PORTB_ID,PB5,LOGIC_HIGH);
		GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_LOW);
		GPIO_SetupPin_Value(PORTA_ID,PA3,LOGIC_HIGH);
		break;
	case 4:
		GPIO_SetupPin_Value(PORTB_ID,PB6,LOGIC_HIGH);
		GPIO_SetupPin_Value(PORTB_ID,PB5,LOGIC_HIGH);
		GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_HIGH);
		GPIO_SetupPin_Value(PORTA_ID,PA3,LOGIC_LOW);
		break;
	}


}
/*Connection of SevenSegment is PB0,PB1,PB2,PB4*/
void sevenSeg_Display(uint8 num ,uint8 sevenSeg_for_display_num)
{
	sevenSeg_DisplayNum(sevenSeg_for_display_num );
	switch(num)
	{
	case 0:
		GPIO_SetupPin_Value(PORTB_ID,0,LOGIC_LOW);  /*Set PB0*/
		GPIO_SetupPin_Value(PORTB_ID,1,LOGIC_LOW);  /* PB1 Low*/
		GPIO_SetupPin_Value(PORTB_ID,2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB_ID,4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 1:
		GPIO_SetupPin_Value(PORTB_ID,0,LOGIC_HIGH);  /*Set PB0*/
		GPIO_SetupPin_Value(PORTB_ID,1,LOGIC_LOW);  /* PB1 Low*/
		GPIO_SetupPin_Value(PORTB_ID,2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB_ID,4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 2:
		GPIO_SetupPin_Value(PORTB_ID,PB0,LOGIC_LOW);  /* PB0 low*/
		GPIO_SetupPin_Value(PORTB_ID,PB1,LOGIC_HIGH);  /* PB1 high*/
		GPIO_SetupPin_Value(PORTB_ID,PB2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB_ID,PB4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 3:
		GPIO_SetupPin_Value(PORTB_ID,PB0,LOGIC_HIGH);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB_ID,PB1,LOGIC_HIGH);  /* PB1 high*/
		GPIO_SetupPin_Value(PORTB_ID,PB2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB_ID,PB4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 4:
		GPIO_SetupPin_Value(PORTB_ID,PB0,LOGIC_LOW);  /* PB0 LOW*/
		GPIO_SetupPin_Value(PORTB_ID,PB1,LOGIC_LOW);  /* PB1 LOW*/
		GPIO_SetupPin_Value(PORTB_ID,PB2,LOGIC_HIGH);  /*PB2  high*/
		GPIO_SetupPin_Value(PORTB_ID,PB4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 5:
		GPIO_SetupPin_Value(PORTB_ID,PB0,LOGIC_HIGH);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB_ID,PB1,LOGIC_LOW);  /* PB1 high*/
		GPIO_SetupPin_Value(PORTB_ID,PB2,LOGIC_HIGH);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB_ID,PB4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 6:
		GPIO_SetupPin_Value(PORTB_ID,0,LOGIC_LOW);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB_ID,1,LOGIC_HIGH);  /* PB1 LOW*/
		GPIO_SetupPin_Value(PORTB_ID,2,LOGIC_HIGH);  /*PB2  HIGH*/
		GPIO_SetupPin_Value(PORTB_ID,4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 7:
		GPIO_SetupPin_Value(PORTB_ID,0,LOGIC_HIGH);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB_ID,1,LOGIC_HIGH);  /* PB1 high*/
		GPIO_SetupPin_Value(PORTB_ID,2,LOGIC_HIGH);  /*PB2  high*/
		GPIO_SetupPin_Value(PORTB_ID,4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 8:
		GPIO_SetupPin_Value(PORTB_ID,0,LOGIC_LOW);  /* PB0 LOW*/
		GPIO_SetupPin_Value(PORTB_ID,1,LOGIC_LOW);  /* PB1 LOW*/
		GPIO_SetupPin_Value(PORTB_ID,2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB_ID,4,LOGIC_HIGH);  /*PB4 high*/
		break;
	case 9:
		GPIO_SetupPin_Value(PORTB_ID,0,LOGIC_HIGH);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB_ID,1,LOGIC_LOW);  /* PB1 LOW*/
		GPIO_SetupPin_Value(PORTB_ID,2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB_ID,4,LOGIC_HIGH);  /*PB4 high*/
		break;
	}
}
