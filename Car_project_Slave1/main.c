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
uint8 g_temp;
uint8 g_data;
uint8 count=0;
uint8 speed=0;
void displayStatus(uint8 s);
void moveDcMotor(uint8 s);
int  main(void)
{
	GPIO_SetupPin_Direction(PORTC_ID, 0, PIN_OUTPUT);/*DC Motor*/
	GPIO_SetupPin_Direction(PORTC_ID, 1, PIN_OUTPUT);

	GPIO_SetupPin_Direction(PORTB_ID, 3, PIN_OUTPUT);/*OC0 Enable of DC Motor to control speed*/

	TIM0_init();/*Used for DC Motor with PWM*/
	TIM0_start();
	TIM0_dutyCycle(0);

	GPIO_SetupPin_Direction(PORTD_ID,5, PIN_OUTPUT);/*Servo Motor on OC1A*/
	GPIO_SetupPin_Direction(PORTD_ID,4, PIN_OUTPUT);/*Servo Motor on OC1B*/

	TIM1_init();
	TIM1_setICR(5000);
	TIM1_start();


	ADC_init();
	ADC_selectChannel(ADC1);


	SPI_slaveInit();

	uint8 status=0;

	while(1)
	{

		status =SPI_slaveRecive();
		displayStatus(status);

		moveDcMotor(status);

	}
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
		ADC_startConversionPollingMode();
		uint8 raw_adc_value=ADC_readChannel();
		g_temp=((uint8)raw_adc_value*150*5)/(1023*1.5);
		SPI_masterTransmit(g_temp);
		break;
	}

}

void moveDcMotor(uint8 s)
{

switch(s)
{
case 'L':
case 'l':
	speed=0;
	speed=SPI_slaveRecive();
	if(speed>= '1' && speed<= '9')
	{
		TIM0_dutyCycle(speed*300);
		GPIO_SetupPin_Value(PORTC_ID, 0, LOGIC_LOW);
		GPIO_SetupPin_Value(PORTC_ID, 1, LOGIC_HIGH);
	}


	break;
case 'R':
case 'r':
	GPIO_SetupPin_Value(PORTC_ID, 0, LOGIC_HIGH);
	GPIO_SetupPin_Value(PORTC_ID, 1, LOGIC_HIGH);
	break;
case 'W':
case 'w':
	TIM0_dutyCycle(1000);
	GPIO_SetupPin_Value(PORTC_ID, 0, LOGIC_HIGH);
	GPIO_SetupPin_Value(PORTC_ID, 1, LOGIC_LOW);

	break;
case 'S':
case 's':
	GPIO_SetupPin_Value(PORTC_ID, 0, LOGIC_HIGH);
	GPIO_SetupPin_Value(PORTC_ID, 1, LOGIC_HIGH);
	break;
}
}
