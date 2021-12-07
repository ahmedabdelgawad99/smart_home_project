#ifndef ADC_INT_H_
#define ADC_INT_H_
#include "../MCAL/stdTypes.h"
#include "ADC_Config.h"
/*Functions*/
void AD_Init(u8 Vref , u8 Prescaler); /*AVCC,VREF,INTV*/ /* 2,4,8,16,32,64,128*/
void AD_Start_Conversion();
void Auto_Trigger_Enable(u8 Mode); /*Free_Running_mode ,Analog_Comparator*/
void Analog_Select_Channel(u8 Channel); /*0,1,2,3,4,5,6,7*/
u8 AD_Read_High(u8 Direction); /*LEFT_READING , RIGHT_READING*/ /*only reads the high 8_bits*/
u16 AD_Read(u8 Direction); /*LEFT_READING , RIGHT_READING*/ /* reads the all 10_bits*/
void ADC_Polling();/*enable ADC interrupt*/
void ADC_IE();
#endif /* ADC_INT_H_ */
