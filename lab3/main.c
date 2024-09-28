/* This file will hold Lab3
Created by: Brenardo Garcia Marti
For ECE 4330

Write software for the M0 that counts the number of times the optical sensor is
blocked/unblocked. Your design should include hardware and software so that the user
can indicate when to start and stop the count. Also, the user should “know” when the
counter is operating. One solution is to designate read start/stop buttons and status LED’s
on the Nuvoton board.

Write C-routines to include all the software requirements discussed in Lecture on Lab 3,
including: (Software design needs to support)
(1) A separate start button using the keypad
(2) A separate reset button to reset the counter using the keypad
(3) A separate stop button using an external interrupt button. This button should stop the
counter but not reset the counter. This external interrupt should send a flag from the ISR
to stop the counter in main.
(4) A counter recording number of objects blocking the light.
(5) A heartbeat signal on the RGB LED (one blink)
(6) One or all of the red LEDs toggle when a block is detected.
(7) Display the count on LCD or 7-segment or both
*/

#include <stdio.h>
#include "NUC1xx.h"

#include "user_func.h"

int main (void) {
	int prevInputKeypad = 0; // from lab 1
	heartbeat();
	
	OpenSevenSegment(); // init 7-segment
	OpenKeyPad(); //initialize Keypad
	
	while(1){
		
		
	keypad_input(&prevInputKeypad);
	CloseKeyPad();
	}//end while
} //end main
