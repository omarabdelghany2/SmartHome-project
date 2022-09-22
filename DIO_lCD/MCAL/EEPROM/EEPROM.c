/*
 * EEPROM.c
 *
 * Created: 9/19/2022 8:37:25 PM
 *  Author: OMARZAR3
 */ 
#include "EEPROM.h"

void EEPROM_Write(uint16 Address,uint8 Data)
{
	while(EECR_REG&(EEPROM_Write_Complete));
	EEARL_REG=Address;
	EEDR_REG=Data;
	EECR_REG|=EEPROM_Master_Write_Enable;
	EECR_REG|=EEPROM_Write_Enable;
	
}
uint8 EEPROM_Read(uint16 Address)
{
	while(EECR_REG&(EEPROM_Write_Complete));
	EEARL_REG=Address;
	EECR_REG|=EEPROM_Rread_Enable;
	return(EEDR_REG);
}