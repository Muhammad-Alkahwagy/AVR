/*
 * Stepper_Interface.h
*/

#ifndef HAL_STEPPER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_STEPPER_INTERFACE_H_

#define CW	0
#define CCW	1

/******************************************************************/
/*Func. Name: Stepper_voidInit                                    */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: initialises the stepper motor                      */
/******************************************************************/
void Stepper_voidInit(void);


/******************************************************************/
/*Func. Name: Stepper_voidStop                                    */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: stops the stepper motor                      */
/******************************************************************/
void Stepper_voidStop(void);


/******************************************************************/
/*Func. Name: Stepper_voidRotate                                  */
/*i/p arguments: Copy_u8Direction: CW, CCW 						  */
/* 				 Copy_u16Angle: unsigned angle                    */
/*return: void                                                    */
/*Description: rotates the stepper motor in a set direction
*  by desired angle							                      */
/******************************************************************/
void Stepper_voidRotate(u8 Copy_u8Direction, u16 Copy_u16Angle);



#endif
