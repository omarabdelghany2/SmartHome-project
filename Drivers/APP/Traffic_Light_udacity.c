/*
 * Traffic_Light_udacity.c
 *
 * Created: 8/11/2022 7:13:58 PM
 *  Author: pc
 */ 
#include "Traffic_Light_udacity.h"
void normal_mode();
void pedestrian_mode();

bool flag=false;
void start_Traffic_light()
{
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
		if(flag==false)
			normal_mode();
	
		else
			pedestrian_mode();
	}
		
		
}


void ISR_traffic()
{
	flag=true;
}

void normal_mode ()
{
	int count=5;
	//entering green led of car
	while(flag==false&&(count>0))
	{
		DIO_SetPinValue(PORTA,PIN0,HIGH);
		DIO_SetPinValue(PORTA,PIN1,LOW);
		DIO_SetPinValue(PORTA,PIN2,LOW); 
		
		Seven_Segment_Write_Number(count);
		
		DIO_SetPinValue(PORTB,PIN0,LOW);
		DIO_SetPinValue(PORTB,PIN1,LOW);
		DIO_SetPinValue(PORTB,PIN2,HIGH);		
		
		count--;
		TIMER_delay(1);
	}
	count=5;
	//entering yellow led of car
	while(flag==false&&(count>0))
	{
		DIO_SetPinValue(PORTA,PIN0,LOW);
		DIO_SetPinValue(PORTA,PIN1,HIGH);
		DIO_SetPinValue(PORTA,PIN2,LOW);
		
	    DIO_SetPinValue(PORTB,PIN0,LOW);
	    DIO_SetPinValue(PORTB,PIN1,HIGH);
	    DIO_SetPinValue(PORTB,PIN2,LOW);		
		TIMER_delay(0.1);
		DIO_SetPinValue(PORTA,PIN1,LOW);
		DIO_SetPinValue(PORTB,PIN1,LOW);
		TIMER_delay(0.1);
		Seven_Segment_Write_Number(count);
		TIMER_delay(1);
		count--;	
	}
		count=5;
		//entering the red led of car
		while(flag==false&&(count>0))
		{
			DIO_SetPinValue(PORTA,PIN0,LOW);
			DIO_SetPinValue(PORTA,PIN1,LOW);
			DIO_SetPinValue(PORTA,PIN2,HIGH);
			
			DIO_SetPinValue(PORTB,PIN0,HIGH);
			DIO_SetPinValue(PORTB,PIN1,LOW);
			DIO_SetPinValue(PORTB,PIN2,LOW);
			Seven_Segment_Write_Number(count);
			TIMER_delay(1);
			count--;
		}
	
}

void pedestrian_mode()
{
	int count=5;
	//the button pressed while the green led of cars was high
	if(DIO_GetPinValue(PORTA,0))
	{
		//entering the yellow led of both
		while(flag==true&&count>0)
		{
			DIO_SetPinValue(PORTA,PIN0,LOW);
			DIO_SetPinValue(PORTA,PIN1,HIGH);
			DIO_SetPinValue(PORTA,PIN2,LOW);
			DIO_SetPinValue(PORTB,PIN0,LOW);
			DIO_SetPinValue(PORTB,PIN1,HIGH);
			DIO_SetPinValue(PORTB,PIN2,LOW);			
			TIMER_delay(0.1);
			
			DIO_SetPinValue(PORTA,PIN1,LOW);
			DIO_SetPinValue(PORTB,PIN1,LOW);
			
			TIMER_delay(0.1);
			Seven_Segment_Write_Number(count);
			TIMER_delay(1);
			count--;
		}
		//entering the red led of car
		count=5;
		while(flag==true&&count>0)
			{
				DIO_SetPinValue(PORTA,PIN0,LOW);
				DIO_SetPinValue(PORTA,PIN1,LOW);
				DIO_SetPinValue(PORTA,PIN2,HIGH);
				
				DIO_SetPinValue(PORTB,PIN0,HIGH);
				DIO_SetPinValue(PORTB,PIN1,LOW);
				DIO_SetPinValue(PORTB,PIN2,LOW);				
				Seven_Segment_Write_Number(count);
				TIMER_delay(1);
				count--;
			}
	}
	//the button pressed while the red led of cars was high
	else if(DIO_GetPinValue(PORTA,2))
	{
		count=5;
		while(flag==true&&count>0)
		{
			DIO_SetPinValue(PORTA,PIN0,LOW);
			DIO_SetPinValue(PORTA,PIN1,LOW);
			DIO_SetPinValue(PORTA,PIN2,HIGH);

			DIO_SetPinValue(PORTB,PIN0,HIGH);
			DIO_SetPinValue(PORTB,PIN1,LOW);
			DIO_SetPinValue(PORTB,PIN2,LOW);
			Seven_Segment_Write_Number(count);
			TIMER_delay(1);
			count--;
		}
	}
	//the button pressed while the yellow led was high
	else
	{
		while(flag==true&&(count>0))
		{
			DIO_SetPinValue(PORTA,PIN0,LOW);
			DIO_SetPinValue(PORTA,PIN1,HIGH);
			DIO_SetPinValue(PORTA,PIN2,LOW);
			DIO_SetPinValue(PORTB,PIN0,LOW);
			DIO_SetPinValue(PORTB,PIN1,HIGH);
			DIO_SetPinValue(PORTB,PIN2,LOW);			
			TIMER_delay(0.1);
			
			DIO_SetPinValue(PORTA,PIN1,LOW);
			DIO_SetPinValue(PORTB,PIN1,LOW);
			
			TIMER_delay(0.1);
			Seven_Segment_Write_Number(count);
			TIMER_delay(1);
			count--;
		}
		count=5;
		while(flag==true&&(count>0))
		{
			DIO_SetPinValue(PORTA,PIN0,LOW);
			DIO_SetPinValue(PORTA,PIN1,LOW);
			DIO_SetPinValue(PORTA,PIN2,HIGH);

			DIO_SetPinValue(PORTB,PIN0,HIGH);
			DIO_SetPinValue(PORTB,PIN1,LOW);
			DIO_SetPinValue(PORTB,PIN2,LOW);

			Seven_Segment_Write_Number(count);
			TIMER_delay(1);
			count--;
		}
		
	}

	flag=false;
	
}