#include "gpio.h"
#include "timers.h"
#include "sevenSegConfig.h"
#include "sevenSeg.h"


/**
 * Description: 
 * @param 
 */
void sevenSegInit(En_SevenSegId_t a_segment_id){
	switch(a_segment_id){
		case SEG_0:
		gpioPinDirection(SEG_EN1_GPIO,SEG_EN1_BIT,OUTPUT);
		break;
		case SEG_1:
		gpioPinDirection(SEG_EN2_GPIO,SEG_EN2_BIT,OUTPUT);
		break;
	}
	gpioPinDirection(SEG_BCD_GPIO,SEG_BCD_BITS,OUTPUT);
}

/**
 * Description: 
 * @param 
 */
void sevenSegEnable(En_SevenSegId_t en_segment_id){
	switch(en_segment_id){
		case SEG_0:
		gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,HIGH);
		break;
		case SEG_1:
		gpioPinWrite(SEG_EN2_GPIO,SEG_EN2_BIT,HIGH);
		break;
	}

}

/**
 * Description: 
 * @param 
 */
void sevenSegDisable(En_SevenSegId_t en_segment_id){
	switch(en_segment_id){
		case SEG_0:
		gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,LOW);
		break;
		case SEG_1:
		gpioPinWrite(SEG_EN2_GPIO,SEG_EN2_BIT,LOW);
		break;
	}
}

/**
 * Description: 
 * @param 
 */
void sevenSegWrite(En_SevenSegId_t en_segment_id, uint8_t u8_number){
	if(u8_number<10)
	{
 		switch(en_segment_id){
 			case SEG_0:
 			
 			sevenSegDisable(SEG_1);
			sevenSegEnable(SEG_0);
 			break;
 			case SEG_1:
			sevenSegDisable(SEG_0);
 			sevenSegEnable(SEG_1);
 			
 			break;
 		}
	
		gpioPinWrite(SEG_BCD_GPIO,SEG_BCD_BITS,(u8_number));
	}
	
}
/**
 * Description: 
 * @param 
 */
void sevenSegWrite2Numbers(uint8_t u8_number){
	if(u8_number<100){
		uint8_t units,tenth;
		units = u8_number%10;
		tenth = u8_number/10;
		sevenSegWrite(SEG_0,units);
		timer1DelayMs(1);
		sevenSegWrite(SEG_1,tenth);
		//timer1DelayMs(1);
		
		
	}
}