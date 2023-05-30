#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/*SPI Registers*/
#define SPI_SPDR_REG       *((volatile u8*)0x2F)   //SPI Data Register
#define SPI_SPSR_REG       *((volatile u8*)0x2E)   //SPI Status Register
#define SPI_SPCR_REG       *((volatile u8*)0x2D)   //SPI Control Register

/*SPI_SPSR_REG bits*/
#define SPSR_SPIF     7     //SPI Interrupt Flag
#define SPSR_WCOL     6     //Write Collision Flag
#define SPSR_SPI2X    0     //Double SPI Speed Bit

/*SPI_SPCR_REG bits*/
#define SPCR_SPIE   7     //SPI Interrupt Enable
#define SPCR_SPE    6     //SPI Enable
#define SPCR_DORD   5     //Data Order
#define SPCR_MSTR   4     //Master/Slave Select
#define SPCR_CPOL   3     //Clock Polarity
#define SPCR_CPHA   2     //Clock Phase
#define SPCR_SPR1   1     //SPI Clock Rate Select 1
#define SPCR_SPR0   0     //SPI Clock Rate Select 0

/*SPI pins*/
#define SS     PIN4
#define MOSI   PIN5
#define MISO   PIN6
#define SCK    PIN7

/*Mode of operation*/
#define MASTER      0
#define SLAVE       1

/*Speed*/
#define NORMAL_SPEED   0
#define DOUBLE_SPEED   1

/*speed mask*/
#define SCK_MASK    0b11111100

/*Clock rates*/
#define  SCK_4    0
#define  SCK_16   1
#define  SCK_64   2
#define  SCK_128  3

#define  SCK_2    0
#define  SCK_8    1
#define  SCK_32   2
#define  SCK_64   3

#endif
