/*
 * ADC_Reg.h
 *
 * Created: 6/29/2022 6:15:37 PM
 *  Author: pc
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_

#define  ADMUX_REG				*((volatile uint8*)0x27)
#define  ADCH_REG				*((volatile uint8*)0x25)
#define  ADCL_REG				*((volatile uint8*)0x24)
#define  ADCSRA_REG				*((volatile uint8*)0x26)
#define  ADCLH_REG				*((volatile uint16*)0x24)
#define  SFIOR_REG				*((volatile uint8*)0x50)






#endif /* ADC_REG_H_ */