/*
 * ADC_LAB.c
 *
 * Created: 7/2/2022 2:30:11 AM
 *  Author: pc
 */ 
#define F_CPU 10000000UL
#include "util/delay.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/DIO/DIO.h"
#include "../LIB/BIT_Math.h"
#include "../MCAL/ADC/ADC_Types.h"
#include "../LIB/STD_Types.h"
#include "../HAL/LCD/LCD.h"
#include <stdlib.h>


#define potent			1
#define button			2
#define LED				3
void ADC_LAB()
{	
	LCD_Intialize();
	
	DIO_SetPinDirection(PORTA,potent,Input);
	DIO_SetPinDirection(PORTA,button,Input);
		char StringResult[10];
		
	
	ADC_Intialize();
	while(1)
	{
		ADC_StartConversion(potent);
		uint16 Result=ADC_GetResult();	
		if(!DIO_GetPinValue(PORTA,button))
		{
			DIO_SetPinValue(PORTA,LED,HIGH);
			
			itoa(Result,StringResult,10);//1023
			LCD_WriteString(StringResult,0,0);
			
			
		}
		else
		{
			DIO_SetPinValue(PORTA,LED,LOW);
			LCD_WriteString("         ",0,0);
		}
		
	}
	
	
	
}