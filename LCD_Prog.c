/*
 * LCD_Prog.c
 *
 * Created: 27-Feb-22 2:51:51 PM
 *  Author: lenovo
 */ 

#include "LCD_Interface.h"

#define LCD_Clear_            0x01
#define LCD_Home_             0x02
#define LCD_EntryMode         0x06
#define LCD_DisplayOff        0x08
#define LCD_DisplayOn         0x0C
#define LCD_FinctionReset     0x30
#define LCD_FinctionSet8bit   0x38
#define LCD_SetCursor         0x80


void LCD_Init(void)
{
	/* delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(50);
	/* Return Home*/
	LCD_SendCommand(LCD_Home_);
	_delay_ms(15);
	/* Function Set*/
	LCD_SendCommand(LCD_FinctionSet8bit);
	_delay_ms(1);
	/* Display ON */
	LCD_SendCommand(LCD_DisplayOn);
	_delay_ms(1);
	/* Clear Display */
	LCD_SendCommand(LCD_Clear_);
	_delay_ms(15);
	/* Entry Mode Set */
	LCD_SendCommand(LCD_EntryMode);
	_delay_ms(2);
}

void LCD_SendCommand(u8 cmd)
{
	/* Set RS to LOW */
	DIO_SetPinValue(PORT_A,PIN0,LOW);
	/* Set RW to LOW */
	DIO_SetPinValue(PORT_A,PIN1,LOW);
	/* Set E to HIGH */
	DIO_SetPinValue(PORT_A,PIN2,HIGH);
	/* Load Command on data bus*/
	DIO_SetPortValue(PORT_B,cmd);
	/* Set E to LOW */
	DIO_SetPinValue(PORT_A,PIN2,LOW);
	/* wait E to settle */
	_delay_ms(5);
	/* Set E to HIGH */
	DIO_SetPinValue(PORT_A,PIN2,HIGH);
	/* delay for 10ms to let the LCD execute the command */
	_delay_ms(10);
}

void LCD_WriteChar(u8 ch)
{
	/* Set RS to High */
	DIO_SetPinValue(PORT_A,PIN0,HIGH);
	/* Set RW to LOW */
	DIO_SetPinValue(PORT_A,PIN1,LOW);
	/* Set E to HIGH */
	DIO_SetPinValue(PORT_A,PIN2,HIGH);
	/* Load Data on data bus*/
	DIO_SetPortValue(PORT_B,ch);
	/* Set E to LOW */
	DIO_SetPinValue(PORT_A,PIN2,LOW);
	/* wait E to settle */
	_delay_ms(5);
	/* Set E to HIGH */
	DIO_SetPinValue(PORT_A,PIN2,HIGH);
	/* delay for 10ms to let the LCD execute the Data */
	_delay_ms(10);
}

void LCD_WriteString(u8 *str)
{
	u8 i;
	for(i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
		_delay_ms(100);
	}
	
	
}
/* Y = Row position , X = Column position */  
void LCD_GoTo(u8 Y, u8 X)
{
	if(X>0 && X<16)
	{
		switch(Y)
		{
			case 1:
			LCD_SendCommand(X+127); break;
			case 2:
			LCD_SendCommand(X+191); break;
			default:
			break;
		}
	}
}

void LCD_WriteNumber(u64 num)
{
	u8 str[16]={0} , i=0;
	s8 j;
		if(num==0)
		{
			LCD_WriteChar('0');
		}
		else
		{
			while(num>0)
			{
				str[i]=num%10+'0';
				i++;
				num=num/10;
			}
			for(j=i-1;j>=0;j--)
			{
				LCD_WriteChar(str[j]);
				_delay_ms(100);
			}
		}
}

void LCD_WriteNumberInBinary(u8 num)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
		LCD_WriteChar(((num>>i)&1)+'0');
		_delay_ms(100);
	}
	
}

void LCD_CreateCharacter(u8 *pattern, u8 location)
{
	u8 i;
	LCD_SendCommand(0x40+(location*8));
	for(i=0;i<8;i++)
	{
		LCD_WriteChar(pattern[i]);
	}
	LCD_GoTo(1,1);
}

void LCD_Clear(void)
{
	LCD_SendCommand(LCD_Clear_);
}
