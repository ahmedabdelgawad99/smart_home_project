/*
 * main.c
 *
 *  Created on: Nov 22, 2021
 *      Author: .........
 */
/*OTHER PERIHERALS INTERFACES*/
#include "util/delay.h"
#include "../HAL/Remote_Int.h"
#include "../HAL/LCD_int.h"
#include "../HAL/Keypad_int.h"
#include "../HAL/AC_Int.h"
#include "../HAL/Temprature_Sensor_Int.h"
#include "../HAL/LED_Buzzer_Int.h"
#include "../HAL/Door_Int.h"
#include "../MCAL/AVR_REG.h"
#include "../MCAL/Interrupt_Int.h"
#include "../MCAL/GIE_Int.h"
#include "../HAL/EEPROM_int.h"
#include <string.h>
/****VALUES OF User_Check****/
#define ADMIN    2
#define USER     1
/****Values of Program_Check****/
#define REMOTE   1
#define KEYPAD   2
/****Function Prototypes****/
void Program_Check_Fun();
void Peripherals_Init();
/****GLOBAL VARIABLES****/
static u8 Program_Check;
u8 User_Char[6]={'A','B','C','D','E','F'};
/***************************************************************************************************************************/

int main ()
{

	 /****************Variables Deceleration****************/
	u8 Data;                             /*Remote Control*/
	u8 Key_Check=0;                      /*KeyPad*/
	u8 User_Num=0;                       /*For Login and Sign Up System*/
	u8 User_Check ;                      /*For Login and Sign Up System*/
	u8 Admin_Check=1;                    /*For Login and Sign Up System*/
	u8 Trial_Number=0;                   /*For Login and Sign Up System*/
	u8 Add_Num=0;                        /*For UserName and Password Address*/
	u8 Em_Add_Num=0;                     /*For Emergency Address*/
	u8 Check;                            /*To check for PassWord and UserName*/
	u8 Memo_Data[8];                     /*Memory*/
	u8 UserName[8];                      /*Remote Control*/
	u8 PassWord[8];                      /*Remote Control*/
	u8 Emergency[4];                     /*Remote Control*/
/***********************************************************************************************************************/
	Peripherals_Init();                  /*Function Initialization Deceleration*/
   	while (1)
	{
   		   Temp_AC_Check();
/*************************************************************************************************************************************/
/********************************************************REMOTE SYSTEM PROGRAM********************************************************/
/*************************************************************************************************************************************/
			if (Program_Check == REMOTE)
				{
			      USART_Send_String("****************HI****************\r\n");
				  USART_Send_String("Welcome to Controlling Your Home\r\n");
				  Remote_New_Line(2);
			    	/******************* SIGN_UP OF ADMIN *******************/
			            if(User_Num==0)
			            {
			            	do{
			            	Temp_AC_Check();
			        		Remote_Send_String("Please Enter Admin UserName\r\n");
			        		Remote_Typing(UserName,8,SHOWN);
			        		Remote_New_Line(1);
			        		Remote_Send_String("Please Enter Admin PassWord\r\n");
			        		Remote_Typing(PassWord,8,SHOWN);
			        		Remote_New_Line(2);
			        		Remote_Send_String("Enter Your Admin 4_Digits Emergency PassWord\r\n");
			        		Remote_Typing(Emergency,4,SHOWN);
			        		Remote_New_Line(2);
				    		Remote_Send_String("Your UserName\r\n");
				       		Remote_Display(UserName,8);
				       		Remote_New_Line(1);
				       		Remote_Send_String("Your Password\r\n");
				       		Remote_Display(PassWord,8);
				       		Remote_New_Line(1);
				       		Remote_Send_String("Your Emergency PassWord\r\n");
				       		Remote_Display(Emergency,4);
				       		Remote_New_Line(2);
				    	    Remote_Send_String("To Confirm Press 'C' **PROGRAM WILL EXIT** \r\n");
				    	    Remote_Send_String("To Decline Press 'D' \r\n");
				    		Remote_New_Line(2);
				    	    Data= USART_Recive_Char();
				    	    if(Data == 'C'||Data=='c')
				    	     {
				    	    	Temp_AC_Check();
				    	    	Remote_Send_String("PLEASE WAIT");
				    	        Save_Info(0,UserName,8);
				    			Save_Info(48,PassWord,8);
				    			Save_Info(96,Emergency,4);
				    			Add_Num+=8;       /*increment the Address for the Next Store*/
				    			Em_Add_Num+=4;    /*increment the Address for the Next Store*/
				    			Remote_New_Line(2);
				    			Remote_Send_String("YOUR USER CHARCTER is  ");
				    			USART_Send_Char(User_Char[User_Num]);
				    			Remote_New_Line(1);
				    			Remote_Send_String("****PLEASE MEMORIZE YOUR USER CHARCTER****");
				    			Remote_New_Line(2);
				    			Remote_Send_String("IF YOU WISH TO RESTART THE PROGRAM PRESS ANY KEY \r\n");
				    			User_Num++;
				    	    	Program_Check=0;      /*PROGRAM RESTART*/
				    	    	USART_RX_IE();        /*PROGRAM RESTART*/
                               break;
				    	     }
				    	    else
				    	     {
				    	 	   Data = 'A';
				    	     }

			            	}while(Data =='A');
			            }
			            else if(User_Num !=0)
			            {
			            	Temp_AC_Check();
			         		USART_Send_String("A) SIGN IN\r\n");
			            	USART_Send_String("B) ADD NEW USER\r\n");
			            	Data = USART_Recive_Char();
/*************************************************************************************************************************************/
/***************************************************************SIGN IN***************************************************************/
/*************************************************************************************************************************************/
			            	if (Data=='A'||Data=='a')
			            	{
			            		do
			            		{
			            	    Temp_AC_Check();
			            		USART_Send_String("ENTER UR USER CHARCTER\r\n");
			            		Data = USART_Recive_Char();
			   				    Remote_Send_String("Please Enter UserName\r\n");
				        		Remote_Typing(UserName,8,SHOWN);
				        		Remote_New_Line(1);
				        		Remote_Send_String("Please Enter PassWord\r\n");
				        		Remote_Typing(PassWord,8,STAR);
				        		Remote_New_Line(2);
				        		//Check=Info_Check(Memo_Data,UserName);
				        		Data= USART_Recive_Char();
				        			if(/*strcmp(UserName,PassWord)==0*||*/ Data=='B'|| Data=='b')
				        			{
				        				USART_Send_String("User Not Found");
				        				Remote_New_Line(1);
				        				User_Check=0;
				        			}
				        			else
				        			{
				        				/*Condition if user signed in is  the Admin*/
				        				/*if(Check==ADMIN)
				        				Admin_Check=ADMIN;*/
				        				/*Condition if user signed in is not the Admin*/
				        				/*else if(Check==USER)
				        				Admin_Check=USER;*/
				        				User_Check=1;
   				        			}

			            		}while(User_Check==0);
                              Data= USART_Recive_Char();
			            	 if(/*Admin_Check == ADMIN ||*/ Data=='A' || Data=='a')
			            	 {
			            		     Temp_AC_Check();
			            		     Remote_Send_String("To Open Door Press 'O' \r\n");
			            		     Remote_Send_String("To Close Door Press 'S' \r\n");
			            		     Remote_Send_String("To Open Light  Press 'L' \r\n");
			            		     Remote_Send_String("To Close Light  Press 'C' \r\n");
			            		     Remote_Send_String("To Exit The Program Press 'E'  \r\n ");
									 do {
										 Data=USART_Recive_Char();
										 if(Data=='O'||Data=='o')
										 {
											Door_Open();
											LCD_ClearDisplay();
											LCD_enuSendString("DOOR OPEN");
	 									 }
										 else if(Data == 'S'|| Data=='s')
										 {
											 Door_Close();
											 LCD_ClearDisplay();
										 }
										 else if (Data =='L' || Data=='l')
										 {
											 leds_vON();
											 LCD_ClearDisplay();
											 LCD_enuSendString("LIGHT ON");
										 }
										 else if (Data =='C'||Data=='c')
										 {
											 leds_vOFF();
											 LCD_ClearDisplay();
										 }

									 }while (Data!='E'&& Data!= 'e');
							  Remote_New_Line(1);
							  Remote_Send_String("IF YOU WISH TO RESTART THE PROGRAM PRESS ANY KEY \r\n");
			            	 }

			            	 else if(/*Admin_Check == USER ||*/Data =='U' ||Data =='u')
			            	 {
			            		     Temp_AC_Check();
			            		     Remote_Send_String("To Open Light  press 'L' \r\n");
			            		     Remote_Send_String("To Close Light  press 'C' \r\n");
			            		     Remote_Send_String("To Exit The Program Press 'E' \r\n ");
									 do {
										 Data=USART_Recive_Char();
										 if (Data =='L' || Data=='l')
										 {
											 leds_vON();
											 LCD_ClearDisplay();
											 LCD_enuSendString("LIGHT_ON");
										 }
										 else if (Data =='C'|| Data=='c')
										 {
											 leds_vOFF();
											 LCD_ClearDisplay();
										 }
									   }while(Data!='E'&& Data!= 'e');
								Remote_New_Line(1);
								Remote_Send_String("IF YOU WISH TO RESTART THE PROGRAM PRESS ANY KEY \r\n");
			            	  }
/******************************************************************************************************************************************/			            	 }
/***************************************************************ADD NEW USER***************************************************************/
/******************************************************************************************************************************************/
			            	else if (Data == 'B'||Data =='b')
							{
			            		do
			            		{
			            			Temp_AC_Check();
									Remote_Send_String("Please Enter Admin UserName\r\n");
									Remote_Typing(UserName,8,SHOWN);
									Remote_New_Line(1);
									Remote_Send_String("Please Enter Admin PassWord\r\n");
									Remote_Typing(PassWord,8,STAR);
									Remote_New_Line(2);
									/*search algorithm To check Admin Info*/
									Data =USART_Recive_Char();
									if(Data=='L'||Data=='l')
									{
										USART_Send_String("User Not Found");
										Remote_New_Line(1);
										User_Check=0;
									}
									else
									{
										do{
										Temp_AC_Check();
										Remote_Send_String("Please Enter UserName\r\n");
										Remote_Typing(UserName,8,SHOWN);
										Remote_New_Line(1);
										Remote_Send_String("Please Enter PassWord\r\n");
										Remote_Typing(PassWord,8,SHOWN);
										Remote_New_Line(2);
										Remote_Send_String("Your UserName\r\n");
										Remote_Display(UserName,8);
										Remote_New_Line(1);
										Remote_Send_String("Your Password\r\n");
										Remote_Display(PassWord,8);
										Remote_New_Line(1);
										Remote_Send_String("To Confirm Press 'C' **PROGRAM WILL EXIT** \r\n");
										Remote_Send_String("To Decline Press 'D' \r\n");
										Data= USART_Recive_Char();
											if(Data == 'C'||Data == 'c')
												{
												    Remote_Send_String("PLEASE WAIT");
												    Save_Info(Add_Num,UserName,8);
						    	                    Save_Info(Add_Num+48,PassWord,8);
						    	                    Save_Info(Em_Add_Num+96,PassWord,4);
						    	                    Remote_Display(User_Char[User_Num],1);
									    			Add_Num+=8;       /*increment the Address for the Next Store*/
									    			Em_Add_Num+=4;    /*increment the Address for the Next Store*/
									    			Remote_New_Line(2);
									    			Remote_Send_String("YOUR USER CHARCTER is  ");
									    			USART_Send_Char(User_Char[User_Num]);
									    			Remote_New_Line(1);
									    			Remote_Send_String("****PLEASE MEMORIZE YOUR USER CHARCTER****");
									    			Remote_New_Line(2);
									    			Remote_Send_String("IF YOU WISH TO RESTART THE PROGRAM PRESS ANY KEY \r\n");
									    			User_Num++;
									    	    	Program_Check=0;      /*PROGRAM RESTART*/
									    	    	USART_RX_IE();        /*PROGRAM RESTART*/
												    User_Check=1;
												    break;
												}
											else
												 {
												   Data = 'A';

												 }

					            	}while(Data =='A');

				        		}

				        	}while(User_Check ==0);
						}

			       }
		    Program_Check=0;      /*PROGRAM RESTART*/
		    USART_RX_IE();        /*PROGRAM RESTART*/
	     }
/*************************************************************************************************************************************/
/*********************************************************LCD&KEYPAD PROGRAM**********************************************************/
/*************************************************************************************************************************************/
		else if (KeyPad_Press_Check()!= KEYPAD_NOT_PRESSED)
		{

		do{
			do{				LCD_ClearDisplay();
			                LCD_enuSendString("ENTER_PASSWORD");
			                LCD_DisplayPassword();
			                //KeyPad_Typing(Emergency);
			                //Read_Info(96,Data,4);
							//Searching_Function(Emergency,Data);
							Keypad_enuGetPressedKey(&Key_Check);
							if(Key_Check == 1)
							{
								break;
							}
							else
							{

								do{
											LCD_ClearDisplay();
											LCD_enuSendString("WRONG_INFO");
											_delay_ms(2000);
											LCD_ClearDisplay();
											LCD_enuSendString("ENTER_USER_NAME");
											//keyPad_Typing(Emergency.UserName,SHOWN);
											LCD_ClearDisplay();
											LCD_enuSendString("ENTER_PASSWORD");
											//keyPad_Typing(Emergency.PassWord,STAR);
											//search algorithm
											Keypad_enuGetPressedKey(&Key_Check);
											if(Key_Check==2)
											{

												break;
											}
											else if(Key_Check==3)
											{
												Trial_Number++;
												Data=1;
												if(Trial_Number==3)
												{
													while(1)
													{
														LCD_ClearDisplay();
														LCD_enuSendString("ERORR");
														buzzer_vON();
													}
												}
											else;
											}
											else;

								}while(Data==1);
							}

			             }while(Data==2);
			   LCD_enuSendString("1)LIGHT ON  ");
			   LCD_enuSendString("2)LIGHT OFF");
			   LCD_enuSendString("3) END");
			   Keypad_enuGetPressedKey(&Key_Check);
			   if(Key_Check ==1)
			   {
				   leds_vON();
				   Data=3;
			   }
			   else if (Key_Check==2)
			   {
				   leds_vOFF();
				   Data=3;
			   }
			   else if (Key_Check==3)
			   {
				   break;
			   }
			}while(Data==3);
		}
		else;
     }
}

/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
void Peripherals_Init()
{
	 Call_Back_Fun(Program_Check_Fun);
	 AC_Init();
	 Door_Ini();
	 Temp_Sens_Init();
     LCD_enuInit();
	 Keypad_enuInit();
	 Remote_Init();
	 GIE_Enable();
	 EEPROM_enuInit();
}
void Program_Check_Fun()
{
	Program_Check=1;
	USART_Recive_Char();
    USART_RX_ID();
}

