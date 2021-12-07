/*
 * USART_Int.h
 *
 *  Created on: Oct 26, 2021
 *      Author: Abdelrahman Mahmoud
 */
#ifndef USART_INT_H_
#define USART_INT_H_
#include "../MCAL/stdTypes.h"
void USART_Init(u8 Mode,u8 Parity,u8 Stop_Bits,u8 Charcter_Size);
void USART_TX_Enabel();
void USART_RX_Enabel();
void USART_TX_IE();
void USART_RX_IE();
void USART_UDRE_IE();
void USART_Baud_Rate();
void USART_Send_Char(u8 Data);
u8 USART_Recive_Char();
void USART_Send_String(char *T_Data);
void USART_Recive_String(u8 *R_Data);
void USART_RX_ID();
#endif /* USART_INT_H_ */
