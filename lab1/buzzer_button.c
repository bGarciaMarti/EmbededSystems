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
			if (GPB_15==0){
				GPB_11=0;
			}
			else{
				GPB_11=1;
			}
}
