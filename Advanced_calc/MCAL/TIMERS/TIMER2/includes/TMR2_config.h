/*
 * TMR2_config.h
 *
 *  Created on: Oct 23, 2023
 *      Author: AhmedAbogabl
 */

#ifndef TMR2_CONFIG_H
#define TMR2_CONFIG_H

/*
 * Timer/Counter 0 operating mode.
 * Options:
 *   - TMR2_CTC_MODE: Clear Timer on Compare (CTC) mode
 *   - TMR2_NORMAL_MODE: Normal mode
 *   - TMR2_FAST_PWM_MODE: Fast PWM mode
 *   - TMR2_PWM_PHASE_CORRECT: Phase Correct PWM mode
 */
#define TMR2_MODE TMR2_FAST_PWM_MODE

/*
 * Timer/Counter 0 PWM mode.
 * Options:
 *   - TMR2_INVERTING: Inverting PWM
 *   - TMR2_NONINVERTING: Non-inverting PWM
 */
#define TMR2_PWM_MODE TMR2_INVERTING

/*
 * Timer/Counter 0 prescaler.
 * Options:
 *   - TMR2_PRESCALER_1: No prescaling
 *   - TMR2_PRESCALER_8: 8-bit prescaler
 *   - TMR2_PRESCALER_64: 64-bit prescaler
 *   - TMR2_PRESCALER_256: 256-bit prescaler
 *   - TMR2_PRESCALER_1024: 1024-bit prescaler
 */
#define TMR2_PRESCALER TMR2_PRESCALER_64

/*
 * Preload value for Timer/Counter 0 in normal mode (overflow mode).
 */
#define TMR2_PRELOAD_VALUE 113

/*
 * Number of overflows needed to achieve the desired delay in overflow mode.
 */
#define TMR2_ovCount 977

// If you need CTC mode, you can uncomment and configure the following:
// #define TMR2_ctcCount 250

#endif /* TMR2_CONFIG_H */
