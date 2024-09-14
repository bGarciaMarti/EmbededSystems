/* This file will hold Lab1a code:
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1a part 3, using driver to make a blinky LED
*/

#include "user_func.h"

//~~~~~~~~~~~~~~~~~~~~~//
/*Functions that us timer/ "Driver method" to blind the green RGB LEDs */
//~~~~~~~~~~~~~~~~~~~~~//
void blinky_Drv(void)
{
	//select 22 MHz for Timer0 clock source
	// 7 = Internal 22MHz
	DrvSYS_SelectIPClockSource(E_SYS_TMR0_CLKSRC,7);
	DrvTIMER_Init();
		
	//Timer 1, 1/2 s, periodic
	DrvTIMER_Open(E_TMR0,2,E_PERIODIC_MODE);	
	
	
	DrvTIMER_SetTimerEvent(E_TMR0,1,(TIMER_CALLBACK)TMR0_callback,1);
	//Enable timer ISR
	DrvTIMER_EnableInt(E_TMR0);
	// Clear interrupt flag
	DrvTIMER_ClearIntFlag(E_TMR0);
	//Enable timer
	DrvTIMER_Start(E_TMR0); //start counting TCSR.CEN = 1
}

void TMR0_callback(void) //flashes led (green)
{
	GPA_13 = ~GPA_13;
	DrvTIMER_ClearIntFlag(E_TMR0); // or TIMER1->TISR.TIF = 1;
}
