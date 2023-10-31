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
void moveDcMotor(uint8 s);
void displayStatus(uint8 s);
void DC_motor(void);

uint8 g_flag_Interrupt=0;
int  main(void)
{
	/*Connecton of DC Motor*/
	GPIO_SetupPin_Direction(PORTC_ID, 0, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTC_ID, 1, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTC_ID, 2, PIN_OUTPUT);
	GPIO_SetupPin_Direction(PORTC_ID, 3, PIN_OUTPUT);

	GINT_Enable();
	TIM0_init();
	TIM0_start();
	TIM0_setPreload(24);
	TIM0_EnableOVFInterrupt(DC_motor);

	GPIO_SetupPin_Direction(PORTD_ID,5, PIN_OUTPUT);/*Servo Motor on OC1A*/
	GPIO_SetupPin_Direction(PORTD_ID,4, PIN_OUTPUT);/*Servo Motor on OC1B*/


	TIM1_init();
	TIM1_setICR(5000);
	TIM1_start();

	SPI_slaveInit();
	uint8 status=0;
	while(1)
	{

		status =SPI_slaveRecive();
		displayStatus(status);

		if(g_flag_Interrupt==1)
		{
			moveDcMotor(status);
			g_flag_Interrupt=0;

		}

	}
}
void displayStatus(uint8 s)
{
	switch(s)
	{
	case'E':
	case'e':
		TIM1_dutyCycle_OCRB(3000);
		_delay_ms(1000);
		break;
	case'F':
	case'f':
		TIM1_dutyCycle_OCRB(0);
		_delay_ms(1000);
		break;
	case'G':
	case'g':
		TIM1_dutyCycle_OCRA(3000);
		_delay_ms(1000);
		break;
	case'H':
	case'h':
		TIM1_dutyCycle_OCRA(0);
		_delay_ms(1000);
		break;
	}

}

void moveDcMotor(uint8 s)
{
switch(s)
{
case 'R':
case 'r':
	GPIO_SetupPin_Value(PORTC_ID, 0, LOGIC_HIGH);
	GPIO_SetupPin_Value(PORTC_ID, 1, LOGIC_LOW);
	GPIO_SetupPin_Value(PORTC_ID, 2, LOGIC_LOW);
	GPIO_SetupPin_Value(PORTC_ID, 3, LOGIC_LOW);
	break;
case 'L':
case 'l':
	GPIO_SetupPin_Value(PORTC_ID, 0, LOGIC_LOW);
	GPIO_SetupPin_Value(PORTC_ID, 1, LOGIC_LOW);
	GPIO_SetupPin_Value(PORTC_ID, 2, LOGIC_LOW);
	GPIO_SetupPin_Value(PORTC_ID, 3, LOGIC_HIGH);
	break;
case 'W':
case 'w':
	GPIO_SetupPin_Value(PORTC_ID, 0, LOGIC_HIGH);
	GPIO_SetupPin_Value(PORTC_ID, 1, LOGIC_LOW);
	GPIO_SetupPin_Value(PORTC_ID, 2, LOGIC_HIGH);
	GPIO_SetupPin_Value(PORTC_ID, 3, LOGIC_LOW);
	break;
case 'S':
case 's':
	GPIO_SetupPin_Value(PORTC_ID, 0, LOGIC_HIGH);
	GPIO_SetupPin_Value(PORTC_ID, 1, LOGIC_HIGH);
	GPIO_SetupPin_Value(PORTC_ID, 2, LOGIC_HIGH);
	GPIO_SetupPin_Value(PORTC_ID, 3, LOGIC_HIGH);
	break;
}
}

void DC_motor(void)
{


	g_flag_Interrupt=1;
}

