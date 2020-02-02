/*
 * SwICU.h
 *
 *  Created on: Oct 27, 2019
 *      Author: Sprints
 */

#ifndef SWICU_H_
#define SWICU_H_

#include "interrupts.h"
#include "timers.h"
	

extern volatile uint8_t ReadingFlag;

typedef enum EN_SwICU_Edge_t{
	SwICU_Edgefalling,
	SwICU_EdgeRisiging
}EN_SwICU_Edge_t;

void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge);//init timer and dei
EN_SwICU_Edge_t SwICU_GetCfgEdge(void);//don't use it
void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdgeedge);//change cfg of the int pin
void SwICU_Read(volatile uint8_t * a_pu8_capt);//use it to read timer
void SwICU_Stop(void);//stop timer
void SwICU_Start(void);//start timer
void SwICU_Enable(void);//stop
void SwICU_Disable(void);//

#endif /* SWICU_H_ */
