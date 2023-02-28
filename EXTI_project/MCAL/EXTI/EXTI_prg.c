/*
 * EXTI_prg.c
 *
 *  Created on: Feb 7, 2023
 *      Author: lenovo
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include"../../LIB/std_types2.h"
#include "../../LIB/BIT_MATH.h"
#include"EXTI_int.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"
static
void(*Arr_CallBack[3])(void)={NULL,NULL,NULL};
void M_EXTI_void_enable(u8 copy_u8IntID, u8 copy_u8Sense)
{
	if(copy_u8Sense >= 0 && copy_u8Sense<=3)
	{
		// step 1: config sense
		switch(copy_u8IntID)
		{
		case EXTI_INT0_ID:
			MCUCR_REG &= EXTI_INT0_TRIG_MASK;
			MCUCSR_REG |= copy_u8Sense;
			break;
		case EXTI_INT1_ID:
			MCUCR_REG &= EXTI_INT1_TRIG_MASK;
			MCUCSR_REG |= copy_u8Sense<<EXTI_INT1_TRIG_SHIFT;
			break;
		case EXTI_INT2_ID:
			// CLR_BIT(MCUCSR_REG, ,ISC2_BIT);
			MCUCSR_REG |= (GET_BIT(copy_u8Sense,0))<<EXTI_INT2_TRIG_SHIFT;
			break;
		}
		//step 2: enable PIE
		if(copy_u8IntID>= INT2_BIT && copy_u8IntID<= INT1_BIT)
		{
			SET_BIT(GICR_REG,copy_u8IntID);
		}
	}
}
void M_EXTI_void_disable(u8 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case EXTI_INT0_ID:
		// CLR_BIT(GICR,EXTI_INT0_ID);
		break;
	case EXTI_INT1_ID:
		// CLR_BIT(GICR_REG,INT1);
		break;
	case EXTI_INT2_ID:
		// CLR_BIT(GICR_REG,INT2);
		break;
	}
	//method 2
	//if(copy_u8IntID>=EXTI_INT0_ID && copy_u8IntID<=EXTI_INT2_ID)
	// CLR_BIT(GICR_REG,copy_u8IntID);
}
void M_EXTI_void_setCallBack(void (*ptrfn)(void),u8 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case EXTI_INT0_ID:
		Arr_CallBack[0]=ptrfn;
		break;
	case EXTI_INT1_ID:
		Arr_CallBack[1]=ptrfn;
		break;
	case EXTI_INT2_ID:
		Arr_CallBack[2]=ptrfn;
		break;
	}
}
ISR(INT0_vect)
{
	if(Arr_CallBack[0] != NULL)
	{
		Arr_CallBack[0]();
	}
}
ISR(INT1_vect)
{
	if(Arr_CallBack[1] != NULL)
	{
		Arr_CallBack[1]();
	}
}
ISR(INT2_vect)
{
	if(Arr_CallBack[2] != NULL)
	{
		Arr_CallBack[2]();
	}
}
