/*File Gaurd*/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


/*ADC Channel IDs*/
#define ADC0    0
#define ADC1    1
#define ADC2    2
#define ADC3    3
#define ADC4    4
#define ADC5    5
#define ADC6    6
#define ADC7    7

/*******************************************************************/
/*Func. Name: ADC_voidInit                                         */
/*i/p arguments: void                                              */
/*Description: initializes ADC with prebuild configuration         */
/*return: void                                                     */
/*******************************************************************/
void ADC_voidInit(void); 
 
 
/*******************************************************************/
/*Func. Name: ADC_u16ReadSynchronous                               */
/*i/p arguments:                                                   */
/*Copy_u8ChID: ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7      */
/*Description: gets reading from  a specific ADC channel           */
/*return: u16                                                      */
/*******************************************************************/
u16 ADC_u16ReadSynchronous(u8 Copy_u8ChID); 


/*******************************************************************/
/*Func. Name: ADC_u16ReadAsynchronous                              */
/*i/p arguments:                                                   */
/* ADC_pvoidCallBackFunPtr: pointer to call back function          */
/* Copy_u8ChID: ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7     */
/*Description: gets reading from  a specific ADC channel           */
/*return: u16                                                      */
/*******************************************************************/
u16 ADC_u16ReadAsynchronous(u8 Copy_u8ChID, void(*Copy_pvoidCallBackFunPtr)(void));

#endif