#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "../DIO/DIO_Interface.h"

/*******************************************************************/
/*Func. Name: SPI_voidInit                                         */
/*i/p arguments: void                                              */
/*Description: initializes SPI peripheral                          */
/*return: void                                                     */
/*******************************************************************/
void SPI_voidInit(void)
{
    #if(SPI_MODE == MASTER)
        /*select master mode*/
        SET_BIT(SPI_SPCR_REG,SPCR_MSTR);

        /*Configure pin directions*/
        DIO_voidSetPinDirection(PORTB,MOSI,OUTPUT);
        DIO_voidSetPinDirection(PORTB,MISO,INPUT);
        DIO_voidSetPinDirection(PORTB,SCK,OUTPUT);
        DIO_voidSetPinDirection(PORTB,SS,OUTPUT);

        DIO_voidSetPinValue(PORTB,SS,HIGH);

        /*select speed*/
        #if(SPI_SPEED == NORMAL_SPEED)
            CLR_BIT(SPI_SPSR_REG,SPSR_SPI2X);
        #elif(SPI_SPEED == DOUBLE_SPEED)
            SET_BIT(SPI_SPSR_REG,SPSR_SPI2X);
        #endif
        /*select Clock rate*/
        SPI_SPCR_REG &= SCK_MASK;
        SPI_SPCR_REG |= SPI_SCK;

    #elif(SPI_MODE == SLAVE)
        /*select slave mode*/
        CLR_BIT(SPI_SPCR_REG,SPCR_MSTR);

        /*Configure pin directions*/
        DIO_voidSetPinDirection(PORTB,MOSI,INPUT);
        DIO_voidSetPinDirection(PORTB,MISO,OUTPUT);
        DIO_voidSetPinDirection(PORTB,SCK,INPUT);
        DIO_voidSetPinDirection(PORTB,SS,INPUT);
        
    #else
        #error Wrong Selection of operation mode
    #endif

    /*Select Data Order (MSB first)*/
    CLR_BIT(SPI_SPCR_REG,SPCR_DORD);

    /*Select Clock polarity*/
    CLR_BIT(SPI_SPCR_REG,SPCR_CPOL);    //Leading -> Rising edge

    /*Select Clock phase*/
    CLR_BIT(SPI_SPCR_REG,SPCR_CPHA);    //Sample on leading, Setup on trailing

    /*enable SPI*/
    SET_BIT(SPI_SPCR_REG,SPCR_SPE);

}


void SPI_MasterTransmit(u8 Copy_u8DataTransmitted)
{
	/*Pull Slave SS pin low*/
	DIO_voidSetPinValue(PORTB,SS,LOW);

	/* Start transmission */
    SPI_SPDR_REG = Copy_u8DataTransmitted;

	/* Wait for transmission complete */
    while((GET_BIT(SPI_SPSR_REG ,SPSR_SPIF) == 0));

    /*Clear SPIF flag*/
    u8 Local_u8Buffer =  SPI_SPDR_REG;

    /* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and then accessing SPDR
     *  hence flush buffer used here to access SPDR after SPSR read */

}

u8 SPI_MasterReceive(void)
{
	/*Pull Slave SS pin low*/
	DIO_voidSetPinValue(PORTB,SS,LOW);

	/* Start transmission of dummy data*/
    SPI_SPDR_REG = 0xFF;

	/* Wait for transmission complete */
    while((GET_BIT(SPI_SPSR_REG ,SPSR_SPIF) == 0));

    /*Clear SPIF flag*/
    u8 Local_u8Buffer =  SPI_SPDR_REG;

    return Local_u8Buffer;

}


void SPI_SlaveReceive(u8* pu8_DataReceived)
{
	/* Wait for reception complete */
    while((GET_BIT(SPI_SPSR_REG ,SPSR_SPIF) == 0));

	/* Return data register */
	*pu8_DataReceived =  SPI_SPDR_REG;
}

void SPI_SlaveTransmit(u8 Copy_u8DataTransmitted)
{
	/* Start transmission */
    SPI_SPDR_REG = Copy_u8DataTransmitted;

	/* Wait for transmission complete */
    while((GET_BIT(SPI_SPSR_REG ,SPSR_SPIF) == 0));

    /*Clear SPIF flag*/
    u8 Local_u8Buffer =  SPI_SPDR_REG;

}


/*******************************************************************/
/*Func. Name: SPI_voidTranseive                                    */
/*i/p arguments: Copy_u8DataTransmitted: u8 data to be transmitted */
/*             pu8_DataReceived: pointer to u8 data to be received */
/*Description: transmits and receives data via through peripheral  */
/*return: void                                                     */
/*******************************************************************/
void SPI_voidTranseive(u8 Copy_u8DataTransmitted , u8* pu8_DataReceived)
{
	/*Pull Slave SS pin low*/
	DIO_voidSetPinValue(PORTB,SS,LOW);

	/* Start transmission */
    SPI_SPDR_REG = Copy_u8DataTransmitted;

	/* Wait for transmission complete */
    while((GET_BIT(SPI_SPSR_REG ,SPSR_SPIF) == 0));

    /*Clear SPIF flag*/
    u8 Local_u8Buffer =  SPI_SPDR_REG;

    /* Wait for Reception complete */
    //while((GET_BIT(SPI_SPSR_REG ,SPSR_SPIF) == 0));

    /* get received data */
    *pu8_DataReceived = SPI_SPDR_REG;

}
