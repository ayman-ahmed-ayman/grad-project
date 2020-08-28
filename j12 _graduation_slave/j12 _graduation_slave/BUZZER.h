/*
 * BUZZER.h
 *
 * Created: 8/27/2020 6:52:00 PM
 *  Author: ahmad
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_


#include "BIT_Math.h"
#include "ATMEGA32_Regs.h"
#include "DIO.h"

void BUZZER_Init(void);

void BUZZER_ON(void);

void BUZZER_OFF(void);





#endif /* BUZZER_H_ */