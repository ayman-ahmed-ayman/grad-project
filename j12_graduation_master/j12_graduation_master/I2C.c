/*
 * I2C.c
 *
 * Created: 08/08/2020 12:40:44 م
 *  Author: Ali
 */ 

#include "I2C.h"



void I2C_Init_Master(void)
{
	TWBR = 0x0C ;
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	SET_BIT(TWCR ,2);
}

void I2C_Init_Slave(void)
{
	TWAR = (0x01 << 1) ;
	SET_BIT(TWCR ,2);
}

void I2C_Start_Cond(void)
{
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	
	while(GET_BIT(TWCR,7) == 0);
	
	while((TWSR & 0XF8) == START_ACK);
}

void I2C_Repeated_Start(void)
{
	
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	
	while(GET_BIT(TWCR,7) == 0);
	
	while((TWSR & 0XF8) == REP_START_ACK);
}

void I2C_Send_Slave_Address_Write_Operation(uint8 addr)
{
	TWDR = (addr << 1);
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	
	while(GET_BIT(TWCR,7) == 0);
		
	while((TWSR & 0XF8) == SLAVE_ADD_AND_WR_ACK);
}

void I2C_Send_Slave_Address_Read_Operation(uint8 addr)
{
	TWDR = (addr << 1) | (0X01);
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	
	while(GET_BIT(TWCR,7) == 0);
	
	while((TWSR & 0XF8) == SLAVE_ADD_AND_RD_ACK);
}

void I2C_Write_Byte(uint8 data)
{
	TWDR = data ;
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	
	while(GET_BIT(TWCR,7) == 0);
	
	while((TWSR & 0XF8) == WR_BYTE_ACK);
}

uint8 I2C_Read_Byte(void)
{
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	
	while(GET_BIT(TWCR,7) == 0);
	
	while((TWSR & 0XF8) == RD_BYTE_WITH_NACK);
	
	return TWDR;
}

void I2C_Stop(void)
{
	SET_BIT(TWCR,4);
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,7);
	
	while(GET_BIT(TWCR,7) == 0);
	
}