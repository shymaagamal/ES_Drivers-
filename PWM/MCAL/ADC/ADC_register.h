/*
 * ADC_register.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Shaimaa Gamal
 */

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_




/**********************************************************************************************************
 *                                ADMUX Register
 *********************************************************************************************************/
typedef struct
{
	uint8 MUX:5;
	uint8 ADLAR:1;
	uint8 REF:2;
}ADMUX;
#define ADMUX_REG   ((volatile ADMUX *) 0X27)


/**********************************************************************************************************
 *                                          ADCSRA Register
 *********************************************************************************************************/
typedef struct
{
	uint8 ADPS:3;
	uint8 ADIE:1;
	uint8 ADIF:1;
	uint8 ADATE:1;
	uint8 ADSC:1;
	uint8 ADEN:1;

}ADCSRA;
#define ADCSRA_REG   ((volatile ADCSRA *) 0X26)



/**********************************************************************************************************
 *                                          ADCL-ADCH Register
 *********************************************************************************************************/
#define ADCL_REG       *((volatile uint8*) 0X24)
#define ADCH_REG       *((volatile uint8*) 0X25)
#define ADC_DATA_REG   *((volatile uint16*) 0X24)

/**********************************************************************************************************
 *                                          SFIOR Register
 *********************************************************************************************************/

typedef struct
{
	uint8 :5;
	uint8 ADTS:3;

}SFIOR;
#define SFIOR_REG   ((volatile SFIOR *) 0X50)

#endif /* MCAL_ADC_ADC_REGISTER_H_ */
