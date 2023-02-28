/*
 * timer_priv.h
 *
 *  Created on: Feb 9, 2023
 *      Author: lenovo
 */

#ifndef TIMER_TIMER_PRIV_H_
#define TIMER_TIMER_PRIV_H_
//TIMER REG
#define TCNT0_REG		(*((volatile u8 *)0x52))		//COUNTER REG
#define TCCR0_REG		(*((volatile u8 *)0X53))		//COMPARE MATCH REG
#define OCR0_REG		(*((volatile u8 *)0X5C))		//CONTROL REG

#define TIMSK_REG		(*((volatile u8 *)0X59))		//PIE s
#define TIFR_REG		(*((volatile u8 *)0X58))		//FLAGS

// REG BITs

//TCCR0 REG
#define WGM01_BIT			3
#define WGM00_BIT			6

//TIMSK REG
#define TOIE0_BIT			0		//OVERFLOW INTERRUPT ENABLE
#define OCIE0_BIT			1		//COMPARE MATCH INTERRUPT ENABLE



#define TIMER0_PRESCALER_MASK	0b11111000		//0XF8
#define TIMER0_OC0_MASK			0b11001111		//0XCF
#define TIMER0_OC0_SHIFT			4

//TIMER MODES
#define TIMER0_NORMAL_MODE			0			//الرقم دة مش مهم انا بعمل مقارنة بس
#define TIMER0_CTC_MODE				1
#define TIMER0_FAST_PWM_MODE		2
#define TIMER0_PHASECORRECT_MODE	3

// PRESCALER OPTIONS
#define TIMER0_PRESCALER_NO_CLOCK				0
#define TIMER0_PRESCALER_NO_PRESCALER			1
#define TIMER0_PRESCALER_8						2
#define TIMER0_PRESCALER_64						3
#define TIMER0_PRESCALER_256					4
#define TIMER0_PRESCALER_1024					5
#define TIMER0_PRESCALER_EXTCLK_FALL_EDGE		6
#define TIMER0_PRESCALER_EXTCLK_RAISING_EDGE	7

//OC0 PIN MODE OPTIONS FOR NON PWM
#define TIMER0_OC0_MODE_DISSCONECTED	0
#define TIMER0_OC0_MODE_TOGGLE			1
#define TIMER0_OC0_MODE_CLEAR			2
#define TIMER0_OC0_MODE_SET				3
// OC0 pin mode options for pwm
#define TIMER0_PWM_NON_INVERTED   0x20//0b0010 0000
#define TIMER0_PWM_INVERTED	      0x30// 0b0011 0000

#endif /* TIMER_TIMER_PRIV_H_ */
