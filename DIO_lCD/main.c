/*
 * main.c
 *
 * Created: 6/27/2022 10:59:34 AM
 *  Author: pc
 */ 

#include "APP/SPI_TRY.h"
#include "HAL/LCD/LCD.h"
#include "HAL/KeyPad/KeyPad.h"
#include "MCAL/EEPROM/EEPROM.h"
#include "LIB/STD_Types.h"

int main()
{
	 Timer_intialize();
	LCD_Intialize();
	
	/*DIO_SetPortDirection(PORTA,Output);
	uint8 data=0;
	EEPROM_Write(0,'b');
		EEPROM_Write(1,'c');

	 data =EEPROM_Read(1);*/
	uint8 in;
	DIO_SetPortDirection(PORTD,Output);
	while(1)
	{
		in=KeyPad();
		if((in!='N'))
		{
			LCD_WriteData(in);
			DIO_SetPortValue(PORTD,0xff);
			in='N';
		}
		else
		{
			DIO_SetPortValue(PORTD,0x00);
		}

		in-'N';
		
	}
}