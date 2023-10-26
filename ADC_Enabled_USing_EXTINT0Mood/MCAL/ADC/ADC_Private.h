/*
 * ADC_Private.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/**********************************************************************************************************
 *                                ADMUX Register
 *********************************************************************************************************/
/*Reference Selection Bit*/
typedef enum
{
	AREF_INTERNAL_VREF_Turned_off=0b00,
	AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN=0b01,
	Internal_VREF_with_EXTERNAL_Capacitor_AT_AREF_PIN=0B11

}REF;

/*ADC Left Adjust Result Bit*/
typedef enum
{
	RightAdjustResult=0,
	LeftAdjustResult=1
}ADLAR;


/**********************************************************************************************************
 *                                          ADCSRA Register
 *********************************************************************************************************/
/*ADC Prescaler Selection*/
typedef enum
{
	PreScaler_2=0b001,
	PreScaler_4=0b010,
	PreScaler_8=0b011,
	PreScaler_16=0b100,
	PreScaler_32=0b101,
	PreScaler_64=0b110,
	PreScaler_128=0b111
}ADPS;

/*ADC Interrupt Enable*/
typedef enum
{
	disable_INT=0,
	EN_INT=1
}ADIE;

/*ADC Auto Trigger Enable*/
typedef enum
{
	DisableAutoTriggered=0,
	AutoTriggered=1
}ADATE;


/*ADC Start Conversion*/
typedef enum
{
	Stop=0,
	startConversion=1,

}ADSC;



/**********************************************************************************************************
 *                                          SFIOR Register
 *********************************************************************************************************/

/*ADC Auto Trigger Source*/
typedef enum
{
	FreeRunningMode=0b000,
	AnalogComparator=0b001,
	ExternalInterruptRequest0=0b010,
	TimerCounter0CompareMatch=0b011,
	TimerCounter0Overflow=0b100,
	TimerCounter1CompareMatchB=0b101,
	TimerCounter1Overflow=0b110,
	TimerCounter1CaptureEvent=0b111
}ADTS;



#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
