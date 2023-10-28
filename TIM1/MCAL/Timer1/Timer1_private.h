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
	NormalNONPWM,
	ToggleOncomparematchNONPWM,
	ClearOnCompareMatchNONPWM,
	SetOncomparematchNONPWM,
}COMNonPWM;

typedef enum
{
	NormalFastPWM,
	ToggleOnCompareMatchFastPWM,
	ClearOnCompareMatchFastPWM,
	SetOnCompareMatchNONPWM,
}COMFastPWM;

typedef enum
{
	NormalPhasePWM,
	ToggleOnCompareMatchPhasePWM,
	ClearOnCompareMatchPhasePWM,
	SetOnCompareMatchPhasePWM,
}COMPhaseCorrect;




#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
