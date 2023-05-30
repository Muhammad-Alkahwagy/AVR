/*
 * Project name: Smart home system (Slave)
 * Version: 02
 * Description:
 * 				A smart home system with the following features:
 * 				> Login system that supports 10 users with different usernames and passwords
 * 				> Alarm system in case of burglary attempts
 *				> Motion detection system
 *				> Automated Air conditioning system
 *				> Automated Lighting system
 *				> Automated door
 *				
 *   Created on: May 4, 2023
 *       Author: Muhammad Sameer Alkahwagy
 */

#include <util/delay.h>

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../MCAL/USART/USART_Interface.h"

#include "configurations.h"
#include "operations.h"

int main()
{
	//PIN Connections
	DIO_voidSetPinDirection(AC_PORT,AC_PIN,OUTPUT);	//A.C.
	DIO_voidSetPinDirection(LIGHT_PORT,LIGHT1,OUTPUT);	//Light pins
	DIO_voidSetPinDirection(LIGHT_PORT,LIGHT2,OUTPUT);	//Light pins
	DIO_voidSetPinDirection(LIGHT_PORT,LIGHT3,OUTPUT);	//Light pins

	DIO_voidSetPinDirection(PORTA,PIN0,INPUT);	//Temp. sensor(ADC0)
	DIO_voidSetPinDirection(PORTA,PIN2,INPUT);	//LDR(ADC2)


	//Components initialization
	ADC_voidInit();
	USART_voidInit();

	u8 Received_Data;

	while(1)
	{

		/*read USART data sent frm main controller*/
		USART_voidReceive(&Received_Data);

		if(Received_Data == 1)
		{
			//Start inside operations
			while(1)
			{
				//Air conditioner
				AirConditioner();

				//Light System
				LightSystem();
			}

		}

	}
}
