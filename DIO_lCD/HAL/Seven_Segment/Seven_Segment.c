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
	DIO_SetPinDirection(PORTB , PIN0 , Output);// A//data pins
	DIO_SetPinDirection(PORTB , PIN1 , Output);// B
	DIO_SetPinDirection(PORTB , PIN2 , Output);// C
	DIO_SetPinDirection(PORTB , PIN3 , Output);// D
	
	
	DIO_SetPinDirection(PORTB  , PIN4 ,  Output); //EN1 //
	DIO_SetPinDirection(PORTB  , PIN1 ,  Output); //EN2
}

//DCBA number=3 then=->
//0011
void Seven_Segment_Write_Number(uint8 number)
{
	DIO_SetPinValue(PORTB  ,  PIN0  ,  GetBIT(number  ,  0));
	DIO_SetPinValue(PORTB  ,  PIN1  ,  GetBIT(number  ,  1));
	DIO_SetPinValue(PORTB  ,  PIN2  ,  GetBIT(number  ,  2));
	DIO_SetPinValue(PORTB  ,  PIN3  ,  GetBIT(number  ,  3));	
}

void Seven_Segment_Enable1()
{
	DIO_SetPinValue(PORTB , PIN4 , HIGH);
}

void Seven_Segment_Enable2()
{
	DIO_SetPinValue(PORTB , PIN1 , HIGH);
}

void Seven_Segment_Disable1()
{
	DIO_SetPinValue(PORTB , PIN4 , LOW);
}

void Seven_Segment_Disable2()
{
    DIO_SetPinValue(PORTB , PIN1 , LOW);
}