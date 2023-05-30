/*File Gaurd*/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/* External Interrupt options */
#define INT0    0
#define INT1    1
#define INT2    2

/*Sense Control*/
#define LOW_LEVEL       0
#define ON_CHANGE       1
#define FALLING_EDGE    2
#define RISING_EDGE     3


/*******************************************************************/
/*Func. Name: EXTI_voidInit                                        */
/*i/p arguments: void                                              */
/*Description: initializes external interrupt with prebuild config.*/
/*return: void                                                     */
/*******************************************************************/
void EXTI_voidInit(void); 
 
 
/*******************************************************************/
/*Func. Name: EXTI_voidEnable                                      */
/*i/p arguments: Copy_u8IntID: INT0, INT1, INT2                    */
/*Copy_u8Trigger: LOW_LEVEL, ON_CHANGE, FALLING_EDGE, RISING_EDGE  */
/*Description: enables interrupt(postbuild) and sets trigger mode  */
/*return: void                                                     */
/*******************************************************************/
void EXTI_voidEnable(u8 Copy_u8IntID, u8 Copy_u8Trigger); 
 
 
/*******************************************************************/
/*Func. Name: EXTI_voidDisable                                     */
/*i/p arguments: Copy_u8IntID: INT0, INT1, INT2                    */
/*Description: disables chosen interrupt                           */
/*return: void                                                     */
/*******************************************************************/
void EXTI_voidDisable(u8 Copy_u8IntID);


/*******************************************************************/
/*Func. Name: EXTI_voidSetCallBack                                 */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls Interrupt Service Routine                     */
/*return: void                                                     */
/*******************************************************************/
void EXTI_voidSetCallBack(void (*LpF)(void));


#endif