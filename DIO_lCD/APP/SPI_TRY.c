/*
 * SPI_TRY.c
 *
 * Created: 9/8/2022 5:10:58 AM
 *  Author: pc
 */ 
#include "SPI_TRY.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER/TIMER.h"
void SPI_try()
{
	Timer_intialize();
	
	SPI_Master_Intialize();
	DIO_SetPortDirection(PORTA,Output);
	
	uint8 num=0;
	while(1)
	{
		SPI_Master_Transmit(0);
		TIMER_delay(5);
		
		SPI_Master_Transmit(0xf0);
		TIMER_delay(5);
		
		num++;
	}
}