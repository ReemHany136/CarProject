#include "registers.h"
#include "timers.h"

#include "HwPWM.h"

static uint16_t Top,duty;
void HwPWMInit(void){
	timer1Init(T1_PHASE_CORRECT_PWM,(T1_OC1A_CLEAR|T1_OC1B_CLEAR),PWM_PRESCALE_MASK,0,duty,duty,Top,T1_POLLING);
}
void HWPWMCalcTop(uint32_t* freq){
	Top =(F_CPU/(2 * PWM_PRESCALE * (*freq)));
}
void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency){
	HWPWMCalcTop(&a_u32_frequency);
	duty = (Top * a_u8_duty/100.0);
	HwPWMInit();
	timer1Start();
}
