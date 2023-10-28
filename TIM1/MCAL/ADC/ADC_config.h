/*
 * ADC_config.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/**********************************************************************************************************
 *                                ADMUX Register
 *********************************************************************************************************/
/*
 * Voltage Reference Selection:(REF)
 * 1- AREF pin (External voltage reference) 	->	AREF_INTERNAL_VREF_Turned_off
 * 2- AVCC with external capacitor at AREF pin 	-> 	AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN
 * 3- Internal 2.56V Voltage Reference with
 * external capacitor at AREF pin				-> Internal_VREF_with_EXTERNAL_Capacitor_AT_AREF_PIN
 */
#define ADC_VOLTAGE_REFERENCE	AVCC_WITH_EXTERNAL_CAPACITOR_AT_AREF_PIN

/*
 * ADC Left Adjust Result (ADLAR)
 *  - To enable the right adjust put    (0)
 *  - To enable the left adjust put     (1)
 */
#define ADC_LEFT_ADJUST		(RightAdjustResult)


/**********************************************************************************************************
 *                                          ADCSRA Register
 *********************************************************************************************************/



/*
 * ADC Auto Trigger:(ADATE)
 * - To disable the ADC auto trigger -> put (DisableAutoTriggered)
 * - To enable the ADC auto trigger -> put (AutoTriggered)
 */
#define ADC_AUTO_TRIGGER_ENABLE		AutoTriggered


/*
 * ADC Clock Division Factors:(ADPS)
 * Clock Division Factor of 2		->	PreScaler_2
 * Clock Division Factor of 4		->	PreScaler_4
 * Clock Division Factor of 8		->	PreScaler_8
 * Clock Division Factor of 16		->	PreScaler_16
 * Clock Division Factor of 32		->	PreScaler_32
 * Clock Division Factor of 64		->	PreScaler_64
 * Clock Division Factor of 128		->	PreScaler_128
 */
#define ADC_PRESCALER_FACTOR	PreScaler_64



/**********************************************************************************************************
 *                                          SFIOR Register
 *********************************************************************************************************/

/*
 * ADC Auto Trigger Sources (Auto trigger must be enabled):(ADTS)
 * Free Running mode				->	FreeRunningMode
 * Analog Comparator				->	AnalogComparator
 * External Interrupt Request 0		->	ExternalInterruptRequest0
 * Timer/Counter0 Compare Match		->	TimerCounter0CompareMatch
 * Timer/Counter0 Overflow			->	TimerCounter0Overflow
 * Timer/Counter Compare Match B	->	TimerCounter1CompareMatchB
 * Timer/Counter1 Overflow			->	TimerCounter1Overflow
 * Timer/Counter1 Capture Event		->	TimerCounter1CaptureEvent
 */
#define	ADC_AUTO_TRIG_SOURCE	FreeRunningMode

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
