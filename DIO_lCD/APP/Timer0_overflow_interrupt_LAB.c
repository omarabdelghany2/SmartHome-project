/*
 * Timer0_overflow_interrupt_LAB.c
 *
 * Created: 8/9/2022 7:03:28 PM
 *  Author: pc
 */ 

#include "Timer0_overflow_interrupt_LAB.h"

void ISR()
{
	DIO_SetPinValue(PORTB,4,HIGH);
	
}

void Timer_Lab()
{
	DIO_SetPortDirection(PORTB,Output);
	TIMER_SetCallback(ISR);
	Global_Interrupt_Enable();
	Timer_intialize();
	uint8 data=0b11111111;
	DIO_SetPortDirection(PORTC,Output);
	while(1)
	{
		data=TCNT0_REG;
		DIO_SetPortValue(PORTC,data);
		_delay_ms(1000);
	}
	
}