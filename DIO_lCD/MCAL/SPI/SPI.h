/*
 * SPI.h
 *
 * Created: 9/7/2022 10:53:29 PM
 *  Author: pc
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "../../LIB/BIT_Math.h"
#include "SPI_REG.h"
#include "SPI_Types.h"
#include "SPI_Config.h"
#include "../DIO/DIO.h"
#include "../../LIB/STD_Types.h"

 void SPI_Master_Intialize();
 void SPI_Slave_Intialize();
 void SPI_Master_Transmit(uint8 SendByte);
 uint8 SPI_Master_Recieve();
 void SPI_Slave_Transmit(uint8 SendByte);
 uint8 SPI_Slave_Recieve();

#endif /* SPI_H_ */