// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include <avr/interrupt.h>
// #include <avr/io.h>
// #include "util/std_types.h"
// #include "util/bit_math.h"
// #include "MCAL/DIO/dio.h"
// #include "MCAL/ADC/ADC_int.h"
// #include "MCAL/EXTI/EXTI.h"
// #include "HAL/CLCD/CLCD_int.h"
// #include <util/delay.h>
// #include <stdio.h>
// 
// 
// int main(void){
// 	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
// 	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN0,DIO_PIN_OUTPUT);
// 
// 	TCCR0=5;
// 	TCNT0=248;
// 	TIMSK=1;
// 	sei();
// 	while (1)
// 	{
// 	}
// }
// ISR(TIMER0_OVF_vect){
// 	static u8 L_counter = 0;
// 	static u8 B_counter = 0;
// 
// 	L_counter++;
// 	B_counter++;
// 	if(L_counter==62){
// 		DIO_togglePin(DIO_PORTC,DIO_PIN7);
// 		L_counter=0;
// 	}
// 	if(B_counter==(62*2)){
// 			DIO_togglePin(DIO_PORTB,DIO_PIN0);
// 			B_counter=0;
// 		}
// }
// 
