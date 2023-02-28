/*
 * timer_prg.c
 *
 *  Created on: Feb 9, 2023
 *      Author: lenovo
 */
#include <stdlib.h>
#include <MATH.h>
#include "timer_int.h"
#include "timer_config.h"
#include "timer_priv.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/interrupt.h>
static u32 NumberOFOverflows =0;
static u32 NumberOFRemainingTicks =0;

void M_Timer0_void_setTime(u32 copy_u32timeMS) // time in millisecond
{
	u32 Loc_prescalerArr[]={1,8,64,256,1024};
	f32 Lock_TickTime = (f32)Loc_prescalerArr[TIMER0_PRESCALER-1]/ FCPU;
	u32 NoOFDesiredTicks =(copy_u32timeMS * 1000)/ Lock_TickTime;
#if(TIMER0_MODE == TIMER0_NORMAL_MODE)
	NumberOFOverflows = NoOFDesiredTicks/256;
	NumberOFRemainingTicks = NoOFDesiredTicks % 256;
	if(NumberOFRemainingTicks !=0)
	{
		TCNT0_REG = 256 - NumberOFRemainingTicks;
		NumberOFOverflows++;
	}
#elif(TIMER0_MODE == TIMER0_CTC_MODE)

#endif
}
static void (* Arr_callBack[2])(void)={NULL ,NULL};
void M_TIMER0_void_Init(void)
{
	//STEP 1 : CONFIG TIMER MODE
#if(TIMER0_MODE == TIMER0_NORMAL_MODE)
	{
		CLR_BIT(TCCR0_REG,WGM00_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);

		//STEP 2 : UNDER EACH MODE CONFIG OC0 PIN MODE
#if(TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISSCONECTED && TIMER0_OC0_MODE <= TIMER0_OC0_MODE_SET)

		{
			//STEP 1: APPLY MASK
			TCCR0_REG &= TIMER0_OC0_MASK;
			//STEP 2: INSERT VALUE
			TCCR0_REG |= (TIMER0_OC0_MODE << TIMER0_OC0_SHIFT);
		}
#else
#error ("wrong OC0 Mode")
#endif
	}
#elif(TIMER0_MODE == TIMER0_CTC_MODE)
	CLR_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);
#if(TIMER0_OC0_MODE >= TIMER0_OC0_MODE_DISSCONECTED && TIMER0_OC0_MODE == TIMER0_OC0_MODE_SET)


	//STEP 1: APPLY MASK
	TCCR0_REG &= TIMER0_OC0_MASK;
	//STEP 2: INSERT VALUE
	TCCR0_REG |= (TIMER0_OC0_MODE << TIMER0_OC0_SHIFT);

#else
#error ("WRONG OC0 ODE")
#endif
#elif(TIMER0_MODE == TIMER0_FAST_PWM_MODE)
	SET_BIT(TCCR0_REG,WGM00_BIT);
	SET_BIT(TCCR0_REG,WGM01_BIT);

#elif(TIMER0_MODE == TIMER0_PHASECORRECT_MODE)
	SET_BIT(TCCR0_REG,WGM00_BIT);
	CLR_BIT(TCCR0_REG,WGM01_BIT);
#endif

#if((TIMER0_OC0_MODE == TIMER0_PWM_NON_INVERTED) || (TIMER0_OC0_MODE == TIMER0_PWM_INVERTED))
	TCCR0_REG &= TIMER0_OC0_MASK;
	TCCR0_REG |= TIMER0_OC0_MODE;
