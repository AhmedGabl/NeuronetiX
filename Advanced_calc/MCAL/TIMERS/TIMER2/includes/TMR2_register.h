/*
 * TMR0_register.h
 *
 *  Created on: Oct 23, 2023
 *      Author: AhmedAbogabl
 */

#ifndef TMR0_REGISTER_H
#define TMR0_REGISTER_H

#include "../../../../utils/STD_TYPES.h"

/* TIMER0 REGISTERS */

// Timer/Counter Control Register
#define TCCR2   (*(volatile u8*)0x45)
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7

// Timer/Counter Register
#define TCNT2   (*(volatile u8*)0x44)

// Output Compare Register
#define OCR2    (*(volatile u8*)0x43)

// Timer/Counter Interrupt Mask Register
#define TIMSK   (*(volatile u8*)0x59)
#define TOIE2   6
#define OCIE2   7

// Timer/Counter Interrupt Flag Register
#define TIFR    (*(volatile u8*)0x58)
#define TOV2    6
#define OCF2    7

#endif /* TMR0_REGISTER_H */
