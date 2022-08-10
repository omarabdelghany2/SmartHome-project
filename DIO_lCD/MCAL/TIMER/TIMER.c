/*
 * TIMER.c
 *
 * Created: 8/8/2022 9:03:49 PM
 *  Author: pc
 */ 
#include "TIMER.h"

static void(*Timer_CallBackPtr)(void)=NULL;
void Timer_intialize()
{
/*STEPS IN INTIALIZE
1)SELECT CLOCK SOURCE
2)SELECT MODE OF OPERATION
3)ENABLE OR DISABLE OF INTERRUPT
*/
//1)
	TCCR0_REG&&TIMER_CLOCK_SELECT_clr_msk;
	TCCR0_REG||TIMER_CLK_SELECTOR;
//2)
	TCCR0_REG&&TIMER_WAVE_FORM_MODE_clr_msk;
	TCCR0_REG||TIMER_WAVEFORM_SELECTOR;
//3)
	TIMSK_REG&&(11111100);
	TIMSK_REG||TIMER_OVERFLOW_INTERRUPT_STATUS	;
	TIMSK_REG||TIMER_CompareMatch_INTERRUPT_STATUS;
	
}

void TIMER_SetCallback(void(*CopyFuncPTR)(void))
{
	Timer_CallBackPtr=CopyFuncPTR;
}
void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	if(Timer_CallBackPtr!=NULL)
		Timer_CallBackPtr();
}