/*
 * led_int.h
 *
 *  Created on: Jan 31, 2023
 *      Author: lenovo
 */

#ifndef LED_INT_H_
#define LED_INT_H_
#include "../LIB/std_types2.h"
#define Red_Led 0
#define Grn_Led 1
#define Blu_Led 2
void H_Led_void_ledINit(u8 LedID);
void H_Led_void_setON(u8 LedID);
void H_Led_void_setOFF(u8 LedID);
void H_Led_void_toggle(u8 LedID);
#endif /* LED_INT_H_ */
