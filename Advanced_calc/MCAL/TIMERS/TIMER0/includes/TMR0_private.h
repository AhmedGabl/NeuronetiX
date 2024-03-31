/*
 * TMR0_private.h
 *
 *  Created on: Oct 23, 2023
 *      Author: AhmedAbogabl
 */

#ifndef TMR0_PRIVATE_H
#define TMR0_PRIVATE_H

// Timer/Counter 0 modes
#define TMR0_CTC_MODE            1
#define TMR0_NORMAL_MODE         2
#define TMR0_FAST_PWM_MODE       3
#define TMR0_PWM_PHASE_CORRECT   4

// Types of generated PWM
#define TMR0_INVERTING           1
#define TMR0_NONINVERTING        2

// Allowed prescaler values
#define TMR0_PRESCALER_1         1
#define TMR0_PRESCALER_8         2
#define TMR0_PRESCALER_64        3
#define TMR0_PRESCALER_256       4
#define TMR0_PRESCALER_1024      5

#endif /* TMR0_PRIVATE_H */
