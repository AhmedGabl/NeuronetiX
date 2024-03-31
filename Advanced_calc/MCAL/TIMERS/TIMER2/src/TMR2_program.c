/*
 * TMR2_program.c
 *
 *  Created on: Oct 23, 2023
 *      Author: AhmedAbogabl
 */

#include "../includes/TMR2_interface.h"

// Callback function pointers for timer0 overflow and CTC events
static void (*TMR2_privatePtrToCAllBackOVF)(void) = NULL;
static void (*TMR2_privatePtrToCAllBackCTC)(void) = NULL;

// Counter for tracking CTC events
volatile static u32 private_ctcCounter;

// Function to set a delay using CTC mode
void TMR2_voidSetDelay_ms_usingCTC(u16 copy_u16Delay_ms) {
#if TMR2_PRESCALER == TMR2_PRESCALER_1

	// Under the condition that the tick time is 4 microseconds, set OCR2 to 249
	OCR2 = 249;
	private_ctcCounter = copy_u16Delay_ms * 64;

#elif TMR2_PRESCALER == TMR2_PRESCALER_8

	// Under the condition that the tick time is 4 microseconds, set OCR2 to 249
	OCR2 = 249;
	private_ctcCounter = copy_u16Delay_ms * 8;

#elif TMR2_PRESCALER == TMR2_PRESCALER_32

	// Under the condition that the tick time is 4 microseconds, set OCR2 to 249
	OCR2 = 249;
	private_ctcCounter = copy_u16Delay_ms*2;

#elif TMR2_PRESCALER == TMR2_PRESCALER_64

	// Under the condition that the tick time is 4 microseconds, set OCR2 to 249
	OCR2 = 249;
	private_ctcCounter = copy_u16Delay_ms;

#elif TMR2_PRESCALER == TMR2_PRESCALER_128

	// Under the condition that the tick time is 4 microseconds, set OCR2 to 249
	OCR2 = 249;
	private_ctcCounter = copy_u16Delay_ms/2;

#elif TMR2_PRESCALER == TMR2_PRESCALER_256

	// Under the condition that the tick time is 4 microseconds, set OCR2 to 249
	OCR2 = 249;
	private_ctcCounter = copy_u16Delay_ms / 4;

#elif TMR2_PRESCALER == TMR2_PRESCALER_1024

	// Under the condition that the tick time is 4 microseconds, set OCR2 to 249
	OCR2 = 249;
	private_ctcCounter = copy_u16Delay_ms / 16;

#endif
}

// Function to set the PWM duty cycle for Fast PWM and Phase Correct PWM
void TMR2_voidSetDutyCycleForPWM(u8 copy_u8DutyCycle) {
#if TMR2_MODE == TMR2_FAST_PWM_MODE

	if ((100 >= copy_u8DutyCycle)) {

#if TMR2_PWM_MODE == TMR2_NONINVERTING
		if (copy_u8DutyCycle == 0)
		OCR2 = 0;
		else
		OCR2 = (((u16) copy_u8DutyCycle * 256) / 100) - 1;

#elif TMR2_PWM_MODE == TMR2_INVERTING
		copy_u8DutyCycle = 100 - copy_u8DutyCycle;
		if (copy_u8DutyCycle == 0)
			OCR2 = 0;
		else
			OCR2 = (((u16) copy_u8DutyCycle * 256) / 100) - 1;
#endif
	}

#elif TMR2_MODE == TMR2_PWM_PHASE_CORRECT

	if ((100 >= copy_u8DutyCycle)) {

#if TMR2_PWM_MODE == TMR2_NONINVERTING
		OCR2 = (((u16) copy_u8DutyCycle * 255) / 100);
#elif TMR2_PWM_MODE == TMR2_INVERTING
		copy_u8DutyCycle = 100 - copy_u8DutyCycle;
		OCR2 = (((u16) copy_u8DutyCycle * 255) / 100);
#endif
	}

#endif
}

// Function to initialize Timer0 based on the selected mode
void TMR2_voidInit(void) {
#if TMR2_MODE == TMR2_CTC_MODE
	// Select CTC mode
	CLR_BIT(TCCR2, WGM20);
	SET_BIT(TCCR2, WGM21);
	// Enable Output Compare Match Interrupt (OCI)
	SET_BIT(TIMSK, OCIE2);

#elif TMR2_MODE == TMR2_NORMAL_MODE
	// Select normal mode
	CLR_BIT(TCCR2, WGM20);
	CLR_BIT(TCCR2, WGM21);
	// Initialize timer with a preload value
	TCNT2 = TMR2_PRELOAD_VALUE;
	// Enable overflow interrupt
	SET_BIT(TIMSK, TOIE2);

#elif TMR2_MODE == TMR2_FAST_PWM_MODE
	// Select Fast PWM mode
	SET_BIT(TCCR2, WGM20);
	SET_BIT(TCCR2, WGM21);

#if TMR2_PWM_MODE == TMR2_INVERTING
	SET_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);

