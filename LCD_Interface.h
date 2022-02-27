/*
 * LCD_Interface.h
 *
 * Created: 27-Feb-22 2:51:35 PM
 *  Author: lenovo
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "UTILS.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"

/******************* PIN CONFIG *******************/

// LCD_PORT    PORTB
/*********PORTA*********/
// RS          PINA0
// RW          PINA1
// E           PINA2
/**************************************************/


void LCD_Init(void);
void LCD_SendCommand(u8 cmd);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8 *ptr);
void LCD_GoTo(u8 Y, u8 X);
void LCD_WriteNumber(u64 num);
void LCD_WriteNumberInBinary(u8 num);
void LCD_Clear(void);
#endif /* LCD_INTERFACE_H_ */