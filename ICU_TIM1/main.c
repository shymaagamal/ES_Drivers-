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
#include "MCAL/Timer1/Timer1_registers.h"
volatile uint8 g_count=1;
volatile uint32 T_period;
volatile uint32 T_ON;
volatile uint32 t1;
void ICR_calculateTime();
int  main(void)
{
	LCD_init();


	TIM0_init();
	TIM0_start();
	TIM0_dutyCycle(90);

	TIM1_init();
	TCCR1B_REG->ICES1=1; // rising
	TIM1_start();
	GINT_Enable();

	GPIO_SetupPin_Direction(PORTB_ID, 3, PIN_OUTPUT);


	TIM1_Enable_ICR_Interrupt(ICR_calculateTime);

	while(1)
	{




	}
}

void ICR_calculateTime()
{

	if(g_count==1)
		{
			t1=TIM1_getICR();
			TCCR1B_REG->ICES1=0;  // falling
			g_count=2;
		}
		else if(g_count==2)
		{

			T_ON=TIM1_getICR() - t1;
			TCCR1B_REG->ICES1=1;  // rising
			LCD_goToRowColumn(1, 0);
			LCD_displayString("T_ON: ");
			LCD_goToRowColumn(1, 6);
			LCD_intgerToString(T_ON);
			g_count=3;
		}
		else if(g_count==3)
		{

			T_period= TIM1_getICR() - t1;
			LCD_goToRowColumn(2, 0);
			LCD_displayString("T_cycle is :");
			LCD_goToRowColumn(2, 13);
			LCD_intgerToString((uint32)T_period);
			g_count=0;
		}

}
