/*
 * UART_Config.h
 *
 * Created: 8/29/2022 12:13:25 AM
 *  Author: pc
 */ 

#include "UART_types.h"
#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*
speed of transmission selectors

UART_Speed_double
UART_Speed_single

*/

#define UART_Speed_selector		UART_Speed_double

////////////////////////////////////////////////////////////////////////////////////////////////////
/*

UART mode multi ENABLE OR DISABLE

UART_Mode_multi_disable
UART_Mode_multi_enable
*/


#define UART_Mode_multi_selector	UART_Mode_multi_disable
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

		receiving enable								UCSRB_REG	BIT4
 UART_Receiving_clr_msk						
 UART_Receiving_Enable						
 UART_Receiving_Disable						


*/

#define UART_ReceivingStatus		UART_Receiving_Enable			

////////////////////////////////////////////////////////////////////////////////////////////////////
/*

Transmitting enable								UCSRB_REG	BIT3
 UART_Transmitting_clr_msk
 UART_Transmitting_Enable					
 UART_Transmitting_Disable						
*/


#define UART_TransmittingStatus			UART_Transmitting_Enable

////////////////////////////////////////////////////////////////////////////////////////////////////

/*

transmitting interrupt enable or disable

 UART_transmit_interrupt_enable	
 UART_transmit_interrupt_disable	

*/




#define UART_Transmitting_interrupt_status	 UART_transmit_interrupt_disable	
////////////////////////////////////////////////////////////////////////////////////////////////////
/*

receiving interrupt enable or disable

 UART_Recieve_interrupt_enable	
 UART_Recieve_interrupt_disable	

*/
////////////////////////////////////////////////////////////////////////////////////////////////////
#define UART_Receiving_interrupt_status		  UART_Recieve_interrupt_disable	


/*

select the mode synchronous or asynchronous
UART_Mode_Asynchronous		
UART_Mode_Synchronous		

*/
#define UART_Mode_Synchronous_selector		UART_Mode_Synchronous
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
parity mode selectors
UART_parity_disable								
UART_parity_Enable_even						
UART_parity_Enable_odd


*/
#define UART_parity_selector				UART_parity_disable		

////////////////////////////////////////////////////////////////////////////////////////////////////


/*

			UART stop bits number
UART_Stop_Bit_One								
UART_Stop_Bit_two								


*/

#define UART_Stop_Bits_number_selector		UART_Stop_Bit_One	
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
UART_CHARACTER SIZE

 UART_CharacterSize_5bit_first_UCSZ					
 UART_CharacterSize_5bit_SECOND_USCRB				
 UART_CharacterSize_6bit_first_UCSZ					
 UART_CharacterSize_6bit_SECOND_USCRB				
 UART_CharacterSize_7bit_first_UCSZ				
 UART_CharacterSize_7bit_SECOND_USCRB				
 UART_CharacterSize_8bit_first_UCSZ					
 UART_CharacterSize_8bit_SECOND_USCRB			
 UART_CharacterSize_9bit_first_UCSZ					
 UART_CharacterSize_9bit_SECOND_USCRB				


*/

#define  UART_CharacterSize_selector_UCSZ			 UART_CharacterSize_8bit_first_UCSZ	
#define  UART_CharacterSize_selector_USCRB			  UART_CharacterSize_8bit_SECOND_USCRB	
#endif /* UART_CONFIG_H_ */