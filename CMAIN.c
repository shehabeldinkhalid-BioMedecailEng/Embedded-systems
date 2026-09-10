 #define F_CPU 16000000UL
 #include <util/delay.h>
 #include <avr/interrupt.h>
 #include <avr/io.h>
 #include "util/std_types.h"
 #include "util/bit_math.h"
 #include "MCAL/DIO/dio.h"
 #include "MCAL/ADC/ADC_int.h"
 #include "MCAL/EXTI/EXTI.h"
 #include "HAL/CLCD/CLCD_int.h"
 #include <util/delay.h>
 #include "RTOS/FreeRTOS.h"
 #include "RTOS/FreeRTOSConfig.h"
 #include "RTOS/task.h"

void TasK1(){
	while(1){
		
	}
}

void TasK2(){
	while(1){
		DIO_voidSetPinVal(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
		vTaskDelay(200);
		DIO_voidSetPinVal(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		vTaskDelay(200);
	}
}

void TasK3(){
	while(1){
		DIO_voidSetPinVal(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
		vTaskDelay(300);
		DIO_voidSetPinVal(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
		vTaskDelay(300);
	}
}
 int main(void){
 	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	
	xTaskCreate(TasK1,"LED1_open",100,NULL,3,NULL);
	xTaskCreate(TasK2,"LED2_open",100,NULL,2,NULL);
	xTaskCreate(TasK3,"LED3_open",100,NULL,1,NULL);
	vTaskStartScheduler();
	while(1){
	
	}
 }

