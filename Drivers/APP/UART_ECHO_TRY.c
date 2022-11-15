/*
 * UART_ECHO_TRY.c
 *
 * Created: 9/5/2022 5:17:26 PM
 *  Author: pc
 */ 
#include "UART_ECHO_TRY.h"


#include "../MCAL/TIMER/TIMER.h"
void UART_Start()
{	
	UART_Intialize();
	uint8 received=0;
	
	while(1)
	{
		
		received=UART_Receive();
		UART_Transmit(received);
	}

}
