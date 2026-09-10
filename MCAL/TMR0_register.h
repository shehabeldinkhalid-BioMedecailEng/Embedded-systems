/*
 * TMR0_register.h
 *
 * Created: 10/04/2026 02:52:54 م
 *  Author: eslam
 $33 ($53) TCCR0 FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00 80
 $32 ($52) TCNT0 Timer/Counter0 (8 Bits) 82
 $39 ($59) TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 82, 112, 130
 $38 ($58) TIFR OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0 83, 112, 130
 $3C ($5C) OCR0 Timer/Counter0 Output Compare Register 82
 */ 


#ifndef TMR0_REGISTER_H_
#define TMR0_REGISTER_H_

#define TMR0_TCNT0_REG			*(volatile u8 *)(0x52)
#define TMR0_OCR0_REG			*(volatile u8 *)(0x5C)

/* Timer control Register */
#define TMR0_TCCR0_REG			*(volatile u8 *)(0x53)
#define TMR0_TCCR0_CS00			0
#define TMR0_TCCR0_CS01			1	
#define TMR0_TCCR0_CS02			2
#define TMR0_TCCR0_WGM01		3
#define TMR0_TCCR0_COM00		4
#define TMR0_TCCR0_COM01		5
#define TMR0_TCCR0_WGM00		6
#define TMR0_TCCR0_FOC0			7
/* $39 ($59) TIMSK OCIE2 TOIE2 TICIE1 OCIE1A OCIE1B TOIE1 OCIE0 TOIE0 82, 112, 130*/
#define TMR0_TIMSK_REG			*(volatile u8 *)(0x59)
#define TMR0_TIMSK_TOIE0		0
#define TMR0_TIMSK_OCIE0		1

/* $38 ($58) TIFR OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0 83, 112, 130*/
#define TMR0_TIFR_REG			*(volatile u8 *)(0x58)
#define TMR0_TIFR_TOV0			0
#define TMR0_TIFR_OCF0			1

#endif /* TMR0_REGISTER_H_ */