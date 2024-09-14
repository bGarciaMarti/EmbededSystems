/* This file will hold Lab1a code:
the two versions of blinking LEDs with delay function
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1ab
*/

#include "user_func.h"
#include "DrvTimer.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"

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

//~~~~~~~~~~~~~~~~~~~~~//
/*Functions that us interrupt/ "Register method" to blind the lone red LED*/
//~~~~~~~~~~~~~~~~~~~~~//
void blinky_reg(void)
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
	
	TIMER1->TCSR.TDR_EN = 1;
	
	//Enable Timer
	TIMER1->TCSR.CRST = 1; // reset timer counter
	TIMER1->TCSR.CEN= 1; // enable counter
	TIMER1->TCSR.TDR_EN= 1; //data register function enabled
}

void TMR1_IRQHandler(void) // flashes led (?)
{
	GPA_14 = ~GPA_14;
	TIMER0->TISR.TIF = 1; //clear flag
}

