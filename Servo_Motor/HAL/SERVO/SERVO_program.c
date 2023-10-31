/** ========================= The file information ========================== */
/**
 *  Project		: AVR_ATmega32_Driver
 * 	File name	: SERVO_program.h
 *  Created on	: Oct 28, 2023
 *  Author		: ENG. Mahmoud Sayed
 **/
/** ========================================================================= */




/** ================================= Notes ================================= */
/*
	 * The whole cycle time = 20 ms.
	 * The ON time is between 750 us and 2500 us.
	 * 750 us  -> -90 Degree
	 * 2500 us -> 90 Degrees
	 *
	 * Mapping the angle value and the T_ON value will be:
	 * T_ON (in us) = (Angle * ((2500 - 750) / 180)) + 750
	 *
	 * To get the number of ticks for the required ON time:
	 * NO_of_ticks = T_ON (in us)/tick_time (in us)
	 *
	 * The TOP will be calculated as:
	 * TOP = 20,000 / tick_time (in us)
	 * */
/** ========================================================================= */




/** =========================== All Included Files ========================== */
#include "../../LIB/BIT_Math.h"
#include "../../LIB/std_types.h"
#include "SERVO_config.h"
#include "SERVO_interface.h"

#include "../../MCAL/TIM1/TIM1_interface.h"
#include"../../MCAL/TIM1/TIM1_config.h"
#include"../../MCAL/TIM1/TIM_registers.h"
/** ========================================================================= */




/** ==================== Servo Functions Implementation ===================== */
void HAL_SERVO_Init(void)
{
	/* Initialize the Timer 1 */
	MCAL_TIM1_SetTimerCompareMode(TIM1_FAST_PWM_MODE_OC1A_NON_INVERTED);
	GPIO_SetupPin_Direction(OC1A_PIN, PIN_OUTPUT);

	/* Prepare the Servo motor to be moved to its reference position */
	MCAL_TIM1_SetCompareValue(OC1A, 999);// Compare match set to zero
	ICR1 = 40000;     // TOP (40,000 * tick time = 20 ms)

	/* Start the timer 1 */
	MCAL_TIM1_EnableTimer();

}


void HAL_SERVO_SetAngle(uint16 Copy_Angle)
{
	/* Equation (Mapping) */
    // 750 us  -> 0 degree    -> 1500
    // 2500 us -> 180 degrees -> 5000

	/* Set the new position to the servo motor (by changing the output compare value) */
	MCAL_TIM1_SetCompareValue(OC1A, Copy_Angle);
}
/** ========================================================================= */

