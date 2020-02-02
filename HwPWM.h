/*
 * HwPWM.h
 *
 *  Created on: Oct 28, 2019
 *      Author: Think
 */

#ifndef HWPWM_H_
#define HWPWM_H_

#include "timers.h"


/*
typedef enum Freq_Prescale_10bit{
	FreqHZ_PRESCALE_NO = 	15625, FreqHZ_PRESCALE_8 = 1953,
	FreqHZ_PRESCALE_64 = 244, FreqHZ_PRESCALE_256 = 61,
	FreqHZ_PRESCALE_1024 = 15
}Freq_Prescale_10bit;*/
#define PWM_PRESCALE  1024
#define PWM_PRESCALE_MASK T1_PRESCALER_1024

void HwPWMInit(void);
void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency);
#endif /* HWPWM_H_ */
