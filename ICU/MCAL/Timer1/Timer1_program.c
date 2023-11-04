/*
 * Timer1_program.c
 *
 *  Created on: Oct 28, 2023
 *      Author: Shaimaa Gamal
 */


#include "Timer1_interface.h"
#include "Timer1_registers.h"
#include "Timer1_config.h"
#include "Timer1_private.h"



void (*TIM1_callBackOV_ptr)(void) = NULL;
void (*TIM1_callBackOCRA_ptr)(void) = NULL;
void (*TIM1_callBackOCRB_ptr)(void) = NULL;
void (*TIM1_callBackICR_ptr)(void) = NULL;

void TIM1_WGMMood(WGMMood WGM)
{

switch(WGM)
{
case TIM1_Normal:
TCCR1A_REG->WGM=0b00;
TCCR1B_REG->WGM=0b00;
break;
case TIM1_PWMPhaseCorrect8bit:
	TCCR1A_REG->WGM=0b01;
	TCCR1B_REG->WGM=0b00;
break;
case TIM1_PWMPhaseCorrect9bit:
	TCCR1A_REG->WGM=0b10;
	TCCR1B_REG->WGM=0b00;
break;
case TIM1_PWMPhaseCorrect10bit:
	TCCR1A_REG->WGM=0b11;
	TCCR1B_REG->WGM=0b00;
break;
case TIM1_CTC:
	TCCR1A_REG->WGM=0b00;
	TCCR1B_REG->WGM=0b01;
break;
case TIM1_FastPWM8bit:
	TCCR1A_REG->WGM=0b01;
	TCCR1B_REG->WGM=0b10;
break;
case TIM1_FastPWM9bit:
	TCCR1A_REG->WGM=0b10;
	TCCR1B_REG->WGM=0b01;
break;
case TIM1_FastPWM10bit:
	TCCR1A_REG->WGM=0b11;
	TCCR1B_REG->WGM=0b01;
break;
case TIM1_PWMPhaseandFrequencyCorrect_ICR1_TOP:
	TCCR1A_REG->WGM=0b00;
	TCCR1B_REG->WGM=0b10;
break;
case TIM1_PWMPhaseandFrequencyCorrect_OCR1A_TOP:
	TCCR1A_REG->WGM=0b00;
	TCCR1B_REG->WGM=0b00;
break;
case TIM1_PWMPhaseCorrect_ICR1_TOP:
	TCCR1A_REG->WGM=0b00;
	TCCR1B_REG->WGM=0b00;
break;
case TIM1_PWMPhaseCorrect_OCR1A_TOP:
	TCCR1A_REG->WGM=0b01;
	TCCR1B_REG->WGM=0b10;
break;
case TIM1_CTC_ICR1_TOP:
	TCCR1A_REG->WGM=0b00;
	TCCR1B_REG->WGM=0b11;
break;
case TIM1_FASTPWM_ICR1_TOP:
	TCCR1A_REG->WGM=0b10;
	TCCR1B_REG->WGM=0b11;
break;
case TIM1_FASTPWM_OCR1A_TOP:
	TCCR1A_REG->WGM=0b11;
	TCCR1B_REG->WGM=0b11;
break;
}


}
void TIM1_FastPWMMood(COMFastPWM COM)
{
	switch(COM)
	{
	case TIM1_NormalFastPWM:
		TCCR1A_REG->COM1A0=0;
		TCCR1A_REG->COM1B0=0;
		TCCR1A_REG->COM1A1=0;
		TCCR1A_REG->COM1B1=0;
		break;
	case TIM1_Toggle_OC1A_OnCompareMatchFastPWM:
		TCCR1A_REG->COM1A0=1;
		TCCR1A_REG->COM1B0=1;
		TCCR1A_REG->COM1A1=0;
		TCCR1A_REG->COM1B1=0;
		break;
	case TIM1_ClearOnCompareMatchFastPWM:
		TCCR1A_REG->COM1A0=0;
		TCCR1A_REG->COM1B0=0;
		TCCR1A_REG->COM1A1=1;
		TCCR1A_REG->COM1B1=1;
		break;
	case TIM1_SetOnCompareMatchFastPWM:
		TCCR1A_REG->COM1A0=1;
		TCCR1A_REG->COM1B0=1;
		TCCR1A_REG->COM1A1=1;
		TCCR1A_REG->COM1B1=1;
		break;

	}
}
void TIM1_NonPWMMood(COMNonPWM COM)
{
	switch(COM)
	{
	case TIM1_NormalNONPWM:
		TCCR1A_REG->COM1A0=0;
		TCCR1A_REG->COM1B0=0;
		TCCR1A_REG->COM1A1=0;
		TCCR1A_REG->COM1B1=0;
		break;
	case TIM1_ToggleOncomparematchNONPWM:
		TCCR1A_REG->COM1A0=1;
		TCCR1A_REG->COM1B0=1;
		TCCR1A_REG->COM1A1=0;
		TCCR1A_REG->COM1B1=0;
		break;
	case TIM1_ClearOnCompareMatchNONPWM:
		TCCR1A_REG->COM1A0=0;
		TCCR1A_REG->COM1B0=0;
		TCCR1A_REG->COM1A1=1;
		TCCR1A_REG->COM1B1=1;
		break;
	case TIM1_SetOncomparematchNONPWM:
		TCCR1A_REG->COM1A0=1;
		TCCR1A_REG->COM1B0=1;
		TCCR1A_REG->COM1A1=1;
		TCCR1A_REG->COM1B1=1;
		break;

	}
}
void TIM1_phaseCorrectMood(COMPhaseCorrect COM)
{
	switch(COM)
	{
	case TIM1_NormalPhasePWM:
		TCCR1A_REG->COM1A0=0;
		TCCR1A_REG->COM1B0=0;
		TCCR1A_REG->COM1A1=0;
		TCCR1A_REG->COM1B1=0;
		break;
	case TIM1_Toggle_OC1A_OnCompareMatchPhasePWM:
		TCCR1A_REG->COM1A0=1;
		TCCR1A_REG->COM1B0=1;
		TCCR1A_REG->COM1A1=0;
		TCCR1A_REG->COM1B1=0;
		break;
	case TIM1_ClearOnCompareMatchPhasePWM:
		TCCR1A_REG->COM1A0=0;
		TCCR1A_REG->COM1B0=0;
		TCCR1A_REG->COM1A1=1;
		TCCR1A_REG->COM1B1=1;
		break;
	case TIM1_SetOnCompareMatchPhasePWM:
		TCCR1A_REG->COM1A0=1;
		TCCR1A_REG->COM1B0=1;
		TCCR1A_REG->COM1A1=1;
		TCCR1A_REG->COM1B1=1;
		break;

	}
}


