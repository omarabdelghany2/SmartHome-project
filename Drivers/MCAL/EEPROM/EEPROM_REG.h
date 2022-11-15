/*
 * EEPROM_REG.h
 *
 * Created: 9/19/2022 8:37:58 PM
 *  Author: omarz
 */ 


#ifndef EEPROM_REG_H_
#define EEPROM_REG_H_
#include "../../LIB/STD_Types.h"


#define EEARH_REG	(*(volatile uint8* )0x3F)       
#define EEARL_REG	(*(volatile uint8* )0x3E)   
#define EEDR_REG	(*(volatile uint8* )0x3D)   
#define EECR_REG	(*(volatile uint8* )0x3C)    
#define EEAR_REG	(*(volatile uint16*)0x3E)   

#endif /* EEPROM_REG_H_ */