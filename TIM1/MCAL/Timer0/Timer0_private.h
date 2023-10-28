/*
 * Timer_private.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_TIMER0_TIMER_PRIVATE_H_
#define MCAL_TIMER0_TIMER_PRIVATE_H_
#include "../../LIB/std_types.h"
#include "../../LIB/BIT_Math.h"
/***********************************************************************************************
 *										TCCR0 Register
 **********************************************************************************************/

typedef enum
{
	NoClockSource=0b000,
	NoPrescaling=0b001,
	Prescaling_8=0b010,
	Prescaling_64=0b011,
	Prescaling_256=0b100,
	Prescaling_1024=0b101,
	ClockOnFallingEdge=0b110,
	ClockOnRisingEdge=0b111
}CS;

typedef enum
{
	NormalOC0DisconnectedNONPWM=0b00,
	ToggleOC0OnCompareMatchNONPWM=0b01,
	ClearOC0OnCompareMatchNONPWM=0b10,
	SetOC0OnCompareMatchNONPWM=0b11,
}COMNonPWM;

typedef enum
{
	NormalPortOperationOC0DisconnecteFastPWM=0b00,
	ClearOnCompareMatchFastPWM=0b10,
	SetOnCompareMatchFastPWM=0b11,

}COMFastPWMMode;

typedef enum
{
	NormalPortOperationOC0DisconnectedPhaseCorrect=0b00,
	ClearOC0oncomparePhaseCorrect=0b10,
	SetOC0OnComparePhaseCorrect=0b11,

}COMPhaseCorrectPWMMode;



#endif /* MCAL_TIMER0_TIMER_PRIVATE_H_ */
