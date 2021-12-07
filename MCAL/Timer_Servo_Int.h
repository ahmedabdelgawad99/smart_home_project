/*
 * TIM0.h
 *
 *  Created on: Oct 11, 2021
 *      Author: hp
 */

#ifndef TIMER_SERVO_INT_H_
#define TIMER_SERVO_INT_H_
#include "../MCAL/stdTypes.h"

void TOV_EN(void);
void Waveform_Gen_Mode();
void CompareMode_Phase_correct();
void Clk_Select();
void Select_Channel();
void WR_TCNValue(u8 value);

void OCR1AL_Value(u8 Val1);
void OCR1AH_Value(u8 Val2);
void OCR1AH_OCR1ALValue(u16 Val1);

void Motor_90_DEG();
void Motor_180_DEG();
void Motor_0_DEG();


#endif /* TIMER_SERVO_INT_H_ */
