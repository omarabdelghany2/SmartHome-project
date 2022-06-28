/*
 * LCD_Lab.c
 *
 * Created: 6/27/2022 6:47:03 PM
 *  Author: pc
 */ 
#include "../HAL/LCD/LCD.h"

#include "avr/delay.h"
void LCD_lab()
{
	LCD_Intialize();
	while(1)
	{
		
	LCD_WriteData('M');
	LCD_WriteData('A');
	LCD_WriteData('R');
	LCD_WriteData('K');
	LCD_WriteData('I');
	LCD_WriteData('Z');
	LCD_WriteData('O');
	LCD_WriteData('0');
	LCD_WriteData('.');
	LCD_WriteData('.');
	LCD_WriteData('.');
	LCD_WriteData('5');
	
	_delay_ms(2000);
	LCD_WriteCmd(0x01);	
	}
}