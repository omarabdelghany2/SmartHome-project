/*
 * EXTI_LAB.c
 *
 * Created: 7/30/2022 2:51:01 AM
 *  Author: pc
 */ 
#include "../LIB/STD_Types.h"
#include "../MCAL/DIO/DIO_Types.h"
#include "util/delay.h"
#include "../MCAL/GIE/GIE.h"
void EXTI0_ISR(void);
void EXTI_LAB(void)
{	
	//button for interrupt
	DIO_SetPinDirection(PORTD,PIN2,Input);
	//interrupt led pin
	DIO_SetPinDirection(PORTA,PIN3,Output);
	//led2 pin
	DIO_SetPinDirection(PORTD,PIN3,Output);
	
	EXTI_Intialization();
	EXTI_SetCallback(EXTI0_ISR);
	//ENABLE INT0
	EXTI_EnableInt0();
	//u have to enable global interrupt here 
	Global_Interrupt_Enable();
	
	while(1)
	{
		DIO_SetPinValue(PORTD,PIN3,HIGH);
		_delay_ms(100);
		DIO_SetPinValue(PORTD,PIN3,LOW);
		_delay_ms(100);
	}
}

void EXTI0_ISR(void)
{
	DIO_SetPinValue(PORTA,PIN3,HIGH);
	_delay_ms(1000);
	DIO_SetPinValue(PORTA,PIN3,LOW);
	_delay_ms(1000);
}