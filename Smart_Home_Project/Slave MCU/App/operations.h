/*Functions implementations*/

void AirConditioner(void)
{
	//varaiables
	u16 digital_Value;
	u16 milliVolt;
	u16 temperature;

	//Air conditioner
	digital_Value = ADC_u16ReadSynchronous(TEMP_SENSOR);
	milliVolt = (digital_Value * 5000UL)/1024;
	temperature = milliVolt/10;
	if(temperature > 25)
	{
		//turn on A.C.
		DIO_voidSetPinValue(AC_PORT,AC_PIN,HIGH);
	}
	else
	{
		//turn off A.C.
		DIO_voidSetPinValue(AC_PORT,AC_PIN,LOW);
	}
}

void LightSystem(void)
{
	u16 reading;
	u16 Digital_reading;
	
	Digital_reading = ADC_u16ReadSynchronous(LIGHT_SENSOR);
	reading = (Digital_reading * 5000UL)/1024;

	if(reading >=0 && reading <750)
	{
		//turn off all the lights
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT1,LOW);
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT2,LOW);
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT3,LOW);
	}
	else if(reading >=750 && reading <2200)
	{
		//turn on Light1
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT1,HIGH);

		//turn off Light1 & Light2
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT2,LOW);
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT3,LOW);
	}
	else if(reading >=2200 && reading <4000)
	{
		//turn ON Light1 & Light2
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT1,HIGH);
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT2,HIGH);

		//turn off Light3
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT3,LOW);
	}
	else
	{
		//turn ON all the lights
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT1,HIGH);
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT2,HIGH);
		DIO_voidSetPinValue(LIGHT_PORT,LIGHT3,HIGH);
	}

}
