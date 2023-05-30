/*
 * TWI_Program.c
 *
 *  Created on: Apr 14, 2023
 *      Author: Muhammad
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TWI_Private.h"
#include "TWI_Config.h"
#include "TWI_Interface.h"


void TWI_voidMasterInit(u8 Copy_u8Address)
{
    //Set prescaler = 1 (TWPS1:0 = 0)
    CLR_BIT(TWSR,TWSR_TWPS0);
    CLR_BIT(TWSR,TWSR_TWPS1);

    //Set Bit-rate (SCL Freq.= 200KHz) , TWBR = 12
    TWBR = TWBR_VAL;

	/*Check if the master node will be addressed or not*/
	if(Copy_u8Address == 0)
	{
		/*Do Nothing*/
	}
	else
	{
		/*Set The Required Address to The Master*/
		TWAR = (Copy_u8Address << 1);
	}

    //Enable Acknowledge & TWI
    TWCR = (1<<TWCR_TWEA)|(1<<TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
    //Set device's own slave address in TWI Address Register (TWAR)
    TWAR = Copy_u8SlaveAddress <<1;     //general call disabled (to enable, OR TWAR with 0x01)

    //Enable Acknowledge & TWI
    TWCR = (1<<TWCR_TWEA)|(1<<TWCR_TWEN);
}


error_st TWI_error_stStartCondition(void)
{   
    error_st Local_ErrorState;

    /*Clear TWINT Flag and send Start Condition*/
    TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);

    /*Wait for TWINT Flag set*/
    while (!(TWCR & (1<<TWCR_TWINT)));

    /*Check value of masked TWI Status Register against Start condition Status Code*/
    if(TWSR_MASKED == START)
        Local_ErrorState = TWI_Ok;
    else
        Local_ErrorState = StartCondition_Failed;
    
    return Local_ErrorState;
}

error_st TWI_error_stReStartCondition(void)
{
    error_st Local_ErrorState;

    /*Clear TWINT Flag and send Start Condition*/
    TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);

    /*Wait for TWINT Flag set*/
    while (!(TWCR & (1<<TWCR_TWINT)));

    /*Check value of masked TWI Status Register against ReStart condition Status Code*/
    if(TWSR_MASKED == RESTART)
        Local_ErrorState = TWI_Ok;
    else
        Local_ErrorState = ReStartCondition_Failed;
    
    return Local_ErrorState;

}

/*Master Transmitter Mode*/
error_st TWI_error_stSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
    error_st Local_ErrorState;

    /*Load SLA_W into TWDR Register*/
    TWDR = Copy_u8SlaveAddress<<1;

    /*Clear TWINT Flag to Start transmission of address*/
    TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

    /*Wait for TWINT Flag set*/
    while (!(TWCR & (1<<TWCR_TWINT)));

    /*Check value of masked TWI Status Register against SLA_W + ACK Status Code*/
    if(TWSR_MASKED == SLA_W_ACK)
        Local_ErrorState = SLA_W_Ack;

    else if(TWSR_MASKED == SLA_W_NACK)
        Local_ErrorState = SLA_W_Not_Ack;

    else
        Local_ErrorState = SLA_W_Failed;
    
    return Local_ErrorState;
}


/*Master Receiver Mode*/
error_st TWI_error_stSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
    error_st Local_ErrorState;

    /*Load SLA_R into TWDR Register*/
    TWDR = (Copy_u8SlaveAddress<<1) | 0x01;

    /*Clear TWINT Flag to Start transmission of address*/
    TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

    /*Wait for TWINT Flag set*/
    while (!(TWCR & (1<<TWCR_TWINT)));

    /*Check value of masked TWI Status Register against SLA_R + ACK Status Code*/
    if(TWSR_MASKED == SLA_R_ACK)
        Local_ErrorState = SLA_R_Ack;

    else if(TWSR_MASKED == SLA_R_NACK)
        Local_ErrorState = SLA_R_Not_Ack;

    else
        Local_ErrorState = SLA_R_Failed;
    
    return Local_ErrorState;
}


error_st TWI_error_stSendDataByte(u8 Copy_SentData)
{
    error_st Local_ErrorState = TWI_Ok;

    /*Load Data into TWDR Register*/
    TWDR = Copy_SentData;

    /*Clear TWINT Flag to Start transmission of data*/
    TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

    /*Wait for TWINT Flag set*/
    while (!(TWCR & (1<<TWCR_TWINT)));

    /*Check value of masked TWI Status Register against Data transmitted + ACK Status Code*/
    if(TWSR_MASKED == DATA_T_ACK)
        Local_ErrorState = Send_Data_Ack;

    else if(TWSR_MASKED == DATA_T_NACK)
        Local_ErrorState = Send_Data_Not_Ack;

    else
        Local_ErrorState = Send_Data_Failed;
    
    return Local_ErrorState;
}


error_st TWI_error_stReadDataByte(u8 *pu8_ReadData)
{
    error_st Local_ErrorState = Read_Data_Failed;

    if(pu8_ReadData != NULL)
    {
        /*Clear TWINT Flag to Start reception of data*/
        TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

        /*Wait for TWINT Flag set*/
        while (!(TWCR & (1<<TWCR_TWINT)));

        /*Check value of masked TWI Status Register against Data received + ACK Status Code*/
        if(TWSR_MASKED == DATA_R_ACK)
        {
            Local_ErrorState = Read_Data_Ack;

            /*Read Data from TWDR Register*/
            *pu8_ReadData = TWDR;        
        }
        else if(TWSR_MASKED == DATA_R_NACK)
            Local_ErrorState = Read_Data_Not_Ack;
    }
    
    return Local_ErrorState;
}


void TWI_voidStopCondition(void)
{
    /*Clear TWINT Flag and send Stop Condition*/
    TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTO)|(1<<TWCR_TWEN);
}


error_st TWI_error_stSlaveReadDataByte(u8 *pu8_ReadData)
{
    error_st Local_ErrorState = Read_Data_Failed;

    if(pu8_ReadData != NULL)
    {
        /*Clear TWINT Flag to Start reception of data*/
        TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

        /*Wait for TWINT Flag set*/
        while (!(TWCR & (1<<TWCR_TWINT)));

        /*Check value of masked TWI Status Register against own SLA+W + ACK Status Code*/
        if(TWSR_MASKED == OSLA_W_ACK)
        {
            /*Clear TWINT Flag to Start reception of data*/
            TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEA);    //data byte will be received and acknowledge will be returned

            /*Wait for TWINT Flag set*/
            while (!(TWCR & (1<<TWCR_TWINT)));

            /*Check value of masked TWI Status Register against own SLA+W + data received + ACK Status Code*/
            if(TWSR_MASKED == OSLA_R_ACK)
            {
                Local_ErrorState = Read_Data_Ack;

                /*Read Data from TWDR Register*/
                *pu8_ReadData = TWDR;                
            }
        }
        else
            Local_ErrorState = Read_Data_Not_Ack;
    }
    
    return Local_ErrorState;
}