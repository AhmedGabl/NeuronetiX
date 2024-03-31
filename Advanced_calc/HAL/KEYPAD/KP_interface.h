/*
 * KP_interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: AhmedAbogabl
 */

#ifndef HAL_KEYPAD_KP_INTERFACE_H_
#define HAL_KEYPAD_KP_INTERFACE_H_


#include "../../utils/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"

#define KP_NOKEY 'T'


/*
#define R1	PC_5
#define R2	PC_4
#define R3	PC_3
#define R4	PC_2

#define C1	PD_7
#define C2	PD_6
#define C3	PD_5
#define C4	PD_3
*/


//KP column pins
#define col1  PD_7
#define col2  PD_6
#define col3  PD_4
#define col4  PD_3
//KP raw pins
#define row1 PC_5
#define row2 PC_4
#define row3 PC_3
#define row4 PC_2


//rows and colums count
#define keypad_rows 4
#define keypad_coul 4
//function prototypes

void KP_Init(void);
void KP_GetKey(u8*  value);
//u8 KP_GetKey(void);
//void KP_GetKey(u8* Key_value);

#endif /* HAL_KEYPAD_KP_INTERFACE_H_ */
