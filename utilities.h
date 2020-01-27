/*
 * utilities.h
 *
 * Created: 1/21/2020 1:00:06 PM
 *  Author: Reem
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_


#define set_bit(Reg,bit_no)				Reg |=		 (1<<bit_no)
#define clr_bit(Reg,bit_no)				Reg &=		~(1<<bit_no)
#define toggle_bit(Reg,bit_no)			Reg ^=		 (1<<bit_no)

#define set_bit_mask(Reg,bit_mask)		Reg |=		 (bit_mask)
#define clr_bit_mask(Reg,bit_mask)		Reg &=		~(bit_mask)
#define toggle_bit_mask(Reg,bit_mask)	Reg ^=		 (bit_mask)
#define get_bit(Reg,pin_)				(Reg & pin_)


#endif /* UTILITIES_H_ */