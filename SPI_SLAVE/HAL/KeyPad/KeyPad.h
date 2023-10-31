/*
 * KeyPad.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_

#include "../../MCAL/GPIO/GPIO_Config.h"


#define KEYPAD_DATA       {{'7','8','9','/'} ,\
					       {'4','5','6','*'},\
					       {'1','2','3','-'},\
						   {'C','0','=','+'}}

#define KEYPAD_ROWS_PORT_ID   PORTC_ID
#define NUMBER_OF_ROWS 4

#define KEYPAD_ROW1  2
#define KEYPAD_ROW2  3
#define KEYPAD_ROW3  4
#define KEYPAD_ROW4  5

#define KEYPAD_ROW_PINS  {KEYPAD_ROW1,KEYPAD_ROW2,KEYPAD_ROW3,KEYPAD_ROW4}




#define KEYPAD_COLS_PORT  PIND
#define NUMBER_OF_COLS 4

#define KEYPAD_COL1  3
#define KEYPAD_COL2  5
#define KEYPAD_COL3  6
#define KEYPAD_COL4  7

#define KEYPAD_COL_PINS  {KEYPAD_COL1,KEYPAD_COL2,KEYPAD_COL3,KEYPAD_COL4}

#define KEYPAD_COLS_PORT_ID PORTD_ID

void KeyPad_init(void);

uint8 KeyPad_getPressedKey(void);

#endif /* HAL_KEYPAD_H_ */
