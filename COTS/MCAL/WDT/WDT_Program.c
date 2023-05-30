/*Inclusions*/
/*Include Header files from LIB Layer*/
#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"

/*Inclusion for my own header files*/
#include "../DIO/DIO_Interface.h"

#include "WDT_Private.h"
#include "WDT_Config.h"
#include "WDT_Interface.h"


/*******************************************************************/
/*Func. Name: WDT_voidEnable                                       */
/*i/p arguments: void                                              */
/*Description: enables watch dog timer                             */
/*return: void                                                     */
/*******************************************************************/
void WDT_voidEnable(void)
{
    SET_BIT(WDT_WDTCR_REG, WDT_WDTCR_WDE);
}


/*******************************************************************/
/*Func. Name: WDT_voidDisble                                       */
/*i/p arguments: void                                              */
/*Description: disables watch dog timer                            */
/*return: void                                                     */
/*******************************************************************/
void WDT_voidDisble(void)
{
    /*Reset WDT*/
    CLR_BIT(MCUSR_REG,WDT_WDRF);

    /* Write logical one to WDTOE and WDE */
    WDT_WDTCR_REG |= (1<<WDT_WDTCR_WDTOE) | (1<<WDT_WDTCR_WDE);

    /* Turn off WDT */
    WDT_WDTCR_REG = 0x00;

} 
 


/*******************************************************************/
/*Func. Name: WDT_voidSetTimeOut                                   */
/*i/p arguments: void                                              */
/*Description: Sets sleep time of watch dog timer                  */
/*return: void                                                     */
/*******************************************************************/
void WDT_voidSetTimeOut(void)
{
    /*input validation*/
    /* 
    if(Copy_u8TimeOut >= 0 || Copy_u8TimeOut <= 7)
    {

    } 
    */

    WDT_WDTCR_REG &= CLK_MASK;

    WDT_WDTCR_REG |= WDT_CLK;

}
