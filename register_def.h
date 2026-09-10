
#ifndef REGISTER_DEF_H_
#define REGISTER_DEF_H_

// /*
// $1B ($3B) PORTA PORTA7 PORTA6 PORTA5 PORTA4 PORTA3 PORTA2 PORTA1 PORTA0 64
// $1A ($3A) DDRA DDA7 DDA6 DDA5 DDA4 DDA3 DDA2 DDA1 DDA0 64
// $19 ($39) PINA PINA7 PINA6 PINA5 PINA4 PINA3 PINA2 PINA1 PINA0 64
// $18 ($38) PORTB PORTB7 PORTB6 PORTB5 PORTB4 PORTB3 PORTB2 PORTB1 PORTB0 64
// $17 ($37) DDRB DDB7 DDB6 DDB5 DDB4 DDB3 DDB2 DDB1 DDB0 64
// $16 ($36) PINB PINB7 PINB6 PINB5 PINB4 PINB3 PINB2 PINB1 PINB0 65
// $15 ($35) PORTC PORTC7 PORTC6 PORTC5 PORTC4 PORTC3 PORTC2 PORTC1 PORTC0 65
// $14 ($34) DDRC DDC7 DDC6 DDC5 DDC4 DDC3 DDC2 DDC1 DDC0 65
// $13 ($33) PINC PINC7 PINC6 PINC5 PINC4 PINC3 PINC2 PINC1 PINC0 65
// $12 ($32) PORTD PORTD7 PORTD6 PORTD5 PORTD4 PORTD3 PORTD2 PORTD1 PORTD0 65
// $11 ($31) DDRD DDD7 DDD6 DDD5 DDD4 DDD3 DDD2 DDD1 DDD0 65
// $10 ($30) PIND PIND7 PIND6 PIND5 PIND4 PIND3 PIND2 PIND1 PIND0 65*/
#define PORTA_REG     *((volatile u8 *)(0x3b))
#define DDRA_REG     *((volatile u8 *)(0x3a))
#define PINA_REG     *((volatile u8 *)(0x39))
#define PORTB_REG     *((volatile u8 *)(0x38))
#define DDRB_REG     *((volatile u8 *)(0x37))
#define PINB_REG     *((volatile u8 *)(0x36))
#define PORTC_REG     *((volatile u8 *)(0x35))
#define DDRC_REG     *((volatile u8 *)(0x34))
#define PINC_REG     *((volatile u8 *)(0x33))
#define PORTD_REG     *((volatile u8 *)(0x32))
#define DDRD_REG     *((volatile u8 *)(0x31))
#define PIND_REG     *((volatile u8 *)(0x30))


/************************ EXTI******************/
#define MCUCR_REG     *((volatile u8*)(0x55))
#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3
#define MCUCSR_REG    *((volatile u8*)(0x54))
#define MCUCSR_ISC2   6

#define GICR_REG       *((volatile u8*)(0x5b))
#define GICR_INT2       5
#define GICR_INT0       6
#define GICR_INT1       7


#define GIFR_REG       *((volatile u8*)(0x5a))
#define GIFR_INT2       5
#define GIFR_INT0       6
#define GIFR_INT1       7



/**************************ADC Reg ***************************/


/*ADC Multiplexer Register */
#define ADC_ADMUX_REG        *((volatile u8* )(0x27))
#define ADC_ADMUX_REFS1      7
#define ADC_ADMUX_REFS0      6
#define ADC_ADMUX_ADLAR      5
/*ADC Control Register */
#define ADC_ADCSRA_REG       *((volatile u8* )(0x26))
#define ADC_ADCSRA_ADEN      7
#define ADC_ADCSRA_ADSC      6
#define ADC_ADCSRA_ADATE     5
#define ADC_ADCSRA_ADIF      4
#define ADC_ADCSRA_ADIE      3
#define ADC_ADCSRA_ADPS2     2
#define ADC_ADCSRA_ADPS1     1
#define ADC_ADCSRA_ADPS0     0

/*ADC Data Register */
#define ADC_ADC_REG          *((volatile u16*)(0x24))
#define ADC_ADCL_REG         *((volatile u8* )(0x24))
#define ADC_ADCH_REG         *((volatile u8* )(0x25))


/************************** Timer/Counter Register ***************************/
/*Timer/Counter Control Register � TCCR0 */
#define TIMER_TCCR0_REG        *((volatile u8* )(0x53))
#define TIMER_TCCR0_FOC0      7
#define TIMER_TCCR0_WGM00     6
#define TIMER_TCCR0_WGM01     3
#define TIMER_TCCR0_COM01     5
#define TIMER_TCCR0_COM00     4
#define TIMER_TCCR0_CS00      0
#define TIMER_TCCR0_CS01      1
#define TIMER_TCCR0_CS02      2


/*Timer/Counter Register � TCNT0 */
#define TIMER_TCNT0_REG       *((volatile u8*)(0x52))


/*Output Compare Register � OCR0  */
#define TIMER_OCR0_REG          *((volatile u8*)(0x5C))

/*Timer/Counter Interrupt Mask Register � TIMSK  */
#define TIMER_TIMSK_REG          *((volatile u8*)(0x59))
#define TIMER_TIMSK_OCIE0   1
#define TIMER_TIMSK_TOIE0   0

/*Timer/Counter Interrupt Flag Register � TIFR*/
#define TIMER_TIMSK_REG          *((volatile u8*)(0x58))
#define TIMER_TIMSK_OCF0   1
#define TIMER_TIMSK_TOV0   0

#endif /* REGISTER_DEF_H_ */