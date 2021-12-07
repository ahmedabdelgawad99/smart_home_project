/*
 * Remote_Prog.c
 *
 *  Created on: Nov 26, 2021
 *      Author: Ali
 */
#include "../MCAL/ADC_Int.h"
#include "../MCAL/ADC_Config.h"
#include "AC_Int.h"
#include "LED_Buzzer_Int.h"
void Temp_Sens_Init()
{
	 Analog_Select_Channel(0);
	 AD_Init(AVCC,64);
}
u8 Temp_Sens_Read()
{
	u8 Read;
	AD_Start_Conversion();
	ADC_Polling();
	Read=(AD_Read_High(LEFT_READING))*2;
	return Read;
}
void Temp_AC_Check()
{

	u8  Temperature;
	Temperature =Temp_Sens_Read();
	if (Temperature > 28)
	{
	     AC_On();
	     LCD_enuSendString("AC_ON");
	}
	else if (Temperature < 21)
	{
		AC_Off();
		LCD_ClearDisplay();
	}
	else;
}
