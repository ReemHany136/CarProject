
#include "gpio.h"
#include "timers.h"
#include "dcMotorConfig.h"
#include "dcMotor.h"

/**
 * Description: 
 * @param
 */
void MotorDC_Init(En_motorType_t en_motor_number){
	#if SWPWM_MODE == ENABLE
		#if SW_PWM_TIMER == TIM_0
		timer0Init(T1_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_64,0,0,T0_INTERRUPT_NORMAL);
		#elif SW_PWM_TIMER == TIM_1
		timer1Init(T1_NORMAL_MODE,T1_OC1_DIS,T1_PRESCALER_64,0,0,0,0,T1_INTERRUPT_NORMAL);
		#elif SW_PWM_TIMER == TIM_2
		timer2Init(T2_NORMAL_MODE,T2_OC2_DIS,T2_PRESCALER_64,0,0,0,T2_INTERRUPT_NORMAL);
		#endif	
	#endif
	switch(en_motor_number){
		case MOT_1:
		gpioPinDirection(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,OUTPUT);
			
		gpioPinDirection(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,OUTPUT);
		gpioPinDirection(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,OUTPUT);
		break;
		
		case MOT_2:
		gpioPinDirection(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,OUTPUT);
			
		gpioPinDirection(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,OUTPUT);
		gpioPinDirection(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,OUTPUT);
		break;
	}
}

/**
 * Description: 
 * @param 
 * @param 
 */
void MotorDC_Dir(En_motorType_t en_motor_number, En_motorDir_t en_motor_dir){
	switch(en_motor_number){
		case MOT_1:
		switch(en_motor_dir){
			case FORWARD:
			gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
			gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
			break;
			case BACKWARD:
			gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
			gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);
			break;
			case STOP:
			gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
			gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
			break;
		}
		
		
		break;
		
		case MOT_2:
		
		switch(en_motor_dir){
			case FORWARD:
			gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
			gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
			break;
			case BACKWARD:
			gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
			gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);
			break;
			case STOP:
			gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
			gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
			break;
		}
		break;
	}
}

/**
 * Description: 
 * @param 
 */
void MotorDC_Speed_PollingWithT0(uint8_t u8_motor_speed){
	#if SW_PWM_TIMER == TIM_0
	timer0SwPWM(u8_motor_speed,MOTOR_FREQ);
	#elif SW_PWM_TIMER == TIM_1
	timer1SwPWM(u8_motor_speed,MOTOR_FREQ);
	#elif SW_PWM_TIMER == TIM_2
	timer2SwPWM(u8_motor_speed,MOTOR_FREQ);
	#endif
	
}

/**
 * Description: set the port value (which is PORT register)
 * @param 
 */
void MotorDC_Speed_HwPWM(uint8_t u8_motor_speed);