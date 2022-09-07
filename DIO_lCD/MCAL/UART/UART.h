/*
 * UART.h
 *
 * Created: 8/29/2022 12:14:09 AM
 *  Author: pc
 */ 

#ifndef UART_H_
#define UART_H_

#include "UART_REG.h"
#include "UART_Config.h"
#include "../../LIB/BIT_Math.h"




void UART_Intialize();

void UART_Transmit(uint8 Send_Byte);

uint8 UART_Receive();



#endif /* UART_H_ */