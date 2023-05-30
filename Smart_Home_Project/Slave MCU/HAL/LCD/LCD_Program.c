#include <util/delay.h>
/*Include Header files from LIB Layer*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*Include my own header files*/
#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"

/******************************************************************/
/*Func. Name: LCD_voidInit                                        */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: initialises the LCD module                         */
/******************************************************************/
void LCD_voidInit(void)
{	
	/*Configurations of LCD control pins in the MCU as O/P*/
	DIO_voidSetPortDirection(DATA_REG, OUTPUT);
	DIO_voidSetPinDirection(CTRL_REG, RS_PIN, OUTPUT);
	DIO_voidSetPinDirection(CTRL_REG, RW_PIN, OUTPUT);
	DIO_voidSetPinDirection(CTRL_REG, EN_PIN, OUTPUT);

	_delay_ms(50);

	/*Send function set instruction to the LCD*/
	LCD_voidSendInstruction(FUNC_SET);
	_delay_ms(2);

	LCD_voidSendInstruction(DISPLAY_ON);
	_delay_ms(2);

	LCD_voidSendInstruction(CLEAR_DISPLAY);
	_delay_ms(2);

	LCD_voidSendInstruction(ENTRY_MODE);
	_delay_ms(2);

}

/******************************************************************/
/*Func. Name: LCD_voidSendInstruction                             */
/*i/p arguments: Copy_u8Instruction: 1-Byte instruction           */
/*return: void                                                    */
/*Description: sends instruction to the LCD controller            */
/******************************************************************/
void LCD_voidSendInstruction(u8 Copy_u8Instruction)
{
	/*Set pin RW to LOW to write on LCD*/
	DIO_voidSetPinValue(CTRL_REG, RW_PIN, LOW);

	/*Set pin RS to LOW to send an instruction*/
	DIO_voidSetPinValue(CTRL_REG, RS_PIN, LOW);

	/*Send instruction to LCD through data port*/
	DIO_voidSetPortValue(DATA_REG,Copy_u8Instruction);

	/*apply a falling edge on enable pin*/
	DIO_voidSetPinValue(CTRL_REG,EN_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_REG,EN_PIN,LOW);
}

/******************************************************************/
/*Func. Name: LCD_voidSendChar                                    */
/*i/p arguments: Copy_u8Char: 1-Byte character                    */
/*return: void                                                    */
/*Description: sends a character to the LCD display               */
/******************************************************************/
void LCD_voidSendChar(u8 Copy_u8Char)
{
	/*Set pin RW to LOW to write on LCD*/
	DIO_voidSetPinValue(CTRL_REG, RW_PIN, LOW);

	/*Set pin RS to HIGH to send data*/
	DIO_voidSetPinValue(CTRL_REG, RS_PIN, HIGH);

	/*Send data to LCD through data port*/
	DIO_voidSetPortValue(DATA_REG, Copy_u8Char);

	/*apply a falling edge on enable pin*/
	DIO_voidSetPinValue(CTRL_REG, EN_PIN, HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CTRL_REG, EN_PIN, LOW);
}

/******************************************************************/
/*Func. Name: LCD_voidSendString                                  */
/*i/p arguments: *p_u8Char: pointer to char - array of characters */
/*return: void                                                    */
/*Description: sends a string of characters to the LCD display    */
/******************************************************************/
void LCD_voidSendString(u8 *p_u8Char)
{
	while(*p_u8Char)
	{
		LCD_voidSendChar(*p_u8Char);
		p_u8Char++;
	}
}

/******************************************************************/
/*Func. Name: LCD_voidSendNumber                                  */
/*i/p arguments: Copy_u32: unsigned number                        */
/*return: void                                                    */
/*Description: sends a number to the LCD display                  */
/******************************************************************/
void LCD_voidSendNumber(u32 Copy_u32Number)
{
	u8 Local_Au8Arr[10],
	   Local_u8Iter1,
	   Local_u8Iter2,
	   Local_u8Digit;

	if((Copy_u32Number/10))
	{

	Local_u8Iter1 = 0;
	while(Copy_u32Number)
	{
		Local_Au8Arr[Local_u8Iter1] = Copy_u32Number % 10;
		Copy_u32Number /= 10;
		Local_u8Iter1++;
	}
	Local_u8Iter1--;

	for( Local_u8Iter2 = 0; Local_u8Iter2 <= Local_u8Iter1; Local_u8Iter2++ )
	{
		Local_u8Digit = Local_Au8Arr[Local_u8Iter1 - Local_u8Iter2] + '0';

		LCD_voidSendChar(Local_u8Digit);
	}

	}
	else
		LCD_voidSendChar(Copy_u32Number + '0');

}

/******************************************************************/
/*Func. Name: LCD_voidGoToXY                                      */
/*i/p arguments: Copy_u8Line: Line1, Line2                        */
/*               Copy_u8Position: unsigned char                   */
/*return: void                                                    */
/*Description: sends a number to the LCD display                  */
/******************************************************************/
void LCD_voidGoToXY(u8 Copy_u8Line, u8 Copy_u8Position)
{
	switch(Copy_u8Line)
	{
		case LINE1:	LCD_voidSendInstruction(0x80 + Copy_u8Position);
					break;
		case LINE2:	LCD_voidSendInstruction(0xC0 + Copy_u8Position);
					break;
		default:	
					break;
	}
}

/******************************************************************/
/*Func. Name: LCD_voidClearDisplay                                */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: clears the LCD display                             */
/******************************************************************/
void LCD_voidClearDisplay(void)
{
	LCD_voidSendInstruction(CLEAR_DISPLAY);
}
