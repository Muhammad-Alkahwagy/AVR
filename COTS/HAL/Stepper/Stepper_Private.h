/*
 * Stepper_Private.h
 */

#ifndef HAL_STEPPER_STEPPER_PRIVATE_H_
#define HAL_STEPPER_STEPPER_PRIVATE_H_

#define INIT	0x0F					// 1111
#define STEPS	{0x07,0x0B,0x0D,0x0E}   // 0111, 1011, 1101, 1110

/******************************************************************/
/*Func. Name: Private_voidStride                                  */
/*i/p arguments: Copy_u8Direction: CW, CCW 						  */
/*return: void                                                    */
/*Description: rotates the motor 1 stride in a set direction      */
/******************************************************************/
void Private_voidStride(u8 Copy_u8Direction);


#endif
