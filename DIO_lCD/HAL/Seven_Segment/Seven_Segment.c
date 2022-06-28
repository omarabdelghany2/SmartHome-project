/*
 * Seven_Segment.c
 *
 * Created: 6/27/2022 10:42:06 AM
 *  Author: pc
 */ 
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO_Types.h"
#include "../../LIB/STD_Types.h"

void Seven_Segment_Intialization()
{
	DIO_SetPinDirection(PORTA , PIN4 , Output);// A//data pins
	DIO_SetPinDirection(PORTA , PIN5 , Output);// B
	DIO_SetPinDirection(PORTA , PIN6 , Output);// C
	DIO_SetPinDirection(PORTA , PIN7 , Output);// D
	
	
	DIO_SetPinDirection(PORTB  , PIN2 ,  Output); //EN1 //
	DIO_SetPinDirection(PORTB  , PIN1 ,  Output); //EN2
}

//DCBA number=3 then=->
//0011
void Seven_Segment_Write_Number(uint8 number)
{
	DIO_SetPinValue(PORTA  ,  PIN4  ,  GetBIT(number  ,  0));
	DIO_SetPinValue(PORTA  ,  PIN5  ,  GetBIT(number  ,  1));
	DIO_SetPinValue(PORTA  ,  PIN6  ,  GetBIT(number  ,  2));
	DIO_SetPinValue(PORTA  ,  PIN7  ,  GetBIT(number  ,  3));	
}

void Seven_Segment_Enable1()
{
	DIO_SetPinValue(PORTB , PIN2 , HIGH);
}

void Seven_Segment_Enable2()
{
	DIO_SetPinValue(PORTB , PIN1 , HIGH);
}

void Seven_Segment_Disable1()
{
	DIO_SetPinValue(PORTB , PIN2 , LOW);
}

void Seven_Segment_Disable2()
{
    DIO_SetPinValue(PORTB , PIN1 , LOW);
}