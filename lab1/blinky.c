/* This file will hold Lab1a code:
the two versions of blinking LEDs with delay function
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1a
*/

#include "user_func.h"
#include "DrvTimer.h"
#include "DrvSYS.h"

void blinkFunc(void)
{
	//select 22 MHz for Timer1 clock source
	//0=External 12MHz, 1= External 32KHz, 2= HCLK, 7 = Internal 22MHz
	DrvSYS_SelectIPClockSource(E_SYS_TMR1_CLKSRC,7);
		
	DrvTIMER_Init();
		
	//Timer 1, 1/2 s, periodic
	DrvTIMER_Open(E_TMR1,2,E_PERIODIC_MODE);	

}
