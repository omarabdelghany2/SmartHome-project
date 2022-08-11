/*
 * TIMER.c
 *
 * Created: 8/8/2022 9:03:49 PM
 *  Author: pc
 */ 
#include "TIMER.h"

static int overflow =0;

static void(*Timer_CallBackPtr)(void)=NULL;
void Timer_intialize()
{
/*STEPS IN INTIALIZE
1)SELECT MODE OF OPERATION
2)ENABLE OR DISABLE OF INTERRUPT
3)SELECT CLOCK SOURCE
*/

	TCNT0_REG=0;
//1)
	TCCR0_REG&=TIMER_WAVE_FORM_MODE_clr_msk;
	TCCR0_REG|=TIMER_WAVEFORM_SELECTOR;
//2)
	TIMSK_REG&=(0b11111100);
	TIMSK_REG|=TIMER_OVERFLOW_INTERRUPT_STATUS	;
	TIMSK_REG|=TIMER_CompareMatch_INTERRUPT_STATUS;
	
	TIMER_SetCallback(TIMER0_ISR);
	
	//3)
	//TCCR0_REG&&TIMER_CLOCK_SELECT_clr_msk;
	
}
void TIMER0_ISR()
{
	overflow++;
	};

void TIMER_SetCallback(void(*CopyFuncPTR)(void))
{
	Timer_CallBackPtr=CopyFuncPTR;
}

void TIMER_delay(float delay)
{
	Global_Interrupt_Enable();
	TCCR0_REG|=TIMER_CLK_SELECTOR;
	delay*=2000;
	while(overflow<delay)
	{
		
	}
	overflow=0;
	TCCR0_REG&=TIMER_CLOCK_SELECT_clr_msk;
}



void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	if(Timer_CallBackPtr!=NULL)
		Timer_CallBackPtr();
}