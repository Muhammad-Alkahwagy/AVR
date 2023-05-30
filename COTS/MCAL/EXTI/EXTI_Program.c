/*Inclusions*/
/*Include Header files from LIB Layer*/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"

/*Inclusion for my own header files*/
#include "../DIO/DIO_Interface.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"


void (*GpF)(void) = NULL;


/*******************************************************************/
/*Func. Name: EXTI_voidInit                                        */
/*i/p arguments: void                                              */
/*Description: initializes external interrupt with prebuild config.*/
/*return: void                                                     */
/*******************************************************************/
void EXTI_voidInit(void)
{
    #if (INT_EN == INT0)

        /*enable INT0*/
        SET_BIT(GICR_REG,GICR_INT0);

        #if(SENSE_CONTROL == LOW_LEVEL)
            CLR_BIT(MCUCR_REG,ISC01);
            CLR_BIT(MCUCR_REG,ISC00);

        #elif(SENSE_CONTROL == ON_CHANGE)
            CLR_BIT(MCUCR_REG,ISC01);
            SET_BIT(MCUCR_REG,ISC00);

        #elif(SENSE_CONTROL == FALLING_EDGE)
            SET_BIT(MCUCR_REG,ISC00);
            CLR_BIT(MCUCR_REG,ISC01);

        #elif(SENSE_CONTROL == RISING_EDGE)
            SET_BIT(MCUCR_REG,ISC00);
            SET_BIT(MCUCR_REG,ISC01);

        #endif

    #elif (INT_EN == INT1)

        /*enable INT1*/
        SET_BIT(GICR_REG,GICR_INT1);

        #if(SENSE_CONTROL == LOW_LEVEL)
            CLR_BIT(MCUCR_REG,ISC11);
            CLR_BIT(MCUCR_REG,ISC10);

        #elif(SENSE_CONTROL == ON_CHANGE)
            CLR_BIT(MCUCR_REG,ISC11);
            SET_BIT(MCUCR_REG,ISC10);

        #elif(SENSE_CONTROL == FALLING_EDGE)
            SET_BIT(MCUCR_REG,ISC10);
            CLR_BIT(MCUCR_REG,ISC11);

        #elif(SENSE_CONTROL == RISING_EDGE)
            SET_BIT(MCUCR_REG,ISC10);
            SET_BIT(MCUCR_REG,ISC11);

        #endif

    #elif (INT_EN == INT2)

        /*enable INT2*/
        SET_BIT(GICR_REG,GICR_INT2);

        #if(SENSE_CONTROL == FALLING_EDGE)
            CLR_BIT(MCUCR_REG,ISC2);

        #elif(SENSE_CONTROL == RISING_EDGE)
            SET_BIT(MCUCR_REG,ISC2);

        #endif

    #else
        #error  Wrong selection of interrupt  
    #endif
}


/*******************************************************************/
/*Func. Name: EXTI_voidEnable                                      */
/*i/p arguments: Copy_u8IntID: INT0, INT1, INT2                    */
/*Copy_u8Trigger: LOW_LEVEL, ON_CHANGE, FALLING_EDGE, RISING_EDGE  */
/*Description: enables interrupt(postbuild) and sets trigger mode  */
/*return: void                                                     */
/*******************************************************************/
void EXTI_voidEnable(u8 Copy_u8IntID, u8 Copy_u8Trigger)
{
    switch(Copy_u8IntID)
    {
        case INT0:
                    SET_BIT(GICR_REG,GICR_INT0);    //set INT0 PIE to one
                    switch(Copy_u8Trigger)
                    {
                        case LOW_LEVEL:
                                        CLR_BIT(MCUCR_REG,ISC01);
                                        CLR_BIT(MCUCR_REG,ISC00);
                                        break;
                        case ON_CHANGE:
                                        CLR_BIT(MCUCR_REG,ISC01);
                                        SET_BIT(MCUCR_REG,ISC00);
                                        break;
                        case FALLING_EDGE:
                                        SET_BIT(MCUCR_REG,ISC01);
                                        CLR_BIT(MCUCR_REG,ISC00);
                                        break;
                        case RISING_EDGE:
                                        SET_BIT(MCUCR_REG,ISC01);
                                        SET_BIT(MCUCR_REG,ISC00);
                                        break;
                        default:        
                                        break;
                    }
                    break;

        case INT1:
                    SET_BIT(GICR_REG,GICR_INT1);    //set INT1 PIE to one
                    switch(Copy_u8Trigger)
                    {
                        case LOW_LEVEL:
                                        CLR_BIT(MCUCR_REG,ISC11);
                                        CLR_BIT(MCUCR_REG,ISC10);
                                        break;
                        case ON_CHANGE:
                                        CLR_BIT(MCUCR_REG,ISC11);
                                        SET_BIT(MCUCR_REG,ISC10);
                                        break;
                        case FALLING_EDGE:
                                        SET_BIT(MCUCR_REG,ISC11);
                                        CLR_BIT(MCUCR_REG,ISC10);
                                        break;
                        case RISING_EDGE:
                                        SET_BIT(MCUCR_REG,ISC11);
                                        SET_BIT(MCUCR_REG,ISC10);
                                        break;
                        default:        
                                        break;
                    }
                    break;

        case INT2:
                    SET_BIT(GICR_REG,GICR_INT2);    //set INT2 PIE to one
                    switch(Copy_u8Trigger)
                    {
                        case FALLING_EDGE:
                                        CLR_BIT(MCUCSR_REG,ISC2);
                                        break;
                        case RISING_EDGE:
                                        SET_BIT(MCUCSR_REG,ISC2);
                                        break;
                        default:        
                                        break;
                    }
                    break;
        
        default:
                    break;

    }
}

/******************************************************************/
/*Func. Name: EXTI_voidDisable                                    */
/*i/p arguments: Copy_u8IntID: INT0, INT1, INT2                   */
/*Description: disables chosen interrupt                          */
/*return: void                                                    */
/******************************************************************/
void EXTI_voidDisable(u8 Copy_u8IntID)
{
    switch(Copy_u8IntID)
    {
        case INT0:  CLR_BIT(GICR_REG,GICR_INT0);    //set INT0 PIE to zero
                    break;
                    
        case INT1:  CLR_BIT(GICR_REG,GICR_INT1);    //set INT1 PIE to zero
                    break;

        case INT2:  CLR_BIT(GICR_REG,GICR_INT2);    //set INT2 PIE to zero
                    break;
        
        default:    break;

    }
}

/*******************************************************************/
/*Func. Name: EXTI_voidSetCallBack                                 */
/*i/p arguments: (*LpF)(void): pointer to function                 */
/*Description: calls Interrupt Service Routine                     */
/*return: void                                                     */
/*******************************************************************/
void EXTI_voidSetCallBack(void (*LpF)(void))
{
    GpF = LpF;
}

/*ISR for INT0*/
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
    if (GpF != NULL)
    {
        GpF();
    } 
}