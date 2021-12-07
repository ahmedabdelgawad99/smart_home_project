/*
 * USART_Private.h
 *
 *  Created on: Oct 26, 2021
 *      Author: Abdelrahman Mahmoud
 */
#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_
/*UCSRA BINS*/
#define RXC  7 /* USART Receive Complete*/
#define TXC  6 /*USART Transmit Complete*/
#define UDRE 5 /*USART Data Register (UDR) Empty*/
#define FE   4 /*Frame error*/
#define DOR  3 /*data overrun*/
#define PE   2 /*parity error bin*/
#define U2X  1 /*Double the USART Transmission Speed*/
#define MPCM 0 /* Multi-processor Communication Mode*/
/*UCSRB BINS*/
#define RXCIE 7 /*Receiver Interrupt Enable*/
#define TXCIE 6 /*Transmitter Interrupt Enable*/
#define UDRIE 5 /*Data Register (UDR) Empty Interrupt Enable*/
#define RXEN  4 /*Receiver Enable*/
#define TXEN  3 /*Transmitter Enable*/
#define UCSZ2 2
#define RXB8  1 /*for the 9th bit in the 9bit mode*/
#define TXB8  0 /*for the 9th bit in the 9bit mode*/
/*UCSRC BINS*/
#define USREL 7 /*register select*/
#define UMSEL 6 /*Mode select[synch , asynch]*/
#define UPM1  5 /*parity mode*/
#define UPM0  4 /*parity mode*/
#define USBS  3 /*stop bits*/
#define UCSZ1 2 /*Character size select*/
#define UCSZ0 1 /*Character size select*/
#define UCPOL 0 /*clock enable only for synch mode*/
/*System Frequency*/
#define FOSC 16000000UL
#endif /* USART_PRIVATE_H_ */
