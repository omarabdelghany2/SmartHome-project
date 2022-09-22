/*
 * KeyPad.c
 *
 * Created: 9/11/2022 9:28:18 PM
 *  Author: pc
 */ 
#define F_CPU		1000000
#include "KeyPad.h"
#include "../LCD/LCD.h"

#include "avr/delay.h"
uint8 KeyPad()
{
	
	DIO_SetPinValue(PORTB,0,HIGH);
	_delay_ms(1);
	if((PIN_keyPad & 0b00010000)) return('1');
	if((PIN_keyPad & 0b00100000)) return('2');
	if((PIN_keyPad & 0b01000000)) return('3');
	if((PIN_keyPad & 0b10000000)) return('A');
	
	DIO_SetPinValue(PORTB,0,LOW);
	DIO_SetPinValue(PORTB,1,HIGH);
	_delay_ms(1);
	if((PIN_keyPad & 0b00010000)) return('4');
	if((PIN_keyPad & 0b00100000)) return('5');
	if((PIN_keyPad & 0b01000000)) return('6');
	if((PIN_keyPad & 0b10000000)) return('B');
	
	
	DIO_SetPinValue(PORTB,1,LOW);
	DIO_SetPinValue(PORTB,2,HIGH);
_delay_ms(1);
	if((PIN_keyPad & 0b00010000)) return('7');
	if((PIN_keyPad & 0b00100000)) return('8');
	if((PIN_keyPad & 0b01000000)) return('9');
	if((PIN_keyPad & 0b10000000)) return('C');
	
	
	DIO_SetPinValue(PORTB,2,LOW);
	DIO_SetPinValue(PORTB,3,HIGH);
_delay_ms(1);
	if((PIN_keyPad & 0b00010000)) return('*');
	if((PIN_keyPad & 0b00100000)) return('0');
	if((PIN_keyPad & 0b01000000)) return('#');
	if((PIN_keyPad & 0b10000000)) return('D');
	DIO_SetPinValue(PORTB,3,LOW);

	return('N');
			
}