#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/*******************************************************************/
/*Func. Name: SPI_voidInit                                         */
/*i/p arguments: void                                              */
/*Description: initializes SPI peripheral                          */
/*return: void                                                     */
/*******************************************************************/
void SPI_voidInit(void);

/*******************************************************************/
/*Func. Name: SPI_voidTranseive                                    */
/*i/p arguments: Copy_u8DataTransmitted: u8 data to be transmitted */
/*             pu8_DataReceived: pointer to u8 data to be received */
/*Description: transmits and receives data through SPI peripheral  */
/*return: void                                                     */
/*******************************************************************/
void SPI_voidTranseive(u8 Copy_u8DataTransmitted , u8* pu8_DataReceived);

void SPI_MasterTransmit(u8 Copy_u8DataTransmitted);

u8 SPI_MasterReceive(void);

void SPI_SlaveReceive(u8* pu8_DataReceived);

void SPI_SlaveTransmit(u8 Copy_u8DataTransmitted);



#endif
