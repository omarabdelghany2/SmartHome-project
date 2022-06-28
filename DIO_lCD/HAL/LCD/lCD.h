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





#endif /* LCD_H_ */