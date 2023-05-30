/*File Gaurd*/
#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H


/*******************************************************************/
/*Func. Name: WDT_voidEnable                                       */
/*i/p arguments: void                                              */
/*Description: enables watch dog timer                             */
/*return: void                                                     */
/*******************************************************************/
void WDT_voidEnable(void); 


/*******************************************************************/
/*Func. Name: WDT_voidDisble                                       */
/*i/p arguments: void                                              */
/*Description: disables watch dog timer                            */
/*return: void                                                     */
/*******************************************************************/
void WDT_voidDisble(void); 
 


/*******************************************************************/
/*Func. Name: WDT_voidSetTimeOut                                   */
/*i/p arguments: void                                              */
/*Description: Sets sleep time of watch dog timer                  */
/*return: void                                                     */
/*******************************************************************/
void WDT_voidSetTimeOut(void); 


#endif