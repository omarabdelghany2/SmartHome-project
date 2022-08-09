/*
 * LCD.c
 *
 * Created: 6/27/2022 5:23:48 PM
 */

#define F_CPU 10000000UL
#include "avr/delay.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/BIT_Math.h"	
#include "../../LIB/STD_Types.h"
	



//PORTA for Data_bus
//PORTB pin3->Enable  pin1 and 2->(RS)//(R/W)


static uint8 InitStepFinished = 0;

void LCD_WriteCmd(uint8 Cmd)
{
	DIO_SetPinValue(PORTB,PIN1,LOW);//RS and R/W should be low to write command
	DIO_SetPinValue(PORTB,PIN2,LOW);
	
	
	DIO_SetPinValue(PORTA,PIN4,GetBIT(Cmd,4));
	DIO_SetPinValue(PORTA,PIN5,GetBIT(Cmd,5));
	DIO_SetPinValue(PORTA,PIN6,GetBIT(Cmd,6));
	DIO_SetPinValue(PORTA,PIN7,GetBIT(Cmd,7));
	
	//delay and reading by down Edge
	
					//
					DIO_SetPinValue(PORTB,PIN3,HIGH);
					_delay_ms(1);                       //delay for reading block
					DIO_SetPinValue(PORTB,PIN3,LOW);
	
					//
	if(InitStepFinished)
	{
		
		DIO_SetPinValue(PORTA,PIN4,GetBIT(Cmd,0));
		DIO_SetPinValue(PORTA,PIN5,GetBIT(Cmd,1));
		DIO_SetPinValue(PORTA,PIN6,GetBIT(Cmd,2));
		DIO_SetPinValue(PORTA,PIN7,GetBIT(Cmd,3));

		//delay and reading by down Edge
		
					//
					DIO_SetPinValue(PORTB,PIN3,HIGH);
					_delay_ms(1);                       //delay for reading block
					DIO_SetPinValue(PORTB,PIN3,LOW);
		
					//
	}
	
	
}
void LCD_Intialize()
{
	DIO_SetPortDirection(PORTA,Output);
	DIO_SetPortDirection(PORTB,Output);//for control pins
	_delay_ms(30);
	LCD_WriteCmd(0x20);///intialize orders
	LCD_WriteCmd(0x20);
	LCD_WriteCmd(0x80);
	_delay_ms(1);
	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0xf0);
	_delay_ms(1);
	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0x10);
	_delay_ms(2);
	
	InitStepFinished=1;
	
}

void LCD_WriteData(uint8 Data)
{
		DIO_SetPinValue(PORTB,PIN1,HIGH);//RS and R/W should be high and  low to write Data
		DIO_SetPinValue(PORTB,PIN2,LOW);
	
	
		DIO_SetPinValue(PORTA,PIN4,GetBIT(Data,4));
		DIO_SetPinValue(PORTA,PIN5,GetBIT(Data,5));
		DIO_SetPinValue(PORTA,PIN6,GetBIT(Data,6));
		DIO_SetPinValue(PORTA,PIN7,GetBIT(Data,7));
	
							//delay and reading by down Edge
	
							//
							DIO_SetPinValue(PORTB,PIN3,HIGH);
							_delay_ms(1);                       //delay for reading block
							DIO_SetPinValue(PORTB,PIN3,LOW);
	
							//
	
		
		DIO_SetPinValue(PORTA,PIN4,GetBIT(Data,0));
		DIO_SetPinValue(PORTA,PIN5,GetBIT(Data,1));
		DIO_SetPinValue(PORTA,PIN6,GetBIT(Data,2));
		DIO_SetPinValue(PORTA,PIN7,GetBIT(Data,3));

							//delay and reading by down Edge
		
							//
							DIO_SetPinValue(PORTB,PIN3,HIGH);
							_delay_ms(1);                       //delay for reading block
							DIO_SetPinValue(PORTB,PIN3,LOW);
		
							//
	
	
	
}
void LCD_GoToPos(uint8 Row,uint8 Column)
{
	if((Row<2)&&(Column<16))
	{
		uint8 Address=(Row*0x40)+Column;
		SetBIT(Address,7);
		LCD_WriteCmd(Address);
	}
}
void LCD_WriteString(uint8 *Str,uint8 Row,uint8 Column)
{	uint8 Index=0;//for the curser indexing
	uint8 Line0=0;//for row indexing
	LCD_GoToPos(Row,Column);
	while ((Str[Index]!='\0')&&((Row*16)+Index+Column)<32)//while ends by ending of string
	{
		if (((Row*16)+Index+Column)<16)//for the first row indexing
		{
			LCD_WriteData(Str[Index]);
			Index++;
		}
		else if((((Row*16)+Index+Column)==16))//for the end of first row indexing and going to the second
		{
			LCD_GoToPos(1,0);
			Line0=1;
		}
		else if(((Row*16)+Index+Column)<32&&Line0==1)//for the second row indexing
		{
			LCD_WriteData(Str[Index]);
			Index++;
		}
	}
}

void LCD_StoreCustomChr(uint8*pattern , uint8 CGRAM_Index)
{
	uint8 address;//address of CGRAM to store the character
	if(CGRAM_Index<8)
	{
	
	address=CGRAM_Index*8;//every idex occupy 8 places OR 8 BYTES 
	address=SetBIT(address,6);//set bit no 6 to tell LCD to go to CGRAM not DDRAM
	LCD_WriteCmd(address);//Tell LCD
		for(uint8 index=0;index<8;index++)//store the character
		{
		LCD_WriteData(pattern[index]);
		}
	}
	LCD_WriteCmd(0x02);//return home command toDDRAM 
	
}
void LCD_DisplayCustomchr(uint8 CGRAM_Index,uint8 ROW,uint8 Column)
{
	LCD_GoToPos(ROW,Column);
	LCD_WriteData(CGRAM_Index);
}