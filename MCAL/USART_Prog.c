/*
 * USART_Prog.c
 *
 *  Created on: Oct 26, 2021
 *      Author: Abdelrahman Mahmoud
 */
#include "../MCAL/stdTypes.h"
#include "../MCAL/AVR_REG.h"
#include "USART_Config.h"
#include "USART_Private.h"
#include "util/delay.h"
u8 State = 1;
void USART_Init(u8 Mode,u8 Parity,u8 Stop_Bits,u8 Charcter_Size)
{
	u8 Result=0x00;
	switch(Mode)
	{
	case Asynch_Noraml_Mode:
		Result &=~(1<<UMSEL);
		State = Asynch_Noraml_Mode;
		break;
	case Asynch_Double_Speed_Mode:
		Result &=~(1<<UMSEL);
		UCSRA  |= (1<<U2X);
		State = Asynch_Double_Speed_Mode;
		break;
	case Synch:
		Result |=(1<<UMSEL);
		break;
	default:
		break;
	}
	switch(Parity)
	{
	case DISABLE:
		Result &=~(1<<UPM0);
		Result &=~(1<<UPM1);
		break;
	case EVEN:
		Result &=~(1<<UPM0);
		Result |= (1<<UPM1);
		break;
	case ODD:
		Result |= (1<<UPM0);
		Result |= (1<<UPM1);
		break;
	default:
		break;
	}
	switch(Stop_Bits)
	{
	case 1 :
		Result &=~(1<<USBS);
		break;
	case 2 :
		Result |= (1<<USBS);
		break;
	default:
		break;
	}
   switch(Charcter_Size)
   {
   case 5:
	   Result &=~(1<<UCSZ0);
	   Result &=~(1<<UCSZ1);
	   UCSRB  &=~(1<<UCSZ2);
	   break;
   case 6:
	   Result |= (1<<UCSZ0);
	   Result &=~(1<<UCSZ1);
	   UCSRB  &=~(1<<UCSZ2);
	   break;
   case 7:
	   Result &=~(1<<UCSZ0);
	   Result |= (1<<UCSZ1);
	   UCSRB  &=~(1<<UCSZ2);
	   break;
   case 8:
	   Result |= (1<<UCSZ0);
	   Result |= (1<<UCSZ1);
	   UCSRB  &=~(1<<UCSZ2);
	   break;
   case 9:
	   Result |= (1<<UCSZ0);
	   Result |= (1<<UCSZ1);
	   UCSRB  |= (1<<UCSZ2);
	   break;
   default:
	   break;
   }
   Result |=(1<<USREL);
   UCSRC=Result;
}
void USART_TX_Enabel()
{
	UCSRB |=(1<<TXEN);
}
void USART_RX_Enabel()
{
	UCSRB |=(1<<RXEN);
}
void USART_TX_IE()
{
	UCSRB |=(1<<TXCIE);
}
void USART_RX_IE()
{
	UCSRB |=(1<<RXCIE);
}
void USART_RX_ID()
{
	UCSRB &=~(1<<RXCIE);
}
void USART_UDRE_IE()
{
	UCSRB |=(1<<UDRIE);
}
void USART_Baud_Rate()
{
	UBRRL =103;
	UBRRH =0x00;
}
void USART_Send_Char(u8 Data)
{
	while(!((UCSRA>>5)&1)); /*UDR Empty Register Method*/
	UDR = Data;


}
u8 USART_Recive_Char()
{
	while(((UCSRA>>7)&1)==0);
	return UDR;

}
void USART_Send_String(char *T_Data)
{

	u8 Str_Size = 0;
	while(T_Data[Str_Size] != 0)
	{
		while(!((UCSRA>>5)&1)); /*UDR Empty Register Method*/
		UDR = T_Data[Str_Size];
		Str_Size ++;
	}
}
void USART_Recive_String(u8 *R_Data)
{
	u8 End,Str_Size = 0,New_Data;
	while(((UCSRA>>7)&1)==0);
	End = UDR;
	while(1)
	{
		while(((UCSRA>>7)&1)==0);
		New_Data = UDR;
		if(New_Data==End)
		{
			R_Data[Str_Size]=0;
			break;
		}
		R_Data[Str_Size++]=New_Data;
		}
}
/*u8 Remote_Check()
{
		{
		while(((UCSRA>>7)&1)==0)
		{
			UCSRA|=(1<<7);
			_delay_ms(10);
		}

	}
	return UDR;
}*/
