/*
 * Timer1_private.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_
/******************************************************************************************************************************************
 *												TCCR1A Register
 *****************************************************************************************************************************************/


typedef enum
{
	TIM1_NormalNONPWM,
	TIM1_ToggleOncomparematchNONPWM,
	TIM1_ClearOnCompareMatchNONPWM,
	TIM1_SetOncomparematchNONPWM,
}COMNonPWM;

typedef enum
{
	TIM1_NormalFastPWM,
	TIM1_Toggle_OC1A_OnCompareMatchFastPWM,
	TIM1_ClearOnCompareMatchFastPWM,
	TIM1_SetOnCompareMatchFastPWM,
}COMFastPWM;

typedef enum
{
	TIM1_NormalPhasePWM,
	TIM1_Toggle_OC1A_OnCompareMatchPhasePWM,
	TIM1_ClearOnCompareMatchPhasePWM,
	TIM1_SetOnCompareMatchPhasePWM,
}COMPhaseCorrect;


typedef enum
{
	TIM1_Normal,
	TIM1_PWMPhaseCorrect8bit,
	TIM1_PWMPhaseCorrect9bit,
	TIM1_PWMPhaseCorrect10bit,
	TIM1_CTC,
	TIM1_FastPWM8bit,
	TIM1_FastPWM9bit,
	TIM1_FastPWM10bit,
	TIM1_PWMPhaseandFrequencyCorrect_ICR1_TOP,
	TIM1_PWMPhaseandFrequencyCorrect_OCR1A_TOP,
	TIM1_PWMPhaseCorrect_ICR1_TOP,
	TIM1_PWMPhaseCorrect_OCR1A_TOP ,
	TIM1_CTC_ICR1_TOP,
	TIM1_FASTPWM_ICR1_TOP,
	TIM1_FASTPWM_OCR1A_TOP,
}WGMMood;

/******************************************************************************************************************************************
 *												TCCR1B Register
 *****************************************************************************************************************************************/

typedef enum
{
	TIM1_NoClockSource=0b000,
	TIM1_NoPrescaling=0b001,
	TIM1_Prescaling_8=0b010,
	TIM1_Prescaling_64=0b011,
	TIM1_Prescaling_256=0b100,
	TIM1_Prescaling_1024=0b101,
	TIM1_ClockOnFallingEdge=0b110,
	TIM1_ClockOnRisingEdge=0b111
}CS;
#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
