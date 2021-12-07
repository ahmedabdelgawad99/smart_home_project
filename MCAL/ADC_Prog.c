#include "../MCAL/stdTypes.h"
#include "ADC_Private.h"
#include "../MCAL/AVR_REG.h"
#include "ADC_Config.h"
void AD_Init(u8 Vref , u8 Prescaler)
{
switch(Prescaler)
{
   case 2:
	ADCSRA |= (1<<ADPS0);
	ADCSRA &=~(1<<ADPS1);
	ADCSRA &=~(1<<ADPS2);
	break;
   case 4:
	ADCSRA &=~(1<<ADPS0);
	ADCSRA |= (1<<ADPS1);
	ADCSRA &=~(1<<ADPS2);
	break;
   case 8:
	ADCSRA |= (1<<ADPS0);
	ADCSRA |= (1<<ADPS1);
	ADCSRA &=~(1<<ADPS2);
	break;
   case 16:
	ADCSRA &=~(1<<ADPS0);
	ADCSRA &=~(1<<ADPS1);
	ADCSRA |= (1<<ADPS2);
	break;
   case 32:
	ADCSRA |= (1<<ADPS0);
	ADCSRA &=~(1<<ADPS1);
	ADCSRA |= (1<<ADPS2);
	break;
   case 64:
	ADCSRA &=~(1<<ADPS0);
	ADCSRA |= (1<<ADPS1);
	ADCSRA |= (1<<ADPS2);
	break;
   case 128:
	ADCSRA |= (1<<ADPS0);
	ADCSRA |= (1<<ADPS1);
	ADCSRA |= (1<<ADPS2);
	break;
}
switch(Vref)
{
   case VREF :
	   ADMUX &=~(1<<REFS0);
	   ADMUX &=~(1<<REFS1);
	   break;
   case AVCC :
 	   ADMUX |= (1<<REFS0);
 	   ADMUX &=~(1<<REFS1);
 	   break;
   case INTV :
	   ADMUX |= (1<<REFS0);
	   ADMUX |= (1<<REFS1);
 	   break;
}

   ADCSRA |= (1<<ADEN);
}
void AD_Start_Conversion()
{
	ADCSRA |= (1<<ADSC);
}
void Auto_Trigger_Enable(u8 Mode)
{
	if(Mode<=7)
	{
	SFIOR &= 0x1F;
	SFIOR |= (Mode<<5);
	}
	ADCSRA |= (1<<ADATE);
}
void Analog_Select_Channel(u8 Channel)
{
	if (Channel<=31)
	{
		ADMUX &=~0x1F;
		ADMUX |= Channel;
	}

}
u8 AD_Read_High(u8 Direction)
{
	u8 Reading;
 switch(Direction)
   {
 case RIGHT_READING:
	 Reading =(ADCL>>2);
	 Reading|=(ADCH<<6);
	 break;
 case LEFT_READING:
	 ADMUX |=(1<<ADLAR);
	 Reading=ADCH;
	 break;
 default:
	  break;
   }
 return Reading;
}
void ADC_Polling()
{
	while (!(ADCSRA<<4)&1);
		  ADCSRA |=(1<<4);
}
void ADC_IE()
{
	ADCSRA |=(1<<ADIE);
}
