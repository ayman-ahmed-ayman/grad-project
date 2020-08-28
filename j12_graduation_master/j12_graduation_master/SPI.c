/*
 * SPI.c
 *
 * Created: 8/14/2020 6:36:18 AM
 *  Author: ahmad
 */ 
#include "SPI.h"
void SPI_Master_INIT(void)
{
	DIO_SetPinDir(DIO_PORTB  ,DIO_PIN4, DIO_PIN_OUTPUT );
	DIO_SetPinDir(DIO_PORTB  ,DIO_PIN5, DIO_PIN_OUTPUT );
	DIO_SetPinDir(DIO_PORTB  ,DIO_PIN6, DIO_PIN_INPUT );
	DIO_SetPinDir(DIO_PORTB  ,DIO_PIN7, DIO_PIN_OUTPUT );
	DIO_WritePin(DIO_PORTB ,DIO_PIN4, DIO_PIN_HIGH );

    SPI->SPCR=0X53 ;
}
void SPI_Slave_INIT(void)
{
	DIO_SetPinDir(DIO_PORTB  ,DIO_PIN4, DIO_PIN_INPUT );
	DIO_SetPinDir(DIO_PORTB  ,DIO_PIN5, DIO_PIN_INPUT );
	DIO_SetPinDir(DIO_PORTB  ,DIO_PIN6, DIO_PIN_OUTPUT );
	DIO_SetPinDir(DIO_PORTB  ,DIO_PIN7, DIO_PIN_INPUT );
	 SPI->SPCR=0X40  ;
}

uint8 SPI_Send_Recvie(uint8 sent    )
{   uint8 recevied=0;
	 SPI->SPDR = sent;
	
	while (GET_BIT(SPI->SPSR,7 )==0);
	recevied  =  SPI->SPDR ;
	return recevied ;

}

