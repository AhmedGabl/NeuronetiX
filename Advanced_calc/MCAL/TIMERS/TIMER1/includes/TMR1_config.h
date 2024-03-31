/*
 * TMR1_config.h
 *
 * Created on: Oct 29, 2023
 * Author: AhmedAbogabl
 */

#ifndef TMR1_CONFIG_H
#define TMR1_CONFIG_H

/*
 * Timer/Counter 1 operating mode.
 * Options:
 *   - TMR1_CTC_MODE_4: Clear Timer on Compare (CTC) mode
 *   - TMR1_NORMAL_MODE_0: Normal mode
 *   - TMR1_FAST_PWM_MODE: Fast PWM mode
 *   - TMR1_PWM_PHASE_CORRECT: Phase Correct PWM mode
 *   -
 */
#define TMR1_MODE TMR1_FAST_PWM_MODE_14

/*
 * Timer/Counter 1 PWM mode.
 * Options:
 *   - TMR1_INVERTING: Inverting PWM
 *   - TMR1_NONINVERTING: Non-inverting PWM
 */
#define TMR1_PWM_MODE TMR1_NONINVERTING

/*
 * Timer/Counter 1 prescaler.
 * Options:
 *   - TMR1_PRESCALER_1: No prescaling
 *   - TMR1_PRESCALER_8: 8-bit prescaler
 *   - TMR1_PRESCALER_64: 64-bit prescaler
 *   - TMR1_PRESCALER_256: 256-bit prescaler
 *   - TMR1_PRESCALER_1024: 1024-bit prescaler
 */
#define TMR1_PRESCALER TMR1_PRESCALER_64

/*
 * Preload value for Timer/Counter 1 in normal mode (overflow mode).
 */
#define TMR1_PRELOAD_VALUE 65535

/*
 * Number of overflows needed to achieve the desired delay in overflow mode.
 */
#define TMR1_ovCount 0  // Modify according to your requirement

// If you need CTC mode, you can uncomment and configure the following:
// #define TMR1_ctcCount 250

#endif /* TMR1_CONFIG_H */
