/*
 * EXTI_config.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

#include "EXTI_private.h"
#include "../../LIB/BIT_Math.h"
#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/GPIO_Config.h"



#define EXINT0_PIN   2
#define EXINT1_PIN   3
#define EXINT2_PIN   2

typedef enum
{
	falling_edge,rising_edge
}interupt_sense_control;

typedef enum
{
	INT1,INT0,INT2
}GINT_Control;



void EXTI_initINT0(interupt_sense_control control);
void EXTI_initINT1(interupt_sense_control control);
void EXTI_initINT2(interupt_sense_control control);

void EXTI_Enable(GINT_Control GControl, void (*callbackPtr)(void),interupt_sense_control control);

uint8 Read_flags(GINT_Control GControl);



#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
