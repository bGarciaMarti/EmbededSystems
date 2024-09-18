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
	int prevInputKeypad = 0;
	
	heartbeat(); // ISR to blink LED
	
	//init_tutorialBlinky();
	
	
	Initial_panel(); // init LCD
	clr_all_panel(); // from LCD_Driver.c
	//outStringLCD("hello world");
	
	OpenSevenSegment(); // init 7-segment
	OpenKeyPad(); //initialize Keypad
	
	
	while(1){
		//tutorialBlinky(); //myTutorial blink
		
		//blinky_Drv(); // timer to blink green LED
		
		GPB_11=GPB_15;
		//beep(); //retired
	
		//multiplex7segment(2024); // display 2024 on the 7-segment display

		keypad_input(&prevInputKeypad);
		CloseKeyPad();
		
	}
	
} //end main
