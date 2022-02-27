/*
 * DIO_Interface.h
 *
 * Created: 23-Feb-22 6:34:57 PM
 *  Author: lenovo
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "UTILS.h"
#include "DIO_Register.h"

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define INPUT 0x00
#define OUTPUT 0xFF

#define HIGH 0xFF
#define LOW 0x00

void DIO_SetPinValue (u8 Port,u8 Pin,u8 PinVal);

u8 DIO_GetPinValue (u8 Port,u8 Pin);

void DIO_SetPinDirection (u8 Port,u8 Pin,u8 PinDir);

void DIO_SetPortDirection (u8 Port, u8 PortDir);

void DIO_SetPortValue (u8 Port,u8 PortVal);

u8 DIO_GetPortValue (u8 port);

#endif /* DIO_INTERFACE_H_ */