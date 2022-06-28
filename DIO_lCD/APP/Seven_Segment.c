/*
 * Seven_Segment.c
 *
 * Created: 6/27/2022 11:00:23 AM
 *  Author: pc
 */ 
#define F_CPU 10000000UL
#include "avr/delay.h"
#include "../HAL/Seven_Segment/Seven_Segment.h"
#include "../LIB/STD_Types.h"

void Sev_Seg(uint8 number,float time)
{
	Seven_Segment_Intialization();
	float time_ms=time*1000;
	for(uint8 i=0;i<number;i++)
	{
		uint8 Left=i/10;
		uint8 Right=i%10;
		for(float j=0 ; j<(time_ms/20) ; j++)//20=10+10 the delay from below 
		{
			Seven_Segment_Enable1();
			Seven_Segment_Write_Number(Left);
			_delay_ms(10);
			Seven_Segment_Disable1();
			
			Seven_Segment_Enable2();
			Seven_Segment_Write_Number(Right);
			_delay_ms(10);
			Seven_Segment_Disable2();
			
		}
		
	}
}