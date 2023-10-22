/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "HAL/lcd.h"

int  main(void)
{


	LCD_init();
	SWITCH_init();
    while(1)
	{
    	if(!GET_BIT(PIND,PD7))
    	{
        	LCD_goToRowColumn(0,0);
        	LCD_displayString("Shaimaa");
    	}
    	else if(!GET_BIT(PIND,PD6))
    	{
        	LCD_goToRowColumn(0,8);
        	LCD_displayString("Gamal");
    	}
    	else if(!GET_BIT(PIND,PD5))
    	{
        	LCD_goToRowColumn(0,14);
        	LCD_displayString("Salem");
    	}
    	else if(!GET_BIT(PIND,PD3))
    	{
    		LCD_clearScreen();
    	}



;
	}


}
