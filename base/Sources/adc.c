/*
 * adc.c
 *
 *  Created on: Mar 7, 2016
 *      Author: Eduardo
 */
#include "derivative.h"

/*MODULO ADC*/

void adcInit(void);
int readAdc();

void adcInit(void)
{
	 
	 SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK; //ENABLE ADC CLK
	 SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; //CLK PORTB
	 PORTB_PCR0 = PORT_PCR_MUX(0);//SELECT AS ANALOG INPUT
	 ADC0_CFG1 = 0; // Reset register
	 ADC0_CFG1 |= (ADC_CFG1_MODE(3)  |  	// 16 bits mode
					  ADC_CFG1_ADICLK(0)|	// Input Bus Clock (20-25 MHz out of reset (FEI mode))
					  ADC_CFG1_ADIV(1)) ;	// Clock divide by 2 (10-12.5 MHz)
	 ADC0_SC1A = 0x8; //PORTB0 AS ADC
}

int readAdc()
{
	int data=0,bit=0; //Values from de adc
	bit = ADC0_SC1A;
	if(bit == 136){
	  data = ADC0_RA;
	  ADC0_SC1A = 0x8; //PORTB0 AS ADC
	}
	return data;
}


