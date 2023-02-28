/*
 * Dio_int.h
 *
 *  Created on: Jan 30, 2023
 *      Author: lenovo
 */

#ifndef DIO_DIO_INT_H_
#define DIO_DIO_INT_H_
#include "../../LIB/std_types2.h"

void M_Dio_void_setPinDir(u8 port,u8 pin,u8 dir);
void M_Dio_void_setPinValue(u8 port,u8 pin,u8 dir);
void M_Dio_void_getPinValue(u8 port,u8 pin,u8 *dir);
void Dio_tog(u8 port,u8 pin);
void setPortValue(u8 port,u8 value);
void getPortValue(u8 port, u8 *value);
#endif /* DIO_DIO_INT_H_ */
