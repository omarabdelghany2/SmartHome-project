/*
 * ADC.h
 *
 * Created: 6/29/2022 6:16:44 PM
 *  Author: pc
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include "ADC_Config.h"
#include "ADC_Reg.h"
#include "ADC_Types.h"

typedef enum
{
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
	}ADC_Channel_Types;

void ADC_Intialize();

void ADC_StartConversion(ADC_Channel_Types ADC_channel);

uint16 ADC_GetResult();



////////////
//ADC INTERRUPT ENABLE AND DISABLE
void ADC_EnableInt();
void ADC_DisableInt();

void ADC_SetCallback(void(*CopyFuncPTR)(void));
void __vector_16(void);

#endif /* ADC_H_ */