/*
 * UART.h
 *
 * Created: 8/12/2020 4:08:58 PM
 *  Author: ahmad
 */ 


#ifndef UART_H_
#define UART_H_
#include "DIO.h"
void UART_Init(void);

void UART_SendByte(uint8 data);

void UART_SendString(uint8* str);

uint8  UART_RecvedByte(void);

uint8* UART_RecvedString(void);


#endif /* UART_H_ */