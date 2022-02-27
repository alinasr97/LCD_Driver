/*
 * DIO_Register.h
 *
 * Created: 23-Feb-22 6:33:52 PM
 *  Author: lenovo
 */ 


#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_


#define PINA_Register    (*((volatile unsigned char*)0x39))
#define DDRA_Register    (*((volatile unsigned char*)0x3A))
#define PORTA_Register   (*((volatile unsigned char*)0x3B))

#define PINB_Register    (*((volatile unsigned char*)0x36))
#define DDRB_Register    (*((volatile unsigned char*)0x37))
#define PORTB_Register   (*((volatile unsigned char*)0x38))

#define PINC_Register    (*((volatile unsigned char*)0x33))
#define DDRC_Register    (*((volatile unsigned char*)0x34))
#define PORTC_Register   (*((volatile unsigned char*)0x35))

#define PIND_Register    (*((volatile unsigned char*)0x30))
#define DDRD_Register    (*((volatile unsigned char*)0x31))
#define PORTD_Register   (*((volatile unsigned char*)0x32))


#endif /* DIO_REGISTER_H_ */