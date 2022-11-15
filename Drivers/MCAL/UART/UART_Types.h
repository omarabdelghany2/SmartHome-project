/*
 * UART_types.h
 *
 * Created: 8/29/2022 12:13:44 AM
 *  Author: pc
 */ 


#ifndef UART_TYPES_H_
#define UART_TYPES_H_

//speed of transmission bit 1 in UCSRA_REG

#define UART_Speed_clr_msk				0b11111101
#define UART_Speed_double				0b00000010
#define UART_Speed_single				0b00000000


//multi processor communication Mode UCSRA_REG BIT0
#define UART_Mode_multi_clr_msk			0b11111110
#define UART_Mode_multi_disable			0b00000000
#define UART_Mode_multi_enable			0b00000001


//receiving interrupt enable UCSRB_REG	BIT7
#define UART_Recieve_interrupt_clr_msk	0b01111111
#define UART_Recieve_interrupt_enable	0b10000000
#define UART_Recieve_interrupt_disable	0b00000000


//transmitting interrupt enable UCSRB_REG	BIT6
#define UART_transmit_interrupt_clr_msk				0b10111111
#define UART_transmit_interrupt_enable				0b01000000
#define UART_transmit_interrupt_disable				0b00000000

//USART DATA REGISTER EMPTY INTERRUPT ENABLE	UCSRB_REG	BIT5
#define UART_DataRegister_Empty_interrupt_clr_msk		0b11011111
#define UART_DataRegister_Empty_interrupt_Enable		0b00100000
#define UART_DataRegister_Empty_interrupt_disable		0b00000000

//receiving enable								UCSRB_REG	BIT4
#define UART_Receiving_clr_msk							0b11101111
#define UART_Receiving_Enable							0b00010000
#define UART_Receiving_Disable							0b00000000

//Transmitting enable								UCSRB_REG	BIT3
#define UART_Transmitting_clr_msk						0b11110111
#define UART_Transmitting_Enable						0b00001000
#define UART_Transmitting_Disable						0b00000000

//UART SELECT accessing the UCSRC or the UBRRH register   USCRC_REG BIT7  will pull it out of config
#define UART_select_access_UCSRC						0b10000000
#define UART_select_access_UBRRH						0b00000000

//USART MODE SELECT between synchronous or asynchronous		USCRC_REG BIT6
#define UART_Mode_Synchronous							0b01000000		
#define UART_Mode_Asynchronous							0b00000000				


//PAIRTY MODE SELECTION							USCRC_REG		BIT5,4
#define UART_parity_clr_msk								0b11001111
#define UART_parity_disable								0b00000000
#define UART_parity_Enable_even							0b00100000
#define UART_parity_Enable_odd							0b00110000
//NUMBER OF STOP BITS	by transmitter the receiver ignores the setting
#define UART_Stop_Bit_One								0b00000000
#define UART_Stop_Bit_two								0b00001000

//character size select			***first in UCSZ_REG bit 1->2	****second in USCRB_REG BIT 2
#define UART_CharacterSize_5bit_first_UCSZ					0b00000000
#define UART_CharacterSize_5bit_SECOND_USCRB				0b00000000
#define UART_CharacterSize_6bit_first_UCSZ					0b00000010
#define UART_CharacterSize_6bit_SECOND_USCRB				0b00000000
#define UART_CharacterSize_7bit_first_UCSZ					0b00000100
#define UART_CharacterSize_7bit_SECOND_USCRB				0b00000000
#define UART_CharacterSize_8bit_first_UCSZ					0b00000110
#define UART_CharacterSize_8bit_SECOND_USCRB				0b00000000
#define UART_CharacterSize_9bit_first_UCSZ					0b00000110
#define UART_CharacterSize_9bit_SECOND_USCRB				0b00000100





#endif /* UART_TYPES_H_ */