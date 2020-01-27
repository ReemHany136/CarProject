#include "gpio.h"
#include "softwareDelay.h"
#include "pushButtonConfig.h"
#include "pushButton.h"


void pushButtonInit(En_buttonId_t en_butotn_id){
	switch(en_butotn_id){
		case BTN_0:
			
			gpioPinDirection(BTN_0_GPIO , BTN_0_BIT ,INPUT);
			gpioPinWrite(BTN_0_GPIO, BTN_0_BIT ,HIGH);
			
			break;
		case BTN_1:
			gpioPinDirection( BTN_1_GPIO , BTN_1_BIT , INPUT );
			gpioPinWrite( BTN_1_GPIO , BTN_1_BIT , HIGH );
			break;
		case BTN_2:
			gpioPinDirection(BTN_2_GPIO, BTN_2_BIT ,INPUT);
			gpioPinWrite(BTN_2_GPIO, BTN_2_BIT ,HIGH);
			break;
		case BTN_3:
			gpioPinDirection(BTN_3_GPIO ,BTN_3_BIT ,INPUT);
			gpioPinWrite(BTN_3_GPIO ,BTN_3_BIT ,HIGH);
			break;
	}
}
En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id){
	softwareDelayMs(50);
	switch(en_butotn_id){
		case BTN_0:
		if (gpioPinRead(BTN_0_GPIO,BTN_0_BIT)==0)
		{
			return Pressed;
		}
		else{
			return Released;
		}
		break;
		case BTN_1:
		if(gpioPinRead(BTN_1_GPIO,BTN_1_BIT)==0)
		{
			return Pressed;
		}
		else{
			return Released;
		}
		break;
		case BTN_2:
		if(gpioPinRead(BTN_2_GPIO,BTN_2_BIT)==0)
		{
			return Pressed;
		}
		else{
			return Released;
		}
		break;
		case BTN_3:
		if(gpioPinRead(BTN_3_GPIO,BTN_3_BIT)==0)
		{
			return Pressed;
		}
		else{
			return Released;
		}
		break;
	}
}
