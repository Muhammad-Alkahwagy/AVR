/*File Gaurd*/
#ifndef GIE_INTERFACE_H
#define GIE_INTERFACE_H


/******************************************************************/
/*Func. Name: GIE_void_Enable                                     */
/*i/p arguments: void                                             */
/*Description: Enables Interrupts                                 */
/*             sets the I_bit (Global interrupt enable) in SREG   */
/*return: void                                                    */
/******************************************************************/
void GIE_void_Enable(void);


/******************************************************************/
/*Func. Name: GIE_void_Disable                                    */
/*i/p arguments: void                                             */
/*Description: disables Interrupts                                */
/*             clears the I_bit (Global interrupt enable) in SREG */
/*return: void                                                    */
/******************************************************************/
void GIE_void_Disable(void);


#endif