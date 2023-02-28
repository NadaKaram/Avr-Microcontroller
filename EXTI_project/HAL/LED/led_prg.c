/*
 * led_prg.c
 *
 *  Created on: Jan 31, 2023
 *      Author: lenovo
 */


#include "led_priv.h"
#include  "led_config.h"
#include "led_int.h"
#include "Dio_int.h"
#include "../../LIB/std_types2.h"
void H_Led_void_ledINit(u8 LedID)
{
	switch(LedID)
	{
	case Red_Led:
		M_Dio_void_setPinDir(LED_RED_PORT,LED_RED_PIN,1);
		break;
	case Grn_Led:
		M_Dio_void_setPinDir(LED_GREEN_PORT,LED_GREEN_PIN,1);
		break;
	case Blu_Led:
		M_Dio_void_setPinDir(LED_BLU_PORT,LED_BLU_PIN,1);
		break;

	}
}
void H_Led_void_setON(u8 LedID)
{
	switch(LedID)
	{
	case Red_Led:
#if(LED_RED_DIRECTION == LED_FORWARD)
	{
		M_Dio_void_setPinValue(LED_RED_PORT,LED_RED_PIN,1);
	}
#elif (LED_RED_DIRECTION == LED_REVERSE)
	{
		M_Dio_void_setPinValue(LED_RED_PORT,LED_RED_PIN,0);
	}
#endif
	break;
	case Grn_Led:
#if(LED_GREEN_DIRECTION == LED_FORWARD)
		M_Dio_void_setPinValue(LED_GREEN_PORT,LED_GREEN_PIN,1);
#elif (LED_GREEN_DIRECTION == LED_REVERSE)
		{
			M_Dio_void_setPinValue(LED_GREEN_PORT,LED_GREEN_PIN,0);
		}
#endif
		break;
	case Blu_Led:
#if(LED_BLU_DIRECTION == LED_FORWARD)
	{
		M_Dio_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,1);
	}
#elif (LED_BLU_DIRECTION == LED_REVERSE)
	{
		M_Dio_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,0);
	}
#endif
	break;


}
}
void H_Led_void_setOFF(u8 LedID)
{
	switch(LedID)
	{
	case Red_Led:
#if(LED_RED_DIRECTION == LED_FORWARD)
	{
		M_Dio_void_setPinValue(LED_RED_PORT,LED_RED_PIN,0);
	}
#elif (LED_RED_DIRECTION == LED_REVERSE)
	{
		M_Dio_void_setPinValue(LED_RED_PORT,LED_RED_PIN,1);
	}
#endif
	break;
	case Grn_Led:
#if(LED_RED_DIRECTION == LED_FORWARD)
	{
		M_Dio_void_setPinValue(LED_GREEN_PORT,LED_GREEN_PIN,0);
	}
#elif (LED_RED_DIRECTION == LED_REVERSE)
	{
		M_Dio_void_setPinValue(LED_GREEN_PORT,LED_GREEN_PIN,1);
	}
#endif
	break;
	case Blu_Led:
#if(LED_RED_DIRECTION == LED_FORWARD)
	{
		M_Dio_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,0);
	}
#elif (LED_RED_DIRECTION == LED_REVERSE)
	{
		M_Dio_void_setPinValue(LED_BLU_PORT,LED_BLU_PIN,1);
	}
#endif
	break;

}
}
void H_Led_void_toggle(u8 LedID)
{
	switch(LedID)
	{
	case Red_Led:
		Dio_tog(LED_RED_PORT,LED_RED_PIN);
		break;
	case Grn_Led:
		Dio_tog(LED_GREEN_PORT,LED_GREEN_PIN);
		break;
	case Blu_Led:
		Dio_tog(LED_BLU_PORT,LED_BLU_PIN);
		break;

	}
}
