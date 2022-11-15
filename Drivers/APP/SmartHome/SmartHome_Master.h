/*
 * SmarHome.h
 *
 * Created: 9/26/2022 3:27:04 PM
 *  Author: pc
 */ 


#ifndef SMARHOME_H_
#define SMARHOME_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../MCAL/SPI/SPI.h"
#include "../../MCAL/EEPROM/EEPROM.h"
#include "../../HAL/KeyPad/KeyPad.h"
#include "../../HAL/LCD/lCD.h"
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"


void SmartHome_App_Start();

#define Right  0
#define wrong  1

#define ADMIN  '1'
#define GUEST  '2'
void SmartHome_App_Start_Master();
void SetPassword();
int EnterPassword();
int SelectMode();
void Guest_Mode();
void ADMIN_Mode();

#endif /* SMARHOME_H_ */