/*Inclusions*/
#include <util/delay.h>
/*Include Header files from LIB Layer*/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"

/*Inclusion for my own header files*/
#include "../DIO/DIO_Interface.h"

#include "ADC_Private.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"

/*Indicator for ADC state*/
u8 ADC_u8BusyFlag = NOTBUSY;

u16 ADC_u16Result;

void(*ADC_pvoidNotification)(void) = NULL;


/*******************************************************************/
/*Func. Name: ADC_voidInit                                         */
/*i/p arguments: void                                              */
/*Description: initializes ADC with prebuild configuration         */
/*return: void                                                     */
/*******************************************************************/
void ADC_voidInit(void)
{
    //Select reference voltage
    #if(REF_VOLT == AREF)
        CLR_BIT(ADC_U8ADMUX_REG,ADMUX_REFS1);
        CLR_BIT(ADC_U8ADMUX_REG,ADMUX_REFS0);

    #elif(REF_VOLT == AVCC)
        CLR_BIT(ADC_U8ADMUX_REG,ADMUX_REFS1);
        SET_BIT(ADC_U8ADMUX_REG,ADMUX_REFS0);

    #elif(REF_VOLT == RESERVED)
        SET_BIT(ADC_U8ADMUX_REG,ADMUX_REFS1);
        CLR_BIT(ADC_U8ADMUX_REG,ADMUX_REFS0);

    #elif(REF_VOLT == INTERNAL)
        SET_BIT(ADC_U8ADMUX_REG,ADMUX_REFS1);
        SET_BIT(ADC_U8ADMUX_REG,ADMUX_REFS0);
    
    #else
        #error Wrong selection of refernce voltage

    #endif

    //Right or Left Adjust
    #if(RES_ADJUST == RIGHT)
        CLR_BIT(ADC_U8ADMUX_REG,ADMUX_ADLAR);

    #elif(RES_ADJUST == LEFT)
        SET_BIT(ADC_U8ADMUX_REG,ADMUX_ADLAR);

    #endif

    //enable ADC peripheral
    SET_BIT(ADC_U8ADCSRA_REG,ADCSRA_ADEN);

    //clear prescaler bits 0:2 in ADC_U8ADCSRA_REG
    ADC_U8ADCSRA_REG &= PRESCALER_MASK;
    //set prescaler bits according to selection
    ADC_U8ADCSRA_REG |= PRESCALER;

}

/*******************************************************************/
/*Func. Name: ADC_u16ReadSynchronous                               */
/*i/p arguments:                                                   */
/*Copy_u8ChID: ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7      */
/*Description: gets reading from  a specific ADC channel           */
/*return: u16                                                      */
/*******************************************************************/
u16 ADC_u16ReadSynchronous(u8 Copy_u8ChID)
{

    if(ADC_u8BusyFlag == BUSY)
    {
        return BUSY;
    }
    else
    {
        ADC_u8BusyFlag = BUSY;

        //clear bits (0:4) in ADC_U8ADMUX_REG
        ADC_U8ADMUX_REG &= ADMUX_MASK;

        //select ADC channel
        switch(Copy_u8ChID)
        {
            case ADC0:  ADC_U8ADMUX_REG |= ADC0;
                        break;
            case ADC1:  ADC_U8ADMUX_REG |= ADC1;
                        break;
            case ADC2:  ADC_U8ADMUX_REG |= ADC2;
                        break;
            case ADC3:  ADC_U8ADMUX_REG |= ADC3;
                        break;
            case ADC4:  ADC_U8ADMUX_REG |= ADC4;
                        break;
            case ADC5:  ADC_U8ADMUX_REG |= ADC5;
                        break;
            case ADC6:  ADC_U8ADMUX_REG |= ADC6;
                        break;
            case ADC7:  ADC_U8ADMUX_REG |= ADC7;
                        break;
            default:
                        break;
        }

        //Start conversion
        SET_BIT(ADC_U8ADCSRA_REG,ADCSRA_ADSC);

        //poll on ADC Interrupt flag
        while(GET_BIT(ADC_U8ADCSRA_REG,ADCSRA_ADIF) == 0);

        /*Conversion Completed*/

        //clear the ADC Interrupt flag for incoming conversions
        SET_BIT(ADC_U8ADCSRA_REG,ADCSRA_ADIF);
        _delay_us(10);

        ADC_u8BusyFlag = NOTBUSY;

        //return reading
        return  ADC_U16ADCD_REG;
    }

}


/*******************************************************************/
/*Func. Name: ADC_u16ReadAsynchronous                              */
/*i/p arguments:                                                   */
/* ADC_pvoidCallBackFunPtr: pointer to call back function          */
/* Copy_u8ChID: ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7     */
/*Description: gets reading from  a specific ADC channel           */
/*return: u16                                                      */
/*******************************************************************/
u16 ADC_u16ReadAsynchronous(u8 Copy_u8ChID, void(*Copy_pvoidCallBackFunPtr)(void))
{
    if(ADC_u8BusyFlag == NOTBUSY )
    {
        ADC_u8BusyFlag = BUSY;

        //clear bits (0:4) in ADC_U8ADMUX_REG
        ADC_U8ADMUX_REG &= ADMUX_MASK;

        //select ADC channel
        switch(Copy_u8ChID)
        {
            case ADC0:  ADC_U8ADMUX_REG |= ADC0;
                        break;
            case ADC1:  ADC_U8ADMUX_REG |= ADC1;
                        break;
            case ADC2:  ADC_U8ADMUX_REG |= ADC2;
                        break;
            case ADC3:  ADC_U8ADMUX_REG |= ADC3;
                        break;
            case ADC4:  ADC_U8ADMUX_REG |= ADC4;
                        break;
            case ADC5:  ADC_U8ADMUX_REG |= ADC5;
                        break;
            case ADC6:  ADC_U8ADMUX_REG |= ADC6;
                        break;
            case ADC7:  ADC_U8ADMUX_REG |= ADC7;
                        break;
            default:
                        break;
        }

        //set Call back function
        ADC_pvoidNotification = Copy_pvoidCallBackFunPtr;

        //Start conversion
        SET_BIT(ADC_U8ADCSRA_REG,ADCSRA_ADSC);

        //enable ADC Conversion Complete Interrupt
        SET_BIT(ADC_U8ADCSRA_REG,ADCSRA_ADIE);

        return ADC_u16Result;

    }
    else
    {
        return NOTBUSY;
    }
}


/*ISR(ADC)*/
void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
    if(ADC_pvoidNotification != NULL)
    {
        /*Read ADC result*/
        ADC_u16Result = ADC_U16ADCD_REG;

        /*Change ADC state to NOTBUSY*/
        ADC_u8BusyFlag = NOTBUSY;

        /*Invoke Call Back Function*/
        ADC_pvoidNotification();

        //Disable ADC Conversion Complete Interrupt
        CLR_BIT(ADC_U8ADCSRA_REG,ADCSRA_ADIE);

    }

}
