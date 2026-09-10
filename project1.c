// #define F_CPU 16000000UL
// #include <util/delay.h>
// #include<avr/io.h>
// #include<avr/interrupt.h>
// #include "util/std_types.h"
// #include "util/bit_math.h"
// #include "MCAL/DIO/dio.h"
// #include "MCAL/GIE.h"
// #include "MCAL/TIMER0/Timer0.h"
// #include "MCAL/ADC/ADC_int.h"
// #include "HAL/CLCD/CLCD_int.h"
// #include "HAL/KPAD/KPAD.h"
// #include "HAL/KPAD/KPAD_cfg.h"
// #include <stdio.h>
// u8 i = 0;
// u8 RPass [4] = {1,2,3,4};
// u8 RPress[4];
// u8 Wrong_counter = 0;
// u8 PRESS = 0;
// u8 HMEV = 0;
// u8 check = 0;
// void start()
// {
// 	CLCD_voidInit();
// 	KPAD_voidInit();
// 	CLCD_voidSendString("ENTER_PASSWORD");
// 	CLCD_voidSetCursorPosition(6,1);
// }
// 
// int main(void)
// {
// 	start();
// 	while(1)
// 	{
// 		PRESS = KPAD_u8GetKeyPressed();
// 
// 		if(PRESS != 255)
// 		{
// 			RPress[HMEV] = PRESS;
// 			HMEV++;
// 
// 			CLCD_voidSendData('*');
// 
// 			if(HMEV == 4)
// 			{
// 				check = 1;
// 
// 				for(i=0;i<4;i++)
// 				{
// 					if(RPress[i] != RPass[i])
// 					{
// 						check = 0;
// 						break;
// 					}
// 				}
// 
// 				if(check)
// 				{
// 					CLCD_voidClearDisplay();
// 					CLCD_voidSendString("Correct Password");
// 				}
// 				else
// 				{
// 					CLCD_voidClearDisplay();
// 					CLCD_voidSendString("Wrong Password");
// 					Wrong_counter++;
// 				}
// 
// 				HMEV = 0;
// 			}
// 
// 
// 		}
// 	}	
// }