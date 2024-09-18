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

void init_tutorialBlinky(void){
	//unlock the protected registers
	UNLOCKREG();
	//select the 22MHz RC clock
	DrvSYS_SetOscCtrl(E_SYS_OSC22M,1);
	//wait until the clock is stable
	while(DrvSYS_GetChipClockSourceStatus(E_SYS_OSC22M) != 1);
	//HCLK clock source 7: internal 22MHz RC oscillator
	DrvSYS_SelectHCLKSource(7);
	//Lock the protected registers
	LOCKREG();
	//clock frequency is HCLK clock source/(HCLK_N +1)
	//Max divisor value 0xF; Min value is 0x0 - (hence the "+1" above)
	DrvSYS_SetClockDivider(E_SYS_HCLK_DIV,2); //slower clock, 0 is very fast.
}

void tutorialBlinky (void) {
		
		/* DrvGPIO.h gives us the option to use the pins/ports directly for this chip */
		/* see line 35 in DrvGPIO.h */
		GPC_14 = 1; //off
		GPC_15 = 0; //on
	GPA_12 = 0;
	GPA_12 = 1;
		DrvSYS_Delay(10000000);
		GPC_13 = 1; //off
		GPC_14 = 0; //on
	GPA_13 = 0;
	GPA_13 = 1;
		DrvSYS_Delay(10000000);
		GPC_12 = 1; //off
		GPC_13 = 0; //on
	GPA_14 = 0;
	GPA_14 = 1;
		DrvSYS_Delay(10000000);
		GPC_15 = 1; //off
		GPC_12 = 0; //on
	GPA_15 = 0;
	GPA_15 = 1;
		DrvSYS_Delay(10000000); //DrvSYS.h line 182, DrvSYS.c line 1310
	GPA_12 = 0;
	GPA_13 = 0;
	GPA_14 = 0;
	GPA_15 = 0;
		DrvSYS_Delay(10000000); //DrvSYS.h line 182, DrvSYS.c line 1310
	
} //end main
