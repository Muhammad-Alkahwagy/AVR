/*
 * Project name: Smart home system (Master)
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
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/Keypad/Keypad_Interface.h"
#include "../MCAL/USART/USART_Interface.h"

#include "configurations.h"
#include "operations.h"

int main()
{
	//PIN Connections
	DIO_voidSetPinDirection(BUZZER_PORT,BUZZER_PIN,OUTPUT);		//buzzer
	DIO_voidSetPinDirection(DOOR_PORT,DOOR_OPEN_PIN,OUTPUT);	//Door(CW/open)
	DIO_voidSetPinDirection(DOOR_PORT,DOOR_CLOSE_PIN,OUTPUT);	//Door(CCW/close)
	DIO_voidSetPinDirection(PIR_PORT,PIR_PIN,INPUT);			//PIR(motion detector)

	//Components initialization
	LCD_voidInit();
	KPD_voidInit();
	USART_voidInit();

	//Welcome screen
	LCD_voidGoToXY(LINE1,5);
	LCD_voidSendString("Welcome");
	LCD_voidGoToXY(LINE2,0);
	LCD_voidSendString(" to Smart Home!");
	_delay_ms(1000);

	while(1)
	{
		LCD_voidClearDisplay();
		LCD_voidGoToXY(LINE1,0);
		LCD_voidSendString("user: ");

		//LCD_voidGoToXY(LINE1,6);
		SelectUser();
		LCD_voidSendString(current_user.name);

		for(u8 i=0;i<3;i++)
		{
			LCD_voidClearDisplay();
			LCD_voidGoToXY(LINE1,0);
			LCD_voidSendString("user: ");

			LCD_voidSendString(current_user.name);

			LCD_voidGoToXY(LINE2,0);
			LCD_voidSendString("pass:     ");
			LCD_voidGoToXY(LINE2,6);
			u8 pass = GetPassword();

			if(pass == current_user.pass)
			{
				/*Send USART signal to second MCU to start smart home inside operations*/
				USART_voidTransmit(1);

				//welcome user
				LCD_voidClearDisplay();
				LCD_voidSendString("Welcome, ");
				LCD_voidSendString(current_user.name);
				LCD_voidGoToXY(LINE2,0);

				//open the door
				LCD_voidSendString("Opening Door -->");
				OpenDoor();

				LCD_voidGoToXY(LINE2,0);
				LCD_voidSendString("Door is open >-<");
				_delay_ms(1000);

				//close the door
				LCD_voidGoToXY(LINE2,0);
				LCD_voidSendString("Closing Door <--");
				CloseDoor();

				LCD_voidGoToXY(LINE2,0);
				LCD_voidSendString("Door is closed<>");
				_delay_ms(1000);

				//Inside operations
				while(1)
				{
					LCD_voidClearDisplay();
					LCD_voidGoToXY(LINE1,0);
					LCD_voidSendString("   Smart Home");

					LCD_voidGoToXY(LINE2,0);
					LCD_voidSendString("   is active");
					_delay_ms(500);

					//Motion Detection System
					MotionDetection();
				}

			}
			else
			{
				if(i==2)
				{
					LCD_voidClearDisplay();
					LCD_voidSendString("Warning!!!");
					LCD_voidGoToXY(LINE2,0);
					LCD_voidSendString("Theft Attempt!!!");

					//trigger alarm system
					Alarm();

				}
				else
				{
					LCD_voidClearDisplay();
					LCD_voidSendString("Incorrect pass!!");
					LCD_voidGoToXY(LINE2,0);
					LCD_voidSendString("Try again!");
					_delay_ms(500);
				}
			}
		}
	}
}
