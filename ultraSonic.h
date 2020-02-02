/*
 * UltraSonic.h
 *
 * Created: 1/29/2020 7:58:55 PM
 *  Author: Reem
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define TRIGGER_PORT GPIOC
#define TRIGGER_PIN BIT7
void ultraSonic_Init(void);
void ultraSonic_Enable(void);
int ultraSonic_CalcDistance(void);

#endif /* ULTRASONIC_H_ */