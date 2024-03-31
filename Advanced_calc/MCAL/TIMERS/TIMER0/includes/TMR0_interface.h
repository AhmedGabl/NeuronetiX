/*
 * TMR0_interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: AhmedAbogabl
 */
#ifndef TMR0_INTERFACE_H
#define TMR0_INTERFACE_H

#include "TMR0_private.h"
#include "TMR0_register.h"
#include "TMR0_config.h"
#include "../../../../utils/BIT_MATH.h"
#include "../../../../utils/STD_TYPES.h"

/**
 * @brief Initialize Timer/Counter 0 with the selected configuration.
 */
void TMR0_voidInit(void);

/**
 * @brief Start Timer/Counter 0.
 */
void TMR0_voidStart(void);

/**
 * @brief Stop Timer/Counter 0.
 */
void TMR0_voidStop(void);

/**
 * @brief Set a callback function to be called on Timer/Counter 0 overflow (OVF).
 *
 * @param ptrToFunc Pointer to the overflow callback function.
 */
void TMR0_voidSetCallBackOVF(void (*ptrToFunc)(void));

/**
 * @brief Set a callback function to be called on Timer/Counter 0 Compare Match (CTC).
 *
 * @param ptrToFunc Pointer to the Compare Match callback function.
 */
void TMR0_voidSetCallBackCTC(void (*ptrToFunc)(void));

/**
 * @brief Set the Compare Match value for Timer/Counter 0.
 *
 * @param copy_u8CompareMatchValue The Compare Match value to be set.
 */
void TMR0_voidSetCompareMatchValue(u8 copy_u8CompareMatchValue);

/**
 * @brief Set a delay in milliseconds using Timer/Counter 0 in CTC mode.
 *
 * @param copy_u16Delay_ms The desired delay in milliseconds.
 */
void TMR0_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms);

/**
 * @brief Set the duty cycle for PWM mode.
 *
 * @param copy_u8DutyCycle The duty cycle value (0-100) for PWM mode.
 */
void TMR0_voidSetDutyCycleForPWM(u8 copy_u8DutyCycle);

#endif /* TMR0_INTERFACE_H */
