#include "std_types.h"
#include "utilities.h"
#include "registers.h"
#include "gpio.h"
#include "timers.h"
#include "SwICU.h"
#include "softwareDelay.h"
#include "led.h"
#include "pushButton.h"
#include "sevenSeg.h"
#include "dcMotor.h"
#include "interrupts.h"
#include "ultraSonic.h"

void ultrasonic_DistanceInLeds(void);

int main(void)
{
	uint8_t distance;
	Led_Init(LED_0);
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	ultraSonic_Init();
	ultraSonic_Enable();
	MotorDC_Init(MOT_1);
	MotorDC_Init(MOT_2);
	
// 	MotorDC_Speed_HwPWM(70);
// 	
	while(1){
		
		
		ultrasonic_DistanceInLeds();
		distance = ultraSonic_CalcDistance();
		if (distance!=-1)
		{
			
			if(distance<=15){
				gpioPinWrite(GPIOB,BIT4|BIT5|BIT6|BIT7,distance<<4);
				if(distance<=5){
					MotorDC_Dir(MOT_1,STOP);
					MotorDC_Dir(MOT_2,STOP);
				}
				else{
					MotorDC_Dir(MOT_1,FORWARD);
					MotorDC_Dir(MOT_2,FORWARD);
					MotorDC_Speed_HwPWM(30);
				}
				//Led_On(LED_0);
			}
			else{
				gpioPinWrite(GPIOB,BIT4|BIT5|BIT6|BIT7,15<<4);
				//Led_On(LED_1);
			}
		}
		timer2DelayMs(70);		
		/*distance = ultraSonic_CalcDistance();
		if(distance != -1){
			if(distance<=5){
				MotorDC_Dir(MOT_1,STOP);
				MotorDC_Dir(MOT_2,STOP);
			}
			else{
				MotorDC_Dir(MOT_1,FORWARD);
				MotorDC_Dir(MOT_2,FORWARD);
				MotorDC_Speed_HwPWM(30);
			}
		}
		
		timer2DelayMs(70);*/
	}
}
void ultrasonic_DistanceInLeds(void){
	uint8_t distance;
	distance = ultraSonic_CalcDistance();
	if (distance!=-1)
	{
		
		if(distance<=15){
			gpioPinWrite(GPIOB,BIT4|BIT5|BIT6|BIT7,distance<<4);
			//Led_On(LED_0);
		}
		else{
			gpioPinWrite(GPIOB,BIT4|BIT5|BIT6|BIT7,15<<4);
			//Led_On(LED_1);
		}
	}
	timer2DelayMs(70);
}
