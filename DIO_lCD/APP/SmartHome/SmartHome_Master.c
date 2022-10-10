/*
 * SmartHome.c
 *
 * Created: 9/26/2022 3:26:55 PM
 *  Author: pc
 */ 
#define F_CPU   1000000 
#include "SmartHome_Master.h"
#include "avr/delay.h"
void SmartHome_App_Start_Master()
{

	SPI_Master_Intialize();	
	Keypad_init();
	LCD_Intialize();
	DIO_SetPinDirection(PORTD,0,Output);
	DIO_SetPinDirection(PORTD,1,Output);
	DIO_SetPinDirection(PORTD,2,Output);
	
	//LETS SELECT MODE
		uint8 mode =SelectMode();
		
		if(mode==ADMIN)
		{
			
				 uint8 Readed = EEPROM_Read(4);
				 
				 
				 
				 if(Readed!='S')//so its the first time to run
				 {
					 SetPassword();
					 
				 }
				 else //so lets take password from user
				 {
					 
					 int returned =EnterPassword();
					 
					 
					 while(returned==1)
					 {
						 _delay_ms(1000);
						 LCD_WriteCmd(0x01);
						 LCD_WriteString("wait20second",0,0);
						 _delay_ms(20000);
						 returned=EnterPassword();
					 }
					 
					 
				 }
			ADMIN_Mode();
		}
		else
		{
			
			Guest_Mode();
		}
	
	
	
	
	 
	 //lets choose the mode (ADMIN or GUEST)/////////*///////////////*

	 
	 
}
void SetPassword()
{
	LCD_WriteCmd(0X01);
	LCD_WriteString("Set ADMIN Pass",0,0);
	LCD_GoToPos(1,0);
	//reading the password from the user
	uint8 keypad_reading=NO_KEY_PRESSED;
	for (int i=0;i<4;i++)
	{
		while(1)
		{
			
			keypad_reading  = Keypad_read(ONE_PRESS);
			if (keypad_reading != NO_KEY_PRESSED)
			{
				EEPROM_Write(i,keypad_reading);
				LCD_WriteData(keypad_reading);
				break;
			}
		}
	}
	
	LCD_WriteCmd(0x01);
	LCD_WriteString("password saved",0,0);
	EEPROM_Write(4,'S');
}

int EnterPassword()
{
	 int pass_status= 1;
	 LCD_WriteCmd(0x01);
	 LCD_WriteString("enter your pass",0,0);
	 LCD_GoToPos(1,0);
	 uint8 keypad_reading=NO_KEY_PRESSED;
	 for (int j=0;j<5;j++)
	 {
		 pass_status=1;
		 
		 for (int i=0;i<4;i++)
		 {
			 while(1)
			 {
				 
				 keypad_reading  = Keypad_read(ONE_PRESS);
				 if (keypad_reading != NO_KEY_PRESSED)
				 {
					 LCD_WriteData(keypad_reading);
					 if(keypad_reading!=EEPROM_Read(i))
						pass_status=0;
					 break;
				 }
			 }
		 }
		 if(pass_status==1)
		 {
			 LCD_WriteCmd(0x01);
			 LCD_WriteString("Right",0,0);
			 return(Right);
		 }
		 else
		 {
			 LCD_WriteCmd(0x01);
			 LCD_WriteString("Wrong",0,0);
			 _delay_ms(1000);
			  LCD_WriteString("enter again",0,0);
			 
			 if(j==4)
			 {
				 LCD_WriteCmd(0x01);
				 LCD_WriteString("Block",0,0);
				 return(wrong);
			 }
			 
		 }
		 
	 }
	
}


int SelectMode()
{
	 LCD_WriteCmd(0x01);
	 LCD_WriteString("SelectMode",0,0);
	 _delay_ms(500);
	 LCD_WriteCmd(0x01);
	 LCD_WriteString("1)ADMIN  2)GUEST",0,0);
	 uint8 keypad_reading=NO_KEY_PRESSED;
	 while(1)
	 {
		 
		 keypad_reading  = Keypad_read(ONE_PRESS);
		 if (keypad_reading != NO_KEY_PRESSED)
		 {
			 LCD_WriteData(keypad_reading);
			 
			 return (keypad_reading) ;
			 
		 }
	 }
}

