

/* This file will hold Lab1b code:
the two versions of blinking LEDs with delay function
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1b part 1, create a heartbeat signal using an 
	interrupt service routine and one of the RGB LEDs
*/


#include "DrvSYS.h"
#include "DrvGPIO.h"

void heartbeat(void)
{
	//Clock source
	SYSCLK->CLKSEL1.TMR1_S = 7; // 22 MHz  Timer1 clock source
	SYSCLK->APBCLK.TMR1_EN = 1; //enable Timer1
	
	//Op Mode
	TIMER1->TCSR.MODE = 2; // toggle mode
	
	//Period
	TIMER1->TCSR.PRESCALE=1;
	TIMER1->TCMPR = 5500000; // (0.5s)(1/(1+1))(2.2E7)
	
	//Enable Interrupt
	TIMER1->TCSR.IE = 1;
	TIMER1->TISR.TIF = 1; // clear flag
	NVIC_EnableIRQ(TMR1_IRQn); //init timer interrupt things

	TIMER1->TCSR.TDR_EN = 1;
	
	//Enable Timer
	TIMER1->TCSR.CRST = 1; // reset timer counter
	TIMER1->TCSR.CEN= 1; // enable counter
	TIMER1->TCSR.TDR_EN= 1; //data register function enabled
}

void TMR1_IRQHandler(void) // flashes led (?)
{
	GPA_14 = ~GPA_14;
	TIMER1->TISR.TIF = 1; //clear flag
}

