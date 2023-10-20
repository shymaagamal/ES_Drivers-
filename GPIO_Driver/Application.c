/*
 * Application.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */
#include "GPIO_Config.h"
#include "Application.h"


void sevenSeg_setPin_direction(void)
{


	GPIO_SetupPin_Direction(PORTB,PB0, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTB,PB1, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTB,PB2, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTB,PB4, PIN_OUTPUT);

}


/*Connection of SevenSegment is PB0,PB1,PB2,PB4*/
void sevenSeg_Display(uint8 num)
{

	switch(num)
	{
	case 0:
		GPIO_SetupPort_Value(PORTB,PORTB &0XE8); /* Put 0 in PB0,PB1,PB2,PB4 and don't care with others*/
		break;
	case 1:
		GPIO_SetupPin_Value(PORTB,PB0,LOGIC_HIGH);  /*Set PB0*/
		GPIO_SetupPin_Value(PORTB,PB1,LOGIC_LOW);  /* PB1 Low*/
		GPIO_SetupPin_Value(PORTB,PB2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB,PB4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 2:
		GPIO_SetupPin_Value(PORTB,PB0,LOGIC_LOW);  /* PB0 low*/
		GPIO_SetupPin_Value(PORTB,PB1,LOGIC_HIGH);  /* PB1 high*/
		GPIO_SetupPin_Value(PORTB,PB2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB,PB4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 3:
		GPIO_SetupPin_Value(PORTB,PB0,LOGIC_HIGH);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB,PB1,LOGIC_HIGH);  /* PB1 high*/
		GPIO_SetupPin_Value(PORTB,PB2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB,PB4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 4:
		GPIO_SetupPin_Value(PORTB,PB0,LOGIC_LOW);  /* PB0 LOW*/
		GPIO_SetupPin_Value(PORTB,PB1,LOGIC_LOW);  /* PB1 LOW*/
		GPIO_SetupPin_Value(PORTB,PB2,LOGIC_HIGH);  /*PB2  high*/
		GPIO_SetupPin_Value(PORTB,PB4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 5:
		GPIO_SetupPin_Value(PORTB,PB0,LOGIC_HIGH);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB,PB1,LOGIC_HIGH);  /* PB1 high*/
		GPIO_SetupPin_Value(PORTB,PB2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB,PB4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 6:
		GPIO_SetupPin_Value(PORTB,0,LOGIC_HIGH);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB,1,LOGIC_LOW);  /* PB1 LOW*/
		GPIO_SetupPin_Value(PORTB,2,LOGIC_HIGH);  /*PB2  HIGH*/
		GPIO_SetupPin_Value(PORTB,4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 7:
		GPIO_SetupPin_Value(PORTB,0,LOGIC_HIGH);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB,1,LOGIC_HIGH);  /* PB1 high*/
		GPIO_SetupPin_Value(PORTB,2,LOGIC_HIGH);  /*PB2  high*/
		GPIO_SetupPin_Value(PORTB,4,LOGIC_LOW);  /*PB4 Low*/
		break;
	case 8:
		GPIO_SetupPin_Value(PORTB,0,LOGIC_LOW);  /* PB0 LOW*/
		GPIO_SetupPin_Value(PORTB,1,LOGIC_LOW);  /* PB1 LOW*/
		GPIO_SetupPin_Value(PORTB,2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB,4,LOGIC_HIGH);  /*PB4 high*/
		break;
	case 9:
		GPIO_SetupPin_Value(PORTB,0,LOGIC_HIGH);  /* PB0 high*/
		GPIO_SetupPin_Value(PORTB,1,LOGIC_LOW);  /* PB1 LOW*/
		GPIO_SetupPin_Value(PORTB,2,LOGIC_LOW);  /*PB2  LOW*/
		GPIO_SetupPin_Value(PORTB,4,LOGIC_HIGH);  /*PB4 high*/
		break;
	}
}
