#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define BAUD_RATE   9600UL
#define FOSC        8000000UL  //Hz

//operating mode options:
/*
UBRR_VAL_AS_N     //Asynchronous Normal Mode
UBRR_VAL_AS_DS    //Asynchronous Double Speed Mode
UBRR_VAL_S_M      //Synchronous Master Mode
*/
#define UBRR_VAL    UBRR_VAL_AS_N

#endif

