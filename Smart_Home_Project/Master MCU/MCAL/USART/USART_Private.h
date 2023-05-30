#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/*USART Registers*/
#define USART_UDR_REG        *((volatile u8*)0x2C)   //USART I/O Data Register
#define USART_UCSRA_REG      *((volatile u8*)0x2B)   //USART Control and Status Register A
#define USART_UCSRB_REG      *((volatile u8*)0x2A)   //USART Control and Status Register B
#define USART_UCSRC_REG      *((volatile u8*)0x40)   //USART Control and Status Register C
#define USART_UBRRH_REG      *((volatile u8*)0x40)   //USART Baud Rate Register (High Byte)
#define USART_UBRRL_REG      *((volatile u8*)0x29)   //USART Baud Rate Register (Low Byte)

/*USART_UCSRA_REG bits*/
#define UCSRA_RXC     7     //USART Receive Complete
#define UCSRA_TXC     6     //USART Transmit Complete
#define UCSRA_UDRE    5     //USART Data Register Empty
#define UCSRA_FE      4     //Frame Error
#define UCSRA_DOR     3     //Data OverRun
#define UCSRA_PE      2     //Parity Error
#define UCSRA_U2X     1     //Double the USART Transmission Speed
#define UCSRA_MPCM    0     //Multi-processor Communication Mode

/*USART_UCSRB_REG bits*/
#define UCSRB_RXCIE   7     //RX Complete Interrupt Enable
#define UCSRB_TXCIE   6     //TX Complete Interrupt Enable
#define UCSRB_UDRIE   5     //USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN    4     //Receiver Enable
#define UCSRB_TXEN    3     //Transmitter Enable
#define UCSRB_UCSZ2   2     //Character Size
#define UCSRB_RXB8    1     //Receive Data Bit 8
#define UCSRB_TXB8    0     //Transmit Data Bit 8

/*USART_UCSRC_REG bits*/
#define UCSRC_URSEL   7     //Register Select
#define UCSRC_UMSE1   6     //USART Mode Select
#define UCSRC_UPM1    5     //Parity Mode bit1
#define UCSRC_UPM0    4     //Parity Mode bit0
#define UCSRC_USBS    3     //Stop Bit Select
#define UCSRC_UCSZ1   2     //Character Size bit1
#define UCSRC_UCSZ0   1     //Character Size bit0
#define UCSRC_UCPOL   0     //Clock Polarity

#define UBRRH_URSEL   7     //Register select (UBRRH or UCSRC)


#define UBRR_VAL_AS_N     ( ( FOSC /( 16 * BAUD_RATE) ) - 1 )  //Asynchronous Normal Mode
#define UBRR_VAL_AS_DS    ( ( FOSC /( 8  * BAUD_RATE) ) - 1 )  //Asynchronous Double Speed Mode
#define UBRR_VAL_S_M      ( ( FOSC /( 2  * BAUD_RATE) ) - 1 )  //Synchronous Master Mode

#endif
