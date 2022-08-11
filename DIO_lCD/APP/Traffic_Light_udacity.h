/*
 * Traffic_Light_udacity.h
 *
 * Created: 8/11/2022 7:13:29 PM
 *  Author: pc
 */ 


#ifndef TRAFFIC_LIGHT_UDACITY_H_
#define TRAFFIC_LIGHT_UDACITY_H_
#include "stdbool.h"
#include "../HAL/LCD/LCD.h"
#include "../LIB/STD_Types.h"
#include "../MCAL/DIO/DIO_Types.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../HAL/Seven_Segment/Seven_Segment.h"


void start_Traffic_light();
void ISR_traffic();

#endif /* TRAFFIC_LIGHT_UDACITY_H_ */