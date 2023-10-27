/***************************************************************************************************/
/*                                       GPIO_Program.h
 *                                       Date: Oct 20, 2023
 *                                       Author: Shaimaa Gamal
 *                                       Description: Defining of Functions
 ***************************************************************************************************/


#include "GINT_Config.h"



void GINT_Enable()
{
	SET_BIT(SREG_REG,SREG_I_BIT);
}
void GINT_Disable()
{
	CLEAR_BIT(SREG_REG,SREG_I_BIT);
}
