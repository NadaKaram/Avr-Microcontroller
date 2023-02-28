/*
 * main.c
 *
 *  Created on: Feb 7, 2023
 *      Author: lenovo
 */
#include"led_int.h"
//#include"../HAL/LCD2/lcd_priv.h"
#include "std_types2.h"
#include "Dio_int.h"
#include "timer_int.h"
//#include"../HAL/LCD2/lcd_config.h"
//#include"../MCAL/TIMER/timer_config.h"
//#include"../MCAL/TIMER/timer_int.h"
//#include "../MCAL/EXTI/EXTI_int.h"
#include <avr/delay.h>
//#include<TIMER_int.h>
#include "../HAL/LCD/LCD_int.h"

void Action(void);
#if 0
void Action0(void);
int main(void)
{
	//init the led
	H_Led_void_ledINit(Red_Led);
	//enable the interrupt
	M_EXTI_void_enable(EXTI_INT0_ID,EXTI_TRIG_FALL_EDGE);
	//set call back fn to be Action0
	M_EXTI_void_setCallBack(Action0,EXTI_INT0_ID);
	//enable GIE
	M_GIE_void_enable();

	while(1)
	{


	}

}
void Action0(void)
{

	H_Led_void_toggle(Red_Led);
}
#endif
#if 0
int main(void)
{
	H_Led_void_ledINit(Red_Led);
	M_TIMER0_void_Init();
	M_TIMER0_void_setCallBack(Action, TIMER0_OVF_INT_ID);
	//set time
	M_Timer0_void_setTime(1000);
	//GIE
	M_GIE_void_enable();
	// timer_start
	M_TIMER0_void_Start();
	while(1)
	{

	}

}
void Action(void)
{

	H_Led_void_toggle(Red_Led);
}
#endif
#if 0
void main()
{
	H_LCD_void_Init();
	H_LCD_void_sendString("Hello");
	//  H_LCD_void_gotXY(0,5);
	//	H_LCD_void_sendData('A');
	//  H_LCD_void_sendData('h')
	while(1)
	{
		/*
		  H_LCD_void_sendIntNum(0);
		  _delay_ms(1000);
		  H_LCD_void_clear();
		  H_LCD_void_sendIntNum(235);
		  _delay_ms(1000);
		  H_LCD_void_clear();
		  H_LCD_void_sendIntNum(-100);
		  _delay_ms(1000);
		  H_LCD_void_clear();
		 */

	}

}
#endif
void main()
{
	// init (Timer mode + Timer OC0 mode)
	M_Dio_void_setPinDir(PORTB_ID,PIN3_ID,OUTPUT);
	M_TIMER0_void_Init();
	M_TIMER0_void_Start();
	while(1)
	{
		_delay_ms(1000);
		M_TIMER0_void_setphaseCorrectPWM(50);
		_delay_ms(1000);
		M_TIMER0_void_setphaseCorrectPWM(80);
		_delay_ms(1000);
		M_TIMER0_void_setphaseCorrectPWM(100);
	}


	// set call back
	// ovf interrupt Enable
	// GIE
	// timer start
}
