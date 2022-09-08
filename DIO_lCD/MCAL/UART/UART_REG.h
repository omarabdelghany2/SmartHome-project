/*
 * UART_REG.h
 *
 * Created: 8/29/2022 12:13:07 AM
 *  Author: pc
 */ 
#include "../../LIB/STD_Types.h"

#ifndef UART_REG_H_
#define UART_REG_H_

#define UDR_REG			(*(volatile uint8*)0x2C)  
#define UCSRA_REG		(*(volatile uint8*)0x2B)
#define UCSRB_REG		(*(volatile uint8*)0x2A)
#define UCSRC_REG		(*(volatile uint8*)0x40)
#define UBRRH_REG		(*(volatile uint8*)0x40)
#define UBRRL_REG		(*(volatile uint8*)0x29)






#endif /* UART_REG_H_ */