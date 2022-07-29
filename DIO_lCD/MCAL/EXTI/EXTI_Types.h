/*
 * EXTI_Types.h
 *
 * Created: 7/29/2022 9:34:57 PM
 *  Author: pc
 */ 


#ifndef EXTI_TYPES_H_
#define EXTI_TYPES_H_


//this types of modes of operation of interrupt0 and interrupt1
	
#define EXTI_LOW_LEVEL				 0
#define EXTI_Any_Logical_Change		 1		 
#define EXTI_Falling_Edge			 2
#define EXTI_Rising_Edge			 3


//this types of modes of operation of interrupt 2
#define EXTI_INT2_Falling_Edge       0
#define EXTI_INT2_Rising_Edge        1


#define EXTI_Enable_state			 1
#define EXTI_Disable_state			 0


#endif /* EXTI_TYPES_H_ */