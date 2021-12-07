/*
 * TIMER0_Config.h
 *
 *  Created on: Nov 11, 2021
 *      Author: Ali-Elgazzar
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_




/* N0rmal     PWM_Ph     CTc      FAst_PWM   */
#define Wave_GEN_Mode         FAst_PWM


/*   Normal_port_op  Toggle_OC0      Clear_OC0       Set_OC0  */

#define Compare0_Match_Out          Clear_OC0



/* No_prescaling   No_clk_source     cl_64         cl_256       cl_1024      Ext_cl_ris   Ext_cl_fall  */
#define Cl_Selec    cl_64

#endif /* TIMER0_CONFIG_H_ */
