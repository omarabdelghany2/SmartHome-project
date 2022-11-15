/*
 * Timer0_overflow_interrupt_LAB.c
 *
 * Created: 8/9/2022 7:03:28 PM
 *  Author: pc
 */ 

#include "Timer0_overflow_interrupt_LAB.h"

volatile unsigned char x =0;
uint16 overflow=0;
uint8 sec=0;
void ISR()
{
	DIO_SetPortValue(PORTC,x);
	x++;
	overflow++;
}

void Timer_Lab()
{
	DIO_SetPortDirection(PORTC,Output);
	DIO_SetPortDirection(PORTB,Output);
	DIO_SetPortDirection(PORTD,Output);
	TIMER_SetCallback(ISR);
	Global_Interrupt_Enable();
	Timer_intialize();

while(1)
	{
		if(overflow>2000)
			{
				sec++;
				DIO_SetPortValue(PORTD,sec);
				overflow=0;
			}
	}
	
}