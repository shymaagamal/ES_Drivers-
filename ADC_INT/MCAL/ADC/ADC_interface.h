/*
 * ADC_interface.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "../../LIB/std_types.h"
#include "../../LIB/BIT_Math.h"
#include "ADC_private.h"
#include "ADC_Config.h"

void ADC_init(void);

void ADC_selectChannel(MUX channel);
uint16 ADC_read_channel(void);
void ADC_startConversionPolling(void);
void ADC_startConversionINT(void);
void ADC_setCallBack(void (*callbackPtr)(void));
#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
