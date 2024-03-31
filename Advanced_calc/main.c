#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/PORT/PORT.h"
#include "MCAL/PORT/PORT_cnf.h"
#include "MCAL/TIMERS/TIMER1/includes/TMR1_interface.h"

#include <avr/delay.h>
#include "HAL/LCD/LCD.h"
#include "HAL/KEYPAD/KP_interface.h"


// Function prototypes
float calculate(char *expression);
int isDigit(char c);
int isOperator(char c);
float applyOperation(float a, float b, char op);


int main()
{
    // MCU pins configurations
    Port_Init(pin_cfg);
    LCD_Init();
    KP_Init();

    while (1)
    {
        LCD_CLR();
        char expression[50];
//        LCD_GoTo(2, 1);
//        LCD_PutString("Enter expression:");

        // Get the expression from the user
        u8 idx = 0;
        while (1)
        {
            u8 key;
            KP_GetKey(&key);
            if (key == '=')
            {
                expression[idx] = '\0';
                break;
            }
            else if (key != 'T')
            {
                expression[idx++] = key;
                LCD_PutChar(key);
            }
        }

        // Calculate the result
        float result = calculate(expression);

        // Display the result
        LCD_CLR();
        LCD_PutString("Result:");
    //    LCD_GoTo(1, 0);
        LCD_PutFloat(result);

        _delay_ms(2000);
    }

    return 0;
}

// Function to evaluate the expression and return the result
float calculate(char *expression)
{
    float result = 0;
    float operand1 = 0;
    float operand2 = 0;
    char current_operator = '+';

    for (int i = 0; expression[i] != '\0'; ++i)
    {
        char current_char = expression[i];

        if (isDigit(current_char))
        {
            // Build the operand
            operand2 = operand2 * 10 + (current_char - '0');
        }
        else if (isOperator(current_char))
        {
            // Apply the previous operation and store the result
            result = applyOperation(result, operand2, current_operator);

            // Reset the operand for the next number
            operand2 = 0;

            // Update the current operator
            current_operator = current_char;
        }
    }

    // Apply the final operation and return the result
    return applyOperation(result, operand2, current_operator);
}

// Function to check if a character is a digit
int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

// Function to check if a character is an operator (+, -, *, /)
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to apply the operation
float applyOperation(float a, float b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            // Handle division by zero
            LCD_CLR();
            LCD_PutString("Error: Division by zero");
            _delay_ms(2000);
            return 0;
        }
        else
            return a / b;
    default:
        return 0;
    }
}
