/*
 * stdTypes.h
 *
 *  Created on	: Nov 22, 2021
 *  Version		: 1.0.0
 *  Author		: John
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

/*typedef <dataType> <newName>*/

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
typedef long double f80;

#define NULL				(void*)0

/****Special Data Types****/
/*struct User_Info{               //Used for Storing Sign-Up Data and Pass Login Data
	u8 UserName[8];
	u8 PassWord[8];
};*/

#endif /* STDTYPES_H_ */
