/*
 * EXTI.c
 *
 * Created: 7/29/2022 9:35:42 PM
 *  Author: pc
 */ 
#include "EXTI.h"
void EXTI_Intialization()
{
	ClearBIT(MCUCR_REG,0);
	ClearBIT(MCUCR_REG,1);
	ClearBIT(MCUCR_REG,2);
	ClearBIT(MCUCR_REG,3);
	ClearBIT(MCUCSR_REG,6);
	
	
	/*FOR Interrupt 0*/
	#if   EXT0_MODE == EXTI_Falling_Edge
			MCUCR_REG |=EXTI_Falling_Edge;
	#elif EXT0_MODE == EXTI_Any_Logical_Change
			MCUCR_REG |=EXTI_Any_Logical_Change;
	#elif EXT0_MODE == EXTI_Rising_Edge	
			MCUCR_REG |=EXTI_Rising_Edge;
	#elif EXT0_MODE ==EXTI_LOW_LEVEL
			MCUCR_REG |=EXTI_LOW_LEVEL;
	#endif
	
	/*for interrupt 1*/
	#if   EXT1_MODE == EXTI_Falling_Edge
		   MCUCR_REG  |= ( EXTI_Falling_Edge<<2 );
		   
	#elif EXT1_MODE == EXTI_Any_Logical_Change
		   MCUCR_REG  |= ( EXTI_Any_Logical_Change<<2 );
		   
	#elif EXT1_MODE == EXTI_Rising_Edge
		   MCUCR_REG  |= ( EXTI_Rising_Edge<<2 );
		   
	#elif EXT1_MODE ==EXTI_LOW_LEVEL
		   MCUCR_REG  |= ( EXTI_LOW_LEVEL<<2 );
	#endif
	
	/*for interrupt2*/
	
	#if   EXT2_MODE == EXTI_INT2_Falling_Edge
			MCUCSR_REG  |= (EXTI_INT2_Falling_Edge<<6);
			
	#elif EXT2_MODE == EXTI_INT2_Rising_Edge
			MCUCSR_REG  |= (EXTI_INT2_Rising_Edge<<6);
	#endif
	
	
	
	/*Disable and enable of interrupts*/
	#if EXTI_INT0_INIT_STATE   == EXTI_Disable_state
				ClearBIT(GICR_REG,6);
	#else EXTI_INT0_INIT_STATE == EXTI_Enable_state	
				SetBIT(GICR_REG,6);
	#endif		
		
    #if EXTI_INT1_INIT_STATE   == EXTI_Disable_state
				ClearBIT(GICR_REG,7);
    #else EXTI_INT1_INIT_STATE == EXTI_Enable_state
				SetBIT(GICR_REG,7);		
    #endif	
   
    #if EXTI_INT2_INIT_STATE   == EXTI_Disable_state
				ClearBIT(GICR_REG,5);
    #else EXTI_INT2_INIT_STATE == EXTI_Enable_state
				SetBIT(GICR_REG,5);
    #endif
   	
	   /*clearing interrupts flags*/
	   SetBIT(GIFR_REG,5);
	   SetBIT(GIFR_REG,6);
	   SetBIT(GIFR_REG,7);
	   
}	

void EXTI_EnableInt0()
{
	SetBIT(GICR_REG,6);
}


void EXTI_DisableInt0()
{
	ClearBIT(GICR_REG,6);

}



void EXTI_Enable_Global_Interrupt()
{
	SetBIT(SREG_REG,7);
	
}

void EXTI_Disable_Global_Interrupt()
{
	ClearBIT(SREG_REG,7);
}

void EXTI_SetCallback(void(*CopyFuncPTR)(void))
{
	CallBackPtr=CopyFuncPTR;
}
void __vector_1(void)
{
	if(CallBackPtr!=NULL)
		CallBackPtr();
}