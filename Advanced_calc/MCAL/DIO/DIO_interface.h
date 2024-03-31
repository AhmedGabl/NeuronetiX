/*
 * DIO.h
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedAbogabl
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../utils/BIT_MATH.h"
#include "../../utils/STD_TYPES.h"
#include <avr/io.h>


typedef enum{
	STD_LOW,
	STD_HIGH
}Dio_LevelType;

typedef enum{
	Dio_PORTA,
	Dio_PORTB,
	Dio_PORTC,
	Dio_PORTD
}Dio_PortType;


typedef enum{
	PA_0,
	PA_1,
	PA_2,
	PA_3,
	PA_4,
	PA_5,
	PA_6,
	PA_7,
	PB_0,
	PB_1,
	PB_2,
	PB_3,
	PB_4,
	PB_5,
	PB_6,
	PB_7,
	PC_0,
	PC_1,
	PC_2,
	PC_3,
	PC_4,
	PC_5,
	PC_6,
	PC_7,
	PD_0,
	PD_1,
	PD_2,
	PD_3,
	PD_4,
	PD_5,
	PD_6,
	PD_7
}Dio_ChannelType;



typedef struct {
	u8 offset;
	u8 mask;
	Dio_PortType port;
}Dio_ChannelGroupType;


//If the µC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType
//inherits the size of the largest port.
typedef u8 Dio_PortLevelType;



void Dio_WriteChannel(unsigned char ChannelId,unsigned char Level);

void Dio_WritePort(Dio_PortType Portx,u8 data);

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelI1d);

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

//Dio_PortLevelType Dio_ReadChannelGroup (const Dio_ChannelGroupType* ChannelGroupIdPtr);

#endif
