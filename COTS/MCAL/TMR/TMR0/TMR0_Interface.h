/*File Gaurd*/
#ifndef TMR0_INTERFACE_H
#define TMR0_INTERFACE_H


/*******************************************************************/
/*Func. Name: TMR0_voidInit                                         */
/*i/p arguments: void                                              */
/*Description: initializes TMR0 with prebuild configuration         */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidInit(void); 
 
 
/*******************************************************************/
/*Func. Name: TMR0_voidSetCallBackOF                               */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls TMR0 Overflow Interrupt Service Routine       */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetCallBackOF( void (*LpF)(void));

/*******************************************************************/
/*Func. Name: TMR0_voidSetPreloadValue                             */
/*i/p arguments: Copy_u8PreloadValue: u8                           */
/*Description: assigns preload value to TMR0 register TCNT0        */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetPreloadValue( u8 Copy_u8PreloadValue);


/*******************************************************************/
/*Func. Name: TMR0_voidSetCallBackOCM                              */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls TMR0 Compare match Interrupt Service Routine  */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetCallBackOCM( void (*LpF)(void));

/*******************************************************************/
/*Func. Name: TMR0_voidSetCompareMatchValue                        */
/*i/p arguments: Copy_u8CompareMatchValue: unsigned char (0:255)   */
/*Description: assigns compare match value to register OCR0        */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetCompareMatchValue( u8 Copy_u8CompareMatchValue);


/*******************************************************************/
/*Func. Name: TMR0_voidSetBusyWaitms                               */
/*i/p arguments: Copy_u16WaitValue: wait value in milliseconds     */
/*Description: this function halts the processor for a set time    */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetBusyWaitms(u16 Copy_u16WaitValue);


#endif