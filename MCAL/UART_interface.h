/*
 * UART_interface.h
 *
 * Created: 25/04/2026 02:49:53 م
 *  Author: eslam
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_voidInit(void);
void UART_voidSendChar   (u8 Copy_u8Char);
void UART_voidSendString (u8 * Copy_pu8Str);
void UART_voidRecieveChar(u8 * Copy_pu8Char);

#endif /* UART_INTERFACE_H_ */