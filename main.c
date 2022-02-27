/*
 * Drivers.c
 *
 * Created: 23-Feb-22 6:27:18 PM
 * Author : lenovo
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "UTILS.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
 

int main(void)
{
	DIO_SetPortDirection(PORT_A,OUTPUT);
	DIO_SetPortDirection(PORT_B,OUTPUT);
	LCD_Init();
	
	LCD_WriteString("atmega 32");
	_delay_ms(500);
	LCD_GoTo(2,1);
	LCD_WriteString("Hello ");
	_delay_ms(500);
	LCD_Clear();
	LCD_GoTo(1,1);
	LCD_WriteString("LCD_Driver");
	_delay_ms(500);
	LCD_Clear();
	LCD_WriteChar('Z');
	_delay_ms(500);
	LCD_GoTo(1,5);
	LCD_WriteNumber(19480);
	_delay_ms(500);
	LCD_Clear();
	LCD_GoTo(1,1);
	LCD_WriteString("five in binary =");
	_delay_ms(500);
	LCD_GoTo(2,1);
	LCD_WriteNumberInBinary(5);
	
    while (1) 
    {
		
		
	}
}

