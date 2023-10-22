/*
 * Switch.C
 *
 *  Created on: Oct 22, 2023
 *      Author: Shaimaa Gamal
 */


#include "Switch.h"
#include "../MCAL/GPIO/GPIO_Config.h"
void SWITCH_init()
{
	GPIO_SetupPin_Direction(PORTD_ID,PD7,PIN_INPUT);
	GPIO_SetupPin_Direction(PORTD_ID,PD6,PIN_INPUT);
	GPIO_SetupPin_Direction(PORTD_ID,PD5,PIN_INPUT);
	GPIO_SetupPin_Direction(PORTD_ID,PD3,PIN_INPUT);


}
