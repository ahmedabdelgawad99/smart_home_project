/*
 * EEPROM_int.h
 *
 *  Created on: Nov 30, 2021
 *      Author: Adham
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_
#define PASSWORD_CHECK 0
#define USERNAME_CHECK 1

ES_t EEPROM_enuInit(void);

ES_t EEPROM_enuWriteData(u16 Copy_u16Address, u8 Copy_u8Data);

ES_t EEPROM_enuReadData(u16 Copy_u16Address, u8 * Copy_pu8Data);
void Save_Info(u16 adress,u8* data,u8 len);
void Read_Info(u16 addres,u8* data,u8 len);
//u8 InfoCheck();
u8 Info_Check(u8 User_Num,u8 Trial);
u8 Searching_Function(char User_Info_Ptr[],char User_Input_Ptr[]);
#endif /* EEPROM_INT_H_ */
