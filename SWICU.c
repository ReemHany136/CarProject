#include "utilities.h"
#include "interrupts.h"
#include "timers.h"
#include "gpio.h"
#include "SWICU_Config.h"
#include "SwICU.h"
#include "led.h"

static volatile uint8_t  EdgeFlag = FALSE;
static volatile uint8_t no_of_counts=0;

volatile uint8_t ReadingFlag = FALSE;

_ISR__(INT2_vect){
	
	
	if(EdgeFlag == TRUE){
		//Led_Off(LED_0);
		/*MCUCSR &= ~(1<<6);
		EdgeFlag=FALSE;*/
		SwICU_SetCfgEdge(SwICU_Edgefalling);
		ReadingFlag =FALSE;
		SwICU_Start();
		
	}
	else{
		//Led_On(LED_0);
		SwICU_SetCfgEdge(SwICU_EdgeRisiging);
		/*MCUCSR |= 1<<6;
		EdgeFlag=TRUE;*/
		SwICU_Stop();
		no_of_counts =timer0Read();
		ReadingFlag =TRUE;
		timer0Set(0);
	}
	
}

void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge){
	#if SW_ICU_TIMER == TIM_0
		timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_256,0,0,T0_POLLING);
	#endif
	
	gpioPinDirection(DEI_ICU_PORT,DEI_ICU_PIN,INPUT);
	gpioPinWrite(DEI_ICU_PORT,DEI_ICU_PIN,HIGH);
	
	#if DEI_ICU == INT_2

		EdgeFlag = TRUE;
		set_bit(GICR,5);
		set_bit(MCUCSR,INT2_BIT);//interrupt with the rising edge
	#endif
	EN_GLOBAL_INT;
	
	
}

void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdgeedge){
	switch(a_en_inputCaptureEdgeedge){
		case  SwICU_Edgefalling:
		EdgeFlag = FALSE;
		clr_bit(MCUCSR,INT2_BIT);//interrupt with the falling edge
		break;
		case SwICU_EdgeRisiging:
		EdgeFlag = TRUE;
		set_bit(MCUCSR,INT2_BIT);//interrupt with the rising edge
		break;
	}
}
void SwICU_Read(volatile uint8_t * a_pu8_capt){
	#if SW_ICU_TIMER == TIM_0
	(*a_pu8_capt)= no_of_counts;
	#endif
}
void SwICU_Stop(void){
	#if SW_ICU_TIMER == TIM_0
		timer0Stop();
	#endif
}
void SwICU_Start(void){
	#if SW_ICU_TIMER == TIM_0
		timer0Start();
	#endif
}
