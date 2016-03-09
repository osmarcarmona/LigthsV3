/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include "derivative.h" /* include peripheral declarations */

typedef enum STATE{
	OFF = 0,
	PART = 1,
	HEAD = 2,
	AUTO = 3
};

typedef uint16_t WORD;

void autoStateMachine(char pState);

extern void outputsSet(char value);
extern void outputsInit(void);

extern void inputsInit(void);
extern char inputsRead(void);

extern void adcInit(void);
extern int readAdc();

//void InitializeTMR2();
//void InterruptHandler();

int main(void)
{
	char currentState=0,previousState=0; //Estado actual y estado anterior
	
	inputsInit();
	outputsInit();
	adcInit();		
	
	for(;;) {	   
		//Maquina de estados principal
		previousState=currentState;
		currentState=inputsRead();
	
			
		switch(currentState){
			case PART:
				outputsSet(PART);
				break;
			case HEAD:
				outputsSet(0x03);
				break;
			case AUTO:
				autoStateMachine(previousState);
				break;
			default:
				outputsSet(OFF);
				break;
	
		}
	
	}
	
	return 0;
}
//INITIALIZE AND CONFIGURE PORTS
void autoStateMachine(char pState)
{
	/* cState values
	 * 0=Lights OFF
	 * 1=Half lights
	 * 2=Lights ON
	 */
	int data=0;
	char cState=0,selector=pState;	
	do
	{		
		data = readAdc();
		data = (data * 100) / 65535;

		switch(selector)
		{
			case 1:
					cState = 2;
					outputsSet(0x03);
					break;
			case 2:
					cState = 1;
					outputsSet(PART);
					break;
			case 3:
					cState = 0;
					outputsSet(OFF);
					break;
			default:
				break;
		}
		
		if(data<40&&pState==0)
			selector = 1;
		else if(data>60 && pState==2)
			selector=2;
		else if(data>80 && pState==1)
			selector=3;
		
		pState = cState;
	}while(inputsRead()==3);	
}


/*
//INITIALIZE THE TMR2 REGISTERS WITH INTERRUPTS
void InitializeTMR2(){
	  MCG_C1 = MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK;//ENABLE CLOCK AND SELECT SLOW INTERNAL CLK
	  MCG_C2 = MCG_C2_IRCS_MASK; //FAST INTERNAL CLK REFERENCE
	  SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK; //ENABLE TIMER 2
	  SIM_SOPT2 |= SIM_SOPT2_TPMSRC(3); //SRC OF CLK
	  
	  TPM2_SC = TPM_SC_CMOD(1) | TPM_SC_PS(7); //MODULO AND PRESCALE 128
	  TPM2_MOD = 16383; //MODULO = 16383 FOR 2 SECONDS
	  
	  TPM2_SC |= TPM_SC_TOIE_MASK; //ENABLE INTERRUPTS
	  NVIC_ISER = 1<<19; //ISER TO TPM2
	
}

void InterruptHandler(){
	GPIOB_PTOR = 1<<18;//TOGGLE PIN 18 OF PORT B
	//GPIOD_PTOR = 1<<0;//TOGGLE PIN 0 OF PORT D (EXTERNAL)
	TPM2_SC |= TPM_SC_TOF_MASK;//CLEAR THE INTERRUPT FLAG
}
*/
