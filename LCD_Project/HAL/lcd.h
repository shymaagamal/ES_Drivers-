 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Shaimaa G.Salem
 *
 *******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "../MCAL/GPIO/GPIO_Config.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/





//#define LCD_DATA_PORT PORTD
//#define LCD_DATA_PORT_DIR DDRC
void LCD_init(void);
void LCD_writeCommand(uint8 command);
void LCD_writeData(uint8 command);
void LCD_goToRowColumn(uint8 row,uint8 col);

#endif /* LCD_H_ */
