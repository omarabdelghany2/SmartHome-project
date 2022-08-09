/*
 * main.c
 *
 * Created: 6/27/2022 10:59:34 AM
 *  Author: pc
 */ 
#include "MCAL/DIO/DIO.h"
#include "APP/Seven_Segment.h"
#include "HAL/LCD/lCD.h"
#include "APP/ADC_INTERRUPT_LAB.h"

int main()
{
	
	//ADC_LAB();
	//Sev_Seg(11,0.1);
	ADC_interrupt_Lab();
	while(1)
	{
		
	}
}