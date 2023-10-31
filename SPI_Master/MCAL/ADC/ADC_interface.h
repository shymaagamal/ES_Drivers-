/*
 * ADC_interface.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_
#include "../../LIB/BIT_Math.h"
#include"../../LIB/std_types.h"
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

}ADC_channel;

void ADC_init(void);


void ADC_selectChannel(ADC_channel Channel);

void ADC_startConversionPollingMode(void);

void ADC_startConversion(void);
uint16 ADC_readChannel(void);

void ADC_setCallBackFunction(void (*callBackPtr)(void));

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
