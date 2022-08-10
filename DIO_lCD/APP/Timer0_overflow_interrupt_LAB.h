/*
 * Timer0_overflow_interrupt_LAB.h
 *
 * Created: 8/9/2022 7:08:41 PM
 *  Author: pc
 */ 


#ifndef TIMER0_OVERFLOW_INTERRUPT_LAB_H_
#define TIMER0_OVERFLOW_INTERRUPT_LAB_H_

#define F_CPU 10000000UL
#include "util/delay.h"
#include "../LIB/STD_Types.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../MCAL/GIE/GIE.h"
#include "../LIB/BIT_Math.h"

void ISR();
void Timer_Lab();


#endif /* TIMER0_OVERFLOW_INTERRUPT_LAB_H_ */