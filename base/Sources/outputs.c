#include "derivative.h"

/*MODULO DE OUTPUTS*/

void outputsSet(char value);
void outputsInit(void);

void outputsInit(void)
{
	  SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; //CLK PORTC
	  PORTC_PCR0 = PORT_PCR_MUX(1);//SELECT AS GPIO
	  PORTC_PCR1 = PORT_PCR_MUX(1);//SELECT AS GPIO
	
	  GPIOC_PDDR |= 0b11;//PIN 0 PORT C CONFIGURED AS OUTPUT
	//  GPIOC_PDDR |= 1<<2;//PIN 1 PORT C CONFIGURED AS OUTPUT
}
void outputsSet(char value)
{
	char currentValue = 0;
	currentValue = GPIOC_PDIR;
	if(currentValue != value)
	  GPIOC_PCOR = 0x3;
	GPIOC_PSOR = value;
}




