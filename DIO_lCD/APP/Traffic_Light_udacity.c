/*
 * Traffic_Light_udacity.c
 *
 * Created: 8/11/2022 7:13:58 PM
 *  Author: pc
 */ 
#include "Traffic_Light_udacity.h"
bool flag=false;
void start_Traffic_light()
{
	LCD_Intialize();
	Timer_intialize();
	Seven_Segment_Intialization();
	Seven_Segment_Enable1();
	DIO_SetPortDirection(PORTA,Output);
	DIO_SetPortDirection(PORTB,Output);
	EXTI_SetCallback(ISR_traffic);
	EXTI_Intialization();
	EXTI_EnableInt0();
	
	
	while(1)
	{
	
		if(flag!=false)
		
		{
			//STARTING YELOW LED
				LCD_WriteString("         ",0,0);
				LCD_WriteString("READY",0,0);
				DIO_SetPinValue(PORTA,PIN0,LOW);
				DIO_SetPinValue(PORTA,PIN1,HIGH);
				DIO_SetPinValue(PORTA,PIN2,LOW);
				for(unsigned char count=5;count>0;count--)
				{
					DIO_SetPinValue(PORTA,PIN1,HIGH);
					Seven_Segment_Write_Number(count);
					TIMER_delay(1);
					DIO_SetPinValue(PORTA,PIN1,LOW);
					TIMER_delay(0.1);
				}
				
				
				//STARTING RED LED
				LCD_WriteString("         ",0,0);
				LCD_WriteString("PASS",0,0);
				DIO_SetPinValue(PORTA,PIN0,LOW);
				DIO_SetPinValue(PORTA,PIN1,LOW);
				DIO_SetPinValue(PORTA,PIN2,HIGH);
				for(unsigned char count=5;count>0;count--)
				{
						
						Seven_Segment_Write_Number(count);
						TIMER_delay(1);
				}
				flag=false;
				
		}
		
			//STARTIGN GREEN LED
			DIO_SetPinValue(PORTA,PIN0,HIGH);
			DIO_SetPinValue(PORTA,PIN1,LOW);
			DIO_SetPinValue(PORTA,PIN2,LOW);
			LCD_WriteString("DONT PASS",0,0);
		for(unsigned char count=9;count>0;count--)
		{
			
		Seven_Segment_Write_Number(count);
		TIMER_delay(1);
		}
		
		
	}
}


void ISR_traffic()
{
	flag=true;
}