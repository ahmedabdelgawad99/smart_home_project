/*
 * Air_Con_Prog.c
 *
 *  Created on: Nov 29, 2021
 *      Author: Ali
 */
#include "../MCAL/AVR_REG.h"
#include "../MCAL/Timer0_Int.h"

void AC_On()
{
	MotOr_On();

}
void AC_Off()
{
	 MotOr_0ff();
}
void AC_Init()
{
	DDRB|=(1<<3);
	Waveform0_Gen_Mode();
	Compare0_Match_Out_Mode();
	Clk0_Select();

}
