/*
 * LCD_int.h
 *
 *  Created on: Nov 22, 2021
 *      Author: John
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
#include "../MCAL/errorState.h"
ES_t LCD_enuInit(void);

ES_t LCD_enuSendData(u8 Copy_u8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);

ES_t LCD_enuSendString(const char * Copy_pcString);
void LCD_DisplayUser(void);
void LCD_DisplayPassword();
void LCD_ClearDisplay(void);
#endif /* LCD_INT_H_ */
