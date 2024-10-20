/* This file will hold TEMPLATE for all projects, with heartbeat function included
number example
Created by: Brenardo Garcia Marti
For ECE 4330
*/

#include <stdio.h>
#include "NUC1xx.h"

#include "user_func.h"

int prevInputKeypad = 0;

void calibrateLight(void){
	/*
	 Find ambient light with no LED output
	set CMR to 0; (PWM->CMRx = 0;)
  set a delay to allow the light to dim
  no_LED = the ADC value
	
	 Find ambient light with full LED output
	set CMR to 0xFFFF;
  set a delay to allow the light to get brighter
  full_LED = the ADC value
	*/
}

int main (void) {
	char output[15];
	heartbeat();
	
		/* initialize peripheral hardware */
	OpenKeyPad();
	Initial_panel(); // init the LCD
	DrvGPIO_ClrBit(E_GPD,14); //backlight LCD
	clr_all_panel(); //clear the LCD
	
	
	
	while(1){
	
		keypad_input(&prevInputKeypad);
		switch(prevInputKeypad){
			case 1:
				zero_percent();
					sprintf(output, " %5.2f %%", 0.0);
					print_lcd(1, output);
				break;
			case 2:
				twentyfive_percent();
			break;
			case 3:
				fifty_percent();
			break;
			case 4:
				seventyFive_percent();
			break;
			case 5:
				oneHund_percent();
			break;
			default:
				zero_percent();
			break;
		}
		
		
	//ShowSevenSegment(0,count);
	CloseKeyPad();
		
	}//end while
} //end main
