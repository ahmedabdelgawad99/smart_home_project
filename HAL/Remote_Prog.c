/*
 * Remote_Prog.c
 *
 *  Created on: Nov 26, 2021
 *      Author: Abdelrahman Mahmoud
 */
#include "../MCAL/USART_Config.h"
#include "../MCAL/USART_Private.h"
#include "../MCAL/stdTypes.h"
#include "../MCAL/AVR_REG.h"
void Remote_Init()
{
	  USART_Init(Asynch_Noraml_Mode,DISABLE,1,8);
	  USART_Baud_Rate();
	  USART_RX_Enabel();
	  USART_TX_Enabel();
	  USART_RX_IE();
	  USART_Send_String("PRESS ANY KEY TO START\r\n");


}
void Remote_Typing(u8 *User_ID,u8 Str_Size,u8 State)            /*Shows the characters that the user is typing and saving it in the same time*/
{
	u8 i,Writing;
	if(State==1)
	{
	for(i=0;i<Str_Size;i++)
	{
		Writing=USART_Recive_Char();
		USART_Send_Char('*');
		User_ID[i]=Writing;
	}
	}
	else if(State== 0)
	{
		for(i=0;i<Str_Size;i++)
		{
			Writing=USART_Recive_Char();
			USART_Send_Char(Writing);
			User_ID[i]=Writing;
		}
	}

}
void Remote_Send_String(char *T_Data)                           /*Used to send massages or instructions to the user*/
{
	USART_Send_String(T_Data);
}
void Remote_New_Line(u8 Num_Line)                               /*Create New line*/
{
	u8 i;
	for(i=0;i<Num_Line;i++)
	{
	USART_Send_String("    \r\n");
	}

}
void Remote_Display(u8 *T_Data,u8 Str_Size)                     /*Display User Information*/
{
	u8 i;
	for(i=0 ;i<Str_Size;i++)
		{
			while(!((UCSRA>>5)&1)); /*UDR Empty Register Method*/
			UDR = T_Data[i];
		}
}
