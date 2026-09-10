#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"
#include "UART_register.h"
#include "UART_interface.h"









void UART_voidInit(void){
	/*set boadrate*/
	UBRRH_REG = 0 ;
	UBRRL_REG = 103 ;
	/*select char 8bit */
	UCSRC_REG = 0b10000110 ; 
	/* enable tx,, rx */
	SET_BIT(UCSRB_REG,UCSRB_TXEN );
	SET_BIT(UCSRB_REG,UCSRB_RXEN );
	
}
void UART_voidSendChar   (u8 Copy_u8Char){
	while ( GET_BIT(UCSRA_REG,UCSRA_UDRE)!= 1){
		
		// wait 
		// polling ,, busy wait
	}
	UDR_REG = Copy_u8Char;
}
void UART_voidSendString (u8 * Copy_pu8Str){
	while(*Copy_pu8Str != '\0'){
		UART_voidSendChar(*Copy_pu8Str++);
	}
}
void UART_voidRecieveChar(u8 * Copy_pu8Char);
