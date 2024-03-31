/*
 * TMR1_private.h
 *
 *  Created on: Oct 29, 2023
 *  Author: AhmedAbogabl
 */

#ifndef TMR1_PRIVATE_H
#define TMR1_PRIVATE_H

// Timer/Counter 1 modes
#define TMR1_CTC_MODE_4            1
#define TMR1_NORMAL_MODE_0         2
#define TMR1_FAST_PWM_MODE_14      3
//3
//#define TMR1_PWM_PHASE_CORRECT   4
//#define TMR1_FAST_PWM_MODE_14    5

// Types of generated PWM
#define TMR1_INVERTING           1
#define TMR1_NONINVERTING        2

// TIMER1 prescaler Configurations
#define TMR1_PRESCALER_1         1
#define TMR1_PRESCALER_8         2
#define TMR1_PRESCALER_64        3
#define TMR1_PRESCALER_256       4
#define TMR1_PRESCALER_1024      5

#endif /* TMR1_PRIVATE_H */
