/*
 * ADC_program.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Shaimaa Gamal
 */


#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_Private.h"
#include "ADC_register.h"

/** ======================= Defining global variables ======================= */
void (*ADC_callBack_ptr)(void) = NULL;
/** ========================================================================= */

void ADC_init(void)
{
	/* Set the ADC VREF */
	ADMUX_REG->REF=ADC_VOLTAGE_REFERENCE;


	/* Enable/Disable the ADC left adjust */
#if	(ADC_LEFT_ADJUST == 1)
	ADMUX_REG->ADLAR = LeftAdjustResult;
#else
	ADMUX_REG->ADLAR = RightAdjustResult;
#endif

	/* Enable/Disable the ADC Auto trigger mode (ADATE)*/
#if (ADC_AUTO_TRIGGER_ENABLE == AutoTriggered)
	/* Enable the ADC Auto trigger mode */
	ADCSRA_REG->ADATE = AutoTriggered;

	/* Set the Auto trigger mode source (ADTS)*/
	SFIOR_REG->ADTS = ADC_AUTO_TRIG_SOURCE;

#else
	ADCSRA_REG->ADATE = DisableAutoTriggered;
#endif

	/* Set the ADC clock division */
	ADCSRA_REG->ADPS = ADC_PRESCALER_FACTOR;

	/* Enable the ADC */

	ADCSRA_REG->ADEN = 1;
}


void ADC_selectChannel(ADC_channel Channel)
{
	/* Set the channel selection */
	ADMUX_REG->MUX = Channel;
}

void ADC_startConversionPollingMode(void)
{
	/* Make sure the ADC Interrupt is disabled */
	if(ADCSRA_REG->ADIE == 1)
	{
		ADCSRA_REG->ADIF = 1;	// Clear the ADC Interrupt flag (ADIF)
		ADCSRA_REG->ADIE = 0;	// Clear ADIE
	}

	/* Start the ADC conversion */
	ADC_startConversion();
	/* Poll for the ADC conversion */
	while(ADCSRA_REG->ADSC == startConversion);
}

void ADC_startConversion(void)
{
	/* Start the ADC conversion */
	ADCSRA_REG->ADSC = startConversion;
}

uint16 ADC_readChannel(void)
{
#if	(ADC_LEFT_ADJUST == 1)
	uint16 data=0;
	data = (ADCL_REG >> 6);
	data |= (ADCH_REG << 2);
	return data;
#else
	return ADC_DATA_REG;
#endif
}
void ADC_setCallBackFunction(void (*callBackPtr)(void))
{
	ADCSRA_REG->ADIF=1;
	ADCSRA_REG->ADIE=1;
	if(callBackPtr != NULL)
	{
		ADC_callBack_ptr = callBackPtr;
	}
	ADC_startConversion();
}

/** ===================== ADC ISRs Implementation ========================== */
/* ADC Conversion Complete ISR */
void __vector_16(void)	__attribute__((signal, used));
void __vector_16(void)
{
	if(ADC_callBack_ptr != NULL)
	{
		ADC_callBack_ptr();
	}
}

