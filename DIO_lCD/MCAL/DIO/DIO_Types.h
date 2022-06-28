/*
 * DIO_Types.h
 *
 * Created: 6/25/2022 5:38:04 PM
 *  Author: pc
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum 
{
	Input,
	Output
	}DIO_Direcrion;
	
typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD
	}DIO_Port_ID;


typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7	
	}DIO_PIN_ID;
	


	
#endif /* DIO_TYPES_H_ */