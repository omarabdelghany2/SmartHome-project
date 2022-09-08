/*
 * lCD.h
 *
 * Created: 6/27/2022 5:22:55 PM
 *  Author: pc
 */ 
#include "../../LIB/STD_Types.h"

#ifndef LCD_H_
#define LCD_H_

void LCD_Intialize();
void LCD_WriteCmd(uint8 Cmd);
void LCD_WriteData(uint8 Data);
void LCD_GoToPos(uint8 Row , uint8 Column);
void LCD_WriteString(uint8 *Str , uint8 Row,uint8 Column);
void LCD_StoreCustomChr(uint8*pattern , uint8 CGRAM_Index);
void LCD_DisplayCustomchr(uint8 CGRAM_Index , uint8 ROW , uint8 Column);





#endif /* LCD_H_ */