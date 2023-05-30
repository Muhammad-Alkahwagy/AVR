/*Functions implementations*/

typedef struct User
{
	u8* name;
	u8 pass;
}user;

user user0  = {"Adam",   110 };
user user1  = {"Sarah",  111 };
user user2  = {"John",   112 };
user user3  = {"Matt",   113 };
user user4  = {"Manuel", 114 };
user user5  = {"Adel",   115 };
user user6  = {"Layla",  116 };
user user7  = {"Karim",  117 };
user user8  = {"Hanah",  118 };
user user9  = {"Bob",    119 };

user current_user = {NULL,0};

void SelectUser(void)
{
	u8 UserKey = 0 ;

	while(1)
	{
		UserKey = KPD_u8GetPressedKey();
		if ( UserKey != 0xff  )
		{
			switch(UserKey)
			{
				case '0' :	current_user.name = user0.name; current_user.pass = user0.pass;	break;
				case '1' :	current_user.name = user1.name; current_user.pass = user1.pass;	break;
				case '2' :	current_user.name = user2.name; current_user.pass = user2.pass;	break;
				case '3' :	current_user.name = user3.name; current_user.pass = user3.pass;	break;
				case '4' :	current_user.name = user4.name; current_user.pass = user4.pass;	break;
				case '5' :	current_user.name = user5.name; current_user.pass = user5.pass;	break;
				case '6' :	current_user.name = user6.name; current_user.pass = user6.pass;	break;
				case '7' :	current_user.name = user7.name; current_user.pass = user7.pass;	break;
				case '8' :	current_user.name = user8.name; current_user.pass = user8.pass;	break;
				case '9' :	current_user.name = user9.name; current_user.pass = user9.pass;	break;

				default  :	LCD_voidClearDisplay(); LCD_voidSendString("Invalid user!!");	break;
			}
		}

		if(current_user.name != NULL)
			break;
	}
}

u8 GetPassword (void)
{
	u8 Password = 0 ;
	u8 temp = 0 ;
	u8 PressedKey ;

	while(1)
	{
		PressedKey = KPD_u8GetPressedKey();
		if ( PressedKey != 0xff  )
		{
			if( PressedKey >= '0' && PressedKey <= '9' )
			{
				LCD_voidSendChar('*');
				temp = temp*10 + (PressedKey - '0') ;
				Password = temp ;
			}
			else if ( PressedKey == '=' )
			{
				break ;
			}
		}
	}

	return Password ;
}

void Alarm()
{
	while(1)
	{
		DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,HIGH);
	}
}




void OpenDoor(void)
{
	DIO_voidSetPinValue(DOOR_PORT,DOOR_OPEN_PIN,HIGH);
	DIO_voidSetPinValue(DOOR_PORT,DOOR_CLOSE_PIN,LOW);
	_delay_ms(1000);

	DIO_voidSetPinValue(DOOR_PORT,DOOR_OPEN_PIN,LOW);
	DIO_voidSetPinValue(DOOR_PORT,DOOR_CLOSE_PIN,LOW);

}

void CloseDoor(void)
{
	DIO_voidSetPinValue(DOOR_PORT,DOOR_OPEN_PIN,LOW);
	DIO_voidSetPinValue(DOOR_PORT,DOOR_CLOSE_PIN,HIGH);
	_delay_ms(1000);

	DIO_voidSetPinValue(DOOR_PORT,DOOR_OPEN_PIN,LOW);
	DIO_voidSetPinValue(DOOR_PORT,DOOR_CLOSE_PIN,LOW);
}

void MotionDetection()
{

	while(DIO_u8GetPinValue(PIR_PORT,PIR_PIN))
	{
		DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,HIGH);

		LCD_voidGoToXY(LINE1,0);
		LCD_voidSendString("Someone is here");

		LCD_voidGoToXY(LINE2,0);
		LCD_voidSendString("Check the door!");

	}

	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,LOW);
}

