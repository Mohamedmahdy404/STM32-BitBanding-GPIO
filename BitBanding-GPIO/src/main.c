/*
 * main.c
 *
 *  Created on: Sep 21, 2024
 *
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "RCC_interface.h"




void main(void)
{
	RCC_voidInitSysClock();
		RCC_voidEnableClock(RCC_APB2,2);   //gpioa
		RCC_voidEnableClock(RCC_APB2, 14);
		RCC_voidEnableClock(RCC_APB2,12);
		MSTK_voidInit();

			MGPIO_VidSetPinDirection(GPIOA,1,0b0010);
			MGPIO_VidSetPinDirection(GPIOA,5,0b0010);
			MGPIO_VidSetPinDirection(GPIOA,10,0b0010);

			MGPIO_VidSetPinValue(GPIOA,1,LOW);
			MGPIO_VidSetPinValue(GPIOA,5,HIGH);


			u32 var = 0;
			 SET_BIT_SRAM(var, 1);
			 MGPIO_VidSetPinValue(GPIOA,10,GET_BIT_SRAM(var, 1));


	while(1);
}

