/*
 * Door_Prog.c
 *
 *  Created on: Nov 29, 2021
 *      Author: Loai
 */

#include "../MCAL/Timer_Servo_Int.h"
#include "../MCAL/AVR_REG.h"


void Door_Open()
{
	Motor_180_DEG();
}
void Door_Close()
{
	Motor_90_DEG();

}
void Door_Ini()
{
	DDRD|=(1<<4);
	 Waveform_Gen_Mode();
		 CompareMode_Phase_correct();
		 Clk_Select();
			OCR1AH=(u8)((2500)>>8);
			OCR1AL=(u8)2500;
}
