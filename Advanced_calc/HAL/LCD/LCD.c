/*
 * LCD.c
 *
 *  Created on: Oct 21, 2023
 *      Author: AhmedAbogabl
 */

#include "LCD.h"
#include "avr/delay.h"

static u8 current_pos = 0;


void LCD_SendData(u8 data) {
    Dio_WriteChannel(RS, STD_HIGH);

    // Send data through D4-D7 pins
    Dio_WriteChannel(D4, GET_BIT(data, 4));
    Dio_WriteChannel(D5, GET_BIT(data, 5));
    Dio_WriteChannel(D6, GET_BIT(data, 6));
    Dio_WriteChannel(D7, GET_BIT(data, 7));

    Dio_WriteChannel(EN, STD_HIGH);
    _delay_ms(1);
    Dio_WriteChannel(EN, STD_LOW);
    _delay_ms(1);

    // Send the lower 4 bits
    Dio_WriteChannel(D4, GET_BIT(data, 0));
    Dio_WriteChannel(D5, GET_BIT(data, 1));
    Dio_WriteChannel(D6, GET_BIT(data, 2));
    Dio_WriteChannel(D7, GET_BIT(data, 3));

    Dio_WriteChannel(EN, STD_HIGH);
    _delay_ms(1);
    Dio_WriteChannel(EN, STD_LOW);
    _delay_ms(1);
}

void LCD_SendCMD(u8 command) {
    Dio_WriteChannel(RS, STD_LOW);

    // Send command through D4-D7 pins
    Dio_WriteChannel(D4, GET_BIT(command, 4));
    Dio_WriteChannel(D5, GET_BIT(command, 5));
    Dio_WriteChannel(D6, GET_BIT(command, 6));
    Dio_WriteChannel(D7, GET_BIT(command, 7));

    Dio_WriteChannel(EN, STD_HIGH);
    _delay_ms(1);
    Dio_WriteChannel(EN, STD_LOW);
    _delay_ms(1);

    // Send the lower 4 bits of the command
    Dio_WriteChannel(D4, GET_BIT(command, 0));
    Dio_WriteChannel(D5, GET_BIT(command, 1));
    Dio_WriteChannel(D6, GET_BIT(command, 2));
    Dio_WriteChannel(D7, GET_BIT(command, 3));

    Dio_WriteChannel(EN, STD_HIGH);
    _delay_ms(1);
    Dio_WriteChannel(EN, STD_LOW);
    _delay_ms(1);
}

// Initializes the LCD module by setting various display and cursor settings
void LCD_Init(void) {
    _delay_ms(50);  // Wait for the LCD to power up

    // Setting the display mode and cursor settings
    LCD_SendCMD(LCD_CURSOR_HOME);
    LCD_SendCMD(LCD_FUNCTION_SET_4_BIT_2_LINE_8_DOTS);
    _delay_ms(1);

    LCD_SendCMD(LCD_DISPLAY_ON_UNDER_LINE_CURSOR_ON_BLOCK_CURSOR_ON);
    _delay_ms(1);

    LCD_SendCMD(LCD_CLEAR_COMMAND);
    _delay_ms(2);

    LCD_SendCMD(LCD_ENTRY_MODE_INC_SHIFT_OFF);
    _delay_ms(1);

    LCD_SendCMD(LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_OFF);

//    LCD_SendCMD(LCD_DDRAM_START);  // Set the cursor to the start of the Display Data RAM (DDRAM)
}

// Clears the LCD display
void LCD_CLR(void) {
    LCD_SendCMD(0x01);
    current_pos = 0;
}

// Displays a character on the LCD
void LCD_PutChar(const u8 character) {
    LCD_SendData(character);
    current_pos++;
}

// Displays a text string on the LCD
void LCD_PutString(const u8 *str) {
    while (*str) {
        LCD_PutChar(*str);
        str++;
    }
}

// Displays a character at a specific position on the LCD
void LCD_PutChar_at_X_Y(u8 data, u8 row, u8 col) {
    LCD_GoTo(row, col);
    LCD_SendData(data);
}

// Displays a string at a specific position on the LCD
void LCD_PutString_at_X_Y(u8 *data, u8 row, u8 col) {
    LCD_GoTo(row, col);
    LCD_PutString(data);
}

// Displays an integer value on the LCD
void LCD_PutInt(u32 Number) {
	if(Number == 0 )
	return ;
	else
	LCD_PutInt(Number/10);
	LCD_PutChar((Number%10)+0x30);
}

// Displays a custom character at a specific row and column on the LCD
void LCD_PutCustomChar(u8 row, u8 col, u8 *CustomCharacter, u8 MemPos) {
    LCD_SendCMD(LCD_CGRAM_START + (MemPos * 8));
    for (int i = 0; i < 8; i++) {
        LCD_SendData(CustomCharacter[i]);
    }
    LCD_PutChar_at_X_Y(MemPos, row, col);
}

// Moves the cursor to a specified row and column on the LCD
void LCD_GoTo(u8 row, u8 col) {
    col--;
    switch (row) {
        case ROW1:
            LCD_SendCMD(0x80 + col);
            break;
        case ROW2://C0
            LCD_SendCMD(0xC0 + col);
            break;
        case ROW3:
            LCD_SendCMD(0x94 + col);
            break;
        case ROW4://D4
            LCD_SendCMD(0xD4 + col);
            break;
        default:
            break;
    }
}




// Function to display a float value on the LCD
void LCD_PutFloat(float number) {
    // Display the integer part
    int integerPart = (int)number;
    LCD_PutInt(integerPart);

    // Display the decimal point
    LCD_PutChar('.');

    // Display the fractional part (up to 2 decimal places)
    float fractionalPart = number - integerPart;
    fractionalPart *= 100; // Multiply by 100 to get two decimal places
    int decimalPart = (int)fractionalPart;
    LCD_PutInt(decimalPart);
    if(decimalPart==0)LCD_PutChar('0');

}
