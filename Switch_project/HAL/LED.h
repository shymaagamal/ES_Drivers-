
/***************************************************************************************************/
/*                                       Application.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: some projects using GPIO Driver
 ***************************************************************************************************/

#ifndef APPLICATION_H_
#define APPLICATION_H_


#define DISPLAY_ON_SEG1 1

#include "../MCAL/GPIO/GPIO_Config.h"
#include <util/delay.h>



void setup_LED_Direction(void);
void LED_ON(uint8 port_id,uint8 pin_num);
void LED_OFF(uint8 port_id,uint8 pin_num);

#endif /* APPLICATION_H_ */
