/*
 * ADC_program.c
 *
 *  Created on: Oct 24, 2023
 *      Author: Shaimaa Gamal
 */


#include "ADC_interface.h"

void (*callback_Ptr_ADC_INT)(void)=NULL;

void ADC_init()
{
	ADMUX_REG->REF=AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN; /*REF Mood*/

	ADMUX_REG->ADLAR=RightAdjustResult;  /*Left Adjust Result Mood*/

	ADCSRA_REG->ADPS=PreScaler_128;     /*ADC Prescaler Select Bit*/

	ADCSRA_REG->ADEN=ADC_EN;            /*ADC Enable*/

	ADCSRA_REG->ADIE=disable_INT;               /*ADC Interrupt Enable */

	ADCSRA_REG->ADATE=AutoTriggered;  /*ADC Auto Trigger Enable*/

	SFIOR_REG->ADTS=ExternalInterruptRequest0;      /*ADC Auto Trigger Source*/

}

void ADC_selectChannel(MUX channel)
{
	ADMUX_REG->MUX=channel;
}

uint16 ADC_read_channel(void)
{
	return ADC_DATA_REG;
}
void ADC_startConversionPolling()
{
	ADCSRA_REG->ADSC=startConversion;
	while(ADCSRA_REG->ADSC == 1);
}

void ADC_startConversionINT()
{
	ADCSRA_REG->ADSC=startConversion;



}
void ADC_setCallBack(void (*callbackPtr)(void))
{
	ADCSRA_REG->ADIF=1;
	ADCSRA_REG->ADIE=EN_INT;
	if(callback_Ptr_ADC_INT != NULL)
	{
		callback_Ptr_ADC_INT = callbackPtr;
	}
	ADCSRA_REG->ADSC = 1;

}
void __vector__16(void)__attribute__((signal));
void __vector__16()
{
	if(callback_Ptr_ADC_INT !=NULL)
	{
		callback_Ptr_ADC_INT();
	}
}