#elif TMR2_PWM_MODE == TMR2_NONINVERTING
	CLR_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);
#endif

#elif TMR2_MODE == TMR2_PWM_PHASE_CORRECT
	// Select Phase Correct PWM mode
	SET_BIT(TCCR2, WGM20);
	CLR_BIT(TCCR2, WGM21);

#if TMR2_PWM_MODE == TMR2_INVERTING
	SET_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);

#elif TMR2_PWM_MODE == TMR2_NONINVERTING
	CLR_BIT(TCCR2, COM20);
	SET_BIT(TCCR2, COM21);
#endif

#endif
}

// Function to start Timer0 with the selected prescaler
void TMR2_voidStart(void) {
#if TMR2_PRESCALER == TMR2_PRESCALER_1
	// Select prescaler value = 1
	SET_BIT(TCCR2, CS20);
	CLR_BIT(TCCR2, CS21);
	CLR_BIT(TCCR2, CS22);

#elif TMR2_PRESCALER == TMR2_PRESCALER_8
	// Select prescaler value = 8
	CLR_BIT(TCCR2, CS20);
	SET_BIT(TCCR2, CS21);
	CLR_BIT(TCCR2, CS22);

#elif TMR2_PRESCALER == TMR2_PRESCALER_64
	// Select prescaler value = 64
	SET_BIT(TCCR2, CS20);
	SET_BIT(TCCR2, CS21);
	CLR_BIT(TCCR2, CS22);

#elif TMR2_PRESCALER == TMR2_PRESCALER_256
	// Select prescaler value = 256
	CLR_BIT(TCCR2, CS20);
	CLR_BIT(TCCR2, CS21);
	SET_BIT(TCCR2, CS22);

#elif TMR2_PRESCALER == TMR2_PRESCALER_1024
	// Select prescaler value = 1024
	SET_BIT(TCCR2, CS20);
	CLR_BIT(TCCR2, CS21);
	SET_BIT(TCCR2, CS22);
#endif
}

// Function to stop Timer0 by turning off all prescaler bits
void TMR2_voidStop(void) {
	CLR_BIT(TCCR2, CS20);
	CLR_BIT(TCCR2, CS21);
	CLR_BIT(TCCR2, CS22);
}

// Function to set the callback function for timer0 overflow
void TMR2_voidSetCallBackOVF(void (*ptrToFunc)(void)) {
	if (ptrToFunc != NULL)
		TMR2_privatePtrToCAllBackOVF = ptrToFunc;
}

// Function to set the callback function for timer0 CTC
void TMR2_voidSetCallBackCTC(void (*ptrToFunc)(void)) {
	if (ptrToFunc != NULL)
		TMR2_privatePtrToCAllBackCTC = ptrToFunc;
}

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////***************ISR****************/////////////////////////////

// ISR for timer0 overflow
void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	static u16 local_u16ovCounter = 0;
	local_u16ovCounter++;

	if (TMR2_ovCount == local_u16ovCounter) {
		// Reload preload value
		TCNT2 = TMR2_PRELOAD_VALUE;
		// Clear the counter
		local_u16ovCounter = 0;

		// Call the callback function if assigned
		if (TMR2_privatePtrToCAllBackOVF != NULL) {
			TMR2_privatePtrToCAllBackOVF();
		}
	}
}

// ISR for timer0 output compare match
void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	static u32 local_u32CTCCounter = 0;
	local_u32CTCCounter++;

	if (private_ctcCounter == local_u32CTCCounter) {
		// Clear the counter
		local_u32CTCCounter = 0;
		// Call the callback function if assigned
		if (TMR2_privatePtrToCAllBackCTC != NULL) {
			TMR2_privatePtrToCAllBackCTC();
		}
	}
}

// Function to set the output compare match value (OCR2) for CTC mode
void TMR2_voidSetCompareMatchValue(u8 copy_u8CompareValue) {
	OCR2 = copy_u8CompareValue;
}
