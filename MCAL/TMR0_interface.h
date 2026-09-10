/*
 * TMR0_interface.h
 *
 * Created: 10/04/2026 03:30:22 م
 *  Author: eslam
 */ 


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

typedef enum{
	NO_CLK_SRC  ,    /* 0 0 0 */	
	NO_PRESCALLER,   /* 0 0 1 */
	DIV_BY_8	 ,	 /* 0 1 0 */
	DIV_BY_64	 ,	 /* 0 1 1 */
	DIV_BY_256	 ,	 /* 1 0 0 */
	DIV_BY_1024	 ,	 /* 1 0 1 */
	EXT_FALLING  ,
	EXT_RISING   ,
}TMR0_Prescaler_t;



void TMR0_voidInit();
void TMR0_voidSetPreloadValue(u8 copy_u8Prelaod);
void TMR0_voidStart(u8 copy_u8prescalar);
void TMR0_voidStop();
void TMR0_Set_OVF_CallBack(void (*ptr)(void));
void TMR0_SET_OCRVal(u8 Copy_u8Ocrval);
void TMR0_GeneratePWM(u8 Copy_u8Duty);
#endif /* TMR0_INTERFACE_H_ */