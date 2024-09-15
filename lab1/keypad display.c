/* This file will hold Lab1b code:
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1b part 4a and 4b, displaying keypad input on the LCD and the 7 segment
*/

#include "user_func.h"

void keypad_input(char k){
	//capture key value
	int temp;
	char Line1[15];
	sprintf(Line1, "%s", "key = "); //has 6 characters
	
	temp = Scankey();
	if(temp!=0){
		k=temp;
	}
	
	sprintf(Line1+6, "%d", k);
	
	multiplex7segment(k); // display 2024 on the 7-segment display
	print_lcd(0, Line1); //void print_lcd(unsigned char line, char *str)
	
}
