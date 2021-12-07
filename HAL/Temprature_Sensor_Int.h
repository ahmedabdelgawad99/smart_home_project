/*
 * Remote_Prog.c
 *
 *  Created on: Nov 26, 2021
 *      Author: Ali
 */
#ifndef TEMPRATURE_SENSOR_INT_H_
#define TEMPRATURE_SENSOR_INT_H_
#include "../MCAL/stdTypes.h"
void Temp_Sens_Init();
u16 Temp_Sens_Read();
void Temp_AC_Check();
#endif /* TEMPRATURE_SENSOR_INT_H_ */
