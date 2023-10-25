/*
 * EXTI_config.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Shaimaa Gamal
 */

#include "EXTI_config.h"

void (*callback_Ptr_INT0)(void)=NULL;
void (*callback_Ptr_INT1)(void)=NULL;
void (*callback_Ptr_INT2)(void)=NULL;



void EXTI_initINT1(interupt_sense_control control)
{

	GPIO_SetupPin_Direction(PORTD_ID, EXINT1_PIN, PIN_INPUT);
	GPIO_SetupPin_Value(PORTD_ID, EXINT1_PIN,LOGIC_HIGH);

	//SET_BIT(GICR_REG,GICR_INT1);
	if(control ==rising_edge)
	{
		SET_BIT(MCUCSR_REG,MCUCR_ISC10);
		SET_BIT(MCUCSR_REG,MCUCR_ISC11);
	}
	else if(control==falling_edge)
	{
		CLEAR_BIT(MCUCSR_REG,MCUCR_ISC10);
		SET_BIT(MCUCSR_REG,MCUCR_ISC11);
	}
}
void EXTI_initINT0(interupt_sense_control control)
{
	GPIO_SetupPin_Direction(PORTD_ID, EXINT0_PIN, PIN_INPUT);
	GPIO_SetupPin_Value(PORTD_ID, EXINT0_PIN, LOGIC_HIGH);
	if(control ==rising_edge)
	{
		SET_BIT(MCUCR_REG,MCUCR_ISC00);
		SET_BIT(MCUCR_REG,MCUCR_ISC01);

	}
	else if(control==falling_edge)
	{
		CLEAR_BIT(MCUCR_REG,MCUCR_ISC00);
		SET_BIT(MCUCR_REG,MCUCR_ISC01);
	}

}
void EXTI_initINT2(interupt_sense_control control)
{
	GPIO_SetupPin_Direction(PORTD_ID, EXINT2_PIN, PIN_INPUT);
	GPIO_SetupPin_Value(PORTD_ID, EXINT2_PIN, LOGIC_HIGH);
	if(control ==rising_edge)
	{
		SET_BIT(MCUCSR_REG,MCUCSR_ISC2);
	}
	else if(control==falling_edge)
	{
		CLEAR_BIT(MCUCSR_REG,MCUCSR_ISC2);
	}
}

void EXTI_Enable(GINT_Control GControl, void (*callbackPtr)(void), interupt_sense_control control)
{
	if(GControl==INT0)
	{
		EXTI_initINT0(control);
		SET_BIT(GIFR_REG,GIFR_INTF0);
		SET_BIT(GICR_REG,GICR_INT0);
		callback_Ptr_INT0=callbackPtr;

	}
	else if(GControl==INT1)
	{
		EXTI_initINT1(control);
		SET_BIT(GIFR_REG,GIFR_INTF1);
		SET_BIT(GICR_REG,GICR_INT1);
		callback_Ptr_INT1=callbackPtr;

	}
	else if(GControl==INT2)
	{
		EXTI_initINT0(control);
		SET_BIT(GIFR_REG,GIFR_INTF2);
		SET_BIT(GICR_REG,GICR_INT2);
		callback_Ptr_INT2=callbackPtr;
	}
}

void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	if(callback_Ptr_INT0 !=NULL)
	{
		callback_Ptr_INT0();
	}
}
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	if(callback_Ptr_INT1 !=NULL)
	{
		callback_Ptr_INT1();
	}
}
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	if(callback_Ptr_INT2 !=NULL)
	{
		callback_Ptr_INT2();
	}
}

