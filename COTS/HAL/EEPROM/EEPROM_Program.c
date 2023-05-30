/*
 * EEPROM_Program.c
 *
 *  Created on: Apr 17, 2023
 *      Author: Muhammad Alkahwagy
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EEPROM_Private.h"
#include "EEPROM_Config.h"
#include "EEPROM_Interface.h"

#include "../../MCAL/TWI/TWI_Interface.h"


void EEPROM_voidWrite(u16 Copy_u16ByteAddress, u8 Copy_u8Data)
{

    u8 Local_u8SlaveAddress = EEPROM_FIXED_ADD | (A2_VAL<<2) | ((u8)(Copy_u16ByteAddress>>8));
    
    /*Send Start Condition*/
    TWI_error_stStartCondition();

    /*Send Slave address with write*/
    TWI_error_stSendSlaveAddressWithWrite(Local_u8SlaveAddress);

    /*Send the rest of Byte Address (BA7 -> BA0)*/
    TWI_error_stSendDataByte( (u8)Copy_u16ByteAddress );

    /*Send Data Byte*/
    TWI_error_stSendDataByte(Copy_u8Data);

    /*Delay until the write cycle is finished*/
    _delay_ms(10);
    
    /*Send Stop Condition*/
    TWI_voidStopCondition();

}

u8 EEPROM_u8Read(u16 Copy_u16ByteAddress)
{
    u8 Local_u8ReceivedData;
    u8 Local_u8SlaveAddress = EEPROM_FIXED_ADD | (A2_VAL<<2) | (Copy_u16ByteAddress>>8);

    /*Send Start Condition*/
    TWI_error_stStartCondition();

    /*Send Slave address with write*/
    TWI_error_stSendSlaveAddressWithWrite(Local_u8SlaveAddress);

    /*Send the rest of Byte Address (BA7 -> BA0)*/
    TWI_error_stSendDataByte( (u8)Copy_u16ByteAddress );

    /*Send repeated start condition*/
    TWI_error_stReStartCondition();

    /*Send Slave address with Read*/
    TWI_error_stSendSlaveAddressWithRead(Local_u8SlaveAddress);

    /*Read Data Byte from EEPROM*/
    TWI_error_stReadDataByte(&Local_u8ReceivedData);
    
    /*Delay until the Read cycle is finished*/
    _delay_ms(10);

    /*Send Stop Condition*/
    TWI_voidStopCondition();

    /*return received Data*/
    return Local_u8ReceivedData;    
}