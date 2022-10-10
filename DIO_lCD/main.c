/*
 * main.c
 *
 * Created: 6/27/2022 10:59:34 AM
 *  Author: pc
 */ 


#include "APP/SmartHome/SmartHome_Master.h"
#include "APP/SmartHome/SmartHome_Slave.h"
#include "APP/SPI_TRY.h"

int main()
{
	//SPI_try();
SmartHome_App_Start_Slave();
}