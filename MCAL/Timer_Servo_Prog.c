/*
 * IMP.c
 *
 *  Created on: Oct 11, 2021
 *      Author:  Ali-Elgazzar
 */

#include "../MCAL/AVR_REG.h"
#include "../MCAL/stdTypes.h"
#include "Timer_Servo_Config.h"
#include "Timer_Servo_Int.h"
#include "Timer_Servo_Priv.h"

void TOV_EN(void)
{
	TIMSK |=(1<<0);
}

void WR_TCNValue(u8 value)
{
	TCNT1 =value;
}

void Select_Channel()
{
#if Selec_Ch == Channel_A
		TCCR1A |=(1<<6);
		TCCR1A |=(1<<7);

#elif Selec_Ch == Channel_B
		TCCR1A |=(1<<4);
		TCCR1A |=(1<<5);

#else
#endif
}


/**********************************
 * ********************************
 * *** Waveform Generation Mode function *****
 *********************************
 ***********************************/
void Waveform_Gen_Mode()
{

#if WAVE_GEN_Mode == Normal
	 TCCR1A &=~(1<<1);
     TCCR1A &=~(1<<0);
	 TCCR1B &=~(1<<3);
     TCCR1B &=~(1<<4);


#elif WAVE_GEN_Mode == PWM_PhCrt_MODE9
	 TCCR1A &=~(1<<1);
     TCCR1A |=(1<<0);
	 TCCR1B &=~(1<<3);
     TCCR1B |=(1<<4);

#elif WAVE_GEN_Mode == CTC
	 TCCR1A &=~(1<<1);
     TCCR1A &=~(1<<0);
	 TCCR1B |=(1<<3);
     TCCR1B &=~(1<<4);

#elif WAVE_GEN_Mode == Fast_PWM
	 TCCR1A |=(1<<1);
     TCCR1A |=(1<<0);
	 TCCR1B |=(1<<3);
     TCCR1B |=(1<<4);
#else
#endif
}




/**********************************
 * ********************************
 * *** Compare match function *****
 *********************************
 ***********************************/
void CompareMode_Phase_correct()
{
#if CompareMode_Ph_Corr == Normal_port_op
			TCCR1A &=~(1<<4);
			TCCR1A &=~(1<<5);
			TCCR1B &=~(1<<6);
			TCCR1B &=~(1<<7);

#elif CompareMode_Ph_Corr == Toggle_OC1
			TCCR1A |=(1<<4);
			TCCR1A &=~(1<<5);
			TCCR1B |=(1<<6);
			TCCR1B &=~(1<<7);

#elif CompareMode_Ph_Corr ==  Clear_OC1
			TCCR1A &=~(1<<4);
			TCCR1A |=(1<<5);
			TCCR1B &=~(1<<6);
			TCCR1B |=(1<<7);

#elif CompareMode_Ph_Corr == Set_OC1 :
			TCCR1A |=(1<<4);
			TCCR1A |=(1<<5);
			TCCR1B |=(1<<6);
			TCCR1B |=(1<<7);
#else
#endif
	}


/**********************************
 * ********************************
 * *** Clock source selection function
 *********************************
 ***********************************/
void Clk_Select()
{

#if Clk_Selec == No_prescaling
		TCCR1B |=(1<<0);
		TCCR1B &=~(1<<1);
		TCCR1B &=~(1<<2);

#elif Clk_Selec == No_clk_source
		TCCR1B &=~(1<<0);
		TCCR1B &=~(1<<1);
		TCCR1B &=~(1<<2);

#elif Clk_Selec ==  clk_8
		TCCR1B &=~(1<<0);
		TCCR1B |=(1<<1);
		TCCR1B &=~(1<<2);


#elif Clk_Selec ==  clk_64
		TCCR1B |=(1<<0);
		TCCR1B |=(1<<1);
		TCCR1B &=~(1<<2);

#elif Clk_Selec == clk_256
		TCCR1B &=~(1<<0);
		TCCR1B &=~(1<<1);
	    TCCR1B |=(1<<2);

#elif Clk_Selec ==  clk_1024
		TCCR1B |=(1<<0);
		TCCR1B &=~(1<<1);
		TCCR1B |=(1<<2);

#elif Clk_Selec ==  Ext_clk_ris
		TCCR1B |=(1<<0);
		TCCR1B |=(1<<1);
		TCCR1B |=(1<<2);

#elif Clk_Selec ==  Ext_clk_fall
		TCCR1B &=~(1<<0);
		TCCR1B |=(1<<1);
		TCCR1B |=(1<<2);
#else
#endif
}


void OCR1AH_OCR1ALValue(u16 Val1)
{
	OCR1AH =(Val1)>>8;
	OCR1AL =(u8)Val1;
}


void OCR1AL_Value(u8 Val1)
{
	OCR1AL=(u8)Val1;
}


void OCR1AH_Value(u8 Val2)
{
	OCR1AH=(u8)Val2;
}


void Motor_180_DEG()
{
    OCR1BH=0 ;
    OCR1BL=250;
}


void Motor_90_DEG()
{
    OCR1BH=0;
    OCR1BL=125;
}

void Motor_0_DEG()
{
 DDRD&=~(1<<4);
}



