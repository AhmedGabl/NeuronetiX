/*
 * LCD.h
 *
 *  Created on: Oct 21, 2023
 *      Author: AhmedAbogabl
 */

#ifndef HAL_7SEGMENTS_LCD_H_
#define HAL_7SEGMENTS_LCD_H_

/* ----------------- Section : includes -----------------*/

#include "../../MCAL/PORT/PORT.h"

/* ----------------- Section : Macro Declarations -----------------*/

// LCD dimensions
#define LCD_ROW_NUMBERS			4  // Number of rows in the LCD
#define LCD_COL_NUMBERS			20 // Number of columns in the LCD

// Row numbers
#define ROW1    				((u8)1) // Row 1 on the LCD
#define ROW2    				((u8)2) // Row 2 on the LCD
#define ROW3    				((u8)3) // Row 3 on the LCD
#define ROW4    				((u8)4) // Row 4 on the LCD

// Column numbers
#define COL1	                ((u8)1)  // Column 1 on the LCD
#define COL2	                ((u8)2)  // Column 2 on the LCD
#define COL3	                ((u8)3)  // Column 3 on the LCD
#define COL4	                ((u8)4)  // Column 4 on the LCD
#define COL5	                ((u8)5)  // Column 5 on the LCD
#define COL6	                ((u8)6)  // Column 6 on the LCD
#define COL7	                ((u8)7)  // Column 7 on the LCD
#define COL8	                ((u8)8)  // Column 8 on the LCD
#define COL9	                ((u8)9)  // Column 9 on the LCD
#define COL10	                ((u8)10) // Column 10 on the LCD
#define COL11	                ((u8)11) // Column 11 on the LCD
#define COL12	                ((u8)12) // Column 12 on the LCD
#define COL13	                ((u8)13) // Column 13 on the LCD
#define COL14	                ((u8)14) // Column 14 on the LCD
#define COL15	                ((u8)15) // Column 15 on the LCD
#define COL16	                ((u8)16) // Column 16 on the LCD
#define COL17	                ((u8)17) // Column 17 on the LCD
#define COL18	                ((u8)18) // Column 18 on the LCD
#define COL19	                ((u8)19) // Column 19 on the LCD
#define COL20	                ((u8)20) // Column 20 on the LCD

// Pin mappings for data and control pins
#define D4	                    PB_0 // Data pin D4 on the LCD
#define D5	                    PB_1 // Data pin D5 on the LCD
#define D6	                    PB_2 // Data pin D6 on the LCD
#define D7	                    PB_4 // Data pin D7 on the LCD
#define RS	                    PA_3 // Register select pin on the LCD
#define EN	                    PA_2 // Enable pin on the LCD

// LCD Command Codes
#define LCD_CLEAR_COMMAND                                        	0x01 // Command to clear the LCD display
#define LCD_CURSOR_HOME                                          	0x02 // Command to set the cursor to the home position
#define LCD_ENTRY_MODE_INC_SHIFT_ON                               	0x07 // Increment cursor position, shift display (Entry mode ON)
#define LCD_ENTRY_MODE_INC_SHIFT_OFF                              	0x06 // Increment cursor position, no shift (Entry mode OFF)
#define LCD_ENTRY_MODE_DEC_SHIFT_ON                               	0x05 // Decrement cursor position, shift display (Entry mode ON)
#define LCD_ENTRY_MODE_DEC_SHIFT_OFF                              	0x04 // Decrement cursor position, no shift (Entry mode OFF)
#define LCD_DISPLAY_OFF                                           	0x08 // Turn off the display
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_OFF     	0x0C // Display ON, underline cursor OFF, block cursor OFF
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_ON_BLOCK_CURSOR_OFF      	0x0E // Display ON, underline cursor ON, block cursor OFF
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_ON_BLOCK_CURSOR_ON       	0x0F // Display ON, underline cursor ON, block cursor ON
#define LCD_DISPLAY_ON_UNDER_LINE_CURSOR_OFF_BLOCK_CURSOR_ON      	0x0D // Display ON, underline cursor OFF, block cursor ON
#define LCD_MOVE_CURSOR_LEFT                                      	0x10 // Move the cursor to the left
#define LCD_MOVE_CURSOR_RIGHT                                     	0x14 // Move the cursor to the right
#define LCD_SHIFT_DISPLAY_LEFT                                    	0x18 // Shift the display to the left
#define LCD_SHIFT_DISPLAY_RIGHT                                   	0x1C // Shift the display to the right
#define LCD_FUNCTION_SET_8_BIT_2_LINE_8_DOTS                      	0x38 // 8-bit interface, 2-line display, 5x8 dots font
#define LCD_FUNCTION_SET_4_BIT_2_LINE_8_DOTS                      	0x28 // 4-bit interface, 2-line display, 5x8 dots font
#define LCD_FUNCTION_SET_8_BIT_2_LINE_11_DOTS                     	0x3C // 8-bit interface, 2-line display, 5x11 dots font
#define LCD_FUNCTION_SET_4_BIT_2_LINE_11_DOTS                     	0x2C // 4-bit interface, 2-line display, 5x11 dots font
#define LCD_CGRAM_START                                           	0x40 // Start address for writing to CGRAM
#define LCD_DDRAM_START                                           	0x80 // Start address for writing to DDRAM

/* ----------------- Section : Function Prototypes -----------------*/

/**
 * @brief Initializes the LCD module.
 */
void LCD_Init(void);

/**
 * @brief Clears the LCD display.
 */
void LCD_CLR(void);

/**
 * @brief Displays a single character on the LCD.
 *
 * @param data The character to display.
 */
void LCD_PutChar(const u8 data);

/**
 * @brief Displays a string on the LCD.
 *
 * @param data The string to display.
 */
void LCD_PutString(const u8* data);

/**
 * @brief Displays a character at a specific position on the LCD.
 *
 * @param data The character to display.
 * @param row The row position of the character.
 * @param col The column position of the character.
 */
void LCD_PutChar_at_X_Y(u8 data, u8 row, u8 col);

/**
 * @brief Displays a string at a specific position on the LCD.
 *
 * @param data The string to display.
 * @param row The row position to start the display.
 * @param col The column position to start the display.
 */
void LCD_PutString_at_X_Y(u8* data, u8 row, u8 col);

/**
 * @brief Displays an integer on the LCD.
 *
 * @param Number The integer to display.
 */
void LCD_PutInt(u32 Number);

/**
 * @brief Displays a custom character on the LCD.
 *
 * @param row The row position of the character.
 * @param col The column position of the character.
 * @param CustomCharacter The custom character data.
 * @param MemoryPos The memory position for the custom character.
 */
void LCD_PutCustomChar(u8 row, u8 col, u8* CustomCharacter, u8 MemoryPos);

/**
 * @brief Moves the LCD cursor to a specific row and column.
 *
 * @param row The row to move the cursor to.
 * @param col The column to move the cursor to.
 */
void LCD_GoTo(u8 row, u8 col);

/**
 * @brief Displays text on the LCD in an animated manner.
 *
 * @param text The text to display in an animated way.
 */
void LCD_PutTextAnimated(const char *text);

void LCD_PutFloat(float number);


#endif /* HAL_7SEGMENTS_LCD_H_ */
