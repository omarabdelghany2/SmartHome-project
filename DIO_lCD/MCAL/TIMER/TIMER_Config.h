/*
 * TIMER_Config.h
 *
 * Created: 8/8/2022 9:02:55 PM
 *  Author: pc
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#include "TIMER_Types.h"


/*SELECT THE CLOCK SOURCE
	 TIMER_CLOCK_SELECT_NoClock_Source					
	 TIMER_CLOCK_SELECT_No_Prescaling					
	 TIMER_CLOCK_SELECT_8_Prescaling						
	 TIMER_CLOCK_SELECT_64_Prescaling					
	 TIMER_CLOCK_SELECT_128_Prescaling					
	 TIMER_CLOCK_SELECT_256_Prescaling					
	 TIMER_CLOCK_SELECT_1024_Prescaling					
	 TIMER_CLOCK_SELECT_External_FallingEdge_On(T0)		
	 TIMER_CLOCK_SELECT_External_RisingEdge_On(T0)		

*/
#define TIMER_CLK_SELECTOR						 TIMER_CLOCK_SELECT_256_Prescaling

/*select the wave form from the next choices

	TIMER_WAVE_FORM_MODE_Normal							
	TIMER_WAVE_FORM_MODE_PhaseCorrect					
	TIMER_WAVE_FORM_MODE_CTC
	TIMER_WAVE_FORM_MODE_FASTPWM						

*/
#define TIMER_WAVEFORM_SELECTOR					TIMER_WAVE_FORM_MODE_Normal	

/*	SELECT THE STATUS OF OVERFLOW INTERRUPT
	TIMER_OVERFLOW_Interrupt_Enable_msk					
	TIMER_OVERFLOW_Interrupt_Disable_msk				

*/
#define TIMER_OVERFLOW_INTERRUPT_STATUS			TIMER_OVERFLOW_Interrupt_Enable_msk


/*SELECT THE STATUS OF COMPARE MATCH INTERRPT

	TIMER_Compare_Interrupt_Enable_msk					
	TIMER_Compare_Interrupt_Disable_msk					
*/
#define TIMER_CompareMatch_INTERRUPT_STATUS		TIMER_Compare_Interrupt_Disable_msk	



#endif /* CONFIG_H_ */