/* This file will hold Lab1b code:
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1b part 3, connect the interrupt button and the buzzer
*/
#include "user_func.h"

// Buzzer pin GPB11
// INT GPB15

//from DrvGPIO.c

//pfEINT1Callback


void beep(void){
	DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, (GPIO_EINT1_CALLBACK)pfEINT1Callback);
}

void pfEINT1Callback(void) //sound the buzzer
{
	GPB_15 = 0; //on
	//DrvTIMER_ClearIntFlag(E_TMR0); // or TIMER1->TISR.TIF = 1;
}