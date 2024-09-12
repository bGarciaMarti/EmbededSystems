/* This file will hold the second tutorial for ECE4330 containing both the LED and the 7 segment
number example
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1
*/

#include <stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "DrvTimer.h"

int main (void) {

//select 22 MHz for Timer1 clock source
//0=External 12MHz, 1= External 32KHz, 2= HCLK, 7 = Internal 22MHz
DrvSYS_SelectIPClockSource(E_SYS_TMR1_CLKSRC,7);
	
DrvTIMER_Init();
	
//Timer 1, 1/2 s, periodic
DrvTIMER_Open(E_TMR1,2,E_PERIODIC_MODE);	
	
} //end main
