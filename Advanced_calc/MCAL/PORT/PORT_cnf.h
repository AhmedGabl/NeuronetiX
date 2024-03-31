/*
 * PORT_cnf.h
 *
 *  Created on: Oct 20, 2023
 *      Author: AhmedAbogabl
 */

#ifndef MCAL_PORT_PORT_CNF_H_
#define MCAL_PORT_PORT_CNF_H_

#include "../DIO/DIO_interface.h"
#include <avr/io.h>

//#define CNF_TERMINATE  -1

//numerical id for port direction
typedef enum{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

//numerical id for port pins
typedef enum{
	PORT_PIN0,
	PORT_PIN1,
	PORT_PIN2,
	PORT_PIN3,
	PORT_PIN4,
	PORT_PIN5,
	PORT_PIN6,
	PORT_PIN7,
}Port_PinType;

//group the configurations for each pin in the mcu
typedef struct{
	Dio_PortType port;
	Port_PinType pin;
	Port_PinDirectionType dir;
}Port_ConfigType;

//configurations
extern Port_ConfigType pin_cfg[33];

#endif /* MCAL_PORT_PORT_CNF_H_ */
