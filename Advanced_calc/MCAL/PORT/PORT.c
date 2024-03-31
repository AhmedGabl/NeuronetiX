/* PORT.c
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedAbogabl
 */

#include  "PORT.h"
#include "PORT_cnf.h"

/*
 * function to intialize mcu ports based on the configurations set on  -->PORT_cnf.c
 * number of configurations NUM_OF_CNF and all r inside pin_cnf[NUM_OF_CNF]
 */

void Port_Init(const Port_ConfigType *pin_cfg) {

	int i = 0;
	for (i = 0; i < 32; i++) {

		if (pin_cfg[i].port == -1)
			break;

		switch (pin_cfg[i].port) {

		case Dio_PORTA:
			if (pin_cfg[i].dir == PORT_PIN_OUT) {
				SET_BIT(DDRA, pin_cfg[i].pin);
			} else {
				CLR_BIT(DDRA, pin_cfg[i].pin);
				SET_BIT(PORTA, pin_cfg[i].pin);
			}
			break;
		case Dio_PORTB:
			if (pin_cfg[i].dir == PORT_PIN_OUT) {
				SET_BIT(DDRB, pin_cfg[i].pin);
			} else {
				CLR_BIT(DDRB, pin_cfg[i].pin);
				SET_BIT(PORTB, pin_cfg[i].pin);

			}

			break;
		case Dio_PORTC:
			if (pin_cfg[i].dir == PORT_PIN_OUT) {
				SET_BIT(DDRC, pin_cfg[i].pin);
			} else {
				CLR_BIT(DDRC, pin_cfg[i].pin);
				SET_BIT(PORTC, pin_cfg[i].pin);

			}

			break;
		case Dio_PORTD:
			if (pin_cfg[i].dir == PORT_PIN_OUT) {
				SET_BIT(DDRD, pin_cfg[i].pin);
			} else {
				CLR_BIT(DDRD, pin_cfg[i].pin);
				SET_BIT(PORTD, pin_cfg[i].pin);

			}

			break;

//
//	default:
//		break;
		}
	}
}


void Port_SetPinDirection (Dio_ChannelType Pin,Port_PinDirectionType Direction)
{
	switch(Pin/8)
	{
	case Dio_PORTA:
		if(Direction == PORT_PIN_OUT)
			SET_BIT(DDRA, Pin);
		else
			CLR_BIT(DDRA, Pin);
		break;
	case Dio_PORTB:
		if(Direction == PORT_PIN_OUT)
			SET_BIT(DDRB, Pin % 8);
		else
			CLR_BIT(DDRB, Pin % 8);
		break;
	case Dio_PORTC:
		if(Direction == PORT_PIN_OUT)
			SET_BIT(DDRC, Pin % 8);
		else
			CLR_BIT(DDRC, Pin % 8);
		break;
	case Dio_PORTD:
		if(Direction == PORT_PIN_OUT)
			SET_BIT(DDRD, Pin % 8);
		else
			CLR_BIT(DDRD, Pin % 8);
		break;
	default:	break;
	}
}