#endif

	/*
												#if(TIMER0_PRESCALER == TIMER0_OC0_MODE_DISSCONECTED)
														CLR_BIT(TCCR0_REG,WGM00_BIT);
														CLR_BIT(TCCR0_REG,WGM01_BIT);
												#elif(TIMER0_PRESCALER == TIMER0_OC0_MODE_TOGGLE)
														SET_BIT(TCCR0_REG,WGM00_BIT);
														CLR_BIT(TCCR0_REG,WGM01_BIT);
												#elif(TIMER0_PRESCALER == TIMER0_OC0_MODE_CLEAR)
														CLR_BIT(TCCR0_REG,WGM00_BIT);
														SET_BIT(TCCR0_REG,WGM01_BIT);
												#elif(TIMER0_PRESCALER == TIMER0_OC0_MODE_SET)
														SET_BIT(TCCR0_REG,WGM00_BIT);
														SET_BIT(TCCR0_REG,WGM01_BIT);
													#else
														#error("WRONG TIMER MODE")
													#endif*/

}
void M_TIMER0_void_Start(void)
{
#if(TIMER0_PRESCALER >= TIMER0_PRESCALER_NO_CLOCK && TIMER0_PRESCALER <= TIMER0_PRESCALER_EXTCLK_RAISING_EDGE)
	//step 1 : apply mask
	TCCR0_REG &= TIMER0_PRESCALER_MASK;
	//step 2 : insert value
	TCCR0_REG  |= TIMER0_PRESCALER;

#endif
}
void M_TIMER0_void_EnableInt(u8 copy_u8IntID)
{
	//METHOD 1 --> SWIITCH
	/*
	switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID :
		SET_BIT(TIMSK_REG , TOIE0_BIT);
		break;
	case TIMER0_CMP_INT_ID:
		SET_BIT(TIMSK_REG , OCIE0_BIT);
		break;
	}
	 */

	//METHOD 2 --> SET PIN DIRECT
	SET_BIT(TIMSK_REG, copy_u8IntID);


}
void M_TIMER0_void_DidableInt(u8 copy_u8IntID)
{
	/*
	//METHOD 1
	switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID :
		CLR_BIT(TIMSK_REG , TOIE0_BIT);
		break;
	case TIMER0_CMP_INT_ID:
		CLR_BIT(TIMSK_REG , OCIE0_BIT);
		break;
	}
	 */

	//METHOD 2 --> CLR PIN DIRECT
	CLR_BIT(TIMSK_REG, copy_u8IntID);

}

void M_TIMER0_void_Stop(void)
{
	//step 1 : apply mask
	TCCR0_REG &= TIMER0_PRESCALER_NO_CLOCK;
	//step 2: insert value
	//TCCR0_REG = TIMER0_PRESCALER;

}
void M_TIMER0_void_setCallBack(void (*ptrfn)(void), u8 copy_u8IntID){			//to call file mcal and we cant call two file in same layer
	//method 1
	switch(copy_u8IntID)
	{
	case TIMER0_OVF_INT_ID:
		Arr_callBack[0]=ptrfn;
		break;
	case TIMER0_CMP_INT_ID:
		Arr_callBack[1]=ptrfn;
		break;
		//method 2  access with array
		Arr_callBack[copy_u8IntID]=ptrfn;

	}
}
ISR(TIMER0_OVF_vect)
{
	static  u32 Loc_OVFCounter =0;
	Loc_OVFCounter++;
	if(Loc_OVFCounter ==NumberOFOverflows)
	{
		if(Arr_callBack[TIMER0_OVF_INT_ID] != NULL)
		{
			Arr_callBack[TIMER0_OVF_INT_ID]();
		}
	}
}
ISR(TIMER0_COMP_vect)
{
	if(Arr_callBack[TIMER0_CMP_INT_ID]!=NULL)
	{
		Arr_callBack[TIMER0_CMP_INT_ID]();
	}


}
void M_TIMER0_void_setphaseCorrectPWM(u8 copy_u8Duty)
{
#if(TIMER0_MODE == TIMER0_PHASECORRECT_MODE)
  #if(TIMER0_OC0_MODE == TIMER0_PWM_NON_INVERTED)
	OCR0_REG = abs(((copy_u8Duty*255)/100));
  #elif (TIMER0_OC0_MODE == TIMER0_PWM_INVERTED)
	OCR0_REG= 255 -((copy_u8Duty*255)/100);

  #endif
#endif

}

void M_TIMER0_void_setFastPWM(u8 copy_u8Duty)
{
#if(TIMER0_MODE == TIMER0_FAST_PWM_MODE)
  #if(TIMER0_OC0_MODE == TIMER0_PWM_NON_INVERTED)
	OCR0_REG = abs(((copy_u8Duty*256)/100)-1);
  #elif (TIMER0_OC0_MODE == TIMER0_PWM_INVERTED)
	OCR0_REG= 255 -((copy_u8Duty*256)/100);
     #else
        #error ("wrong OC0 MODE")
#endif
#endif
}

