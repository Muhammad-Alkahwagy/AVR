/*File Gaurd*/
#ifndef TMR1_INTERFACE_H
#define TMR1_INTERFACE_H


/*******************************************************************/
/*Func. Name: TMR1_voidInit                                        */
/*i/p arguments: void                                              */
/*Description: initializes TMR1 with prebuild configuration        */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidInit(void); 


/*******************************************************************/
/*Func. Name: TMR1_voidSetCompareMatchValueToOCR1A                 */
/*i/p arguments: Copy_u16CompareMatchValue: u16 value              */
/*Description: writes compare match value into register OCR1A      */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetCompareMatchValueToOCR1A( u16 Copy_u16CompareMatchValue);


/*******************************************************************/
/*Func. Name: TMR1_voidSetCompareMatchValueToOCR1B                 */
/*i/p arguments: Copy_u16CompareMatchValue: u16 value              */
/*Description: writes compare match value into register OCR1B      */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetCompareMatchValueToOCR1B( u16 Copy_u16CompareMatchValue);


/*******************************************************************/
/*Func. Name: TMR1_voidSetTopValueToICR1                           */
/*i/p arguments: Copy_u16TopValue: u16                             */
/*Description: defines timer1 top value to ICR1 register           */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetTopValueToICR1( u16 Copy_u16TopValue);



/*******************************************************************/
/*Func. Name: TMR1_voidSetCallBackOF                               */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls TMR1 Overflow Interrupt Service Routine       */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetCallBackOF( void (*LpF)(void));

/*******************************************************************/
/*Func. Name: TMR1_voidSetPreloadValue                             */
/*i/p arguments: Copy_u16PreloadValue: u16                         */
/*Description: assigns preload value to TMR1 register TCNT1        */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetPreloadValue( u16 Copy_u16PreloadValue);


/*******************************************************************/
/*Func. Name: TMR1_voidSetCallBackOCM                              */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls TMR1 Compare match Interrupt Service Routine  */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetCallBackOCM( void (*LpF)(void));


#endif