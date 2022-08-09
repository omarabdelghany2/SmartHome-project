/*
* ADC_interrupt_LAB.c
*
* Created: 7/2/2022 2:30:11 AM
*  Author: pc
*/

#include "ADC_INTERRUPT_LAB.h"

#define potent			1
#define button			2
#define LED				3
uint16 counter;
void ADC_Complete_Conv_ISR()
{
	counter++;
	char Value_str[10];
	itoa(counter,Value_str,10);
	LCD_WriteString(Value_str,0,5);
	
	
	
}



void ADC_interrupt_Lab()
{
	

DIO_SetPortDirection(PORTA,Output);
DIO_SetPortDirection(PORTB,Output);

DIO_SetPinDirection(PORTA,potent,Input);
DIO_SetPinDirection(PORTA,button,Input);


ADC_Intialize();
LCD_Intialize();
ADC_EnableInt();
Global_Interrupt_Enable();



ADC_SetCallback(ADC_Complete_Conv_ISR);
ADC_Intialize();
ADC_StartConversion(potent);
while(1)

{
	ADC_StartConversion(potent);
DIO_SetPinValue(PORTB,6,HIGH);
_delay_ms(500);
DIO_SetPinValue(PORTB,6,LOW);
_delay_ms(500);

}
}