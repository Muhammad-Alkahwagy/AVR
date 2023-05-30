/*Inclusions*/
/*Include Header files from LIB Layer*/
#include "../..\..\LIB\STD_TYPES.h"
#include "../..\..\LIB\BIT_MATH.h"

/*Inclusion for my own header files*/
#include "../../DIO/DIO_Interface.h"

#include "TMR0_Private.h"
#include "TMR0_Config.h"
#include "TMR0_Interface.h"

void (*pNotificationT0OF)(void) = NULL;
void (*pNotificationT0OCM)(void) = NULL;

/*******************************************************************/
/*Func. Name: TMR0_voidInit                                        */
/*i/p arguments: void                                              */
/*Description: initializes TMR0 with prebuild configuration        */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidInit(void)
{
    //select mode
    #if(MODE == NORMAL_MODE)
        //Normal mode (overflow mode)
        CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM01);
        CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM00);

        //enable T0 Overflow interrupt
        SET_BIT(TMR0_TIMSK_REG,TMR0_TIMSK_TOIE0);
    
    #elif(MODE == CTC)
        //Clear timer on compare match mode
        SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM01);
        CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM00);

        //enable T0 Output compare match interrupt
        SET_BIT(TMR_TIMSK_REG,TMR0_TIMSK_OCIE0);

    #elif(MODE == FAST_PWM)
        //Fast PWM mode
        SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM01);
        SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM00);

        #if(FAST_PWM_MODE == NON_INVERTING)
            //generate a waveform output on OC0 (non-inverting mode)
		    SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM01);
            CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM00);

        #elif(FAST_PWM_MODE == INVERTING)
            //generate a waveform output on OC0 (inverting mode)
		    SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM01);
            SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM00);

        #endif

    #elif(MODE == PWM_PHASE_CORRECT)
        //PWM (phase correct) mode
        CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM01);
        SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM00);

        #if(PHASE_CORRECT_MODE == NON_INVERTING)
            //generate a waveform output on OC0 (non-inverting mode)
		    SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM01);
            CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM00);

        #elif(PHASE_CORRECT_MODE == INVERTING)
            //generate a waveform output on OC0 (inverting mode)
		    SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM01);
            SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM00);

        #endif

    #else
        #error  Wrong selection of operation mode
    #endif

    /*Clock select*/
    //clear clock select bits
    TMR0_TCCR0_REG &= CLK_MASK;
    //set clock select bits
    TMR0_TCCR0_REG |= TMR0_CLK_SOURCE;

}

/*******************************************************************/
/*Func. Name: TMR0_voidSetCallBackOF                               */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls TMR0 Overflow Interrupt Service Routine       */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetCallBackOF( void (*LpF)(void))
{
    pNotificationT0OF = LpF;
}

/*******************************************************************/
/*Func. Name: TMR0_voidSetCallBackOCM                              */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls TMR0 Compare match Interrupt Service Routine  */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetCallBackOCM( void (*LpF)(void))
{
    pNotificationT0OCM = LpF;
}

/*******************************************************************/
/*Func. Name: TMR0_voidSetPreloadValue                             */
/*i/p arguments: Copy_u8PreloadValue: u8                           */
/*Description: assigns preload value to TMR0 register TCNT0        */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetPreloadValue( u8 Copy_u8PreloadValue)
{
    TMR0_TCNT0_REG = Copy_u8PreloadValue;
}

/*******************************************************************/
/*Func. Name: TMR0_voidSetCompareMatchValue                        */
/*i/p arguments: Copy_u8CompareMatchValue: unsigned char (0:255)   */
/*Description: assigns compare match value to register OCR0        */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetCompareMatchValue( u8 Copy_u8CompareMatchValue)
{
    TMR0_OCR0_REG = Copy_u8CompareMatchValue;
}

/*******************************************************************/
/*Func. Name: TMR0_voidSetBusyWaitms                               */
/*i/p arguments: Copy_u16WaitValue: wait value in milliseconds     */
/*Description: this function halts the processor for a set time    */
/*return: void                                                     */
/*******************************************************************/
void TMR0_voidSetBusyWaitms(u16 Copy_u16WaitValue)
{
    //set compare match value
    TMR0_voidSetCompareMatchValue(COMP_MATCH_VAL);

    u16 Local_u16WaitCount = (Copy_u16WaitValue * 1000UL)/COMP_MATCH_VAL;

    u16 Local_u16Iterator;

    for(Local_u16Iterator = 0; Local_u16Iterator < Local_u16WaitCount ; Local_u16Iterator++)
    {
        //poll on CTC Interrupt flag
        while(GET_BIT(TMR_TIFR_REG, TMR0_TIFR_OCF0) == 0);

        //clear CTC Interrupt flag
        SET_BIT(TMR_TIFR_REG,TMR0_TIFR_OCF0);
        
    }

}


/*ISR(Compare match)*/
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
        if(pNotificationT0OCM != NULL)
        {
            pNotificationT0OCM();
        }
    }
}


/*ISR(Overflow)*/
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
        TMR0_voidSetPreloadValue(PRELOAD_VALUE);

        //take action
        if(pNotificationT0OF != NULL)
        {
            pNotificationT0OF();
        }
    }
}
