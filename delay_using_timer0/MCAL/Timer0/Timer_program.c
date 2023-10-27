/*
 * Timer_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Shaimaa Gamal
 */



#include "../Timer0/Timer_config.h"
#include "../Timer0/Timer_interface.h"
#include "../Timer0/Timer_private.h"
#include "../Timer0/Timer_registers.h"

void (*TIM0_callBackOV_ptr)(void) = NULL;
void (*TIM0_callBackCOMP_ptr)(void) = NULL;

void TIM0_init()
{
	TCCR0_REG->FOC0=0;
#if(NORMAL)

	TCCR0_REG->WGM00=0;
	TCCR0_REG->WGM01=0;
#elif(PHASE_CORRECT)
	TCCR0_REG->WGM00=1;
	TCCR0_REG->WGM01=0;
#elif(CTC)
	TCCR0_REG->WGM00=0;
	TCCR0_REG->WGM01=1;
#elif(FAST_PWM)
	TCCR0_REG->WGM00=1;
	TCCR0_REG->WGM01=1;
#endif


	TCCR0_REG->COM=COM_MODE;
}

void TIM0_stop(void)
{
	TCCR0_REG->CS=NoClockSource;
}

void TIM0_start(void)
{
	TCCR0_REG->CS=Prescaler;
}
void TIM0_setPreload(uint8 preload_Val)
{
	TCNT0_REG=preload_Val;
}
uint8 TIM0_getVal(void)
{
	return TCNT0_REG;
}
void delay_ms(uint8 msec)
{
	TIFR_REG->TOV0=1;
	TIMSK_REG->TOIE0=0;

	while(msec--)
	{
		TIM0_setPreload(6);
		while(TIFR_REG->TOV0 != 1);
		TIFR_REG->TOV0=1;

	}



}
void TIM0_EnableOVFInterrupt(void(*CallbackFunction)(void))
{
	TIFR_REG->TOV0=1;
	TIMSK_REG->TOIE0=1;
	if(CallbackFunction !=NULL)
	{
		TIM0_callBackOV_ptr=CallbackFunction;
	}

}
void TIM0_EnableCOMInterrupt(void(*CallbackFunction)(void))
{
	TIFR_REG->OCF0=1;
	TIMSK_REG->OCIE0=1;
	{
		TIM0_callBackCOMP_ptr=CallbackFunction;
	}

}
void __vector_11(void)	__attribute__((signal, used));
void __vector_11(void)
{
	if(TIM0_callBackOV_ptr != NULL)
	{
		TIM0_callBackOV_ptr();
	}
}
