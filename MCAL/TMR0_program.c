#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"
#include "TMR0_interface.h"
#include "TMR0_private.h"
#include "TMR0_config.h"
#include "TMR0_register.h"

static void (*PRV_pToFunction_Ovf)(void) = NULL;
static void (*PRV_pToFunction_OCf)(void) = NULL;
void TMR0_voidInit(){
	#if TMR0_MODE == TMR0_NORMAL_MODE
		/* SELECT Normal mode */
		CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM00);
		CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM01);
	
		/* enable Timer 0 overflow interrupt */
		SET_BIT(TMR0_TIMSK_REG,TMR0_TIMSK_TOIE0);
		/* select initial preload */
		TMR0_TCNT0_REG = TMR0_INITIAL_PRELOAD;
	#elif TMR0_MODE == TMR0_CTC_MODE
		/* SELECT CTC mode */
		CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM00);
		SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM01);
		/* Enable Timer 0 OCIE */
		SET_BIT(TMR0_TIMSK_REG,TMR0_TIMSK_OCIE0);
		/* Set initial OCR val */
		TMR0_OCR0_REG = TMR0_INITIAL_OCR_VAL;
	#elif TMR0_MODE == TMR0_FAST_PWM
			/* SELECT CTC mode */
			SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM00);
			SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_WGM01);
			#if TMR0_PWM_MODE == TMR0_INVERTED
				SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM00);
				SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM01);
				
			#elif TMR0_PWM_MODE == TMR0_NON_INVERTED
				CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM00);
				SET_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM01);
			#elif TMR0_PWM_MODE == TMR0_DISABLED
				CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM00);
				CLR_BIT(TMR0_TCCR0_REG,TMR0_TCCR0_COM01);
			#else
				#warning "wrong PWM mode "
			#endif 
	#endif
		
		

}
void TMR0_voidSetPreloadValue(u8 copy_u8Prelaod){
	TMR0_TCNT0_REG = copy_u8Prelaod ;
}
void TMR0_SET_OCRVal(u8 Copy_u8Ocrval){
	TMR0_OCR0_REG = Copy_u8Ocrval; 
}
void TMR0_voidStart(TMR0_Prescaler_t copy_u8prescalar){
	TMR0_TCCR0_REG =(TMR0_TCCR0_REG &  0b11111000)|(TMR0_TCCR0_REG| copy_u8prescalar);
}
void TMR0_voidStop(){
	TMR0_TCCR0_REG &= 0b11111000;
}
void TMR0_Set_OVF_CallBack(void (*ptr)(void)){
	PRV_pToFunction_Ovf = ptr ; 
}
void TMR0_Set_OCF_CallBack(void (*ptr)(void)){
		PRV_pToFunction_OCf = ptr ; 
}
void TMR0_GeneratePWM(u8 Copy_u8Duty){
	TMR0_OCR0_REG = ( Copy_u8Duty * 256 )/100;
}
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	if(PRV_pToFunction_Ovf!= NULL){
		PRV_pToFunction_Ovf();
	}else{
		/*error */
	}
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void){
	if(PRV_pToFunction_OCf!= NULL){
		PRV_pToFunction_OCf();
		}else{
		/*error */
	}
}