/*
 * EXTI_Config.h
 *
 * Created: 7/29/2022 9:35:14 PM
 *  Author: pc
 */ 


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
/* configure the external interrupt 0 mode
*Range:
* EXTI_LOW_LEVEL				 
* EXTI_Any_Logical_Change		 
* EXTI_Falling_Edge			 
* EXTI_Rising_Edge			 
*/
#define  EXT0_MODE   EXTI_Falling_Edge		



/* configure the external interrupt 1 mode
*Range:
* EXTI_LOW_LEVEL
* EXTI_Any_Logical_Change
* EXTI_Falling_Edge
* EXTI_Rising_Edge
*/
#define  EXT1_MODE  EXTI_LOW_LEVEL



/* configure the external interrupt 0 mode
*Range:
* EXTI_INT2_Falling_Edge       
* EXTI_INT2_Rising_Edge        
*/
#define  EXT2_MODE   EXTI_INT2_Falling_Edge 

/*state for external interrupt
*/
#define  EXTI_INT0_INIT_STATE	EXTI_Disable_state
#define  EXTI_INT1_INIT_STATE	EXTI_Disable_state
#define  EXTI_INT2_INIT_STATE	EXTI_Disable_state

#endif /* EXTI_CONFIG_H_ */