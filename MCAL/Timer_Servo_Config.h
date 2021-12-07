/*
 * Timer1_Config.h
 *
 *  Created on: Oct 17, 2021
 *      Author:  Ali-Elgazzar
 */

#ifndef TIMER_SERVO_CONFIG_H_
#define TIMER_SERVO_CONFIG_H_

/* Channel_A     Channel_B */
#define Selec_Ch     Channel_B


/* Normal     PWM_PhCrt_MODE9     CTC      Fast_PWM   */
#define WAVE_GEN_Mode        PWM_PhCrt_MODE9


/*   Normal_port_op  Toggle_OC1      Clear_OC1      Set_OC1  */

#define CompareMode_Ph_Corr          Clear_OC1



/* No_prescaling   No_clk_source     clk_64         clk_256       clk_1024      Ext_clk_ris   Ext_clk_fall  */
#define Clk_Selec    clk_64


#endif /* TIMER_SERVO_CONFIG_H_*/
