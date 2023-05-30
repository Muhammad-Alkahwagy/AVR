/*Inclusions*/
/*Include Header files from LIB Layer*/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"

/*Include my own header files*/
#include "GIE_Private.h"
#include "GIE_Interface.h"


/******************************************************************/
/*Func. Name: GIE_void_Enable                                     */
/*i/p arguments: void                                             */
/*Description: Enables Interrupts                                 */
/*             sets the I_bit (Global interrupt enable) in SREG   */
/*return: void                                                    */
/******************************************************************/
void GIE_void_Enable(void)
{
    SET_BIT(SREG,I_BIT);
}

/******************************************************************/
/*Func. Name: GIE_void_Disable                                    */
/*i/p arguments: void                                             */
/*Description: disables Interrupts                                */
/*             clears the I_bit (Global interrupt enable) in SREG */
/*return: void                                                    */
/******************************************************************/
void GIE_void_Disable(void)
{
    CLR_BIT(SREG,I_BIT);
}
