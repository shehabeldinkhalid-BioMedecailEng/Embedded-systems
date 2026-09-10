/*
 * TMR0_config.h
 *
 * Created: 10/04/2026 03:30:45 م
 *  Author: eslam
 */ 


#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_



/*select mode */
/*
	select : 
	TMR0_NORMAL_MODE
	TMR0_PWM_PHASE_CORRECT
	TMR0_CTC_MODE
	TMR0_FAST_PWM
*/
#define TMR0_MODE				TMR0_FAST_PWM

#define TMR0_INITIAL_PRELOAD		244
#define TMR0_INITIAL_OCR_VAL		0

#define TMR0_PWM_MODE			TMR0_NON_INVERTED
/**
TMR0_INVERTED
TMR0_NON_INVERTED
TMR0_DISABLED
*/

#endif /* TMR0_CONFIG_H_ */