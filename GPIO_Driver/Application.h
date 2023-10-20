
/***************************************************************************************************/
/*                                       Application.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: some projects using GPIO Driver
 ***************************************************************************************************/

#ifndef APPLICATION_H_
#define APPLICATION_H_


#define DISPLAY_ON_SEG1 1

#include "GPIO_Config.h"
#include <util/delay.h>

/*Set direction for pins of 7seg to be output*/
void sevenSeg_setPin_direction(void);

/*there are four 7SEG so this function Controls which 7seg will display number */
void sevenSeg_DisplayNum(uint8 sevenSeg_for_display_num);

/*responsible for displaying number that user enter on specific 7seg*/
void sevenSeg_Display(uint8 num, uint8 sevenSeg_for_display_num);

void setup_LED_Direction(void);
void LED_ON(void);

#endif /* APPLICATION_H_ */
