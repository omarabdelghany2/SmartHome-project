/*
 * DIO.c
 *
 * Created: 6/25/2022 5:36:26 PM
 *  Author: pc
 */ 

#include "DIO.h"

void DIO_SetPortDirection(DIO_Port_ID Port_ID,DIO_Direcrion Direction)
{
	if(Output==Direction)
	{
		switch (Port_ID)
		{
			case(PORTA):DDRA_Reg = 0xff;break;
			case(PORTB):DDRB_Reg = 0xff;break;
			case(PORTC):DDRC_Reg = 0xff;break;
			case(PORTD):DDRD_Reg = 0xff;break;
		}
		
	}
	else if(Input==Direction)
	{
		switch (Port_ID)
		{
			case(PORTA):DDRA_Reg=0x00;break;
			case(PORTB):DDRB_Reg=0x00;break;
			case(PORTC):DDRC_Reg=0x00;break;
			case(PORTD):DDRD_Reg=0x00;break;
		}
		
		
	}
}


void DIO_SetPortValue(DIO_Port_ID Port_ID, STD_Value Value)
{
	switch(Port_ID)
	{
		case(PORTA): PORTA_Reg  =Value;break;
		case(PORTB): PORTB_Reg = Value;break;
		case(PORTC): PORTC_Reg = Value;break;
		case(PORTD): PORTD_Reg = Value;break;
	}
}


void DIO_SetPinDirection(DIO_Port_ID Port_ID,DIO_PIN_ID Pin_ID,DIO_Direcrion Direction)
{
	if(Direction==Input)
	{
		switch(Port_ID)
		{
			case(PORTA):ClearBIT(DDRA_Reg,Pin_ID);break;
			case(PORTB):ClearBIT(DDRB_Reg,Pin_ID);break;
			case(PORTC):ClearBIT(DDRC_Reg,Pin_ID);break;
			case(PORTD):ClearBIT(DDRD_Reg,Pin_ID);break;
		}
	}
	
	else if(Direction==Output)
	{
		
		switch(Port_ID)
		{
				case(PORTA):SetBIT(DDRA_Reg,Pin_ID);break;
				case(PORTB):SetBIT(DDRB_Reg,Pin_ID);break;
				case(PORTC):SetBIT(DDRC_Reg,Pin_ID);break;
				case(PORTD):SetBIT(DDRD_Reg,Pin_ID);break;
			
		}
	}
}
void DIO_SetPinValue(DIO_Port_ID Port_ID,DIO_PIN_ID Pin_ID, STD_Value Value)
{
	if(Value==HIGH)
	{
		switch(Port_ID)
		{
			case(PORTA): SetBIT(PORTA_Reg,Pin_ID);break;
			case(PORTB): SetBIT(PORTB_Reg,Pin_ID);break;
			case(PORTC): SetBIT(PORTC_Reg,Pin_ID);break;
			case(PORTD): SetBIT(PORTD_Reg,Pin_ID);break;
			
		}
		
	}
	else if(Value==LOW)
	{
			switch(Port_ID)
			{
				case(PORTA): ClearBIT(PORTA_Reg,Pin_ID);break;
				case(PORTB): ClearBIT(PORTB_Reg,Pin_ID);break;
				case(PORTC): ClearBIT(PORTC_Reg,Pin_ID);break;
				case(PORTD): ClearBIT(PORTD_Reg,Pin_ID);break;
				
			}
	}
}

 STD_Value DIO_GetPinValue(DIO_Port_ID Port_ID,DIO_PIN_ID Pin_ID)
{
	 STD_Value pinvalue=0;
	switch(Port_ID)
	{
		case (PORTA):pinvalue=GetBIT(PINA_Reg,Pin_ID);break;
		case (PORTB):pinvalue=GetBIT(PINB_Reg,Pin_ID);break;
		case (PORTC):pinvalue=GetBIT(PINC_Reg,Pin_ID);break;
		case (PORTD):pinvalue=GetBIT(PIND_Reg,Pin_ID);break;
	}
	return(pinvalue);
	
}

uint8 DIO_GetPortValue(DIO_Port_ID Port_ID)
{
	uint8 Port_Value=0	;
	switch(Port_ID)
	{
		case(PORTA): Port_Value=PINA_Reg;break;
		case(PORTB): Port_Value=PINB_Reg;break;
		case(PORTC): Port_Value=PINC_Reg;break;
		case(PORTD): Port_Value=PIND_Reg;break;
	}
	return(Port_Value);
	
}