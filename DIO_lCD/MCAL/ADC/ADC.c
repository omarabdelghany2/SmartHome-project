/*
 * ADC.c
 *
 * Created: 6/29/2022 6:15:24 PM
 *  Author: pc
 */ 
#include "ADC.h"

void ADC_Intialize()

{	
	//5 STEPS TO INTIALIZE ADC 
		//1)SELECT VOLTAGE REFERNCE
	ADMUX_REG &= ADC_VOLTAGE_REF_CLR_msk;
	ADMUX_REG |= ADC_VOLTAGE_REF_SELECTOR_msk;
	////////////////////////*/////////////////////////////////*///////////////////////
	
	
	//2)SELCET MODE
	#if (ADC_MODE_SELECTOR==ADC_MODE_AUTO_TRIGGER)
		ClearBIT(ADCSRA_REG,5);			// WE GONE TO ADCSRA_REG REGISTER TO CHOOSE AUTO TRIGGER MODE THEN WE GONE TO SFIOR_REG TO CHOOSE THE MODE OF AUTO TRIGGER AS FREE RUNNING MODE 
		SFIOR_REG &=ADC_AUTO_TRIG_SRC_CLR_msk;
		SFIOR_REG|=ADC_AUTO_TRIGGER_SRCE_SELECTOR;
	
	#elif (ADC_MODE_SELECTOR==ADC_MODE_SINGLE_CONVERSION)
		SetBIT(ADCSRA_REG,5);
		SFIOR_REG &=ADC_AUTO_TRIG_SRC_CLR_msk;
		SFIOR_REG|=ADC_AUTO_TRIGGER_SRCE_SELECTOR;
		
	#endif
	///////////////////////////*////////////////////////////////*////////////////////
	
	
	 ///3) Select Adjustment
	 #if(ADC_ADJUSTMENT_SELCTOR==ADC_RIGHT_ADJUSTMENT)
			ClearBIT(ADMUX_REG,5);
			
	#elif(ADC_ADJUSTMENT_SELCTOR==ADC_LEFT_ADJUSTMENT)
			SetBIT(ADMUX,5);		
	#endif
	///////////////////////////////////////////////*/*/////////////////////
	
	
	// 4)CLEAR INTERTUPT FLAG
	SetBIT(ADCSRA_REG,4); //note clearing the flag by setting ADIF TO one not zero hintttt
	
	////////////
	// 5)ENABLE ADC
	SetBIT(ADCSRA_REG,7);
	
}

void ADC_StartConversion(ADC_Channel_Types ADC_Channel)
{
	///SELECT CHANNEL
	ADMUX_REG &= ADC_CHANNEL_SELECTOR_CLR_msk;
	ADMUX_REG |= ADC_Channel; 
	//START CONVERSION
	SetBIT(ADCSRA_REG,6);
}