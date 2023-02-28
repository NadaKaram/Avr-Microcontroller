/*
 * adc.h
 *
 *  Created on: Feb 13, 2023
 *      Author: lenovo
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_
#include "std_types2.h"
#define ADC_0  0
#define ADC_0  1
#define ADC_0  2
#define ADC_0  3
#define ADC_0  4
#define ADC_0  5
#define ADC_0  6
#define ADC_0  7
void ADC_select(unsigned char channel);
unsigned short ADC_Read(void);

#endif /* ADC_ADC_H_ */
