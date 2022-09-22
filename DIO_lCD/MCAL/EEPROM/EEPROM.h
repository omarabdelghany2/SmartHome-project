/*
 * EEPROM.h
 *
 * Created: 9/19/2022 8:37:42 PM
 *  Author: omarz
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "EEPROM_Types.h"
#include "EEPROM_REG.h"


void EEPROM_Write(uint16 Address,uint8 Data);

uint8 EEPROM_Read(uint16 Address);

#endif /* EEPROM_H_ */