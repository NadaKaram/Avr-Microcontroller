/*
 * EXTI_priv.h
 *
 *  Created on: Feb 7, 2023
 *      Author: lenovo
 */

#ifndef EXTI_EXTI_PRIV_H_
#define EXTI_EXTI_PRIV_H_

//registers MCUCR MCUCSR
#define MCUCR_REG         (*((volatile u8*)0x55)) // control trigger for INT0 INT1
#define MCUCSR_REG        (*((volatile u8*)0x54)) // control trigger
#define GICR_REG          (*((volatile u8*)0x5B))//PIE for (INT0 , INT1 , INT2)
#define GIFR_REG          (*((volatile u8*)0x5A))// flags


//MCUCR_REG
#define ISC00_BIT  0
#define ISC01_BIT  1
#define ISC10_BIT  2
#define ISC11_BIT  3
//MCUCSR_REG
#define ISC2_BIT       6
//GICR_REG
#define INT2_BIT       5
#define INT0_BIT       6
#define INT1_BIT       7
#define EXTI_INT0_TRIG_MASK     0b11111100
#define EXTI_INT1_TRIG_MASK     0b11110011
#define EXTI_INT1_TRIG_SHIFT    2
#define EXTI_INT2_TRIG_SHIFT    6
#endif /* EXTI_EXTI_PRIV_H_ */
