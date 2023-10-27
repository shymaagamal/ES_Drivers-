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

uint32 g_tempVal = 0,g_mapVal=0;
uint8 read[10];
uint8 count =0;

#define NUM_OF_OVF     63
/** ============== Callback & Normal functions implementation =============== */
void readTempSensor(void);
uint32 map(uint32 x, uint32 x1, uint32 x2, uint32 y1, uint32 y2);

void TIM0_ADC();
int  main(void)
{

	GINT_Enable();


	ADC_init();
	ADC_selectChannel(ADC1);
	LCD_init();
	LCD_clearScreen();

	LCD_goToRowColumn(0, 0);
	LCD_displayString("Temp value: ");

	LCD_goToRowColumn(1, 0);
	LCD_displayString("Map Value :");
	LED_setUpDirection(PORTB_ID, 7, PIN_OUTPUT);
	LED_OFF(PORTB_ID, 7);

	ADC_setCallBackFunction(readTempSensor);

	TIM0_init();
	TIM0_start();
	TIM0_EnableOVFInterrupt(TIM0_ADC);
	while(1)
	{

	}

}
void TIM0_ADC()
{
	count++;
	if(count==100)
	{
		ADC_EnableInterrupt();
		count=0;

	}

}
void readTempSensor(void)
{
	g_tempVal = ADC_readChannel();
	g_tempVal=(g_tempVal*150*5)/(1023*1.5);
	LCD_goToRowColumn(0, 12);
	LCD_intgerToString(g_tempVal);

	g_mapVal=map(g_tempVal,0, 1023, 2500, 5000);
	LCD_goToRowColumn(1, 12);
	LCD_intgerToString(g_mapVal);
	LED_Toggle(PORTB_ID,7);

}

uint32 map(uint32 x, uint32 x1, uint32 x2, uint32 y1, uint32 y2)
{
	return (((x - x1) * (y2 - y1) / (x2 - x1)) + y1);
}
