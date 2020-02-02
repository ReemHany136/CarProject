/*
 * timers.h
 *
 *  Created on: Oct 22, 2019
 *      Author: Sprints
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "registers.h"
#include "gpio.h"

/*
 * User Configuration Macros
 */

#define T0_PWM_GPIO				GPIOD
#define T0_PWM_BIT				BIT0

#define T1_PWM_GPIO				GPIOD
#define T1_PWM_BIT				BIT4
#define T1_PWM1_GPIO			GPIOD
#define T1_PWM1_BIT				BIT5

#define T2_PWM_GPIO				GPIOD
#define T2_PWM_BIT				BIT5


#define TOV_T0					0
#define OCF0_T0					1
#define TOV_T1					2
#define OCFA_T1					3
#define OCFB_T1					4
#define ICF1					5
#define TOV_T2					6
#define OCF2_T2					7

#define F_CPU					16000000.0
#define _8_BIT_RESOLUTION		256
#define _16_BIT_RESOLUTION		65536
#define _PWM_RESOLUTION			100.0

/*
extern volatile uint8_t		    T0_ON_OFF_Flag,T0_SWPWM_Mode,
								T1_ON_OFF_Flag,T1_SWPWM_Mode,
								T2_ON_OFF_Flag,T2_SWPWM_Mode;*/

typedef enum En_timer0Mode_t{
	T0_NORMAL_MODE=0,T0_COMP_MODE=0x08
}En_timer0Mode_t;

typedef enum En_timer0OC_t{
	T0_OC0_DIS=0,T0_OC0_TOGGLE=0x10,T0_OC0_CLEAR=0x20,T0_OC0_SET=0x30
}En_timer0OC_t;

typedef enum En_timer0perscaler_t{
	T0_NO_CLOCK=0xF8,T0_PRESCALER_NO=0x01,T0_PRESCALER_8=0x02,T0_PRESCALER_64=0x03,T0_PRESCALER_256=0x04,T0_PRESCALER_1024=0x05
}En_timer0perscaler_t;

typedef enum En_timer0Interrupt_t{
	T0_POLLING=0,T0_INTERRUPT_NORMAL=0x01,T0_INTERRUPT_CMP=0x02
}En_timer0Interrupt_t;

typedef enum timer0_Frequency_Levels{
	FIFTH_SPEED_OVF=0,FOURTH_SPEED_OVF=64,THIRD_SPEED_OVF=128,SECOND_SPEED_OVF=192,FIRST_SPEED_OVF=245,
	FULL_SPEED_CTC=255,LOWEST_SPEED_CTC=16
	
}timer0_Frequency_Levels;



// for timer 1
typedef enum En_timer1Mode_t{
	T1_NORMAL_MODE=0x0000,T1_COMP_MODE_OCR1A_TOP=0x0008, T1_COMP_MODE_ICR1_TOP = 0x0018, T1_FAST_PWM_10BIT=0x0308, T1_PHASE_CORRECT_PWM = 0X0210

}En_timer1Mode_t;
typedef enum En_timer1OC_t{
	T1_OC1_DIS=0,T1_OC1A_TOGGLE=0x4000,T1_OC1B_TOGGLE=0x1000,T1_OC1A_CLEAR=0x8000,T1_OC1B_CLEAR=0x2000,T1_OC1A_SET=0xC000,T1_OC1B_SET=0x3000
}En_timer1OC_t;

typedef enum En_timer1perscaler_t{
	T1_NO_CLOCK=0xF8,T1_PRESCALER_NO=0x0001,T1_PRESCALER_8=0x0002,T1_PRESCALER_64=0x0003,T1_PRESCALER_256=0x0004,T1_PRESCALER_1024=0x0005
}En_timer1perscaler_t;

typedef enum En_timer1Interrupt_t{
	T1_POLLING=0,T1_INTERRUPT_NORMAL=0x04,T0_INTERRUPT_CMP_1B=0x08, T1_INTERRUPT_CMP_1A=0x10, T1_INTERRUPT_ICAPTURE = 0x20
}En_timer1Interrupt_t;




