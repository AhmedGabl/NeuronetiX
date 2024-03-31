/*
 * TMR1_interface.h
 *
 * Created on: Oct 29, 2023
 * Author: AhmedAbogabl
 */
#ifndef TMR1_INTERFACE_H
#define TMR1_INTERFACE_H

#include "TMR1_private.h"
#include "TMR1_register.h"
#include "TMR1_config.h"
#include "../../../../utils/BIT_MATH.h"
#include "../../../../utils/STD_TYPES.h"


void TMR1_voidSetFrequencyMode14FastPWM(u16 copy_u16FrequencyValueA);


void TMR1_voidSetDutyCycleMode14FastPWM(F32 copy_f32DutyCycle);

/**
 * @brief Initialize Timer/Counter 1 with the selected configuration.
 */
void TMR1_voidInit(void);

/**
 * @brief Start Timer/Counter 1.
 */
void TMR1_voidStart(void);

/**
 * @brief Stop Timer/Counter 1.
 */
void TMR1_voidStop(void);


/**
 * @brief Set the Compare Match value for Timer/Counter 1.
 *
 * @param copy_u8CompareMatchValue The Compare Match value to be set.
 */
void TMR1_voidSetCompareMatchValueA(u16 copy_u8CompareMatchValueA);



/**
 * @brief Set a callback function to be called on Timer/Counter 1 overflow (OVF).
 *
 * @param ptrToFunc Pointer to the overflow callback function.
 */
void TMR1_voidSetCallBackOVF(void (*ptrToFunc)(void));

/**
 * @brief Set a callback function to be called on Timer/Counter 1 Compare Match (CTC).
 *
 * @param ptrToFunc Pointer to the Compare Match callback function.
 */
void TMR1_voidSetCallBackCTC(void (*ptrToFunc)(void));

/**
 * @brief Set a delay in milliseconds using Timer/Counter 1 in CTC mode.
 *
 * @param copy_u16Delay_ms The desired delay in milliseconds.
 */
void TMR1_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms);

/**
 * @brief Set the duty cycle for PWM mode.
 *
 * @param copy_u8DutyCycle The duty cycle value (0-100) for PWM mode.
 */
void TMR1_voidSetDutyCycleForPWM(u8 copy_u8DutyCycle);

#endif /* TMR1_INTERFACE_H */
