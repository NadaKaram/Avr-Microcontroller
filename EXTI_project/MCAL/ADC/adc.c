/*
 * adc.c
 *
 *  Created on: Feb 13, 2023
 *      Author: lenovo
 */

#include <avr/io.h>
#include "adc.h"


void ADC_select(unsigned char channel)
{
	// select Rf = Avcc and select ADC0 channel
	ADMUX |=(1<<REFS0) | channel;
	//enable ADC
	ADCSRA |=(1<<ADSC);
	ADCSRA |=(1<<ADEN) |(1<<ADPS2) |(1<<ADPS1) |(1<<ADPS0);
}
unsigned short ADC_Read(void)
{
	unsigned int adcValue =0,low,high;
	//start conversion
	ADCSRA |=(1<<ADSC);
	while(ADCSRA &(1<<ADSC));
	//read value
	low=(int)ADCL;
	high=(int)(ADCH*256);
	adcValue = low + high;
	return adcValue;
}


