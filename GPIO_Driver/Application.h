
/***************************************************************************************************/
/*                                       Application.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: some projects using GPIO Driver
 ***************************************************************************************************/

#ifndef APPLICATION_H_
#define APPLICATION_H_

#define PB0 0
#define PB1 1
#define PB2 2
#define PB4 4
#define PB5 5
#define PB6 6

#define PA2 2
#define PA3 3
#define DISPLAY_ON_SEG1 1
#include "GPIO_Config.h"



void sevenSeg_setPin_direction(void);
void sevenSeg_Display(uint8 num, uint8 sevenSeg_for_display_num);

#endif /* APPLICATION_H_ */
