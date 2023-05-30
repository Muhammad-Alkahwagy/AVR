#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "USART_Private.h"
#include "USART_Config.h"
#include "USART_Interface.h"

/*******************************************************************/
/*Func. Name: USART_voidInit                                       */
/*i/p arguments: void                                              */
/*Description: initializes USART peripheral                        */
/*return: void                                                     */
/*******************************************************************/
void USART_voidInit(void)
{
	/*select UBRRH Register*/
	//CLR_BIT(USART_UBRRH_REG,UBRRH_URSEL);

    /* Set baud rate */
    USART_UBRRH_REG = (u8)(UBRR_VAL>>8);
    USART_UBRRL_REG = (u8)UBRR_VAL;

    /*Select Normal speed*/
    CLR_BIT(USART_UCSRA_REG,UCSRA_U2X);

    /*Disable Multi-Processor Communication mode*/
    CLR_BIT(USART_UCSRA_REG,UCSRA_MPCM);

    /* Enable receiver and transmitter */
    USART_UCSRB_REG = (1<<UCSRB_RXEN)|(1<<UCSRB_TXEN);

	/*select UCSRC Register*/
	//SET_BIT(USART_UCSRC_REG,UCSRC_URSEL);

    /* Set frame format: 8data, 1stop bit */
    USART_UCSRC_REG = (1<<UCSRC_URSEL)|(3<<UCSRC_UCSZ0);
}

/*******************************************************************/
/*Func. Name: USART_voidTransmit                                   */
/*i/p arguments: Copy_u8Data: unsigned char data to be transmitted */
/*Description: transmits data via Tx pin                           */
/*return: void                                                     */
/*******************************************************************/
void USART_voidTransmit(u8 Copy_u8Data)
{
    /* Wait for empty transmit buffer */
    while ( GET_BIT(USART_UCSRA_REG,UCSRA_UDRE) == 0 );

    /* Put data into buffer, sends the data */
    USART_UDR_REG = Copy_u8Data;

    /* Wait for Transmit complete */
    while ( GET_BIT(USART_UCSRA_REG,UCSRA_TXC) == 0 );

    /*Clear the Transmit complete flag*/
    SET_BIT(USART_UCSRA_REG,UCSRA_TXC);
}

/*******************************************************************/
/*Func. Name: USART_voidReceive                                    */
/*i/p arguments: pu8_Data: pointer to u8 data to be received       */
/*Description: receives data via Rx pin                            */
/*return: void                                                     */
/*******************************************************************/
void USART_voidReceive(u8* pu8_Data)
{
    /* Wait for data to be received */
    //while ( !(USART_UCSRA_REG & (1<<UCSRA_RXC)) );
    while ( GET_BIT(USART_UCSRA_REG,UCSRA_RXC) == 0 );


    /* Get received data from buffer */
    *pu8_Data = USART_UDR_REG;
}
