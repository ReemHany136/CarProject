/*
 * MotorDC.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Sprints
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "dcMotorConfig.h"
#include "timers.h"

#define MOTOR_FREQ   100

#define ENABLE         1
#define DISABLE        0

#define SWPWM_MODE     ENABLE

#define	TIM_0          0
#define	TIM_1          1
#define	TIM_2          2

#define SW_PWM_TIMER   TIM_1	

typedef enum En_motorType_t{
	MOT_1,
	MOT_2
}En_motorType_t;

typedef enum En_motorDir_t{
	STOP,
	FORWARD,
	BACKWARD
}En_motorDir_t;

/**
 * Description: 
 * @param
 */
void MotorDC_Init(En_motorType_t en_motor_number);

/**
 * Description: 
 * @param 
 * @param 
 */
void MotorDC_Dir(En_motorType_t en_motor_number, En_motorDir_t en_motor_dir);

/**
 * Description: 
 * @param 
 */
void MotorDC_Speed_PollingWithT0(uint8_t u8_motor_speed);

/**
 * Description: set the port value (which is PORT register)
 * @param 
 */
void MotorDC_Speed_HwPWM(uint8_t u8_motor_speed);
#endif /* MOTORDC_H_ */