/*
 * timer_int.h
 *
 *  Created on: Feb 9, 2023
 *      Author: lenovo
 */

#ifndef TIMER_TIMER_INT_H_
#define TIMER_TIMER_INT_H_
#include "../../LIB/std_types2.h"
#define TIMER0_OVF_INT_ID    0
#define TIMER0_CMP_INT_ID    1
void M_TIMER0_void_Init(void);
void M_TIMER0_void_Start(void);
void M_TIMER0_void_Stop(void);
void M_TIMER0_void_SetTime(u32 copy_u32timeMS);
void M_TIMER0_void_EnableInt(u8 copy_u8IntID);
void M_TIMER0_void_DisableInt(u8 copy_u8IntID);
void M_TIMER0_void_setCallBack(void(*ptrfn)(void), u8 copy_u8IntID);
void M_Timer0_void_setTime(u32 copy_u32);
void M_TIMER0_void_setFastPWM(u8 copy_u8Duty);
void M_TIMER0_void_setphaseCorrectPWM(u8 copy_u8Duty);
#endif /* TIMER_TIMER_INT_H_ */
// ovf time= 2 ^resolution * tick time =2^8 * 2=512 micro sec
