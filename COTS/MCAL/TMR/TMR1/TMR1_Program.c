/*Inclusions*/
/*Include Header files from LIB Layer*/
#include "../..\..\LIB\STD_TYPES.h"
#include "../..\..\LIB\BIT_MATH.h"

/*Inclusion for my own header files*/
#include "../../DIO/DIO_Interface.h"

#include "TMR1_Private.h"
#include "TMR1_Config.h"
#include "TMR1_Interface.h"

void (*pNotificationT1OF)(void) = NULL;
void (*pNotificationT1OCM)(void) = NULL;



/*******************************************************************/
/*Func. Name: TMR1_voidInit                                        */
/*i/p arguments: void                                              */
/*Description: initializes TMR1 with prebuild configuration        */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidInit(void)
{
    //select mode
    #if(T1_MODE == T1_NORMAL_MODE)
        //Normal mode (overflow mode)
        CLR_BIT(TMR1_U8_TCCR1A_REG,TMR1_TCCR1A_WGM10);
        CLR_BIT(TMR1_U8_TCCR1A_REG,TMR1_TCCR1A_WGM11);
        CLR_BIT(TMR1_U8_TCCR1B_REG,TMR1_TCCR1B_WGM12);
        CLR_BIT(TMR1_U8_TCCR1B_REG,TMR1_TCCR1B_WGM13);
        //enable Timer1 Overflow interrupt
        SET_BIT(TMR_U8_TIMSK_REG,TMR1_TIMSK_TOIE1);

    #elif(T1_MODE == T1_PWM_PHASE_CORRECT_8_BIT)
    {  }
    #elif(T1_MODE == T1_PWM_PHASE_CORRECT_9_BIT)
    {  }
    #elif(T1_MODE == T1_PWM_PHASE_CORRECT_10_BIT)
    {  }
    #elif(T1_MODE == T1_CTC_OCR1A)
    {  }
    #elif(T1_MODE == T1_FAST_PWM_8_BIT)
    {  }
    #elif(T1_MODE == T1_FAST_PWM_9_BIT)
    {  }
    #elif(T1_MODE == T1_FAST_PWM_10_BIT)
    {  }
    #elif(T1_MODE == T1_PWM_PHASE_AND_FREQ_CORRECT_ICR1)
    {  }
    #elif(T1_MODE == T1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A)
    {  }
    #elif(T1_MODE == T1_PWM_PHASE_CORRECT_ICR1 )
    {  }
    #elif(T1_MODE == T1_PWM_PHASE_CORRECT_OCR1A)
    {  }
    #elif(T1_MODE == T1_CTC_ICR1)
    {  }
    
    #elif(T1_MODE == T1_Fast_PWM_ICR1)
    {
        //select mode
        CLR_BIT(TMR1_U8_TCCR1A_REG,TMR1_TCCR1A_WGM10);
        SET_BIT(TMR1_U8_TCCR1A_REG,TMR1_TCCR1A_WGM11);
        SET_BIT(TMR1_U8_TCCR1B_REG,TMR1_TCCR1B_WGM12);
        SET_BIT(TMR1_U8_TCCR1B_REG,TMR1_TCCR1B_WGM13);

        //generate a non inverted waveform output on OC1A
		SET_BIT(TMR1_U8_TCCR1A_REG,TMR1_TCCR1A_COM1A1);
		CLR_BIT(TMR1_U8_TCCR1A_REG,TMR1_TCCR1A_COM1A0);
    }

    #elif(T1_MODE == T1_Fast_PWM_OCR1A)
    {
    }   

    #else
        #error  Wrong selection of operation mode
        
    #endif

    /*Clock select*/
    //clear clock select bits
    TMR1_U8_TCCR1B_REG &= CLK_MASK;
    //set clock select bits
    TMR1_U8_TCCR1B_REG |= T1_CLK_SOURCE;

}


/*******************************************************************/
/*Func. Name: TMR1_voidSetPreloadValue                             */
/*i/p arguments: Copy_u16PreloadValue: u16                         */
/*Description: assigns preload value to TMR1 register TCNT1        */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetPreloadValue( u16 Copy_u16PreloadValue)
{
    TMR1_U16_TCNT1_REG = Copy_u16PreloadValue;
}


/*******************************************************************/
/*Func. Name: TMR1_voidSetCompareMatchValueToOCR1A                 */
/*i/p arguments: Copy_u16CompareMatchValue: u16 value              */
/*Description: writes compare match value into register OCR1A      */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetCompareMatchValueToOCR1A( u16 Copy_u16CompareMatchValue)
{
    TMR1_U16_OCR1A_REG = Copy_u16CompareMatchValue;
}


/*******************************************************************/
/*Func. Name: TMR1_voidSetCompareMatchValueToOCR1B                 */
/*i/p arguments: Copy_u16CompareMatchValue: u16 value              */
/*Description: writes compare match value into register OCR1B      */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetCompareMatchValueToOCR1B( u16 Copy_u16CompareMatchValue)
{
    TMR1_U16_OCR1B_REG = Copy_u16CompareMatchValue;
}


/*******************************************************************/
/*Func. Name: TMR1_voidSetTopValueToICR1                           */
/*i/p arguments: Copy_u16TopValue: u16                             */
/*Description: defines timer1 top value to ICR1 register           */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetTopValueToICR1( u16 Copy_u16TopValue)
{
    TMR1_U16_ICR1_REG = Copy_u16TopValue;
}





/*******************************************************************/
/*Func. Name: TMR1_voidSetCallBackOF                               */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls TMR1 Overflow Interrupt Service Routine       */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetCallBackOF( void (*LpF)(void))
{
    pNotificationT1OF = LpF;
}

/*******************************************************************/
/*Func. Name: TMR1_voidSetCallBackOCM                              */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls TMR1 Compare match Interrupt Service Routine  */
/*return: void                                                     */
/*******************************************************************/
void TMR1_voidSetCallBackOCM( void (*LpF)(void))
{
    pNotificationT1OCM = LpF;
}


/*

//ISR(Compare match)
void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
    static u16 Local_u16Counter = 0;
    Local_u16Counter++;
    if(Local_u16Counter == CTC_COUNT)
    {
        //reinitialize counter to 0
        Local_u16Counter = 0;

        //take action
        if(pNotificationT1OCM != NULL)
        {
            pNotificationT1OCM();
        }
    }
}


//ISR(Overflow)
void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
    static u16 Local_u16Counter = 0;
    Local_u16Counter++;
    if(Local_u16Counter == OVERFLOW_COUNT)
    {
        //reinitialize counter to 0
        Local_u16Counter = 0;
        //reinitialize timer register to preload value
        TMR1_voidSetPreloadValue(PRELOAD_VALUE);

        //take action
        if(pNotificationT1OF != NULL)
        {
            pNotificationT1OF();
        }
    }
}

*/
