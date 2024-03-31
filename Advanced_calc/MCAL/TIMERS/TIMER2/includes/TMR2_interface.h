/*
 * TMR2_interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: AhmedAbogabl
 */
#ifndef TMR2_INTERFACE_H
#define TMR2_INTERFACE_H

#include "../../../../utils/BIT_MATH.h"
#include "../../../../utils/STD_TYPES.h"
#include "TMR2_config.h"
#include "TMR2_private.h"
#include "TMR2_register.h"

/**
 * @brief Initialize Timer/Counter 0 with the selected configuration.
 */
void TMR2_voidInit(void);

/**
 * @brief Start Timer/Counter 0.
 */
void TMR2_voidStart(void);

/**
 * @brief Stop Timer/Counter 0.
 */
void TMR2_voidStop(void);

/**
 * @brief Set a callback function to be called on Timer/Counter 0 overflow (OVF).
 *
 * @param ptrToFunc Pointer to the overflow callback function.
 */
void TMR2_voidSetCallBackOVF(void (*ptrToFunc)(void));

/**
 * @brief Set a callback function to be called on Timer/Counter 0 Compare Match (CTC).
 *
 * @param ptrToFunc Pointer to the Compare Match callback function.
 */
void TMR2_voidSetCallBackCTC(void (*ptrToFunc)(void));

/**
 * @brief Set the Compare Match value for Timer/Counter 0.
 *
 * @param copy_u8CompareMatchValue The Compare Match value to be set.
 */
void TMR2_voidSetCompareMatchValue(u8 copy_u8CompareMatchValue);

/**
 * @brief Set a delay in milliseconds using Timer/Counter 0 in CTC mode.
 *
 * @param copy_u16Delay_ms The desired delay in milliseconds.
 */
void TMR2_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms);

/**
 * @brief Set the duty cycle for PWM mode.
 *
 * @param copy_u8DutyCycle The duty cycle value (0-100) for PWM mode.
 */
void TMR2_voidSetDutyCycleForPWM(u8 copy_u8DutyCycle);

#endif /* TMR2_INTERFACE_H */
