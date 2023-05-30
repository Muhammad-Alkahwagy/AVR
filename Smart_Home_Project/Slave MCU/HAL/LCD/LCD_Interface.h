#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H


#define LINE1	0
#define LINE2	1

/******************************************************************/
/*Func. Name: LCD_voidInit                                        */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: initialises the LCD module                         */
/******************************************************************/
void LCD_voidInit(void);

/******************************************************************/
/*Func. Name: LCD_voidSendInstruction                             */
/*i/p arguments: Copy_u8Instruction: 1-Byte instruction           */
/*return: void                                                    */
/*Description: sends instruction to the LCD controller            */
/******************************************************************/
void LCD_voidSendInstruction(u8 Copy_u8Instruction);

/******************************************************************/
/*Func. Name: LCD_voidSendChar                                    */
/*i/p arguments: Copy_u8Char: 1-Byte character                    */
/*return: void                                                    */
/*Description: sends a character to the LCD display               */
/******************************************************************/
void LCD_voidSendChar(u8 Copy_u8Char);

/******************************************************************/
/*Func. Name: LCD_voidSendString                                  */
/*i/p arguments: *p_u8Char: pointer to char - array of characters */
/*return: void                                                    */
/*Description: sends a string of characters to the LCD display    */
/******************************************************************/
void LCD_voidSendString(u8 *p_u8Char);

/******************************************************************/
/*Func. Name: LCD_voidSendNumber                                  */
/*i/p arguments: Copy_u32: unsigned number                        */
/*return: void                                                    */
/*Description: sends a number to the LCD display                  */
/******************************************************************/
void LCD_voidSendNumber(u32 Copy_u32Number);

/******************************************************************/
/*Func. Name: LCD_voidGoToXY                                      */
/*i/p arguments: Copy_u8Line: Line1, Line2                        */
/*               Copy_u8Position: unsigned char                   */
/*return: void                                                    */
/*Description: moves the cursor to a specific position on the LCD */
/******************************************************************/
void LCD_voidGoToXY(u8 Copy_u8Line, u8 Copy_u8Position);


/******************************************************************/
/*Func. Name: LCD_voidClearDisplay                                */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: clears the LCD display                             */
/******************************************************************/
void LCD_voidClearDisplay(void);


#endif
