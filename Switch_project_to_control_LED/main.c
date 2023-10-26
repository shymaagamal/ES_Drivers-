/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "HAL/LED.h"
int  main(void)
{
	GPIO_SetupPin_Direction(PORTD_ID,PD7,PIN_INPUT);

	GPIO_SetupPin_Direction(PORTA_ID,PA4,PIN_OUTPUT);

	GPIO_SetupPin_Value(PORTA_ID,PA4,LOGIC_LOW);

	while(1)
	{


		if(!GET_BIT(PIND,PD7))
		{
			GPIO_SetupPin_Value(PORTA_ID,PA4,LOGIC_HIGH);
		}
		else
		{
			GPIO_SetupPin_Value(PORTA_ID,PA4,LOGIC_LOW);
		}

	}
	return 0;
}
