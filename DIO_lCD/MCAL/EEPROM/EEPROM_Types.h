/*
 * EEPROM_Types.h
 *
 * Created: 9/19/2022 8:38:43 PM
 *  Author: omarz
 */ 


#ifndef EEPROM_TYPES_H_
#define EEPROM_TYPES_H_


//interrupt types bin3 in EECR
#define EEPROM_Interrupt_Enable			0b00001000
#define EEPROM_Interrupt_Disable		0b00000000


#define EEPROM_Write_Enable				0b00000010
#define EEPROM_Write_Disable			0b00000000



#define EEPROM_Master_Write_Enable		0b00000100
#define EEPROM_Master_Write_Disable		0b00000000

#define EEPROM_Rread_Enable				0b00000001
#define EEPROM_Rread_Disable			0b00000000




#define EEPROM_Write_Complete			0b00000010









#endif /* EEPROM_TYPES_H_ */