/*
 * TMR0_program.c
 *
 *  Created on: Oct 23, 2023
 *      Author: AhmedAbogabl
 */

#include "../includes/TMR0_interface.h"

// Callback function pointers for timer0 overflow and CTC events
static void (*TMR0_privatePtrToCAllBackOVF)(void) = NULL;
static void (*TMR0_privatePtrToCAllBackCTC)(void) = NULL;

// Counter for tracking CTC events
volatile static u32 private_ctcCounter;

// Function to set a delay using CTC mode
void TMR0_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms) {
#if TMR0_PRESCALER == TMR0_PRESCALER_1

	// Under the condition that the tick time is 4 microseconds, set OCR0 to 249
	OCR0 = 249;
	private_ctcCounter = copy_u16Delay_ms * 64;

#elif TMR0_PRESCALER == TMR0_PRESCALER_8

	// Under the condition that the tick time is 4 microseconds, set OCR0 to 249
	OCR0 = 249;
	private_ctcCounter = copy_u16Delay_ms * 8;

#elif TMR0_PRESCALER == TMR0_PRESCALER_64

	// Under the condition that the tick time is 4 microseconds, set OCR0 to 249
	OCR0 = 249;
	private_ctcCounter = copy_u16Delay_ms;

#elif TMR0_PRESCALER == TMR0_PRESCALER_256

	// Under the condition that the tick time is 4 microseconds, set OCR0 to 249
	OCR0 = 249;
	private_ctcCounter = copy_u16Delay_ms / 4;

#elif TMR0_PRESCALER == TMR0_PRESCALER_1024

	// Under the condition that the tick time is 4 microseconds, set OCR0 to 249
	OCR0 = 249;
	private_ctcCounter = copy_u16Delay_ms / 16;

#endif
}

// Function to set the PWM duty cycle for Fast PWM and Phase Correct PWM
void TMR0_voidSetDutyCycleForPWM(u8 copy_u8DutyCycle) {
#if TMR0_MODE == TMR0_FAST_PWM_MODE

	if ((100 >= copy_u8DutyCycle)) {

#if TMR0_PWM_MODE == TMR0_NONINVERTING
		if (copy_u8DutyCycle == 0)
		OCR0 = 0;
		else
		OCR0 = (((u16) copy_u8DutyCycle * 256) / 100) - 1;

#elif TMR0_PWM_MODE == TMR0_INVERTING
		copy_u8DutyCycle = 100 - copy_u8DutyCycle;
		if (copy_u8DutyCycle == 0)
			OCR0 = 0;
		else
			OCR0 = (((u16) copy_u8DutyCycle * 256) / 100) - 1;
#endif
	}

#elif TMR0_MODE == TMR0_PWM_PHASE_CORRECT

	if ((100 >= copy_u8DutyCycle)) {

#if TMR0_PWM_MODE == TMR0_NONINVERTING
		OCR0 = (((u16) copy_u8DutyCycle * 255) / 100);
#elif TMR0_PWM_MODE == TMR0_INVERTING
		copy_u8DutyCycle = 100 - copy_u8DutyCycle;
		OCR0 = (((u16) copy_u8DutyCycle * 255) / 100);
#endif
	}

#endif
}

// Function to initialize Timer0 based on the selected mode
void TMR0_voidInit(void) {
#if TMR0_MODE == TMR0_CTC_MODE
	// Select CTC mode
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	// Enable Output Compare Match Interrupt (OCI)
	SET_BIT(TIMSK, OCIE0);

#elif TMR0_MODE == TMR0_NORMAL_MODE
	// Select normal mode
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	// Initialize timer with a preload value
	TCNT0 = TMR0_PRELOAD_VALUE;
	// Enable overflow interrupt
	SET_BIT(TIMSK, TOIE0);

#elif TMR0_MODE == TMR0_FAST_PWM_MODE
	// Select Fast PWM mode
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);

#if TMR0_PWM_MODE == TMR0_INVERTING
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);

#elif TMR0_PWM_MODE == TMR0_NONINVERTING
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
#endif

#elif TMR0_MODE == TMR0_PWM_PHASE_CORRECT
	// Select Phase Correct PWM mode
	SET_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);

#if TMR0_PWM_MODE == TMR0_INVERTING
	SET_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);

#elif TMR0_PWM_MODE == TMR0_NONINVERTING
	CLR_BIT(TCCR0, COM00);
	SET_BIT(TCCR0, COM01);
#endif

#endif
}

// Function to start Timer0 with the selected prescaler
void TMR0_voidStart(void) {
#if TMR0_PRESCALER == TMR0_PRESCALER_1
	// Select prescaler value = 1
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

#elif TMR0_PRESCALER == TMR0_PRESCALER_8
	// Select prescaler value = 8
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

#elif TMR0_PRESCALER == TMR0_PRESCALER_64
	// Select prescaler value = 64
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

#elif TMR0_PRESCALER == TMR0_PRESCALER_256
	// Select prescaler value = 256
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);

#elif TMR0_PRESCALER == TMR0_PRESCALER_1024
	// Select prescaler value = 1024
	SET_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#endif
}

// Function to stop Timer0 by turning off all prescaler bits
void TMR0_voidStop(void) {
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
}

// Function to set the callback function for timer0 overflow
void TMR0_voidSetCallBackOVF(void (*ptrToFunc)(void)) {
	if (ptrToFunc != NULL)
		TMR0_privatePtrToCAllBackOVF = ptrToFunc;
}

// Function to set the callback function for timer0 CTC
void TMR0_voidSetCallBackCTC(void (*ptrToFunc)(void)) {
	if (ptrToFunc != NULL)
		TMR0_privatePtrToCAllBackCTC = ptrToFunc;
}

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////***************ISR****************/////////////////////////////

// ISR for timer0 overflow
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	static u16 local_u16ovCounter = 0;
	local_u16ovCounter++;

	if (TMR0_ovCount == local_u16ovCounter) {
		// Reload preload value
		TCNT0 = TMR0_PRELOAD_VALUE;
		// Clear the counter
		local_u16ovCounter = 0;

		// Call the callback function if assigned
		if (TMR0_privatePtrToCAllBackOVF != NULL) {
			TMR0_privatePtrToCAllBackOVF();
		}
	}
}

// ISR for timer0 output compare match
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static u32 local_u32CTCCounter = 0;
	local_u32CTCCounter++;

	if (private_ctcCounter == local_u32CTCCounter) {
		// Clear the counter
		local_u32CTCCounter = 0;
		// Call the callback function if assigned
		if (TMR0_privatePtrToCAllBackCTC != NULL) {
			TMR0_privatePtrToCAllBackCTC();
		}
	}
}

// Function to set the output compare match value (OCR0) for CTC mode
void TMR0_voidSetCompareMatchValue(u8 copy_u8CompareValue) {
	OCR0 = copy_u8CompareValue;
}
