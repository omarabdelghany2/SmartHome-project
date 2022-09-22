/*
 * I2C.h
 *
 * Created: 9/21/2022 3:21:37 AM
 *  Author: omarz
 */ 


#ifndef I2C_H_
#define I2C_H_



void I2C_StartCondition();
void I2C_RestartCondition();
void I2C_StopCondition();
void I2C_SendACK();
uint8 I2C_GetACK();
void ITC_SendByte(uint8 Byte);
uint8 ITC_GetByte();
void I2C_P_Clock();
void I2C_NACK();//END COMMUNICATION

#endif /* I2C_H_ */