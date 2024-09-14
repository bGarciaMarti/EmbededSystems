/* This file will hold the second tutorial for ECE4330 containing both the LED and the 7 segment
number example
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1abc
*/

#include <stdio.h>
#include "NUC1xx.h"
#include "DrvGPIO.h"
#include "LCD_Driver.h"

#include "user_func.h"

int main (void) {

	/* DrvGPIO.h gives us the option to use the pins/ports directly for this chip */
	GPC_13 = 1; //off, green
	GPC_14 = 1; //off ?
	
	NVIC_EnableIRQ(	TMR1_IRQn	); //enable timer ISR
	
	Initial_panel(); // init LCD
	clr_all_panel(); // from LCD_Driver.c
	
	while(1){
		//blinky_Drv(); // timer to blink green LED
		//blinky_reg(); // wip // ISR to blink LED
		//TMR1_IRQHandler(); // wip // ISR to blink LED
		
	char buffer[16];
	int count = 1;
	sprintf(buffer, "howdy world %d", count);
	
	print_lcd(1, buffer); //void print_lcd(unsigned char line, char *str)
	}
	
} //end main
