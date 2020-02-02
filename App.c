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
	
	while(1){
		
		/*Calulating the distance*/
		distance = ultraSonic_CalcDistance();
		/*If the distance is updated or not*/
		if (distance!=-1)
		{
			
			/*In case the distance is smaller than 15 cm it will be viewed on the 4 Leds*/
			if(distance<=15){
				/*Show the distance in 4 leds*/
				gpioPinWrite(GPIOB,BIT4|BIT5|BIT6|BIT7,distance<<4);
				
				/*In case the distance is less than or equal 5 cm the car will stop*/
				if(distance<=5){
					MotorDC_Dir(MOT_1,STOP);
					MotorDC_Dir(MOT_2,STOP);
				}
				/*In case the distance is greater than 5 cm the car will move in duty cycle 30%*/
				else{
					MotorDC_Dir(MOT_1,FORWARD);
					MotorDC_Dir(MOT_2,FORWARD);
					/*The car moves with 30 % duty cycle by the hardware pwm (phase correct pwm)*/
					MotorDC_Speed_HwPWM(30);
				}
			}
			/*In case the distance is greater than 15 cm the 4 Leds will be on*/
			else{
				gpioPinWrite(GPIOB,BIT4|BIT5|BIT6|BIT7,15<<4);
			}
		}
		/*Delay 70 ms between every distance measure*/
		timer2DelayMs(70);		
		
	}
}
void ultrasonic_DistanceInLeds(void){
	uint8_t distance;
	distance = ultraSonic_CalcDistance();
	if (distance!=-1)
	{
		
		if(distance<=15){
			gpioPinWrite(GPIOB,BIT4|BIT5|BIT6|BIT7,distance<<4);
		}
		else{
			gpioPinWrite(GPIOB,BIT4|BIT5|BIT6|BIT7,15<<4);
		}
	}
	timer2DelayMs(70);
}
