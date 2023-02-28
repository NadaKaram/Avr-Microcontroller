/*
 * dio_prg.c
 *
 *  Created on: Jan 30, 2023
 *      Author: lenovo
 */
#include"../../LIB/std_types2.h"
#include "../../LIB/BIT_MATH.h"
#include "Dio_priv.h"
#include "Dio_int.h"
void M_Dio_void_setPinDir(u8 PortNumber,u8 PinNumber,u8 Direction)
{
	if(Direction == LOW)
		{
			switch(PortNumber)
			{
			case PORTA_ID:
				DDRA &=~(1<<PinNumber);
				break;
			case PORTB_ID:
				DDRB &=~(1<<PinNumber);
				break;
			case PORTC_ID:
				DDRC &=~(1<<PinNumber);
				break;
			case PORTD_ID:
				DDRD &=~(1<<PinNumber);
				break;
			}
		}
		else if(Direction == HIGH)
		{
			switch(PortNumber)
			{
			case PORTA_ID:
				DDRA |=(1<<PinNumber);
				break;
			case PORTB_ID:
				DDRB |=(1<<PinNumber);
				break;
			case PORTC_ID:
				DDRC |=(1<<PinNumber);
				break;
			case PORTD_ID:
				DDRD |=(1<<PinNumber);
				break;
			}
		}
}
void M_Dio_void_setPinValue(u8 port,u8 PinNumber,u8 value)
{
	switch(port)
		{
		case PORTA_ID:
			if(value == HIGH)
				PORTA |=(1<<PinNumber);
			else if(value == LOW)
				PORTA &=~(1<<PinNumber);
			break;
		case PORTB_ID:
			if(value == HIGH)
				PORTB |=(1<<PinNumber);
			else if(value== LOW)
				PORTB &=~(1<<PinNumber);
			break;
		case PORTC_ID:
			if(value == HIGH)
				PORTC |=(1<<PinNumber);
			else if(value== LOW)
				PORTC &=~(1<<PinNumber);
			break;
		case PORTD_ID:
			if(value == HIGH)
				PORTD |=(1<<PinNumber);
			else if(value == LOW)
				PORTD &=~(1<<PinNumber);
			break;
		}
}
void M_Dio_void_getPinValue(u8 PortNumber,u8 PinNumber,u8 *value)
{
	switch(PortNumber)
		{
		case PORTA_ID:
			*value =(PINA & (1<<PinNumber))>>PinNumber;
			break;
		case PORTB_ID:
			*value =(PINB & (1<<PinNumber))>>PinNumber;
			break;
		case PORTC_ID:
			*value =(PINC & (1<<PinNumber))>>PinNumber;
			break;
		case PORTD_ID:
			*value =(PIND & (1<<PinNumber))>>PinNumber;
			break;
		}
}
void Dio_tog(u8 port,u8 pin)
{
	switch(port)
	{
	case PORTA_ID:
		TOG_BIT(PORTA,pin);
		break;
	case PORTB_ID:
		TOG_BIT(PORTB,pin);
		break;
	case PORTC_ID:
		TOG_BIT(PORTC,pin);
		break;
	case PORTD_ID:
		TOG_BIT(PORTD,pin);
		break;

	}
}

