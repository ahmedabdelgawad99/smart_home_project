/*
 * Keypad_int.h
 *
 *  Created on: Nov 22, 2021
 *      Author: Ahmed Abdelgwad
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_
#include "../MCAL/errorState.h"
ES_t Keypad_enuInit(void);
ES_t Keypad_enuGetPressedKey(u8 * Copy_pu8KeyValue);
#define KEYPAD_NOT_PRESSED    0xff

#endif /* KEYPAD_INT_H_ */
