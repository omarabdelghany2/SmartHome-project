/*
 * BIT_Math.h
 *
 * Created: 6/25/2022 5:38:17 PM
 *  Author: pc
 */ 



#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define SetBIT(REG,Pin_ID)				   (REG |= (1<<Pin_ID))  
#define ClearBIT(REG,Pin_ID)				   (REG &= ~(1<<Pin_ID))
#define ToggleBIT(REG,Pin_ID)			   (REG ^= (1<<Pin_ID))
#define GetBIT(REG,Pin_ID)				   ((REG>>(Pin_ID))&0x01)


#endif /* BIT_MATH_H_ */