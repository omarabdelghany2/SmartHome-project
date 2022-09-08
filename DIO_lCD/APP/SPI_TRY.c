/*
 * SPI_TRY.c
 *
 * Created: 9/8/2022 5:10:58 AM
 *  Author: pc
 */ 
#include "SPI_TRY.h"
void SPI_try()
{
	SPI_Master_Intialize();
	while(1)
	{
		
	SPI_Master_Transmit('B');
	}
}