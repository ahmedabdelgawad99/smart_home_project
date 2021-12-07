/*
 * DIO_priv.h
 *
 *  Created on: Sep 25, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define DIO_u8GROUP_A 			0
#define DIO_u8GROUP_B 			1
#define DIO_u8GROUP_C 			2
#define DIO_u8GROUP_D 			3

#define DIO_u8PIN0				0
#define DIO_u8PIN1				1
#define DIO_u8PIN2				2
#define DIO_u8PIN3				3
#define DIO_u8PIN4				4
#define DIO_u8PIN5				5
#define DIO_u8PIN6				6
#define DIO_u8PIN7				7

#define DIO_u8OUTPUT			1
#define DIO_u8INPUT				0

#define DIO_u8HIGH				1
#define DIO_u8LOW				0

#define DIO_u8PULL_UP			1
#define DIO_u8FLOAT				0




#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)			0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)				CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)




#define DIO_MASK_BIT			1

#endif /* DIO_PRIV_H_ */
