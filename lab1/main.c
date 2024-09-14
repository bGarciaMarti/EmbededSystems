/* This file will hold the second tutorial for ECE4330 containing both the LED and the 7 segment
number example
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1abc
*/

#include <stdio.h>
#include "NUC1xx.h"

#include "user_func.h"

int main (void) {

	/* DrvGPIO.h gives us the option to use the pins/ports directly for this chip */
	GPC_13 = 1; //off, green
	GPC_14 = 1; //off ?
	
	NVIC_EnableIRQ(	TMR1_IRQn	); //enable timer ISR
	
	Initial_panel(); // init LCD
	clr_all_panel(); // from LCD_Driver.c
	//outStringLCD("howdy world %d");
	
	OpenKeyPad(); //initialize Keypad
	
	

	while(1){
		blinky_Drv(); // timer to blink green LED
		
		//heartbeat(); // wip // ISR to blink LED
		//TMR1_IRQHandler(); // wip // ISR to blink LED
	
		// multiplex7segment(2024); // display 2024 on the 7-segment display
		
		keypad_input();
		CloseKeyPad();
	}
	
} //end main
