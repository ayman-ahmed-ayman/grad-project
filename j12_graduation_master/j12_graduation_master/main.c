/*
 * j12_graduation_master.c
 *
 * Created: 8/17/2020 7:18:21 AM
 * Author : ahmad
 */ 

#include "UART.h"
#include "SPI.h"


#define F_CPU 8000000
#include "util/delay.h"
int main()
{    
	uint8 RX_DATA  =0  ; 
    uint8 Rc_DATA  =0  ; 
    UART_Init();
    _delay_ms (100);
	
    /* Replace with your application code */
     while (1) 
	
     {
		RX_DATA  = UART_RecvedByte();
		if ( (RX_DATA == '5')||(RX_DATA == '6')||(RX_DATA == '7')||(RX_DATA == '8'))
		   {
			 SPI_Master_INIT();
			 DIO_WritePin(DIO_PORTB ,DIO_PIN4, DIO_PIN_LOW );
			 _delay_ms (1000);
			 Rc_DATA = SPI_Send_Recvie(RX_DATA );
			 RX_DATA  =0   ;
		}

	}
}

