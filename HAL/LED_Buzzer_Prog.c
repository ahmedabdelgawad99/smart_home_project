/*
 * leds_buzzer_prog.c
 *
 *  Created on: Nov 27, 2021
 *      Author: Ahmed Abdelgwad
 */
#include "../MCAL/stdTypes.h"
#include "../MCAL/errorState.h"
#include "../MCAL/DIO_int.h"
#include "util/delay.h"


/* choosing led to turn it on*/
void leds_vON(void)
{
		DIO_enuSetPinDirection(DIO_u8GROUP_A, DIO_u8PIN2, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN2,DIO_u8HIGH);

		DIO_enuSetPinDirection(DIO_u8GROUP_A, DIO_u8PIN3, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN3,DIO_u8HIGH);

		DIO_enuSetPinDirection(DIO_u8GROUP_D, DIO_u8PIN2, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN2,DIO_u8HIGH);

		DIO_enuSetPinDirection(DIO_u8GROUP_C, DIO_u8PIN2, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_C,DIO_u8PIN2,DIO_u8HIGH);

		DIO_enuSetPinDirection(DIO_u8GROUP_D, DIO_u8PIN6, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN6,DIO_u8HIGH);
}


/* choosing led to turn it off*/
void leds_vOFF(void)
{
		DIO_enuSetPinDirection(DIO_u8GROUP_A, DIO_u8PIN2, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN2,DIO_u8LOW);

		DIO_enuSetPinDirection(DIO_u8GROUP_A, DIO_u8PIN3, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN3,DIO_u8LOW);

		DIO_enuSetPinDirection(DIO_u8GROUP_D, DIO_u8PIN2, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN2,DIO_u8LOW);

		DIO_enuSetPinDirection(DIO_u8GROUP_C, DIO_u8PIN2, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_C,DIO_u8PIN2,DIO_u8LOW);

		DIO_enuSetPinDirection(DIO_u8GROUP_D, DIO_u8PIN6, DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN6,DIO_u8LOW);
}


/*turn on buzzer*/
void buzzer_vON(void)
{
	DIO_enuSetPinDirection(DIO_u8GROUP_D, DIO_u8PIN7, DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN7,DIO_u8HIGH);
}


/*turn off buzzer*/
void buzzer_vOFF(void)
{
	DIO_enuSetPinDirection(DIO_u8GROUP_D, DIO_u8PIN7, DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN7,DIO_u8LOW);
}





