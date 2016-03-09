/*
 * dipswitch_inputs.c
 *
 *  Created on: Mar 6, 2016
 *      Author: Eduardo
 */
#include "derivative.h"

/*MODULO DE INPUTS*/

void inputsInit(void);
char inputsRead(void);

void inputsInit(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK; //CLK PORTD
	PORTD_PCR0 = PORT_PCR_MUX(1);//SELECT AS GPIO
	PORTD_PCR2 = PORT_PCR_MUX(1);//SELECT AS GPIO
	
	GPIOD_PDDR = 0<<0;//PIN 0 PORT D CONFIGURED AS INPUT
	GPIOD_PDDR = 0<<2;//PIN 2 PORT D CONFIGURED AS INPUT
}
char inputsRead(void)
{
	char LightsOutput=0;
	LightsOutput = GPIOD_PDIR;
	if(LightsOutput>1)
		LightsOutput = LightsOutput - 2;
	return LightsOutput;
}
