#ifndef BIT_MATH_H_
#define BIT_MATH_H_

// 4 NORMAL MACROS [NORMAL REPLACEMENT]
#define SET_BIT(VAR,BIT)    (VAR |=(0x01<<BIT))//BRACKETS BEC I CAN USE IT INSIDE STH. (OPERATION ARRANGEMENTS) // TEXT PLACEMENT TIS IS MICRO
#define CLR_BIT(VAR,BIT)    (VAR &= (~(0x01<<BIT)))
#define GET_BIT(VAR,BIT)    ((VAR>>BIT) & 0x01)
#define TOG_BIT(VAR,BIT)    (VAR ^=(0x01<<BIT))
/*
 * MACRO LIKE FUNCTION ?? Can't get it search
 * #define FUNC(ARG1,ARG2)  (ARG1+ARG2)
 * 0b00001111
 * SetPinVal(7,GET_BIT(0b00001111,7))
*/

#endif /* BIT_MATH_H_ */
