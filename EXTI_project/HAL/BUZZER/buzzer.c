/*
 * buzzer.c
 *
 *  Created on: Feb 4, 2023
 *      Author: lenovo
 */

#include "buzzer.h"
void H_Buzzer_void_INIT(void)
{
	M_Dio_void_setPinDir(BUZZER_PORT,BUZZER_PIN,1);

}
void H_Buzzer_void_ON(void)
{
	 M_Dio_void_setPinValue(BUZZER_PORT,BUZZER_PIN,1);
}
void H_Buzzer_void_OFF(void)
{
	 M_Dio_void_setPinValue(BUZZER_PORT,BUZZER_PIN,0);

}
