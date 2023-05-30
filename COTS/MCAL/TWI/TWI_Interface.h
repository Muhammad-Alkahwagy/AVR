/*
 * TWI_Interface.h
 *
 *  Created on: Apr 14, 2023
 *      Author: Muhammad
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_


typedef enum{

    TWI_Ok,

    StartCondition_Failed,
    ReStartCondition_Failed,

    SLA_W_Ack,
    SLA_W_Not_Ack,
    SLA_W_Failed,

    SLA_R_Ack,
    SLA_R_Not_Ack,
    SLA_R_Failed,

    Send_Data_Ack,
    Send_Data_Not_Ack,
    Send_Data_Failed,

    Read_Data_Ack,
    Read_Data_Not_Ack,
    Read_Data_Failed

}error_st;


void TWI_voidMasterInit(u8 Copy_u8Address);
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

error_st TWI_error_stStartCondition(void);
error_st TWI_error_stReStartCondition(void);
error_st TWI_error_stSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
error_st TWI_error_stSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
error_st TWI_error_stSendDataByte(u8 Copy_SentData);
error_st TWI_error_stReadDataByte(u8 *pu8_ReadData);

error_st TWI_error_stSlaveReadDataByte(u8 *pu8_ReadData);

void TWI_voidStopCondition(void);

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
