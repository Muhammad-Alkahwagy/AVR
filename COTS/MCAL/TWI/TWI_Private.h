/*
 * TWI_Private.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Muhammad Alkahwagy
 */

#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

/*TWI Registers*/
#define TWCR       *((volatile u8*)0x56)   //TWI Control Register
#define TWDR       *((volatile u8*)0x23)   //TWI Data Register
#define TWAR       *((volatile u8*)0x22)   //TWI (Slave) Address Register
#define TWSR       *((volatile u8*)0x21)   //TWI Status Register
#define TWBR       *((volatile u8*)0x20)   //TWI Bit Rate Register


/*TWI Control Register (TWI_TWCR_REG) Bits*/

#define TWCR_TWIE     0      //TWI Interrupt Enable

#define TWCR_TWEN     2      //TWI Enable Bit
#define TWCR_TWWC     3      //TWI Write Collision Flag
#define TWCR_TWSTO    4      //TWI Stop Condition Bit
#define TWCR_TWSTA    5      //TWI Start Condition Bit
#define TWCR_TWEA     6      //TWI Enable Acknowledge Bit
#define TWCR_TWINT    7      //TWI Interrpt Flag


/*TWI Status Register (TWI_TWSR_REG) Bits*/
/*TWI Prescaler Bits*/
#define TWSR_TWPS0    0
#define TWSR_TWPS1    1


/*TWI Address Register (TWI_TWAR_REG) Bits*/
#define TWAR_TWGCE    0     //TWI General Call Recognition Enable Bit

/*Value of the TWI Bit-rate Register*/
#define TWBR_VAL    ( ( (CPU_CLK/SCL) - 16 ) / (2 * PRESCALER) )

#define TWSR_MASKED     (TWSR & 0xF8)


/*status codes*/
#define START          0x08     //A START condition has been transmitted
#define RESTART        0x10     //A repeated START condition has been transmitted
#define SLA_W_ACK      0x18     //SLA+W has been transmitted, ACK has been received
#define SLA_W_NACK     0x20     //SLA+W has been transmitted, NOT ACK has been received
#define DATA_T_ACK     0x28     //Data byte has been transmitted, ACK has been received
#define DATA_T_NACK    0x30     //Data byte has been transmitted, NOT ACK has been received
#define ARBT_LOST      0x38     //Arbitration lost

/*Master Receiver*/
#define SLA_R_ACK      0x40     //SLA+R has been transmitted, ACK has been received
#define SLA_R_NACK     0x48     //SLA+R has been transmitted, NOT ACK has been received
#define DATA_R_ACK     0x50     //Data byte has been received, ACK has been returned
#define DATA_R_NACK    0x58     //Data byte has been received, NOT ACK has been returned

/*Slave Receiver*/
#define OSLA_W_ACK      0x60     //own SLA+W has been received, ACK has been returned
#define OSLA_R_ACK      0x80     //Previously addressed with own SLA+W, data has been received, ACK has been returned
#define OSLA_R_NACK     0x88     //Previously addressed with own SLA+W, data has been received, NOT ACK has been returned





#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
