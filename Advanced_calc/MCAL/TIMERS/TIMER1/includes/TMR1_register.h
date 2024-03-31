/*
 * TMR1_register.h
 *
 *  Created on: Oct 29, 2023
 *      Author: AhmedAbogabl
 */

#ifndef TMR1_REGISTER_H
#define TMR1_REGISTER_H

#include "../../../../utils/STD_TYPES.h"

/* TIMER1 REGISTERS */

// Timer/Counter Control Register A
#define TCCR1A      (*(volatile u8*)0x4F)
#define WGM10       0
#define WGM11       1
#define FOC1B       2
#define FOC1A       3
#define COM1B1      5
#define COM1B0      4
#define COM1A1      7
#define COM1A0      6

// Timer/Counter Control Register B
#define TCCR1B      (*(volatile u8*)0x4E)
#define CS10        0
#define CS11        1
#define CS12        2
#define WGM12       3
#define WGM13       4
#define ICES1       6
#define ICNC1       7

// Timer/Counter Register (16-bit)
#define TCNT1       (*(volatile u16*)0x4C)

// Output Compare Register A
#define OCR1A       (*(volatile u16*)0x4A)

// Output Compare Register B
#define OCR1B       (*(volatile u16*)0x48)

// Input Capture Register
#define ICR1        (*(volatile u16*)0x46)

// Timer/Counter Interrupt Mask Register
#define TIMSK       (*(volatile u8*)0x59)
#define TOIE1       2
#define OCIE1B      3
#define OCIE1A      4
#define TICIE1      5

// Timer/Counter Interrupt Flag Register
#define TIFR        (*(volatile u8*)0x58)
#define TOV1        2
#define OCF1B       3
#define OCF1A       4
#define ICF1        5

#endif /* TMR1_REGISTER_H */
