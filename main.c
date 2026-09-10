#define F_CPU 16000000
#include <util/delay.h>
#include "util/std_types.h"
#include "util/bit_math.h"
#include "MCAL/DIO/dio.h"
#include "HAL/CLCD/CLCD_int.h"
#include "util/bit_math.h"
#include "MCAL/ADC/ADC.h"
#include "HAL/CLCD/CLCD_int.h"
#include "MCAL/DIO/dio.h"
#include <util/delay.h>
#include <stdio.h>

u8 arr[20];
u16 var;
int main(void)
{
	ADC_voidInit();
	CLCD_voidInit();
	while(1){
		//var=ADC_u16StartConvertion(0);
		sprintf(arr,"ADC = %d",5);
		CLCD_voidSendString(arr);
		_delay_ms(1000);
		CLCD_voidClearDisplay();
	}
}

