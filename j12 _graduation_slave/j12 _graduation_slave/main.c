/*
 * j12 _graduation_slave.c
 *
 * Created: 8/17/2020 7:15:24 AM
 * Author : ahmad
 */ 


#include "SPI.h"
#define F_CPU 8000000
#include "util/delay.h"
#include "LED.h"
#include "BUZZER.h"


int main()
{
	uint8 RX_DATA  =0  ;
	uint8 Rc_DATA  =0  ;
	LED0_Init();
    BUZZER_Init();
	SPI_Slave_INIT();	
    /* Replace with your application code */
    while (1) 
    {
		Rc_DATA = SPI_Send_Recvie(RX_DATA );
		_delay_ms (100);
		  if ( Rc_DATA == '5')
		    {
			
			  LED0_ON();
			
			  Rc_DATA  =0   ;
			
		     }
		else if ( Rc_DATA == '6')
		    {
			  LED0_OFF();
			
			  Rc_DATA  =0   ;
			
			
		    }
	   else if ( Rc_DATA == '7')
	        {
		     BUZZER_ON();
		
		    Rc_DATA  =0   ;
		
	        }
	   else if ( Rc_DATA == '8')
	       {
            BUZZER_OFF() ;
		
		    Rc_DATA  =0   ;
		
		
	       }
	   else
		   ;
    } 
}

