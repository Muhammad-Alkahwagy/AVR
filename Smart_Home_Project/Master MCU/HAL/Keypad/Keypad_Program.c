#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "../../MCAL/DIO/DIO_Config.h"

#include "Keypad_Interface.h"
#include "Keypad_Config.h"
#include "Keypad_Private.h"

u8 KPD_Au8ColsArr[NO_OF_COLS]= COLUMNS;
u8 KPD_Au8RowsArr[NO_OF_ROWS]= ROWS;

u8 KPD_Au8KeysArr[NO_OF_ROWS][NO_OF_COLS]= KPD_KEYSET;


void KPD_voidInit(void)
{
    /*Configure the direction of row pins as input*/
    DIO_voidSetPinDirection(KPD_PORT,KPD_R0_pin,INPUT);
    DIO_voidSetPinDirection(KPD_PORT,KPD_R1_pin,INPUT);
    DIO_voidSetPinDirection(KPD_PORT,KPD_R2_pin,INPUT);
    DIO_voidSetPinDirection(KPD_PORT,KPD_R3_pin,INPUT);

    /*Configure the direction of column pins as output*/
    DIO_voidSetPinDirection(KPD_PORT,KPD_C0_pin,OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT,KPD_C1_pin,OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT,KPD_C2_pin,OUTPUT);
    DIO_voidSetPinDirection(KPD_PORT,KPD_C3_pin,OUTPUT);

    /*Deactivate column pins & input Pull-up for row pins*/
    DIO_voidSetPortValue(KPD_PORT,0xFF);

}

u8 KPD_u8GetPressedKey(void)
{
    u8 Local_u8ColIter;
    u8 Local_u8RowIter;
    u8 Local_u8PinValue;
    u8 Local_u8PressedKey = 0xFF;
    u8 Local_u8Flag = 0;

    for(Local_u8ColIter = 0; Local_u8ColIter < NO_OF_COLS; Local_u8ColIter++)
    {   
        /*Activate current column by Setting 0 at output*/
        DIO_voidSetPinValue(KPD_PORT,KPD_Au8ColsArr[Local_u8ColIter],LOW);

        for(Local_u8RowIter = 0; Local_u8RowIter < NO_OF_ROWS; Local_u8RowIter++)
        {
            /*Read current row pin value*/
            Local_u8PinValue = DIO_u8GetPinValue(KPD_PORT,KPD_Au8RowsArr[Local_u8RowIter]);

            /*check if key is pressed*/
            if(!Local_u8PinValue)
            {   
                /*Debouncing*/
                _delay_ms(20);

                /*Read row pin value again to make sure the key is pressed*/
                Local_u8PinValue = DIO_u8GetPinValue(KPD_PORT,KPD_Au8RowsArr[Local_u8RowIter]);
                
                while(!Local_u8PinValue)
                {
                    /*Read row pin value again*/
                    Local_u8PinValue = DIO_u8GetPinValue(KPD_PORT,KPD_Au8RowsArr[Local_u8RowIter]);
                }

                /*Get the pressed key*/
                Local_u8PressedKey= KPD_Au8KeysArr[Local_u8RowIter][Local_u8ColIter];

                Local_u8Flag =1;
                break;
            }
        }
        /*Dectivate current column*/
        DIO_voidSetPinValue(KPD_PORT,KPD_Au8ColsArr[Local_u8ColIter],HIGH);

        if(Local_u8Flag)
            break;
    }

    return Local_u8PressedKey;
}
