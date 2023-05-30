/*
 * EEPROM_Interface.h
 *
 *  Created on: Apr 17, 2023
 *      Author: Muhammad Alkahwagy
 */

#ifndef HAL_EEPROM_INTERFACE_H
#define HAL_EEPROM_INTERFACE_H


void EEPROM_voidWrite(u16 Copy_u16ByteAddress, u8 Copy_u8Data);

u8 EEPROM_u8Read(u16 Copy_u16ByteAddress);





#endif