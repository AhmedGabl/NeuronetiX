/*
 * TMR1_program.c
 *
 * Created on: Oct 29, 2023
 * Author: AhmedAbogabl
 */

#include "../includes/TMR1_interface.h"


void TMR1_voidSetFrequencyMode14FastPWM(u16 copy_u16Frequency_hz) {
//under condition tick time 4microsec  prescaler64//////////////////////////////////////////////
	#if TMR1_PRESCALER == TMR1_PRESCALER_64
	ICR1 = ((1000000UL / copy_u16Frequency_hz) / 4) - 1;
	#endif// TMR1_PRESCALER

}

void TMR1_voidSetDutyCycleMode14FastPWM(F32 copy_f32DutyCycle) {
	if (copy_f32DutyCycle <= 100) {
#if TMR1_PWM_MODE == TMR1_NONINVERTING
		if (copy_f32DutyCycle == 0) {
			OCR1A = 0;
		} else {
			OCR1A = ((copy_f32DutyCycle * (ICR1 + 1)) / 100) - 1;
		}

#elif TMR1_PWM_MODE == TMR1_INVERTING
		if(copy_f32DutyCycle == 100) {
			OCR1A = 0;
		}
		else {
			copy_f32DutyCycle = 100 - copy_u8_duty;
			OCR1A = (((float)copy_f32DutyCycle * (ICR1+1)) / 100) -1;
		}
#endif	//TMR1_FastPWM_14_MODE
	}
}


void TMR1_voidInit(void) {

#if TMR1_MODE == TMR1_FAST_PWM_MODE_14
	//select mode fast_PWM_MODE_14
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);
#if TMR1_PWM_MODE == TMR1_NONINVERTING
	CLR_BIT(TCCR1A, COM1A0);
	SET_BIT(TCCR1A, COM1A1);
#elif TMR1_PWM_MODE == TMR1_INVERTING
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#endif
	TMR1_voidSetFrequencyMode14FastPWM(50);

#endif
}

void TMR1_voidSetCompareMatchValueA(u16 copy_u8CompareMatchValueA) {
	OCR1A = copy_u8CompareMatchValueA;
}

/**
 * @brief Start Timer/Counter 1.
 */
void TMR1_voidStart(void) {
#if TMR1_PRESCALER == TMR1_PRESCALER_1
	// Select prescaler value = 1
	SET_BIT(TCCR1B, CS10);
	CLR_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);

#elif TMR1_PRESCALER == TMR1_PRESCALER_8
	// Select prescaler value = 8
	CLR_BIT(TCCR1B, CS10);
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);

#elif TMR1_PRESCALER == TMR1_PRESCALER_64
	// Select prescaler value = 64
	SET_BIT(TCCR1B, CS10);
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);

#elif TMR1_PRESCALER == TMR1_PRESCALER_256
	// Select prescaler value = 256
	CLR_BIT(TCCR1B, CS10);
	CLR_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS12);

#elif TMR1_PRESCALER == TMR1_PRESCALER_1024
	// Select prescaler value = 1024
	SET_BIT(TCCR1B, CS10);
	CLR_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS12);
#endif

}
/**
 * @brief Stop Timer/Counter 1.
 */
void TMR1_voidStop(void) {
	CLR_BIT(TCCR1B, CS10);
	CLR_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);
}

