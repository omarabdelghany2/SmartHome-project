/*
 * TIMER_Reg.h
 *
 * Created: 8/8/2022 9:04:05 PM
 *  Author: pc
 */ 


#ifndef TIMER_REG_H_
#define TIMER_REG_H_
#include "../../LIB/STD_Types.h"


#define TCCR0_REG			(*(volatile uint8 *)0x53)
#define TCNT0_REG			(*(volatile uint8 *)0x52)
#define OCR0_REG			(*(volatile uint8 *)0x5C)
#define TIMSK_REG			(*(volatile uint8 *)0x59)
#define TIFR_REG			(*(volatile uint8 *)0x58)



#endif /* TIMER_REG_H_ */