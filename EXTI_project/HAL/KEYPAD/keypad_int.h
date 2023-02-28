/*
 * keypad_int.h
 *
 *  Created on: Feb 2, 2023
 *      Author: lenovo
 */

#ifndef KEYPAD_KEYPAD_INT_H_
#define KEYPAD_KEYPAD_INT_H_
#define ACTIVE_LOW_PRESSED  0
#define NOT_PRESSED_KEY 0xFF

void H_KEYPAD_void_init(void);
u8 H_KEYPAD_void_getPressedKey(void);
#endif /* KEYPAD_KEYPAD_INT_H_ */
