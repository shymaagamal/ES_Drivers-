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
#include "MCAL/SPI/SPI_interface.h"

uint8 Data[8]="Shaimaa";
int  main(void)
{


	LCD_init();
	LCD_goToRowColumn(0, 1);
	LCD_displayString("Sending Data");
	SPI_masterInit();
	for(uint8 i=0;Data[i]!='\0';i++)
	{
		SPI_masterTransmit(Data[i]);
		_delay_ms(100);
	}
	while(1)
	{



	}
}



