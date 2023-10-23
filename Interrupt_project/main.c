/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "MCAL/EXTI/EXTI_config.h"
#include "MCAL/GINT/GINT_config.h"
#include "HAL/LCD/lcd.h"
void Wrapper_Fun(void)
{
	LCD_writeData('3');
}
int  main(void)
{

	LCD_init();
	GINT_Enable();
	EXTI_Enable(INT1,Wrapper_Fun,falling_edge);
	while(1)
	{

	}

}