void Guest_Mode()
{
		DIO_SetPinValue(PORTD,0,LOW);
		DIO_SetPinValue(PORTD,1,HIGH);
		DIO_SetPinValue(PORTD,2,LOW);
									

		LCD_WriteCmd(0x01);
		LCD_WriteString("1)ROOM1 2)ROOM2",0,0);
		LCD_WriteString("3)ROOM34)ROOM4",1,0);
		uint8 keypad_reading=NO_KEY_PRESSED;
		while(1)
		{
			
			keypad_reading  = Keypad_read(ONE_PRESS);
			if (keypad_reading != NO_KEY_PRESSED)
			{
				LCD_WriteData(keypad_reading);
				break;
			}

		}
		switch(keypad_reading)
			{
				case '1': 
					LCD_WriteCmd(0x01);
					LCD_WriteString("ROOM1 :1)ON",0,0);
					LCD_WriteString("2)OFF 3)RET",1,0);
					while(1)
					{
						
						keypad_reading  = Keypad_read(ONE_PRESS);
						if (keypad_reading != NO_KEY_PRESSED)
						{
							LCD_WriteData(keypad_reading);
							break;
						}

					}	
					
						if(keypad_reading=='1')
						{
							//will send 1 for room 1 and and O for ON
							SPI_Master_Transmit(1);
							SPI_Master_Transmit('N');
						
							Guest_Mode();
						
						}	
						else if (keypad_reading=='2')	
						{
							SPI_Master_Transmit(1);
							SPI_Master_Transmit('F');
							
							Guest_Mode();
							
						}	
						else
						{
							//SPI_Master_Transmit(0);
							
							Guest_Mode();
						}	
					break;
					case '2':
					LCD_WriteCmd(0x01);
					LCD_WriteString("ROOM2 :1)ON",0,0);
					LCD_WriteString("2)OFF3)RET",1,0);
					while(1)
					{
						
						keypad_reading  = Keypad_read(ONE_PRESS);
						if (keypad_reading != NO_KEY_PRESSED)
						{
							LCD_WriteData(keypad_reading);
							break;
						}

					}
					
					if(keypad_reading=='1')
					{
							SPI_Master_Transmit(2);
							SPI_Master_Transmit('N');
							
							Guest_Mode();
							
					}
					else if (keypad_reading=='2')
					{
							SPI_Master_Transmit(2);
							SPI_Master_Transmit('F');
						
							Guest_Mode();
					}
					else
					{
						Guest_Mode();
					}
					break;
					
					case '3':
					LCD_WriteCmd(0x01);
					LCD_WriteString("ROOM3 :1)ON",0,0);
					LCD_WriteString("2)OFF3)RET",1,0);
					while(1)
					{
						
						keypad_reading  = Keypad_read(ONE_PRESS);
						if (keypad_reading != NO_KEY_PRESSED)
						{
							LCD_WriteData(keypad_reading);
							break;
						}

					}
					
					if(keypad_reading=='1')
					{
							SPI_Master_Transmit(3);
							SPI_Master_Transmit('N');
							
							Guest_Mode();
					}
					else if (keypad_reading=='2')
					{
							SPI_Master_Transmit(3);
							SPI_Master_Transmit('F');
							
							Guest_Mode();
					}
					else
					{
						Guest_Mode();
					}
					break;
					
					
					case '4':
					LCD_WriteCmd(0x01);
					LCD_WriteString("ROOM4 :1)ON",0,0);
					LCD_WriteString("2)OFF3)RET",1,0);
					while(1)
					{
						
						keypad_reading  = Keypad_read(ONE_PRESS);
						if (keypad_reading != NO_KEY_PRESSED)
						{
							LCD_WriteData(keypad_reading);
							break;
						}

					}
					
					if(keypad_reading=='1')
					{
							SPI_Master_Transmit(4);
							SPI_Master_Transmit('N');
							
							Guest_Mode();
					}
					else if (keypad_reading=='2')
					{
							SPI_Master_Transmit(4);
							SPI_Master_Transmit('F');
							
							Guest_Mode();
					}
					else
					{
						Guest_Mode();
					}
					break;
			}
		

		
}

