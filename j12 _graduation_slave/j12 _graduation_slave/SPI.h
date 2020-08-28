/*
 * SPI.h
 *
 * Created: 8/14/2020 6:36:56 AM
 *  Author: ahmad
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"



void SPI_Master_INIT(void);
void SPI_Slave_INIT(void);
uint8 SPI_Send_Recvie(uint8 sent );

#endif /* SPI_H_ */