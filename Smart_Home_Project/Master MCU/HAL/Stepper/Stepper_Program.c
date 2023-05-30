/*
 * Stepper_Program.c
 */

#include <util/delay.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "../../MCAL/DIO/DIO_Config.h"

#include "Stepper_Interface.h"
#include "Stepper_Config.h"
#include "Stepper_Private.h"

/******************************************************************/
/*Func. Name: Stepper_voidInit                                    */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: initializes the stepper motor                      */
/******************************************************************/
void Stepper_voidInit(void)
{
	DIO_voidSetPortDirection(STPR_PORT,OUTPUT);

	DIO_voidSetPortValue(STPR_PORT,INIT);
}

/******************************************************************/
/*Func. Name: Stepper_voidStop                                    */
/*i/p arguments: void                                             */
/*return: void                                                    */
/*Description: stops the stepper motor                      */
/******************************************************************/
void Stepper_voidStop(void)
{
	DIO_voidSetPortValue(STPR_PORT,INIT);
}

/******************************************************************/
/*Func. Name: Stepper_voidRotate                                  */
/*i/p arguments: Copy_u8Direction: CW, CCW 						  */
/* 				 Copy_u16Angle: unsigned angle                    */
/*return: void                                                    */
/*Description: rotates the stepper motor in a set direction
*  by desired angle							                      */
/******************************************************************/
void Stepper_voidRotate(u8 Copy_u8Direction, u16 Copy_u16Angle)
{
	u16 Local_u16Strides;
	u16 Local_u16Iterator;

	Local_u16Strides = (Copy_u16Angle * 512UL )/360;

	for(Local_u16Iterator = 0; Local_u16Iterator < Local_u16Strides; Local_u16Strides++)
	{
		Private_voidStride(Copy_u8Direction);
		_delay_ms(500);
	}
}

/******************************************************************/
/*Func. Name: Private_voidStride                              */
/*i/p arguments: Copy_u8Direction: CW, CCW 						  */
/*return: void                                                    */
/*Description: rotates the motor 1 stride in a set direction      */
/******************************************************************/
void Private_voidStride(u8 Copy_u8Direction)
{
	u8 Local_u8Iterator;
	u8 Stepper_ArrSteps[4]=STEPS;

	switch(Copy_u8Direction)
	{
		case CW:    //turn 1 full_step in C.W. direction
					for(Local_u8Iterator=0; Local_u8Iterator<4; Local_u8Iterator++)
					{
						DIO_voidSetPortValue(STPR_PORT,Stepper_ArrSteps[Local_u8Iterator]);
						_delay_ms(10);
					}
					break;

		case CCW:    //turn 1 full_step in C.C.W. direction
					for(Local_u8Iterator=4; Local_u8Iterator>0; Local_u8Iterator--)
					{
						DIO_voidSetPortValue(STPR_PORT,Stepper_ArrSteps[Local_u8Iterator-1]);
						_delay_ms(10);
					}
					break;

		default:
					break;

	}

}