void ADMIN_Mode()
{
		DIO_SetPinValue(PORTD,0,HIGH);
		DIO_SetPinValue(PORTD,1,LOW);
		DIO_SetPinValue(PORTD,2,LOW);
		LCD_WriteCmd(0x01);
			LCD_WriteString("1)ROOM1 2)ROOM2",0,0);
			LCD_WriteString("3)ROOM3 4)more",1,0);
		uint8 keypad_reading=NO_KEY_PRESSED;
		while(1)
		{
			
			keypad_reading  = Keypad_read(ONE_PRESS);
			if (keypad_reading != NO_KEY_PRESSED)
			{
				LCD_WriteData(keypad_reading);
				break;
			}

		}
		switch(keypad_reading)
		{
			case '1':
			LCD_WriteCmd(0x01);
			LCD_WriteString("ROOM1 :1)ON",0,0);
			LCD_WriteString("2)OFF3)RET",1,0);
			while(1)
			{
				
				keypad_reading  = Keypad_read(ONE_PRESS);
				if (keypad_reading != NO_KEY_PRESSED)
				{
					LCD_WriteData(keypad_reading);
					break;
				}

			}
			
			if(keypad_reading=='1')
			{
			SPI_Master_Transmit(1);
		    SPI_Master_Transmit('N');
		
				ADMIN_Mode();
			}
			else if (keypad_reading=='2')
			{
			SPI_Master_Transmit(1);
			SPI_Master_Transmit('F');
		
				ADMIN_Mode();
			}
			else
			{
				ADMIN_Mode();
			}
			break;
			case '2':
			LCD_WriteCmd(0x01);
			LCD_WriteString("ROOM2 :1)ON",0,0);
			LCD_WriteString("2)OFF3)RET",1,0);
			while(1)
			{
				
				keypad_reading  = Keypad_read(ONE_PRESS);
				if (keypad_reading != NO_KEY_PRESSED)
				{
					LCD_WriteData(keypad_reading);
					break;
				}

			}
			
			if(keypad_reading=='1')
			{
			SPI_Master_Transmit(2);
			SPI_Master_Transmit('N');
			
				ADMIN_Mode();
			}
			else if (keypad_reading=='2')
			{
			SPI_Master_Transmit(2);
			SPI_Master_Transmit('F');
		
				ADMIN_Mode();
			}
			else
			{
				ADMIN_Mode();
			}
			break;
			
			case '3':
			LCD_WriteCmd(0x01);
			LCD_WriteString("ROOM3 :1)ON",0,0);
			LCD_WriteString("2)OFF3)RET",1,0);
			while(1)
			{
				
				keypad_reading  = Keypad_read(ONE_PRESS);
				if (keypad_reading != NO_KEY_PRESSED)
				{
					LCD_WriteData(keypad_reading);
					break;
				}

			}
			
			if(keypad_reading=='1')
			{
			SPI_Master_Transmit(3);
			SPI_Master_Transmit('N');
		
				ADMIN_Mode();
			}
			else if (keypad_reading=='2')
			{
			SPI_Master_Transmit(3);
			SPI_Master_Transmit('F');
			
				ADMIN_Mode();
			}
			else
			{
				ADMIN_Mode();
			}
			break;
			
			case '4':
			LCD_WriteCmd(0x01);
		    LCD_WriteString("1)ROOM4 2)TV ",0,0);
		    LCD_WriteString("3)COND 4)RET",1,0);
		while(1)
			{
					
					keypad_reading  = Keypad_read(ONE_PRESS);
					if (keypad_reading != NO_KEY_PRESSED)
					{
						LCD_WriteData(keypad_reading);
						break;
					}

			}
			switch(keypad_reading)//MORE
			{
				case '1' :
				LCD_WriteCmd(0x01);
				LCD_WriteString("ROOM4 :1)ON",0,0);
				LCD_WriteString("2)OFF 3)RET",1,0);
				while(1)
				{
					
					keypad_reading  = Keypad_read(ONE_PRESS);
					if (keypad_reading != NO_KEY_PRESSED)
					{
						LCD_WriteData(keypad_reading);
						break;
					}

				}
				
				if(keypad_reading=='1')
				{
			SPI_Master_Transmit(4);
			SPI_Master_Transmit('N');
			
					ADMIN_Mode();
				}
				else if (keypad_reading=='2')
				{
			SPI_Master_Transmit(4);
			SPI_Master_Transmit('F');
			
					ADMIN_Mode();
				}
				else
				{
					ADMIN_Mode();
				}
				break;
				
				
				case '2':
				LCD_WriteCmd(0x01);
				LCD_WriteString("TV :1)ON",0,0);
				LCD_WriteString("2)OFF 3)RET",1,0);
				while(1)
				{
					
					keypad_reading  = Keypad_read(ONE_PRESS);
					if (keypad_reading != NO_KEY_PRESSED)
					{
						LCD_WriteData(keypad_reading);
						break;
					}

				}
				
				if(keypad_reading=='1')
				{
			SPI_Master_Transmit(5);
			SPI_Master_Transmit('N');
			
					ADMIN_Mode();
				}
				else if (keypad_reading=='2')
				{
			SPI_Master_Transmit(5);
			SPI_Master_Transmit('F');
			
					ADMIN_Mode();
				}
				else
				{
					ADMIN_Mode();
				}
				break;
				case '3' :
				LCD_WriteCmd(0x01);
				LCD_WriteString("1)SET TEMP ",0,0);
				LCD_WriteString("2)CONTROL3)RET",1,0);
				while(1)
				{
					
					keypad_reading  = Keypad_read(ONE_PRESS);
					if (keypad_reading != NO_KEY_PRESSED)
					{
						LCD_WriteData(keypad_reading);
						break;
					}

				}
				switch(keypad_reading)
				{
					
					case '1' :
					LCD_WriteCmd(0x01);
					LCD_WriteString("SET TEMP :",0,0);
					SPI_Master_Transmit(6);
					SPI_Master_Transmit('S');
					for(int i=0;i<2;i++)
					{
						while(1)
						{
							
							keypad_reading  = Keypad_read(ONE_PRESS);
							if (keypad_reading != NO_KEY_PRESSED)
							{
								LCD_WriteData(keypad_reading);
						//send (keypad reading by SPI)
						SPI_Master_Transmit(keypad_reading);								
								keypad_reading=NO_KEY_PRESSED;
								break;
							}
							

						}
						LCD_GoToPos(11-i,0);
						LCD_WriteData(keypad_reading);
						_delay_ms(500);
						

					}
					
					break;
					case '2':
					LCD_WriteCmd(0x01);
					LCD_WriteString("1)ON, 2)OFF",0,0);
					LCD_WriteString("3)RET",1,0);
					while(1)
					{
						
						keypad_reading  = Keypad_read(ONE_PRESS);
						if (keypad_reading != NO_KEY_PRESSED)
						{
							LCD_WriteData(keypad_reading);
							break;
						}
						

					}
					if(keypad_reading=='1')
					{//send ON to cond
						SPI_Master_Transmit(6);
						SPI_Master_Transmit('C');
						SPI_Master_Transmit('N');
					
					}
					else if(keypad_reading=='2')
					{//send off to cond
						SPI_Master_Transmit(6);
						SPI_Master_Transmit('C');
						SPI_Master_Transmit('F');
										
					}
					else
					ADMIN_Mode();
					break;
					
					case '3':
					ADMIN_Mode();
					break;
				}
				case '4':
				ADMIN_Mode();
				break;
			break;
			}
		}
}