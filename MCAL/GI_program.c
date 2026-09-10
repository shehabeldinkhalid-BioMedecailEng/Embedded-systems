/*
 * GI_program.c
 *
 * Created: 10/3/2025 7:33:47 PM
 *  Author: mahmo
 */ 


//#include "avr/io.h"

#include "../../Utils/BIT_MATH.h"
#include "../../Utils/STD_TYPES.h"

#include "GI_interface.h"
#include "GI_register.h"

void GI_voidEnableGeneralInterrupts(void)
{
	SET_BIT(SREG_REG, 7);
}

void GI_voidDisableGeneralInterrupts(void)
{
	CLR_BIT(SREG_REG, 7);
}