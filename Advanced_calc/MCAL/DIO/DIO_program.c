/*
 * DIO.c
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedAbogabl
 */

#include "DIO_interface.h"

/*
 function to write an output chaneel */

void Dio_WriteChannel(unsigned char ChannelId, unsigned char Level) {

//	unsigned char port = ;
	switch (ChannelId / 8) {
	case Dio_PORTA:
		if (Level == STD_HIGH) {
			SET_BIT(PORTA, ChannelId);
		} else {
			CLR_BIT(PORTA, ChannelId);
		}
		break;
	case Dio_PORTB:
		if (Level == STD_HIGH) {
			SET_BIT(PORTB, ChannelId % 8);
		} else {
			CLR_BIT(PORTB, ChannelId % 8);
		}
		break;
	case Dio_PORTC:
		if (Level == STD_HIGH) {
			SET_BIT(PORTC, ChannelId % 8);
		} else {
			CLR_BIT(PORTC, ChannelId % 8);
		}
		break;
	case Dio_PORTD:
		if (Level == STD_HIGH) {
			SET_BIT(PORTD, ChannelId % 8);
		} else {
			CLR_BIT(PORTD, ChannelId % 8);
		}
		break;
	}
}

/*
 function to read from an  input channel
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) {
	unsigned char port = ChannelId / 8;
	Dio_LevelType level;

	switch (port) {
	case Dio_PORTA:
		level = GET_BIT(PINA, ChannelId);
		break;
	case Dio_PORTB:
		level = GET_BIT(PINB, ChannelId % 8);
		break;
	case Dio_PORTC:
		level = GET_BIT(PINC, ChannelId % 8);
		break;
	case Dio_PORTD:
		level = GET_BIT(PIND, ChannelId % 8);
		break;
	default:
		break;
	}

	return level;
}
/*
 * function to toggle the state of a certain channel n get its value after toggeling
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId) {

	Dio_LevelType level;
	switch (ChannelId / 8) {
	case Dio_PORTA:
		TOG_BIT(PORTA, ChannelId);
		level = GET_BIT(PORTA, ChannelId);
		break;
	case Dio_PORTB:
		TOG_BIT(PORTB, ChannelId % 8);
		level = GET_BIT(PORTB, ChannelId % 8);
		break;
	case Dio_PORTC:
		TOG_BIT(PORTC, ChannelId % 8);
		level = GET_BIT(PORTC, ChannelId % 8);
		break;
	case Dio_PORTD:
		TOG_BIT(PORTD, ChannelId % 8);
		level = GET_BIT(PORTD, ChannelId % 8);
		break;
	default:
		break;
	}

	return level;
}
/*
 * function to wright full port
 */
void Dio_WritePort(Dio_PortType Portx,u8 data){

	switch(Portx){
		case Dio_PORTA:
			PORTA = data;
		break;
		case Dio_PORTB:
			PORTB = data;
		break;
		case Dio_PORTC:
			PORTC = data;
		break;
		case Dio_PORTD:
			PORTD = data;
		break;
	}
}
