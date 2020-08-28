/*
 * BUZZER.c
 *
 * Created: 8/27/2020 6:51:32 PM
 *  Author: ahmad
 */ 
# include "BUZZER.h"
  void BUZZER_Init()
 {
	 DIO_SetPinDir(DIO_PORTC, DIO_PIN0 ,DIO_PIN_OUTPUT);
 }

 void BUZZER_ON()
{
	DIO_WritePin(DIO_PORTC, DIO_PIN0 ,DIO_PIN_HIGH);
}

  void BUZZER_OFF()
{
	DIO_WritePin(DIO_PORTC, DIO_PIN0 ,DIO_PIN_LOW);
}
