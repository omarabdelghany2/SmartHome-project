/*
 * UART.c
 *
 * Created: 8/29/2022 12:14:19 AM
 *  Author: pc
 */ 
#include "UART.h"

void UART_Intialize()
{
	//1)Clearing the register of baud rate //selected baud rate9600 

	uint16 BaudRate=12;
	UBRRL_REG=(uint8)BaudRate;
	UBRRH_REG=(uint8)(BaudRate>>8);
	 

	//2)ENABLE TRANSMIT AND RECIEVE 
	UCSRB_REG |= UART_ReceivingStatus;
	UCSRB_REG |= UART_TransmittingStatus;
	
	//3)set the format 8 data bit no parity and 1 stop bits
					//note(will set bit 7 of the next register to allow me to access UCSRC_REG not UBRRH_REG)
	SetBIT(UCSRC_REG,7);
	UCSRC_REG |= UART_CharacterSize_selector_UCSZ ;
	UCSRC_REG |= UART_Stop_Bits_number_selector;
	UCSRC_REG |= UART_parity_selector;
	//4)CHOOSING THE SPeed will make it normal not double
	UCSRA_REG |= UART_Speed_selector;	
}
void UART_Transmit(uint8 Send_Byte)
{
	while(!GetBIT(UCSRA_REG,5));
	UDR_REG =Send_Byte;	
}

uint8 UART_Receive()
{
	while(!GetBIT(UCSRA_REG,7));
	
	uint8 recieved=UDR_REG;
	return (recieved);
}