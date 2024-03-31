/*
 * TMR2_private.h
 *
 *  Created on: Oct 23, 2023
 *      Author: AhmedAbogabl
 */

#ifndef TMR2_PRIVATE_H
#define TMR2_PRIVATE_H

// Timer/Counter 0 modes
#define TMR2_CTC_MODE            1
#define TMR2_NORMAL_MODE         2
#define TMR2_FAST_PWM_MODE       3
#define TMR2_PWM_PHASE_CORRECT   4

// Types of generated PWM
#define TMR2_INVERTING           1
#define TMR2_NONINVERTING        2

// Allowed prescaler values
#define TMR2_PRESCALER_1         1
#define TMR2_PRESCALER_8         2
#define TMR2_PRESCALER_32        6
#define TMR2_PRESCALER_64        7
#define TMR2_PRESCALER_128       8
#define TMR2_PRESCALER_256       4
#define TMR2_PRESCALER_1024      5

#endif /* TMR2_PRIVATE_H */
