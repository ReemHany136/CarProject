#include "timers.h"
#include "SwICU.h"
#include "ultraSonic.h"
#include "led.h"

 void ultraSonic_Init(void){
	 SwICU_Init(SwICU_EdgeRisiging);
	 gpioPinDirection(TRIGGER_PORT,TRIGGER_PIN,OUTPUT);
 }
 void ultraSonic_Enable(void){
	
	 gpioPinWrite(TRIGGER_PORT,TRIGGER_PIN,HIGH);
	 timer2DelayMs(1);
	 gpioPinWrite(TRIGGER_PORT,TRIGGER_PIN,LOW);
 }
 int ultraSonic_CalcDistance(void){
	 uint8_t time_counts,Distance;
	 uint16_t time_;
	 if (ReadingFlag)
	 {
		 ultraSonic_Enable();
		 SwICU_Read(&time_counts);
		 /*if(time_counts>0)
		 Led_On(LED_0);
		 else{
			 Led_Off(LED_0);
		 }*/
		 time_ = (256/16)*time_counts;
		 
		 Distance = time_/58; 
		 return Distance;
	 }
	
	 return -1;
	
 }