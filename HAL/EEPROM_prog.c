/*
 * EEPROM_prog.c
 *
 *  Created on: Nov 30, 2021
 *      Author: Adham
 */

#include "../MCAL/stdTypes.h"
#include "../MCAL/errorState.h"
#include "../MCAL/IIC_int.h"
#include "util/delay.h"
#include "EEPROM_config.h"
#include "EEPROM_priv.h"
#include <string.h>
ES_t EEPROM_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = IIC_enuInit();

	return Local_enuErrorState;
}

ES_t EEPROM_enuWriteData(u16 Copy_u16Address, u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

#if EEPROM_TYPE == EIGHT_KBIT
	u8 Local_u8Address =( ( 0xA0 | (EEPROM_A2_STATE<<3) | ( ((Copy_u16Address>>8) &3) << 1) ) >>1 );
	u8 Local_ByteAddress = (u8)Copy_u16Address;
#endif

	if (ES_OK == IIC_enuStartCondition())
	{


		if (ES_OK == IIC_enuWriteSlaveAddress(Local_u8Address , 0))
		{
			if (ES_OK==IIC_enuWriteData(Local_ByteAddress))
			{
				if(ES_OK == IIC_enuWriteData(Copy_u8Data))
				{
					IIC_enuStopCondition();
					Local_enuErrorState = ES_OK;
				}
			}
		}
	}
	return Local_enuErrorState;
}

ES_t EEPROM_enuReadData(u16 Copy_u16Address, u8 * Copy_pu8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

#if EEPROM_TYPE == EIGHT_KBIT
	u8 Local_u8Address =( ( 0xA0 | (EEPROM_A2_STATE<<3) | ( ((Copy_u16Address>>8) &3) << 1) ) >>1 );
	u8 Local_ByteAddress = (u8)Copy_u16Address;
#endif

	if (ES_OK == IIC_enuStartCondition())
	{
		if (ES_OK == IIC_enuWriteSlaveAddress(Local_u8Address , 0))
		{
			if (ES_OK==IIC_enuWriteData(Local_ByteAddress))
			{
				if(ES_OK == IIC_enuRepeatedStartCondition())
				{
					if (ES_OK == IIC_enuWriteSlaveAddress(Local_u8Address , 1) )
					{
						if (ES_OK == IIC_enuReadData( Copy_pu8Data ))
						{
							IIC_enuStopCondition();
							Local_enuErrorState = ES_OK;
						}
					}
				}
			}
		}
	}

	return Local_enuErrorState;
}
void Save_Info(u16 adress,u8* data,u8 len)
{
//u8 *data_cast=(u8 *)data;
	 for( u8 i=0;i<len;i++)
		  {
		 EEPROM_enuWriteData(adress+i ,data[i]);
			  _delay_ms(150);
		  }
}
void Read_Info(u16 adress,u8* data,u8 len)
{

	// u8 *data_cast=(u8 *)data;
	  for(u8 i=0;i<len;i++)
	 	  {
		  EEPROM_enuReadData(adress+i,&data[i]);
		  _delay_ms(150);
	 	  }

}

u8 Info_Check(u8 User_Num,u8 Input[])
{
	u8 Check;
	u8 Memory_Data[8];
	switch(User_Num)
	{
	case 'A':
	case 'a':
		Read_Info(0,Memory_Data,8);
		Check=strcmp(Memory_Data,Input);
		if(Check==0)
		{
			Read_Info(48,Memory_Data,8);
			Check=strcmp(Memory_Data,Input);
			if(Check==0)
				return 2;
		}
		break;
	case 'B':
	case 'b':
		Read_Info(8,Memory_Data,8);
		Check=strcmp(Memory_Data,Input);
		if(Check==0)
		{
			Read_Info(56,Memory_Data,8);
			Check=strcmp(Memory_Data,Input);
			if(Check==0)
				return 1;
		}
		break;
	case 'C':
	case 'c':
		Read_Info(16,Memory_Data,8);
		Check=strcmp(Memory_Data,Input);
		if(Check==0)
		{
			Read_Info(64,Memory_Data,8);
			Check=strcmp(Memory_Data,Input);
			if(Check==0)
				return 1;
		}
		break;
	case 'D':
	case 'd':
		Read_Info(24,Memory_Data,8);
		Check=strcmp(Memory_Data,Input);
		if(Check==0)
		{
			Read_Info(72,Memory_Data,8);
			Check=strcmp(Memory_Data,Input);
			if(Check==0)
				return 1;
		}
		break;
	case 'E':
	case 'e':
		Read_Info(32,Memory_Data,8);
		Check=strcmp(Memory_Data,Input);
		if(Check==0)
		{
			Read_Info(80,Memory_Data,8);
			Check=strcmp(Memory_Data,Input);
			if(Check==0)
				return 1;
		}
		break;
	case 'F':
	case 'f':
		Read_Info(40,Memory_Data,8);
		Check=strcmp(Memory_Data,Input);
		if(Check==0)
		{
			Read_Info(88,Memory_Data,8);
			Check=strcmp(Memory_Data,Input);
			if(Check==0)
				return 1;

		}
		break;
	default:
		break;
	}
	return 0;
}
