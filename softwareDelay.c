#include "softwareDelay.h"

void softwareDelayMs(uint32_t u32_delay_in_ms){
	uint32_t i=0;
	volatile uint32_t k=0;
	for(i=0;i<(u32_delay_in_ms*115)/4;i++){	
		k++;
	}
}