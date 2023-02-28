/*
 * keypad_config.h
 *
 *  Created on: Feb 2, 2023
 *      Author: lenovo
 */

#ifndef KEYPAD_KEYPAD_CONFIG_H_
#define KEYPAD_KEYPAD_CONFIG_H_
#include "../../LIB/std_types2.h"

#define KEYPAD_ROW_PORT  PORTB_ID
#define KEYPAD_COL_PORT   PORTD_ID
#define KEYPAD_R0_PORT  PORTB_ID
#define KEYPAD_R0_PIN   PIN4_ID
#define KEYPAD_R1_PORT  PORTB_ID
#define KEYPAD_R1_PIN   PIN5_ID
#define KEYPAD_R2_PORT  PORTB_ID
#define KEYPAD_R2_PIN   PIN6_ID
#define KEYPAD_R3_PORT  PORTB_ID
#define KEYPAD_R3_PIN   PIN7_ID
#define KEYPAD_C0_PORT  PORTD_ID
#define KEYPAD_C0_PIN   PIN2_ID
#define KEYPAD_C1_PORT  PORTD_ID
#define KEYPAD_C1_PIN   PIN3_ID
#define KEYPAD_C2_PORT  PORTD_ID
#define KEYPAD_C2_PIN   PIN4_ID
#define KEYPAD_C3_PORT  PORTD_ID
#define KEYPAD_C3_PIN   PIN5_ID
/*
 * please choose:
 * KEYPAD_ARR_1  or KEYPAD_ARR_2
 */
#define KEYPAD_ARR_MAP  KEYPAD_ARR_1
#define KEYPAD_ARR_1    {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
#define KEYPAD_ARR_2    {{'7','8','9','+'},{'4','5','6','-'},{'1','2','3','*'},{'A','0','=','/'}}
#endif /* KEYPAD_KEYPAD_CONFIG_H_ */
