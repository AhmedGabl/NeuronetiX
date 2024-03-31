/*
 * KP_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: AhmedAbogabl
 */
#include "KP_interface.h"
#include "avr/delay.h"

/*Keypad buttons Key_values */
static const u8 Keys[keypad_rows][keypad_coul]={  {'7','8','9','/'},
														{'4','5','6','*'},
														{'1','2','3','-'},
														{'#','0','=','+'}};
u8 rows[keypad_rows] = {row1, row2,row3,row4};
u8 columns[keypad_coul] = {col1, col2, col3, col4};

void KP_Init(void)
{
	Dio_WriteChannel(col1, STD_HIGH);
	Dio_WriteChannel(col2, STD_HIGH);
	Dio_WriteChannel(col3, STD_HIGH);
	Dio_WriteChannel(col4, STD_HIGH);

}



void KP_GetKey(u8* value) {

	u8 rows[keypad_rows] = {row1, row2,row3,row4};
	u8 columns[keypad_coul] = {col1, col2, col3, col4};

	// Loop through rows and columns to scan for a pressed key
	volatile u8 r, c;

    for (c = 0; c < keypad_coul; c++) {
        Dio_WriteChannel(columns[c], STD_LOW);

        for (r = 0; r < keypad_rows; r++) {
            if (Dio_ReadChannel(rows[r]) == STD_LOW) {
                // Debounce the keypress
     //           _delay_ms(10);
                if (Dio_ReadChannel(rows[r]) == STD_LOW) {
                    *value = Keys[r][c];
                    while (Dio_ReadChannel(rows[r]) == STD_LOW); // Wait for key release
                 //   Dio_WriteChannel(columns[c], STD_HIGH); // Reset the column
                    return;
                }
            }
        }

        Dio_WriteChannel(columns[c], STD_HIGH); // Reset the column
    }

    *value = 'T'; // No key pressed
}



