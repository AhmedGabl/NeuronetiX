/*
 * DIO_register.h
 *
 *  Created on: Oct 25, 2023
 *      Author: AhmedAbogabl
 */

#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

#define PORTA (*((volatile unsigned char *)0x3B))
#define PORTB (*((volatile unsigned char *)0x38))
#define PORTC (*((volatile unsigned char *)0x35))
#define PORTD (*((volatile unsigned char *)0x32))

#define DDRA (*((volatile unsigned char *)0x3A))
#define DDRB (*((volatile unsigned char *)0x37))
#define DDRC (*((volatile unsigned char *)0x34))
#define DDRD (*((volatile unsigned char *)0x31))

#define PINA (*((volatile unsigned char *)0x39))
#define PINB (*((volatile unsigned char *)0x36))
#define PINC (*((volatile unsigned char *)0x33))
#define PIND (*((volatile unsigned char *)0x30))


#endif /* MCAL_DIO_DIO_REGISTER_H_ */
