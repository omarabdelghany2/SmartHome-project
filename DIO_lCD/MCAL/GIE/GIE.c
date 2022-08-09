/*
 * GIE.c
 *
 * Created: 8/1/2022 7:33:58 AM
 *  Author: pc
 */ 
#include "GIE.h"
#include "../../LIB/BIT_Math.h"


static void (*CallBackPtr)(void);
void Global_Interrupt_Enable()
{
	SetBIT(SREG_REG,GIE_ENABLE_BIT);
	
}

void Global_Interrupt_Disable()
{
	ClearBIT(SREG_REG,GIE_ENABLE_BIT);
}

