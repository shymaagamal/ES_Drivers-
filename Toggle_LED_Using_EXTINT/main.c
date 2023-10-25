/*
 * main.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Shaimaa Gamal
 */


/*
 * Exercise2.c
 *
 * Created: 12/7/2013 9:08:25 PM
 * Author: Mohamed Tarek
 */


#include <util/delay.h>
#include "MCAL/EXTI/EXTI_config.h"
#include "MCAL/GINT/GINT_config.h"
unsigned char g_Interrupt_Flag = 0;

void sys_int()
{
	g_Interrupt_Flag = 1;
}

int main(void)
{
	          // Enable and configure external INT1

	LED_setUpDirection(PORTB_ID, 7, PIN_OUTPUT);
	LCD_init();// First led is on at the beginning (Positive Logic configuration)
	GINT_Enable();
	EXTI_Enable(INT0,sys_int,falling_edge);

    while(1)
    {

		if(g_Interrupt_Flag==1)
		{
			LED_Toggle(PORTB_ID, 7);
			LCD_writeData('3');
			g_Interrupt_Flag=0;
		}
	}
}

