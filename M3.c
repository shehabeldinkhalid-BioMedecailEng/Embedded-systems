#include "util/std_types.h"
#include "util/bit_math.h"
#include "MCAL/DIO/dio.h"
#include <util/delay.h>
#define F_CPU  16000000UL

int main(void)
{
    /* Replace with your application code */
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinVal(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		
    while (1) 
    {
		DIO_voidSetPinDir(DIO_PORTC,DIO_PIN_HIGH);
		_delay_ms(1000);
		DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_LOW);
		_delay_ms(1000);
    }
}

