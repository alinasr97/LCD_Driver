/*
 * DIO_Prog.c
 *
 * Created: 23-Feb-22 6:51:12 PM
 *  Author: lenovo
 */ 
#include "DIO_Interface.h"

void DIO_SetPinValue (u8 Port,u8 Pin,u8 PinVal)
{
	if((Port <= PORT_D)&&(Pin <= PIN7))
	{
		if(PinVal == HIGH)
		{
			switch(Port)
			{
				case PORT_A:
				SET_BIT(PORTA_Register,Pin); break;
				case PORT_B:
				SET_BIT(PORTB_Register,Pin); break;
				case PORT_C:
				SET_BIT(PORTC_Register,Pin); break;
				case PORT_D:
				SET_BIT(PORTD_Register,Pin); break;
			}
		}
		else if(PinVal ==LOW)
		{
			switch(Port)
			{
				case PORT_A:
				CLR_BIT(PORTA_Register,Pin); break;
				case PORT_B:
				CLR_BIT(PORTB_Register,Pin); break;
				case PORT_C:
				CLR_BIT(PORTC_Register,Pin); break;
				case PORT_D:
				CLR_BIT(PORTD_Register,Pin); break;
			}
		}
		else
		{
			/* Do nothing, Wrong value to set*/
		}
	}
	else
	{
			/* Do nothing, Wrong PORT ID or PIN ID*/
	}
}

u8 DIO_GetPinValue (u8 Port,u8 Pin)
{
	u8 Result;
	if((Port <= PORT_D)&&(Pin <= PIN7))
	{
		switch(Port)
		{
			case PORT_A: 
			Result =GET_BIT(PINA_Register,Pin); break;
			case PORT_B:
			Result =GET_BIT(PINB_Register,Pin); break;
			case PORT_C:
			Result =GET_BIT(PINC_Register,Pin); break;
			case PORT_D:
			Result =GET_BIT(PIND_Register,Pin); break;
		}
	}
	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		Result =0xFF;
	}
	return Result;
}

void DIO_SetPinDirection (u8 Port,u8 Pin,u8 PinDir)
{
	if((Port <= PORT_D)&&(Pin <= PIN7))
	{
		if(PinDir == OUTPUT)
		{
			switch(Port)
			{
				case PORT_A:
				SET_BIT(DDRA_Register,Pin); break;
				case PORT_B:
				SET_BIT(DDRB_Register,Pin); break;
				case PORT_C:
				SET_BIT(DDRC_Register,Pin); break;
				case PORT_D:
				SET_BIT(DDRD_Register,Pin); break;
			}
		}
		else if(PinDir == INPUT)
		{
			switch(Port)
			{
				case PORT_A:
				CLR_BIT(DDRA_Register,Pin); break;
				case PORT_B:
				CLR_BIT(DDRB_Register,Pin); break;
				case PORT_C:
				CLR_BIT(DDRC_Register,Pin); break;
				case PORT_D:
				CLR_BIT(DDRD_Register,Pin); break;
			}
		}
		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}
	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}

void DIO_SetPortDirection (u8 Port, u8 PortDir)
{
	switch(Port)
	{
		case PORT_A:
		DDRA_Register=PortDir; break;
		case PORT_B:
		DDRB_Register=PortDir; break;
		case PORT_C:
		DDRC_Register=PortDir; break;
		case PORT_D:
		DDRD_Register=PortDir; break;
		default: /* Wrong Port ID */ break;
	}
}

void DIO_SetPortValue (u8 Port,u8 PortVal)
{
	switch(Port)
	{
		case PORT_A:
		PORTA_Register=PortVal; break;
		case PORT_B:
		PORTB_Register=PortVal; break;
		case PORT_C:
		PORTC_Register=PortVal; break;
		case PORT_D:
		PORTD_Register=PortVal; break;
		default: /* Wrong Port ID */ break;
	}
}

u8 DIO_GetPortValue (u8 port)
{
	u8 value;
	switch(port)
	{
		case PORT_A:
		value = GET_BIT(PINA_Register,port); break;
		case PORT_B:
		value = GET_BIT(PINB_Register,port); break;
		case PORT_C:
		value = GET_BIT(PINC_Register,port); break;
		case PORT_D:
		value = GET_BIT(PIND_Register,port); break;
	}
	return value;
}



