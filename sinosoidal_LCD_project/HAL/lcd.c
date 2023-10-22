 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#include "lcd.h"
#include "util/delay.h"
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/



void LCD_init(void)
{
	GPIO_SetupPin_Direction(PORTB_ID,PB0,PIN_OUTPUT);/*D4*/
	GPIO_SetupPin_Direction(PORTB_ID,PB1,PIN_OUTPUT);/*D5*/
	GPIO_SetupPin_Direction(PORTB_ID,PB2,PIN_OUTPUT);/*D6*/
	GPIO_SetupPin_Direction(PORTB_ID,PB4,PIN_OUTPUT);/*D7*/

	GPIO_SetupPin_Direction(PORTA_ID,PA3,PIN_OUTPUT);/*RS*/
	GPIO_SetupPin_Direction(PORTA_ID,PA2,PIN_OUTPUT); /*EN*/

	_delay_ms(40);

	LCD_writeCommand(0x20);
	LCD_writeCommand(0x20);
	LCD_writeCommand(0x80);

	_delay_ms(40);

	LCD_writeCommand(0x00);
	LCD_writeCommand(0xc0);

	_delay_ms(40);

	LCD_writeCommand(0x00);
	LCD_writeCommand(0x10);

	_delay_ms(2);


}

void LCD_writeCommand(uint8 command)
{
	GPIO_SetupPin_Value(PORTA_ID,PA3,LOGIC_LOW);/*RS*/

	GPIO_SetupPin_Value(PORTB_ID,PB0,GET_BIT(command,4));
	GPIO_SetupPin_Value(PORTB_ID,PB1,GET_BIT(command,5));
	GPIO_SetupPin_Value(PORTB_ID,PB2,GET_BIT(command,6));
	GPIO_SetupPin_Value(PORTB_ID,PB4,GET_BIT(command,7));

	GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_HIGH);/*EN*/
    _delay_ms(2);
	GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_LOW);/*EN*/

	 _delay_ms(2);


	GPIO_SetupPin_Value(PORTB_ID,PB0,GET_BIT(command,0));
	GPIO_SetupPin_Value(PORTB_ID,PB1,GET_BIT(command,1));
	GPIO_SetupPin_Value(PORTB_ID,PB2,GET_BIT(command,2));
	GPIO_SetupPin_Value(PORTB_ID,PB4,GET_BIT(command,3));

	GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_HIGH);/*EN*/
	_delay_ms(2);
	GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_LOW);/*EN*/
	_delay_ms(2);
}
void LCD_writeData(uint8 command)
{

	GPIO_SetupPin_Value(PORTA_ID,PA3,LOGIC_HIGH);

	GPIO_SetupPin_Value(PORTB_ID,PB0,GET_BIT(command,4));
	GPIO_SetupPin_Value(PORTB_ID,PB1,GET_BIT(command,5));
	GPIO_SetupPin_Value(PORTB_ID,PB2,GET_BIT(command,6));
	GPIO_SetupPin_Value(PORTB_ID,PB4,GET_BIT(command,7));

	GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_HIGH);/*EN*/
    _delay_ms(2);
	GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_LOW);/*EN*/
	 _delay_ms(2);

	GPIO_SetupPin_Value(PORTB_ID,PB0,GET_BIT(command,0));
	GPIO_SetupPin_Value(PORTB_ID,PB1,GET_BIT(command,1));
	GPIO_SetupPin_Value(PORTB_ID,PB2,GET_BIT(command,2));
	GPIO_SetupPin_Value(PORTB_ID,PB4,GET_BIT(command,3));


	GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_HIGH);/*EN*/
    _delay_ms(2);
	GPIO_SetupPin_Value(PORTA_ID,PA2,LOGIC_LOW);/*EN*/
	_delay_ms(2);
}
void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address;

	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col+0x80;
				break;
		case 1:
				Address=col+0xC0;
				break;
		case 2:
				Address=col+0x94;
				break;
		case 3:
				Address=col+0xD4;
				break;
	}
	/* to write to a specific address in the LCD
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_writeCommand(Address);
}

void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_writeData(Str[i]);
		i++;
	}
}
void LCD_clearScreen(void)
{
	LCD_writeCommand(CLEAR_COMMAND); //clear display
}
