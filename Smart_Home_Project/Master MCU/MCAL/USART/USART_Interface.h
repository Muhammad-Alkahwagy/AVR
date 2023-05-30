#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/*******************************************************************/
/*Func. Name: USART_voidInit                                       */
/*i/p arguments: void                                              */
/*Description: initializes USART peripheral                        */
/*return: void                                                     */
/*******************************************************************/
void USART_voidInit(void);

/*******************************************************************/
/*Func. Name: USART_voidTransmit                                   */
/*i/p arguments: Copy_u8Data: unsigned char data to be transmitted */
/*Description: transmits data via Tx pin                           */
/*return: void                                                     */
/*******************************************************************/
void USART_voidTransmit(u8 Copy_u8Data);


/*******************************************************************/
/*Func. Name: USART_voidReceive                                    */
/*i/p arguments: pu8_Data: pointer to u8 data to be received       */
/*Description: receives data via Rx pin                            */
/*return: void                                                     */
/*******************************************************************/
void USART_voidReceive(u8* pu8_Data);


#endif