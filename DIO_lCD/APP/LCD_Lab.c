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
	uint8 pattern []={0x0E,0x08,0x1E,0x00,0x04,0x04,0x04,0x04};

	LCD_StoreCustomChr(pattern,0);
	LCD_DisplayCustomchr(0,0,0);
	
	while(1)
	{

	
	}
}