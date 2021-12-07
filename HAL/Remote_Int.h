/*
 * Remote_Int.h
 *
 *  Created on: Nov 26, 2021
 *      Author: Abdelrahman Mahmoud
 */

#ifndef REMOTE_INT_H_
#define REMOTE_INT_H_
#include "../MCAL/USART_Int.h"
#include "../MCAL/USART_Config.h"
#define STAR 1
#define SHOWN 0
#define REMOTE_NOT_PRESSED 0
void Remote_Init();
void Remote_Typing();
void Remote_Send_String(char *T_Data);
void Remote_New_Line();
void Remote_Display(u8 *T_Data,u8 Str_Size);
u8 Remote_Check();
#endif /* REMOTE_INT_H_ */
