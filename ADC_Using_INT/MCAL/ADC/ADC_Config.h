/*
 * ADC_Config.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_



/**********************************************************************************************************
 *                                ADMUX Register
 *********************************************************************************************************/

/*Reference Selection Bit*/
typedef enum
{
	AREF_INTERNAL_VREF_Turned_off=0b00,
	AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN=0b01,
	RESERVE=0b00,
	Internal_VREF_with_EXTERNAL_Capacitor_AT_AREF_PIN=0B11

}REF;

/*ADC Left Adjust Result Bit*/
typedef enum
{
	RightAdjustResult=0,
	LeftAdjustResult=1
}ADLAR;

/*Analog Channel and gain selection bit*/
typedef enum
{
	ADC0=0b00000,
	ADC1=0b00001,
	ADC2=0b00010,
	ADC3=0b00011,
	ADC4=0b00100,
	ADC5=0b00101,
	ADC6=0b00110,
	ADC7=0b00111,

}MUX;

/**********************************************************************************************************
 *                                          ADCSRA Register
 *********************************************************************************************************/
/*ADC Prescaler Selection*/
typedef enum
{
	PreScaler_2=0b000,
	PreScaler_two=0b001,
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
	StopAutoTriggered=0,
	AutoTriggered=1
}ADATE;


/*ADC Start Conversion*/
typedef enum
{
	Stop=0,
	startConversion=1,

}ADSC;

/*ADC Enable*/
typedef enum
{
	ADC_DisAble=0,
	ADC_EN=1

}ADEN;

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




#endif /* MCAL_ADC_ADC_CONFIG_H_ */
