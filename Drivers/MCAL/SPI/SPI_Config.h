/*
 * SPI_config.h
 *
 * Created: 9/7/2022 10:52:37 PM
 *  Author: pc
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_
#include "SPI_Types.h"

//prescaling data types for clock  bit1 bit 0 in SPCR



#define SPI_Prescaling_Selector				SPI_prescaling_16_Single_Speed		
/*
 SPI_prescaling_4_Single_Speed		
 SPI_prescaling_16_Single_Speed		
 SPI_prescaling_64_Single_Speed		
 SPI_prescaling_128_Single_Speed		
 SPI_prescaling_2_double_Speed		
 SPI_prescaling_8_double_Speed		
 SPI_prescaling_32_double_Speed		
 SPI_prescaling_64_double_Speed		
*/


///////////////////////////////////////////////////////////////////////////


#define SPI_Speed_Selector				SPI_SingleSpeed


//choosing the speed double or single bit 0 in SPSR
/*
SPI_DoubleSpeed						
SPI_SingleSpeed						
*/
		


#endif /* SPI_CONFIG_H_ */