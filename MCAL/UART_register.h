/*
 * UART_register.h
 *
 * Created: 25/04/2026 02:49:32 م
 *  Author: eslam
 */ 


#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_
/*

$0C ($2C) UDR USART I/O Data Register 159
$0B ($2B) UCSRA RXC TXC UDRE FE DOR PE U2X MPCM 160
$0A ($2A) UCSRB RXCIE TXCIE UDRIE RXEN TXEN UCSZ2 RXB8 TXB8 161
$09 ($29) UBRRL USART Baud Rate Register Low Byte 164
$20 ($40)UBRRH URSEL––– UBRR[11:8] 164
$20 ($40)UCSRC URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL 162
*/

#define UDR_REG		(*(volatile u8*)(0x2C))
#define UBRRL_REG	(*(volatile u8*)(0x29))
#define UBRRH_REG	(*(volatile u8*)(0x40))
#define UCSRA_REG	(*(volatile u8*)(0x2B))

#define UCSRA_RXC   7
#define UCSRA_TXC	6
#define UCSRA_UDRE	5
#define UCSRA_FE	4
#define UCSRA_DOR	3
#define UCSRA_PE	2
#define UCSRA_U2X	1
#define UCSRA_MPCM	0

#define UCSRB_REG	(*(volatile u8*)(0x2A))
#define UCSRB_RXCIE		7
#define UCSRB_TXCIE		6
#define UCSRB_UDRIE		5
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3
#define UCSRB_UCSZ2		2
#define UCSRB_RXB8		1
#define UCSRB_TXB8		0


#define UCSRC_REG	(*(volatile u8*)(0x40))
//$20 ($40)UCSRC URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL 162
#define UCSRC_URSEL		7	
#define UCSRC_UMSEL		6
#define UCSRC_UPM1		5
#define UCSRC_UPM0		4
#define UCSRC_USBS		3
#define UCSRC_UCSZ1		2
#define UCSRC_UCSZ0		1
#define UCSRC_UCPOL		0




#endif /* UART_REGISTER_H_ */