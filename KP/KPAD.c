/*
 * KPAD.c
 *
 * Created: 6/8/2026 9:23:20 PM
 *  Author: Eslam El Hefny
 */ 


#include"../../util/std_types.h"
#include"../../util/bit_math.h"
#include"../../MCAL/DIO/dio.h"
#include"KPAD.h"
#include"KPAD_cfg.h"

u8 KPAD_COL_arr[4]={KPAD_COL_PIN0,KPAD_COL_PIN1,KPAD_COL_PIN2,KPAD_COL_PIN3};
u8 KPAD_ROW_arr[4]={KPAD_ROW_PIN0,KPAD_ROW_PIN1,KPAD_ROW_PIN2,KPAD_ROW_PIN3};
u8 Kpad_mat[4][4]={
					{'7','8','9','/'},
					{'4','5','6','*'},
					{'1','2','3','-'},
					{'C','0','=','+'},
						
};
void KPAD_voidInit(){
	/* row ==> input */
	for(u8 i = 0 ; i<4;i++){
			DIO_voidSetPinDir(KPAD_ROW_PORT,KPAD_ROW_arr[i],DIO_PIN_INPUT);
			DIO_voidSetPinDir(KPAD_COL_PORT,KPAD_COL_arr[i],DIO_PIN_OUTPUT);
			DIO_voidEnablePullUp(KPAD_ROW_PORT,KPAD_ROW_arr[i]);
			DIO_voidSetPinVal(KPAD_COL_PORT,KPAD_COL_arr[i],DIO_PIN_HIGH);
	}
	/* row enable pull up */
	
	
	 /* col output */
	 
	 /*initial value High */
}

u8 KPAD_u8GetKeyPressed(){
	/* Set Col 0 */
	for(u8 i = 0 ; i<4;i++){
		DIO_voidSetPinVal(KPAD_COL_PORT,KPAD_COL_arr[i],DIO_PIN_LOW);
		for(u8 j = 0 ; j<4;j++){
			if((DIO_u8GetPinVal(KPAD_ROW_PORT,KPAD_ROW_arr[j])) == DIO_PIN_LOW){
				while((DIO_u8GetPinVal(KPAD_ROW_PORT,KPAD_ROW_arr[j])) == DIO_PIN_LOW);
				return Kpad_mat[j][i];
			}
		}
		DIO_voidSetPinVal(KPAD_COL_PORT,KPAD_COL_arr[i],DIO_PIN_HIGH);
	}
return 255;
}
