/*
 * SRVM_program.c
 *
 *  Created on: Nov 2, 2023
 *      Author: AhmedAbogabl
 */


#include "../../utils/STD_TYPES.h"
#include "../../utils/BIT_MATH.h"
#include "../../MCAL/TIMERS/TIMER1/includes/TMR1_interface.h"

static u8 flag = 0;

void SRVM_voidOn(u8 Copy_u8Angle) {
    /* TMR1 init at pwm mode 14 */
    if (flag == 0) {
        TMR1_voidInit();
        flag = 1;
        /* Set pwm fre. = 50 */
        TMR1_voidSetFrequencyMode14FastPWM(50);
    }

    /* Set pwm duty cycle between 5 : 10
    depend on desired angle[0 : 180] */
    F32 duty_cycle = (F32)(5.0 + (Copy_u8Angle * (5.0 / 180.0)));
    TMR1_voidSetDutyCycleMode14FastPWM(duty_cycle);

    /* TMR1 start */
    TMR1_voidStart();
}

void SRVM_voidOff(void) {
    /* TMR1 stop */
    TMR1_voidStop();
}
