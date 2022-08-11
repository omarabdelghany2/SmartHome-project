/*
 * EXTI.h
 *
 * Created: 7/29/2022 9:34:05 PM
 *  Author: pc
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include "EXTI_Config.h"
#include "EXTI_Types.h"
#include "../../lib/BIT_Math.h"
#include "../../lib/STD_Types.h"
#include "EXTI_Reg.h"


/*initialize of external interrupt*/
void EXTI_Intialization();


/*enable of external interrupt0*/
void EXTI_EnableInt0();
/*disable of external interrupt0*/
void EXTI_DisableInt0();





/*call back function */


void EXTI_SetCallback(void(*CopyFuncPTR)(void));

void __vector_1(void);


#endif /* EXTI_H_ */