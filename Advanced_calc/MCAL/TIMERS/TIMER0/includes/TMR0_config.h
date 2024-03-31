/*
 * TMR0_config.h
 *
 *  Created on: Oct 23, 2023
 *      Author: AhmedAbogabl
 */

#ifndef TMR0_CONFIG_H
#define TMR0_CONFIG_H

/*
 * Timer/Counter 0 operating mode.
 * Options:
 *   - TMR0_CTC_MODE: Clear Timer on Compare (CTC) mode
 *   - TMR0_NORMAL_MODE: Normal mode
 *   - TMR0_FAST_PWM_MODE: Fast PWM mode
 *   - TMR0_PWM_PHASE_CORRECT: Phase Correct PWM mode
 */
#define TMR0_MODE TMR0_PWM_PHASE_CORRECT

/*
 * Timer/Counter 0 PWM mode.
 * Options:
 *   - TMR0_INVERTING: Inverting PWM
 *   - TMR0_NONINVERTING: Non-inverting PWM
 */
#define TMR0_PWM_MODE TMR0_NONINVERTING

/*
 * Timer/Counter 0 prescaler.
 * Options:
 *   - TMR0_PRESCALER_1: No prescaling
 *   - TMR0_PRESCALER_8: 8-bit prescaler
 *   - TMR0_PRESCALER_64: 64-bit prescaler
 *   - TMR0_PRESCALER_256: 256-bit prescaler
 *   - TMR0_PRESCALER_1024: 1024-bit prescaler
 */
#define TMR0_PRESCALER TMR0_PRESCALER_64

/*
 * Preload value for Timer/Counter 0 in normal mode (overflow mode).
 */
#define TMR0_PRELOAD_VALUE 113

/*
 * Number of overflows needed to achieve the desired delay in overflow mode.
 */
#define TMR0_ovCount 977

// If you need CTC mode, you can uncomment and configure the following:
// #define TMR0_ctcCount 250

#endif /* TMR0_CONFIG_H */
