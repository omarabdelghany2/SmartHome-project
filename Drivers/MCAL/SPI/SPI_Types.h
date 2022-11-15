/*
 * SPI_Types.h
 *
 * Created: 9/7/2022 10:52:17 PM
 *  Author: pc
 */ 


#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_

//prescaling data types for clock  bit1 bit 0 in SPCR
#define SPI_prescaling_4_Single_Speed		0b00000000
#define SPI_prescaling_16_Single_Speed		0b00000001
#define SPI_prescaling_64_Single_Speed		0b00000010
#define SPI_prescaling_128_Single_Speed		0b00000011
#define SPI_prescaling_2_double_Speed		0b00000000
#define SPI_prescaling_8_double_Speed		0b00000001
#define SPI_prescaling_32_double_Speed		0b00000010
#define SPI_prescaling_64_double_Speed		0b00000011


//Choosing master or slave mood bit 4 in SPCR
#define SPI_Master_Mode						0b00010000	
#define SPI_Slave_Mode						0b00000000	

//choosing the speed double or single bit 0 in SPSR
#define SPI_DoubleSpeed						0b00000001
#define SPI_SingleSpeed						0b00000000

#endif /* SPI_TYPES_H_ */