/*
 * D96.c
 *
 * Created: 10/04/2026 02:49:08 م
 * Author : eslam
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "Utils/STD_TYPES.h"
#include "Utils/BIT_MATH.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TMR0/TMR0_interface.h"
#include "MCAL/GI/GI_interface.h"
#include "MCAL/UART/UART_interface.h"

int main(void)
{
	UART_voidInit();
	UART_voidSendString("hello");
	/* Replace with your application code */
    while (1) 
    {
    }
}

