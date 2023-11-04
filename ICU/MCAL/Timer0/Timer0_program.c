/*
 * Timer_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Shaimaa Gamal
 */



#include "Timer0_config.h"
#include "Timer0_interface.h"
#include "Timer0_private.h"
#include "Timer0_registers.h"

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
void TIM0_dutyCycle(uint8 dc)
{
#if(COM_MODE==ClearOnCompareMatchFastPWM)
	OCR0_REG=((dc * 255 )/ 100);
#elif(COM_MODE==SetOnCompareMatchFastPWM)
	OCR0_REG= (dc * 255 )/ 100;
#endif
}
uint8 TIM0_getVal(void)
{
	return TCNT0_REG;
}


void delay_ms(uint32 msec)
{
	TIM0_TIFR_REG->TOV0=1;
	TIM0_TIMSK_REG->TOIE0=0;

	while(msec--)
	{
		TIM0_setPreload(6);
		while(TIM0_TIFR_REG->TOV0 != 1);
		TIM0_TIFR_REG->TOV0=1;

	}



}
void TIM0_EnableOVFInterrupt(void(*CallbackFunction)(void))
{
	TIM0_TIFR_REG->TOV0=1;
	TIM0_TIMSK_REG->TOIE0=1;
	if(CallbackFunction !=NULL)
	{
		TIM0_callBackOV_ptr=CallbackFunction;
	}

}
void TIM0_EnableCOMInterrupt(void(*CallbackFunction)(void))
{
	TIM0_TIFR_REG->OCF0=1;
	TIM0_TIMSK_REG->OCIE0=1;
	if(CallbackFunction !=NULL)
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
