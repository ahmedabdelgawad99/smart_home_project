/*
 * LCD_prog.c
 *
 *  Created on: Nov 22, 2021
 *      Author: John
 */
#include "../MCAL/stdTypes.h"
#include "../MCAL/errorState.h"
#include "../MCAL/DIO_int.h"
#include "Keypad_int.h"
#include "LCD_config.h"
#include "LCD_priv.h"
#include <util/delay.h>

ES_t LCD_enuInit(void)
{
	ES_t Local_u8ErrorState = ES_NOK;

	DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);

	_delay_ms(35);
#if LCD_MODE == FOUR_BIT

	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x28);


#elif LCD_MODE == EIGHT_BIT
	DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x38);

#endif

	_delay_ms(1);
	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x0f);

	_delay_ms(1);
	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x01);

	_delay_ms(2);
	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(0x06);

	return Local_u8ErrorState;
}

ES_t LCD_enuSendData(u8 Copy_u8Data)
{
	ES_t Local_u8ErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
	LCD_enuWriteNLatch(Copy_u8Data);


	return Local_u8ErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_t Local_u8ErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8LOW);
	LCD_enuWriteNLatch(Copy_u8Command);

	return Local_u8ErrorState;
}


ES_t LCD_enuSendString(const char * Copy_pcString)
{
	ES_t Local_u8ErrorState = ES_NOK;

	while (*Copy_pcString)//'\0' ,'0'
	{
		DIO_enuSetPinValue(RS_PORT, RS_PIN , DIO_u8HIGH);
		LCD_enuWriteNLatch(*Copy_pcString++);
	}

	return Local_u8ErrorState;
}


static ES_t LCD_enuWriteNLatch(u8 Copy_u8Data)
{
	ES_t Local_u8ErrorState = ES_NOK;

	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW);

	if (Copy_u8Data == 0x28)//'('
	{
		//u8 Local_u8RS_Val;
		//DIO_enuGetPinValue(RS_PORT, RS_PIN, &Local_u8RS_Val);

		//if (Local_u8RS_Val == DIO_u8LOW)
		{
			DIO_enuSetPinValue(D7_PORT, D7_PIN , ((Copy_u8Data>>7)&1));
			DIO_enuSetPinValue(D6_PORT, D6_PIN , ((Copy_u8Data>>6)&1));
			DIO_enuSetPinValue(D5_PORT, D5_PIN , ((Copy_u8Data>>5)&1));
			DIO_enuSetPinValue(D4_PORT, D4_PIN , ((Copy_u8Data>>4)&1));

			DIO_enuSetPinValue(EN_PORT, EN_PIN , DIO_u8HIGH);
			_delay_ms(5);
			DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
			_delay_ms(5);
		}
	}

#if LCD_MODE == FOUR_BIT //'A' =65=0b 0100  0001

	DIO_enuSetPinValue(D7_PORT, D7_PIN , ((Copy_u8Data>>7)&1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN , ((Copy_u8Data>>6)&1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN , ((Copy_u8Data>>5)&1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN , ((Copy_u8Data>>4)&1));

	DIO_enuSetPinValue(EN_PORT, EN_PIN , DIO_u8HIGH);
	_delay_ms(5);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	_delay_ms(5);


	DIO_enuSetPinValue(D7_PORT, D7_PIN , ((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN , ((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN , ((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN , ((Copy_u8Data>>0)&1));

	DIO_enuSetPinValue(EN_PORT, EN_PIN , DIO_u8HIGH);
	_delay_ms(5);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	_delay_ms(5);

#elif LCD_MODE == EIGHT_BIT
	DIO_enuSetPinValue(D7_PORT, D7_PIN , ((Copy_u8Data>>7)&1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN , ((Copy_u8Data>>6)&1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN , ((Copy_u8Data>>5)&1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN , ((Copy_u8Data>>4)&1));
	DIO_enuSetPinValue(D3_PORT, D3_PIN , ((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D2_PORT, D2_PIN , ((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D1_PORT, D1_PIN , ((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D0_PORT, D0_PIN , ((Copy_u8Data>>0)&1));

	DIO_enuSetPinValue(EN_PORT, EN_PIN , DIO_u8HIGH);
	_delay_ms(5);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	_delay_ms(5);

#else
#error"LCD mode is wrong"
#endif


	return Local_u8ErrorState;
}
void LCD_DisplayUser(void)
{
	u8 key;

	Keypad_enuGetPressedKey(&key);

	if (key != KEYPAD_NOT_PRESSED)
	{
		LCD_enuSendData(key);
	}
}
void LCD_ClearDisplay(void)
{
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8LOW);
	LCD_enuWriteNLatch(0x01);
}

void LCD_DisplayPassword()
{
		u8 key,i;
		for(i=0;i<4;i++)
		{
			Keypad_enuGetPressedKey(&key);
			if (key != KEYPAD_NOT_PRESSED)
			{
	 	            key = '*';
					LCD_enuSendData(key);
			}
		}

}


