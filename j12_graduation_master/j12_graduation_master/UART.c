/*
 * UART.c
 *
 * Created: 8/12/2020 4:08:37 PM
 *  Author: ahmad
 */ 
#include "UART.h"

#define F_CPU 8000000

void UART_Init(void)
{
	uint32 BR_Value = 0; 
 DIO_SetPinDir(DIO_PORTD ,DIO_PIN0 , DIO_PIN_INPUT);
	 DIO_SetPinDir(DIO_PORTD ,DIO_PIN1 , DIO_PIN_OUTPUT );
	UCSRB|=0X18 ;
	UCSRC|=0X86 ;
	BR_Value = ((80000)/(96 * 16))-1;
	UBRRL = BR_Value  ;
	
		
}

void UART_SendByte(uint8 data)
{
	while (GET_BIT(UCSRA,5)==0);
	UDR = data  ;
	
	
}

void UART_SendString(uint8* str)
{
	   uint8 i  =0  ;
	      
		  
		  while (str[i] !='\0')
		  {
			  
			  UART_SendByte(str[i]);
			  i++;
			  
		  }
		  }

uint8 UART_RecvedByte(void)
{
	
	while (GET_BIT(UCSRA,7)==0);
	uint8 data  =0  ;
    data = UDR ;
	return data ;
	
}

uint8* UART_RecvedString(void)
{   uint8 i =0;
	uint8* str =0 ;
	 while (str[i] !='\0')
	 {
		UART_RecvedByte();
		i++;
	 }
	 return str[i];
}