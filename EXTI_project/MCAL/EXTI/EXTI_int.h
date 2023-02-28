/*
 * EXTI_int.h
 *
 *  Created on: Feb 7, 2023
 *      Author: lenovo
 */

#ifndef EXTI_EXTI_INT_H_
#define EXTI_EXTI_INT_H_
#define EXTI_TRIG_LOW_LEVEL  0
#define EXTI_TRIG_ANY_CHANGE 1
#define EXTI_TRIG_FALL_EDGE  2
#define EXTI_TRIG_RAIS_EDGE  3
#include "../../LIB/std_types2.h"
#define EXTI_INT0_ID 6
#define EXTI_INT1_ID 7
#define EXTI_INT2_ID 5
void M_EXTI_void_enable(u8 copy_u8IntID, u8 copy_u8Sense);
void M_EXTI_void_disable(u8 copy_u8IntID);
void M_EXTI_void_setCallBack(void (*ptrfn)(void),u8 copy_u8IntID);
#endif /* EXTI_EXTI_INT_H_ */
