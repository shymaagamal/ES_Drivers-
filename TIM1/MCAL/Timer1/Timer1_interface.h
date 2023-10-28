/*
 * Timer1_interface.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#include "Timer1_private.h"
#include "../../LIB/std_types.h"
void TIM1_WGMMood(WGMMood WGM);

void TIM1_phaseCorrectMood(COMPhaseCorrect COM);

void TIM1_NonPWMMood(COMNonPWM COM);

void TIM1_FastPWMMood(COMFastPWM COM);

void TIM1_init(void);






void TIM1_stop(void);
void TIM1_start(void);

void TIM1_setPreload(uint16 preload_Val);
uint16 TIM1_getVal(void);


void TIM1_dutyCycle(uint8 dc);
void TIM1_EnableOVFInterrupt(void(*CallbackFunction)(void));
void TIM1_Enable_OCRA_Interrupt(void(*CallbackFunction)(void));
void TIM1_Enable_OCRB_Interrupt(void(*CallbackFunction)(void));

void TIM1_Enable_ICR_Interrupt(void(*CallbackFunction)(void));

#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
