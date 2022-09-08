/*
 * SPI.c
 *
 * Created: 9/7/2022 10:53:42 PM
 *  Author: pc
 */ 
#include "SPI.h"


 void SPI_Master_Intialize()
 {
	//1) set MOSI ,SCK,SS as output pins and MISO to input pin
	 
		 DIO_SetPinDirection(PORTB,4,Output);//SS
		 DIO_SetPinDirection(PORTB,5,Output);//MOSI
		 DIO_SetPinDirection(PORTB,7,Output);//SCK
		 DIO_SetPinDirection(PORTB,6,Input);//MISO
	//enable SPI
		SetBIT(SPCR_REG,6);	 
	//2) set SS pin to high	 
		DIO_SetPinValue(PORTB,4,HIGH);
	//3) enable SPIin master mood
		 SPCR_REG |= SPI_Master_Mode;
	//4) Choose prescaling 
		SPCR_REG |= SPI_Prescaling_Selector;
	//5) choose speed 
		SPSR_REG |= SPI_Speed_Selector;		 
		 	
 }
  void SPI_Master_Transmit(uint8 SendByte)
  {
	  //pull SS to low
	  DIO_SetPinValue(PORTB,4,LOW);
	  
	  //write data to SPDR register
	  SPDR_REG =SendByte;
	  
	  //WAIT until Transmit ends
	  while(!GetBIT(SPSR_REG,7));
	  
	  //flush received data 
	  uint8 flusher =SPDR_REG;
	  
	  //set SS to high
	  DIO_SetPinValue(PORTB,4,HIGH);
  }
  
  uint8 SPI_Master_Recieve()
  {
	  
	  
	 //1)set dumy value to SPDR
	 SPDR_REG=0xff;
	 //2)Wait until recieving complete
	 while(!GetBIT(SPCR_REG,7));
	 //3 return the received value
	 uint8 recieved=SPDR_REG;
	 return(recieved);
  }