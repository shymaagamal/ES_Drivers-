/*
 * Timer_interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_TIMER0_TIMER_INTERFACE_H_
#define MCAL_TIMER0_TIMER_INTERFACE_H_
#include "../../LIB/std_types.h"

void TIM0_init(void);
void TIM0_stop(void);
void TIM0_start(void);
void TIM0_setPreload(uint8 preload_Val);
uint8 TIM0_getVal(void);
void delay_ms(uint8 msec);
void TIM0_EnableOVFInterrupt(void(*CallbackFunction)(void));
void TIM0_EnableCOMInterrupt(void(*CallbackFunction)(void));
#endif /* MCAL_TIMER0_TIMER_INTERFACE_H_ */
