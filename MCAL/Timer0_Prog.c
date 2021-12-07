/*
 * IMP.c
 *
 *  Created on: Nov 11, 2021
 *      Author:Ali-Elgazzar
 */
#include "../MCAL/AVR_REG.h"
#include "../MCAL/stdTypes.h"
#include "Timer_Config.h"
#include "Timer0_Int.h"
#include "Timer0_Priv.h"



/**********************************
 * ********************************
 * *** Waveform Generation Mode function *****
 *********************************
 ***********************************/
void Waveform0_Gen_Mode()
{
#if Wave_GEN_Mode ==N0rmal
	 TCCR0 &=~(1<<3);
	 TCCR0 &=~(1<<6);

#elif Wave_GEN_Mode == PWM_Ph
     TCCR0 &=~(1<<6);
     TCCR0 |=(1<<3);

#elif Wave_GEN_Mode == CTc
     TCCR0 &=~(1<<3);
     TCCR0 |=(1<<6);


#elif Wave_GEN_Mode == FAst_PWM
	 TCCR0 |=(1<<3);
	 TCCR0 |=(1<<6);

#else
#error"Waveform_Gen has a wrong choice"
#endif
}



/**********************************
 * ********************************
 * *** Compare match function *****
 *********************************
 ***********************************/
void Compare0_Match_Out_Mode()
{
#if Compare0_Match_Out == Normal_port_op

		TCCR0 &=~(1<<4);
		TCCR0 &=~(1<<5);

#elif Compare0_Match_Out == Toggle_OC0
			TCCR0 |=(1<<4);
			TCCR0 &=~(1<<5);


#elif Compare0_Match_Out == Clear_OC0
			TCCR0 |=(1<<5);
			TCCR0 &=~(1<<4);


#elif Compare0_Match_Out == Set_OC0 :
			TCCR0 |=(1<<5);
			TCCR0 |=(1<<4);

#else
#endif
}




/**********************************
 * ********************************
 * *** Clock source selection function
 *********************************
 ***********************************/

void Clk0_Select()
{

#if Cl_Selec ==No_pres
		TCCR0 |=(1<<0);
		TCCR0 &=~(1<<1);
		TCCR0 &=~(1<<2);

#elif Cl_Selec ==No_cl_source
	    TCCR0 &=~(1<<0);
	    TCCR0 &=~(1<<1);
	    TCCR0 &=~(1<<2);


#elif Cl_Selec == cl_64
	    TCCR0 |=(1<<0);
	    TCCR0 |=(1<<1);
	    TCCR0 &=~(1<<2);

#elif Cl_Selec ==cl_256
	    TCCR0 &=~(1<<0);
	    TCCR0 &=~(1<<1);
	    TCCR0 |=(1<<2);


#elif Cl_Selec ==cl_1024
	    TCCR0 |=(1<<0);
	    TCCR0 &=~(1<<1);
	    TCCR0 |=(1<<2);

#elif Cl_Selec ==Ext_cl_ris
	    TCCR0 |=(1<<0);
	    TCCR0 |=(1<<1);
	    TCCR0 |=(1<<2);


#elif Cl_Selec ==  Ext_cl_fall
	    TCCR0 &=~(1<<0);
	    TCCR0 |=(1<<1);
	    TCCR0 |=(1<<2);
#else
#endif

}

void OCR0_Value(u8 Val)
{
	OCR0 =Val;
}
void MotOr_0ff()
{
	OCR0=0;
}

void MotOr_On()
{
	OCR0=200;
}


