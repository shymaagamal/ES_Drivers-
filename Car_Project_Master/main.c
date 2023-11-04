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
#include"MCAL/UART/USART_interface.h"

#define SLAVE1	PORTA_ID, 0
#define SLAVE2 PORTA_ID, 1

uint8 g_flag_recive_adc=0;
uint8 recive_tempVal=0;
uint8 speed=0;
void sendStatus(uint8 status);

int  main(void)
{
	GPIO_SetupPin_Direction(PORTA_ID, 7, PIN_OUTPUT);

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
		LCD_displayString("close The back right door");
		break;
	case 'R':
	case 'r':
		speed=0;
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);/*Send Status to slave 2 */
		LCD_goToRowColumn(0, 0);
		LCD_displayString("Enter Speed Of Motor from 1 to 9");
		speed=USART_RX_polling(); /*Waiting User for entering speed of motor*/
		SPI_masterTransmit(speed);

		GPIO_SetupPin_Value(SLAVE1,LOGIC_LOW);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_HIGH);
		SPI_masterTransmit(status);/*Send Status to slave 1 to stop left dc motor  */

		LCD_clearScreen();
		LCD_goToRowColumn(0, 0);
		LCD_displayString("Turn Right");
		break;
	case 'L':
	case 'l':
		speed=0;
		GPIO_SetupPin_Value(SLAVE1,LOGIC_LOW);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_HIGH);
		SPI_masterTransmit(status);/*Send Status to slave 1 */

		LCD_goToRowColumn(0, 0);
		LCD_displayString("Enter Speed Of Motor from 1 to 9");

		speed=USART_RX_polling();
		SPI_masterTransmit(speed);/*Waiting User for entering speed of motor*/

		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);/*Send Status to slave 2 to stop left dc motor  */

		LCD_clearScreen();
		LCD_goToRowColumn(0, 0);
		LCD_displayString("Turn Left");

		break;
	case 'W':
	case 'w':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);/*Send Status to slave 2 move forward with motor 1*/


		GPIO_SetupPin_Value(SLAVE1,LOGIC_LOW);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_HIGH);
		SPI_masterTransmit(status);/*Send Status to slave 1 to move forward with motor 2 */

		LCD_goToRowColumn(0, 0);
		LCD_displayString("Move Forward");

		break;
	case 'S':
	case 's':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_HIGH);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_LOW);
		SPI_masterTransmit(status);/*Send Status to slave 2 stop with motor 1*/

		GPIO_SetupPin_Value(SLAVE1,LOGIC_LOW);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_HIGH);
		SPI_masterTransmit(status);/*Send Status to slave 1 move forward with motor 1*/

		LCD_goToRowColumn(0, 0);
		LCD_displayString("Stop The Car");
		break;
	case 'T':
	case 't':
		GPIO_SetupPin_Value(SLAVE1,LOGIC_LOW);
		GPIO_SetupPin_Value(SLAVE2, LOGIC_HIGH);

		SPI_masterTransmit(status);
        _delay_ms(100);
		recive_tempVal=SPI_slaveRecive();

		SPI_masterTransmit(status);
		_delay_ms(100);
		recive_tempVal=SPI_slaveRecive();

		LCD_goToRowColumn(0, 0);
		LCD_intgerToString(recive_tempVal);

		break;


	}
}

