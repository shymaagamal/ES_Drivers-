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
#define SLAVE1	PORTA_ID, 0
#define SLAVE2 PORTA_ID, 1
void sendStatus(uint8 status);

int  main(void)
{


	LCD_init();
	LCD_goToRowColumn(0, 1);
	SPI_masterInit();

	GPIO_SetupPin_Direction(SLAVE1, PIN_OUTPUT);/*Slave 1*/
	GPIO_SetupPin_Direction(SLAVE2, PIN_OUTPUT); /*Slave 2*/

	GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
	GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
	USART_init();

	while(1)
	{
		uint8 state = USART_RX_polling();
		sendStatus(state);


	}
}

void sendStatus(uint8 status)
{
	LCD_clearScreen();
	switch(status)
	{
	case 'A':
	case 'a':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_LOW);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_HIGH);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 1);
		LCD_displayString("Open The front Left door");
		break;

	case 'B':
	case 'b':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_LOW);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_HIGH);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("close The front Left door");
		break;
	case 'C':
	case 'c':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_LOW);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_HIGH);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 1);
		LCD_displayString("Open The front right door");
		break;
	case 'D':
	case 'd':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_LOW);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_HIGH);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("close The front right door");
		break;

	case 'E':
	case 'e':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("Open The back left door");
		break;

	case 'F':
	case 'f':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("close The back left door");
		break;

	case 'G':
	case 'g':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("Open The back right door");
		break;

	case 'H':
	case 'h':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("close The back left door");
		break;
	case 'R':
	case 'r':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("Turn Right");
		break;
	case 'L':
	case 'l':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("Turn Left");
		break;
	case 'W':
	case 'w':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("Move Forward");
		break;
	case 'S':
	case 's':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);
		LCD_goToRowColumn(0, 0);
		LCD_displayString("Stop The Car");
		break;


	}
}
