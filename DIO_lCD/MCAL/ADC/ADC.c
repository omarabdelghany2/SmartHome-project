/*
 * ADC.c
 *
 * Created: 6/29/2022 6:15:24 PM
 *  Author: pc
 */ 
#include "ADC.h"
#include "../../LIB/STD_Types.h"
#include "../DIO/DIO_Types.h"
#include "../DIO/DIO.h"


static void(*ADC_CallBackPtr)(void)=NULL;


void ADC_Intialize()

{	
	//5 STEPS TO INTIALIZE ADC 
		//1)SELECT VOLTAGE REFERNCE
	ADMUX_REG &= ADC_VOLTAGE_REF_CLR_msk;
	ADMUX_REG |= ADC_VOLTAGE_REF_SELECTOR_msk;
	////////////////////////*/////////////////////////////////*///////////////////////
	
	
	//2)SELCET MODE
	#if (ADC_MODE_SELECTOR==ADC_MODE_AUTO_TRIGGER)
		SetBIT(ADCSRA_REG,5);			// WE GONE TO ADCSRA_REG REGISTER TO CHOOSE AUTO TRIGGER MODE THEN WE GONE TO SFIOR_REG TO CHOOSE THE MODE OF AUTO TRIGGER AS FREE RUNNING MODE 
		SFIOR_REG &=ADC_AUTO_TRIG_SRC_CLR_msk;
		SFIOR_REG|=ADC_AUTO_TRIGGER_SRCE_SELECTOR;
	
	#elif (ADC_MODE_SELECTOR==ADC_MODE_SINGLE_CONVERSION)
		ClearBIT(ADCSRA_REG,5);
		
		
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

uint16 ADC_GetResult()
{
	
	/*SINGLE CONVERSION GET RESULT FUNCTION
	while(!GetBIT(ADCSRA_REG,4));//hint bit 4 updated after data is converted and upadted in register ADLH
		SetBIT(ADCSRA_REG,4);
		return(ADCLH_REG);
	*/
	
	//THIS CODE FOR SINGLE AND AUTO TRIGGER FUNCTION
	
	
	#if (ADC_MODE_SELECTOR==ADC_MODE_AUTO_TRIGGER)
		return(ADCLH_REG);	
	
	#elif (ADC_MODE_SELECTOR==ADC_MODE_SINGLE_CONVERSION)
		while(!GetBIT(ADCSRA_REG,4))
			SetBIT(ADCSRA_REG,4);
			return(ADCLH_REG);
		
	
	#endif
	
}


//ADC ENABLE AND DISABLE

void ADC_EnableInt()
{
	SetBIT(ADCSRA_REG,3);
}
void ADC_DisableInt()
{
	ClearBIT(ADCSRA_REG,3);
}

//ADC INTERRUPT SETCALLBACK FUNCTION


void ADC_SetCallback(void(*CopyFuncPTR)(void))
{
	ADC_CallBackPtr=CopyFuncPTR;
}

//THIS SENTENCE IS SPECIAL TO ADC_MAX_NUMBER_OF_STEPS	KE PROCESSEOR NOT TO OPTIMIZE THE CODE AND DELETE THIS FUCNTION
void __vector_16(void) __attribute__((signal , used));

void __vector_16(void)
{
	
	if(ADC_CallBackPtr!=NULL)
	{
		
		ADC_CallBackPtr();
		
	}
		
	
}