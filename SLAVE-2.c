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
#include "MCAL/TWI/BIT_MATH.h"
#include <stdio.h>
u8 slaveAdd = 12;
u8 data = 2;
int main(void){
	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN3,DIO_PIN_HIGH);
	TWI_voidInitSlave(slaveAdd);
	TWI_SlaveReadDataByte(&data);
	
// 	if (data == 12)
// 	{
// 		TOG_BIT(PORTC,DIO_PIN3);
// 	_delay_ms(100);
	while (1){
	}
}