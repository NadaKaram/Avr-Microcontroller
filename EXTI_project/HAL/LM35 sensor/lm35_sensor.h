/*
 * lm35_sensor.h
 *
 *  Created on: Feb 13, 2023
 *      Author: lenovo
 */

#ifndef LM35_SENSOR_LM35_SENSOR_H_
#define LM35_SENSOR_LM35_SENSOR_H_

#include "adc.h"
#include"std_types2.h"
#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

u8 LM35_getTemperature(void);
#endif /* LM35_SENSOR_LM35_SENSOR_H_ */
