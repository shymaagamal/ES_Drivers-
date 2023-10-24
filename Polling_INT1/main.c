/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */



#include "MCAL/EXTI/EXTI_config.h"
#include "MCAL/GINT/GINT_config.h"
#include "HAL/LCD/lcd.h"
#include "HAL/LED/LED.h"
void Wrapper_Fun(void)
{
	LCD_writeData(Read_flags(INT1));
}

int  main(void)
{
	setup_LED_Direction();
	LCD_init();
	LED_OFF(PORTB_ID,7);
	EXTI_Enable(INT1,Wrapper_Fun,falling_edge);
	while(1)
	{
		if(Read_flags(INT1))
		{
			LCD_writeData('3');
			LED_ON(PORTB_ID,7);
			_delay_ms(250);
			SET_BIT(GIFR_REG,GIFR_INTF1);
		}
		else
		{
			LED_OFF(PORTB_ID,7);
		}
	}

}


