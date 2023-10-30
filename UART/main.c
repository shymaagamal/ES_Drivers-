/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Shaimaa Gamal
 */


#include <stdio.h>
#include "MCAL/GINT/GINT_config.h"
#include "HAL/LCD/lcd.h"
#include "HAL/LED/LED.h"
#include "MCAL/EXTI/EXTI_config.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/Timer1/Timer1_interface.h"
#include"MCAL/Timer0/Timer0_interface.h"
#include "HAL/KeyPad/KeyPad.h"
#include "MCAL/UART/USART_interface.h"
#include "MCAL/UART/USART_registers.h"


int  main(void)
{


	LCD_init();
	LCD_goToRowColumn(0, 0);
	LCD_displayString("Sending Data");
	USART_init();

	uint8 recive[10];
	while(1)
	{
		/*USART_TX('N');


		recive=USART_RX();

		LCD_goToRowColumn(1, 1);
		LCD_writeData(recive);
		*/
		//USART_sendingString("Shaimaa");

		USART_receiveString(recive);

		LCD_goToRowColumn(1, 1);
		LCD_displayString(rec3x`ive);

	}
}



