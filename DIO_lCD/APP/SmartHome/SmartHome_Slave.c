/*
 * SmartHome_Slave.c
 *
 * Created: 10/4/2022 9:18:09 PM
 *  Author: pc
 */ 
#define F_CPU 1000000
#include "SmartHome_Slave.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../HAL/LCD/lCD.h"
#include "avr/delay.h"

void SmartHome_App_Start_Slave()


{
		ADC_Intialize();
		LCD_Intialize();
		DIO_SetPortDirection(PORTD,Output);
		DIO_SetPinDirection(PORTA,0,Input);//TEMPARTURE SENSOR
		DIO_SetPortDirection(PORTC,Output);
		SPI_Slave_Intialize();
	
	uint8 Recieved;
	uint8 Set_temp = 0;
	
	while(1)
	{
		
		Recieved=SPI_Slave_Recieve();
		
		switch(Recieved)
		
		{
			case 1 : //room 1
			Recieved=SPI_Slave_Recieve();
			if(Recieved=='N')
				DIO_SetPinValue(PORTD,7,HIGH);
			else if(Recieved=='F')
				DIO_SetPinValue(PORTD,7,LOW);
			Recieved=SPI_Slave_Recieve();
		
				break;	
			
			
			case 2 : //room 2
			Recieved=SPI_Slave_Recieve();
			if(Recieved=='N')
				DIO_SetPinValue(PORTD,6,HIGH);
			else 
				DIO_SetPinValue(PORTD,6,LOW);
	
			break;				
			
			
			case 3 : //room 3
			Recieved=SPI_Slave_Recieve();
			if(Recieved=='N')
				DIO_SetPinValue(PORTD,5,HIGH);
			else if(Recieved=='F')
				DIO_SetPinValue(PORTD,5,LOW);
		
			break;				
						
			case 4 : //room 4
			Recieved=SPI_Slave_Recieve();
			if(Recieved=='N')
				DIO_SetPinValue(PORTD,4,HIGH);
			else if(Recieved=='F')
				DIO_SetPinValue(PORTD,4,LOW);
			
			break;
			//TV
			case 5:
			Recieved=SPI_Slave_Recieve();
			if(Recieved=='N')
			DIO_SetPinValue(PORTD,3,HIGH);
			else if(Recieved=='F')
			DIO_SetPinValue(PORTD,3,LOW);
			
			break;
			//CONDITIONER
			
			case 6 :
			
			Recieved=SPI_Slave_Recieve();
			
			if(Recieved=='C') //C FOR CONTROL (ON OR OFF)
			{
				
				Recieved=SPI_Slave_Recieve();
				
				if(Recieved=='N')
					DIO_SetPinValue(PORTD,2,HIGH);
				else
					DIO_SetPinValue(PORTD,2,LOW);
			}
				
			else if(Recieved=='S')// FOR adjust the temprature
			{
					
					Recieved=SPI_Slave_Recieve();
					Set_temp=(Recieved-'0')*10;
					Recieved=SPI_Slave_Recieve();
					Set_temp+=(Recieved-'0');	
					ADC_StartConversion(ADC_Channel_0);
					_delay_ms(100);
					uint16 RESULT =ADC_GetResult();
					
					//CALCULATIONS TO MAKE THE ANLOG RESULT ACCURATE OF SENSOR TEMPRATURE
					if((RESULT<25)&&(RESULT>6))
						RESULT--;
					if (RESULT<43&&RESULT>=25)
						RESULT-=2;
					if(RESULT>=43)
						RESULT-=3;
						
					Set_temp*=2;	
					//THE CALCULATIONS  ENDS HERE
					if (RESULT>Set_temp)
					{
						DIO_SetPinValue(PORTD,PIN2,HIGH);
						
					}
					else
					{
						DIO_SetPinValue(PORTD,PIN2,LOW);
					}	
						
				}
			
			
				
				break;
				
							
			
									
							
		}
		
		
		
		
	}
	
}
