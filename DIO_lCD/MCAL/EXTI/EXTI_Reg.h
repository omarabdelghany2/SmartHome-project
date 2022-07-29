/*
 * EXTI_Reg.h
 *
 * Created: 7/29/2022 9:35:29 PM
 *  Author: pc
 */ 


#ifndef EXTI_REG_H_
#define EXTI_REG_H_

#define	MCUCR_REG		(*(volatile uint8*)0x55)
#define	MCUCSR_REG		(*(volatile uint8*)0x54)
#define	GICR_REG		(*(volatile uint8*)0x5B)
#define	GIFR_REG		(*(volatile uint8*)0x5A)
#define	SREG_REG		(*(volatile uint8*)0x5F)



#endif /* EXTI_REG_H_ */