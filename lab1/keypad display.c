/* This file will hold Lab1b code:
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1b part 4a and 4b, displaying keypad input on the LCD and the 7 segment
*/

#include "user_func.h"

void keypad_input(void){
	//capture key value
	int temp;
	char k;
	char buffer[16];
	
	temp = Scankey();
	if(temp!=0){
		k=temp;
	}
	
	sprintf(buffer, "%d", k);
	
	multiplex7segment(k); // display 2024 on the 7-segment display

	print_lcd(0, buffer); //void print_lcd(unsigned char line, char *str)
	
}

