/*
 * DIO.h
 *
 * Created: 6/25/2022 5:37:31 PM
 *  Author: pc
 */ 
#include"DIO_Types.h"
#include "../../LIB/STD_Types.h"


#ifndef DIO_H_
#define DIO_H_
void DIO_SetPortDirection(DIO_Port_ID Port_ID,DIO_Direcrion Direction);
void DIO_SetPortValue(DIO_Port_ID Port_ID, STD_Value Value);
void DIO_SetPinDirection(DIO_Port_ID Port_ID,DIO_PIN_ID Pin_ID,DIO_Direcrion Direction);
void DIO_SetPinValue(DIO_Port_ID Port_ID,DIO_PIN_ID Pin_ID, STD_Value Value);
 STD_Value DIO_GetPinValue(DIO_Port_ID Port_ID,DIO_PIN_ID Pin_ID);
uint8 DIO_GetPortValue(DIO_Port_ID);



#endif /* DIO_H_ */