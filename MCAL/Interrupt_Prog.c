/*
 * Interrupt_Prog.c
 *
 *  Created on: Dec 3, 2021
 *      Author: techno
 */

#include "stdTypes.h"
#define ISR(Num)	void Num (void) __attribute__((signal));\
					void Num (void)

static void(*gptr0)(void)=NULL;


ISR(__vector_13)
{
	if(gptr0 != NULL)
	gptr0();/*calling the function through "gptr0 pointer" in ISR*/
}

void Call_Back_Fun(void (*ptf)(void))/*passing the function to be executed in the ISR to pointer*/
{

		if  (ptf != NULL)
		      gptr0=ptf; /*passing the function to other pointer the one that will actually be called in ISR*/





}
