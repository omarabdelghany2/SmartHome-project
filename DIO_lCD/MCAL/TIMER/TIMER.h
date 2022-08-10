/*
 * TIMER.h
 *
 * Created: 8/8/2022 9:03:42 PM
 *  Author: pc
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "TIMER_Config.h"
#include "TIMER_Reg.h"


void Timer_intialize();


void TIMER_SetCallback(void(*CopyFuncPTR)(void));
void __vector_11(void);



#endif /* TIMER_H_ */