void TIM1_init(void)
{
	TCCR1A_REG->FOC1A=0;
	TCCR1A_REG->FOC1B=0;
#if(TIM1_NONPWM==1)
	TIM1_NonPWMMood(TIM1_NONPWM_MOOD);

#elif(TIM1_PHASE_CORRECT==1)

	TIM1_phaseCorrectMood(TIM1_PHASE_CORRECT_MOOD);

#elif(TIM1_FAST_PWM==1)
	TIM1_FastPWMMood(TIM1_FAST_PWM_MOOD);

#endif

	TIM1_WGMMood(TIM1_WGM_MOOD);
}



void TIM1_stop(void)
{
	TCCR1B_REG->CS=TIM1_NoClockSource;
}

void TIM1_start(void)
{
	TCCR1B_REG->CS=TIM1_Prescaler;
}
void TIM1_setPreload(uint16 preload_Val)
{
	TCNT1_REG=preload_Val;
}
uint16 TIM1_getVal(void)
{
	return TCNT1_REG;
}
void TIM1_setICR(uint16 val)
{
	ICR1_REG=val;
}
void TIM1_dutyCycle_OCRA(uint16 dutyCycle)
{
	OCR1A_REG=dutyCycle;
}
void TIM1_dutyCycle_OCRB(uint16 dutyCycle)
{
	OCR1B_REG=dutyCycle;
}
void TIM1_EnableOVFInterrupt(void(*CallbackFunction)(void))
{
	TIM1_TIFR_REG->TOV1=1;
	TIM1_TIMSK_REG->TOIE1=1;
	if(CallbackFunction !=NULL)
	{
		TIM1_callBackOV_ptr=CallbackFunction;
	}
}

void TIM1_Enable_OCRA_Interrupt(void(*CallbackFunction)(void))
{

	TIM1_TIFR_REG->OCF1A=1;
	TIM1_TIMSK_REG->OCIE1A=1;

	if(CallbackFunction !=NULL)
	{
		TIM1_callBackOCRA_ptr=CallbackFunction;
	}

}
void TIM1_Enable_OCRB_Interrupt(void(*CallbackFunction)(void))
{
	TIM1_TIFR_REG->OCF1B=1;
	TIM1_TIMSK_REG->OCIE1B=1;
	if(CallbackFunction !=NULL)
	{
		TIM1_callBackOCRB_ptr=CallbackFunction;
	}
}
void TIM1_Enable_ICR_Interrupt(void(*CallbackFunction)(void))
{
	TIM1_TIFR_REG->ICF1=1;
	TIM1_TIMSK_REG->TICIE1=1;
	if(CallbackFunction !=NULL)
	{
		TIM1_callBackICR_ptr=CallbackFunction;
	}
}

void __vector_6(void) __attribute__((signal, used));
void __vector_6(void)		// TIMER1 CAPT
{
	TIM1_callBackICR_ptr();
}


void __vector_7(void) __attribute__((signal, used));
void __vector_7(void)		// TIMER1 COMPA
{
	TIM1_callBackOCRA_ptr();
}


void __vector_8(void) __attribute__((signal, used));
void __vector_8(void)		// TIMER1 COMPB
{
	TIM1_callBackOCRB_ptr();
}


void __vector_9(void) __attribute__((signal, used));
void __vector_9(void)		// TIMER1 OVF
{
	TIM1_callBackOV_ptr();
}


