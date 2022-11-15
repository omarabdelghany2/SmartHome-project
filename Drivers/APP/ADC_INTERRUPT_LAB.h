/*
 * ADC_INTERRUPT_LAB.h
 *
 * Created: 8/5/2022 3:06:55 AM
 *  Author: pc
 */ 


#ifndef ADC_INTERRUPT_LAB_H_
#define ADC_INTERRUPT_LAB_H_

#define F_CPU 1000000UL
#include "util/delay.h"
#include "../MCAL/ADC/ADC.h"
#include "../MCAL/DIO/DIO.h"
#include "../LIB/BIT_Math.h"
#include "../MCAL/ADC/ADC_Types.h"
#include "../LIB/STD_Types.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/GIE/GIE.h"
#include <stdlib.h>



void ADC_interrupt_Lab();
void ADC_Complete_Conv_ISR();



#endif /* ADC_INTERRUPT_LAB_H_ */