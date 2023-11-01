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
uint32 g_temp;
uint8 g_data;
uint8 count=0;
void displayStatus(uint8 s);
void readTemp();
int  main(void)
{

	GPIO_SetupPin_Direction(PORTD_ID,5, PIN_OUTPUT);/*Servo Motor on OC1A*/
	GPIO_SetupPin_Direction(PORTD_ID,4, PIN_OUTPUT);/*Servo Motor on OC1B*/

	TIM1_init();
	TIM1_setICR(5000);
	TIM1_start();


	GINT_Enable();
	ADC_selectChannel(ADC1);
	ADC_init();


	SPI_slaveInit();
	uint8 status=0;
	GPIO_SetupPin_Direction(PORTB_ID, 1, PIN_OUTPUT);
	ADC_setCallBackFunction(readTemp);
	while(1)
	{

		status =SPI_slaveRecive();
		displayStatus(status);




	}
}
void readTemp()
{
	if(count==10)
	{
		g_temp =ADC_readChannel();
		g_temp=((uint8)g_temp*150*5)/(1023*1.5);

		GPIO_TogglePin_Value(PORTB_ID, 1);
		count=0;
	}
	count++;
}
void displayStatus(uint8 s)
{
	switch(s)
	{
	case'A':
	case'a':
		TIM1_dutyCycle_OCRB(3000);
		_delay_ms(1000);
		break;
	case'B':
	case'b':
		TIM1_dutyCycle_OCRB(0);
		_delay_ms(1000);
		break;
	case'C':
	case'c':
		TIM1_dutyCycle_OCRA(3000);
		_delay_ms(1000);
		break;
	case'D':
	case'd':
		TIM1_dutyCycle_OCRA(0);
		_delay_ms(1000);
		break;
	case'T':
	case't':

		SPI_masterTransmit(g_temp);
		_delay_ms(1000);
		break;
	}

}


