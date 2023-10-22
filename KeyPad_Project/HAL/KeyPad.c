/*
 * KeyPad.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Shaimaa Gamal
 */


#include "KeyPad.h"


void KeyPad_init()
{
	/*Configure Direction of Rows*/
	GPIO_SetupPin_Direction(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW1,PIN_OUTPUT);
	GPIO_SetupPin_Direction(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW2,PIN_OUTPUT);
	GPIO_SetupPin_Direction(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW3,PIN_OUTPUT);
	GPIO_SetupPin_Direction(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW4,PIN_OUTPUT);

	GPIO_SetupPin_Direction(KEYPAD_COLS_PORT_ID,KEYPAD_COL1,PIN_INPUT);
	GPIO_SetupPin_Direction(KEYPAD_COLS_PORT_ID,KEYPAD_COL2,PIN_INPUT);
	GPIO_SetupPin_Direction(KEYPAD_COLS_PORT_ID,KEYPAD_COL3,PIN_INPUT);
	GPIO_SetupPin_Direction(KEYPAD_COLS_PORT_ID,KEYPAD_COL4,PIN_INPUT);

	GPIO_SetupPin_Value(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW1,LOGIC_HIGH);
	GPIO_SetupPin_Value(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW2,LOGIC_HIGH);
	GPIO_SetupPin_Value(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW3,LOGIC_HIGH);
	GPIO_SetupPin_Value(KEYPAD_ROWS_PORT_ID,KEYPAD_ROW4,LOGIC_HIGH);

}

uint8 KeyPad_getPressedKey()
{

	uint8 KeyPad_data[NUMBER_OF_ROWS][NUMBER_OF_COLS]=KEYPAD_DATA;

	uint8 KeyPad_col_Pins[NUMBER_OF_COLS]=KEYPAD_COL_PINS;

	uint8 KeyPad_row_Pins[NUMBER_OF_ROWS]=KEYPAD_ROW_PINS;

	uint8 Data=0XFF;

	for(uint8 row=0;row<NUMBER_OF_ROWS;row++)
	{
		GPIO_SetupPin_Value(KEYPAD_ROWS_PORT_ID,KeyPad_row_Pins[row],LOGIC_LOW);
		for(uint8 col=0;col<NUMBER_OF_COLS;col++)
		{
			if(!GET_BIT(KEYPAD_ROWS_PORT,KeyPad_col_Pins[col]))
			{
				Data=KeyPad_data[row][col];
			}
		}
		GPIO_SetupPin_Value(KEYPAD_ROWS_PORT_ID,KeyPad_row_Pins[row],LOGIC_HIGH);
	}
	return Data;
}