// for timer 2
typedef enum En_timer2Mode_t{
	T2_NORMAL_MODE=0,T2_COMP_MODE=0x08
}En_timer2Mode_t;

typedef enum En_timer2OC_t{
	T2_OC2_DIS=0,T2_OC2_TOGGLE=0x10,T2_OC2_CLEAR=0x20,T2_OC2_SET=0x30
}En_timer2OC_t;

typedef enum En_timer2perscaler_t{
	T2_NO_CLOCK=0xF8,T2_PRESCALER_NO=0x01,T2_PRESCALER_8=0x02, T2_PRESCALER_32=0x03, T2_PRESCALER_64=0x04, T2_PRESCALER_128=0x05, T2_PRESCALER_256 = 0x06, T2_PRESCALER_1024=0x07
}En_timer2perscaler_t;

typedef enum En_timer2Interrupt_t{
	T2_POLLING=0,T2_INTERRUPT_NORMAL=0x40,T2_INTERRUPT_CMP=0x80
}En_timer2Interrupt_t;







/*===========================Timer0 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer0Init(En_timer0Mode_t en_mode,En_timer0OC_t en_OC0,En_timer0perscaler_t en_prescal, uint8_t u8_initialValue, uint8_t u8_outputCompare, En_timer0Interrupt_t en_interruptMask);

/**
 * Description:
 * @param value
 */
void timer0Set(uint8_t u8_value);

/**
 * Description:
 * @return
 */
uint8_t timer0Read(void);

/**
 * Description:
 */
void timer0Start(void);

/**
 * Description:
 */
void timer0Stop(void);

/**
 * Description:
 * @param delay
 */
void timer0DelayMs(uint16_t u16_delay_in_ms);

/*
 * user defined
 */
void timer0DelayUs(uint32_t u32_delay_in_us);

/**
 * Description:
 * @param dutyCycle
 */
void timer0SwPWM(uint8_t u8_dutyCycle,uint8_t frequency);

void timer0PWMCalc(uint8_t u8_dutyCycle, uint8_t freq);







/*===========================Timer1 Control===============================*/
/**
 * Description:
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer1Init(En_timer1Mode_t en_mode,En_timer1OC_t en_OC,En_timer1perscaler_t en_prescal, uint16_t u16_initialValue, uint16_t u16_outputCompareA, uint16_t u16_outputCompareB,uint16_t u16_inputCapture, En_timer1Interrupt_t en_interruptMask);

/**
 * Description:
 * @param value
 */
void timer1Set(uint16_t u16_value);

/**
 * Description:
 * @return
 */
uint16_t timer1Read(void);

/**
 * Description:
 */
void timer1Start(void);

/**
 * Description:
 */
void timer1Stop(void);

/**
 * Description:
 * @param delay
 */
void timer1DelayMs(uint16_t u16_delay_in_ms);

/*
 * user defined
 */
void timer1DelayUs(uint32_t u32_delay_in_us);

/**
 * Description:
 * @param dutyCycle
 */
void timer1SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);

void timer1PWMCalc(uint8_t u8_dutyCycle, uint8_t freq);



/*===========================Timer2 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer2Init(En_timer2Mode_t en_mode,En_timer2OC_t en_OC,En_timer2perscaler_t en_prescal, uint8_t u8_initialValue, uint8_t u8_outputCompare, uint8_t u8_assynchronous, En_timer2Interrupt_t en_interruptMask);
/**
 * Description:
 * @param value
 */
void timer2Set(uint8_t u8_a_value);

/**
 * Description:
 * @return
 */
uint8_t timer2Read(void);

/**
 * Description:
 */
void timer2Start(void);

/**
 * Description:
 */
void timer2Stop(void);

/**
 * Description:
 * @param delay
 */
void timer2DelayMs(uint16_t u16_delay_in_ms);

/*
 * user defined
 */
void timer2DelayUs(uint32_t u16_delay_in_us);

/**
 * Description:
 * @param dutyCycle
 */
void timer2SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);

#endif /* TIMERS_H_ */