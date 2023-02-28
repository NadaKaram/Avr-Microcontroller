/*
 * buzzer.h
 *
 *  Created on: Feb 4, 2023
 *      Author: lenovo
 */

#ifndef BUZZER_BUZZER_H_
#define BUZZER_BUZZER_H_
#include"../../LIB/std_types2.h"
#define BUZZER_PORT PORTC_ID
#define BUZZER_PIN  PIN5_ID
void H_Buzzer_void_INIT(void);
void H_Buzzer_void_ON(void);
void H_Buzzer_void_OFF(void);

#endif /* BUZZER_BUZZER_H_ */
