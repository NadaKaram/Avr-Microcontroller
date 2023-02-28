/*
 * std_types2.h
 *
 *  Created on: Jan 30, 2023
 *      Author: lenovo
 */

#ifndef STD_TYPES2_H_
#define STD_TYPES2_H_
#include <avr/io.h>
typedef unsigned char        u8;
typedef signed char          s8;
typedef unsigned short  int u16;
typedef signed short int    s16;
typedef unsigned long int   u32;
typedef signed long int     s32;
typedef float               f32;
typedef  double             d32;
#define NULL    (void *)0
#define PIN0_ID     0
#define PIN1_ID     1
#define PIN2_ID     2
#define PIN3_ID     3
#define PIN4_ID     4
#define PIN5_ID     5
#define PIN6_ID     6
#define PIN7_ID     7
#define PORTA_ID    1
#define PORTB_ID    2
#define PORTC_ID    3
#define PORTD_ID    4
#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUt 0
#endif /* STD_TYPES2_H_ */
