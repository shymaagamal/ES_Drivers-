/*
 * Timer1_config.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_TIMER1_TIMER1_CONFIG_H_
#define MCAL_TIMER1_TIMER1_CONFIG_H_

#include "Timer1_private.h"
#define TIM1_NONPWM 				1

#define TIM1_PHASE_CORRECT		    0

#define TIM1_FAST_PWM			    0



#define  TIM1_NONPWM_MOOD			TIM1_NormalNONPWM

#define  TIM1_PHASE_CORRECT_MOOD    TIM1_Toggle_OC1A_OnCompareMatchPhasePWM

#define  TIM1_FAST_PWM_MOOD			TIM1_ClearOnCompareMatchFastPWM

#define TIM1_WGM_MOOD				TIM1_Normal


#define TIM1_Prescaler	TIM1_Prescaling_64

#endif /* MCAL_TIMER1_TIMER1_CONFIG_H_ */
