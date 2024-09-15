/* This file will hold Lab1b code:
Created by: Brenardo Garcia Marti
For ECE 4330
Lab 1b part 4a and 4b, displaying keypad input on the LCD and the 7 segment
*/

#include "user_func.h"

#define SEGMENT_ON 1
#define SEGMENT_OFF 0

void keypad_input(int* k){
	//capture key value
	int temp;
	char Line1[15];
	sprintf(Line1, "%s", "key = "); //has 6 characters
	
	temp = Scankey();
	if(temp!=0){
		*k=temp;
	}
	
	sprintf(Line1+6, "%d", *k);
	
	displayKeypadInput7seg(*k); //
	print_lcd(0, Line1); //void print_lcd(unsigned char line, char *str)
	
}

void displayKeypadInput7seg(int num){

		OpenSevenSegment(); // init 7-segment
			GPC_7=SEGMENT_ON; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_OFF;
			
			ShowSevenSegment(3,nth_digit(3, num)); // first
			DrvSYS_Delay(475); //wait 475 us
	
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_ON; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(2,nth_digit(2, num)); // second
			DrvSYS_Delay(475); //wait 475 us
	
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_ON; GPC_4 = SEGMENT_OFF;
			ShowSevenSegment(1,nth_digit(1, num)); // third
			DrvSYS_Delay(475); //wait 475 us
	
			GPC_7=SEGMENT_OFF; GPC_6=SEGMENT_OFF; GPC_5=SEGMENT_OFF; GPC_4 = SEGMENT_ON;
			ShowSevenSegment(0,nth_digit(0, num)); // fourth
			DrvSYS_Delay(475); //wait 475 us
		CloseSevenSegment();
}
