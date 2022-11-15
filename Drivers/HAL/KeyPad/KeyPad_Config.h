/*
 * KeyPad_Config.h
 *
 * Created: 9/11/2022 9:30:46 PM
 *  Author: pc
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "../../MCAL/DIO/DIO.h"

#define ROWS		4
#define COLUMNS		4


#define		ROW_1		0
#define		ROW_2		1
#define		ROW_3		2
#define		ROW_4		3

#define		COL_1		4
#define		COL_2		5
#define		COL_3		6
#define		COL_4		7

#define		Keypad_Port		PORTA
#define		Keypad_Port_Set_Clear	PORTA_Reg

#endif /* KEYPAD_CONFIG_H_ */