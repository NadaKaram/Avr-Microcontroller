/*
 * keypad_prg.c
 *
 *  Created on: Feb 2, 2023
 *      Author: lenovo
 */


#include"Dio_int.h"
#include "keypad_int.h"
#include "keypad_config.h"
#include <util/delay.h>
void H_KEYPAD_void_init(void)
{
	//set all rows directions
	 M_Dio_void_setPinDir(KEYPAD_R0_PORT,KEYPAD_R0_PIN,1);
	 M_Dio_void_setPinDir(KEYPAD_R1_PORT,KEYPAD_R1_PIN,1);
	 M_Dio_void_setPinDir(KEYPAD_R2_PORT,KEYPAD_R2_PIN,1);
	 M_Dio_void_setPinDir(KEYPAD_R3_PORT,KEYPAD_R3_PIN,1);
	 //set all columns directions
	 M_Dio_void_setPinDir(KEYPAD_C0_PORT,KEYPAD_C0_PIN,0);
	 M_Dio_void_setPinDir(KEYPAD_C1_PORT,KEYPAD_C1_PIN,0);
	 M_Dio_void_setPinDir(KEYPAD_C2_PORT,KEYPAD_C2_PIN,0);
	 M_Dio_void_setPinDir(KEYPAD_C3_PORT,KEYPAD_C3_PIN,0);
	 //set the value of the rows
	 M_Dio_void_setPinValue(KEYPAD_R0_PORT,KEYPAD_R0_PIN,HIGH);
	 M_Dio_void_setPinValue(KEYPAD_R1_PORT,KEYPAD_R1_PIN,HIGH);
	 M_Dio_void_setPinValue(KEYPAD_R2_PORT,KEYPAD_R2_PIN,HIGH);
	 M_Dio_void_setPinValue(KEYPAD_R3_PORT,KEYPAD_R3_PIN,HIGH);
// set all rows direction as output
// set all columns direction as inputs
	//deactivate rows
}
u8 H_KEYPAD_void_getPressedKey(void)
{
  u8 Loc_key = NOT_PRESSED_KEY;
 u8 loc_row_indx;
 u8 Loc_col_indx;
 u8 read;
 u8 Loc_KEYPAD_ARR [4][4]=KEYPAD_ARR_1;
 for(loc_row_indx = KEYPAD_R0_PIN;loc_row_indx <= KEYPAD_R3_PIN; loc_row_indx++)
 {
	 M_Dio_void_setPinValue(KEYPAD_ROW_PORT,loc_row_indx ,LOW);
	 for(Loc_col_indx = KEYPAD_C0_PIN;Loc_col_indx <= KEYPAD_C3_PIN; Loc_col_indx++)
	  {
		 //get 1st reading
		 M_Dio_void_getPinValue(KEYPAD_COL_PORT,Loc_col_indx ,&read);
		 if(read== ACTIVE_LOW_PRESSED)
		 {
             //debouncing delay
			 _delay_ms(200);
			 //get 2nd reading
			 M_Dio_void_getPinValue(KEYPAD_COL_PORT,Loc_col_indx ,&read);
			 if(read ==ACTIVE_LOW_PRESSED)
			 {
				 while(read == ACTIVE_LOW_PRESSED)
				 {
					 M_Dio_void_getPinValue(KEYPAD_COL_PORT,Loc_col_indx ,&read);
				 }
				 Loc_key=Loc_KEYPAD_ARR [loc_row_indx-KEYPAD_R0_PIN][Loc_col_indx-KEYPAD_C0_PIN];
				 return Loc_key;
			 }//if 2nd reading
		 }//if 1st reading
	  }
	 //decativate row
	 M_Dio_void_setPinValue(KEYPAD_ROW_PORT,loc_row_indx ,HIGH);
 }

}
