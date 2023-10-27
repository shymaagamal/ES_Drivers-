/*
 * Timer_private.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_
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
	NormalOC0Disconnected=0b00,
	ToggleOC0OnCompareMatch=0b01,
	ClearOC0OnCompareMatch=0b10,
	SetOC0OnCompareMatch=0b11,
}COMNonPWM;

typedef enum
{
	NormalPortOperationOC0Disconnecte=0b00,
	ClearOnCompareMatch=0b10,
	SetOnCompareMatch=0b11,

}COMFastPWMMode;

typedef enum
{
	NormalPortOperationOC0Disconnected=0b00,
	ClearOC0oncompare=0b10,
	SetOC0OnCompare=0b11,

}COMPhaseCorrectPWMMode;



#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
