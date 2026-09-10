/*
 * main.c
 *
 * Created: 8/3/2026 11:10:56 PM
 *  Author: ENG_shehab eldin
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include<avr/io.h>
#include<avr/interrupt.h>
#include "util/std_types.h"

#include "MCAL/DIO/dio.h"
#include "MCAL/TWI/TWI_interface.h"
#include <stdio.h>
u8 nom = 1;
int main(void){
	//DIO_voidSetPinDir(PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_voidSetPinVal(PORTA,DIO_PIN1,DIO_PIN_OUTPUT);

	TWI_voidInitMaster(0);
	TWI_SendStartCondition();
	TWI_SendSlaveAddressWithWrite(12);
	TWI_MasterWriteDataByte(12);
	TWI_SendStopCondition();
	_delay_ms(100);
	
	while (1)
	{
	}
}